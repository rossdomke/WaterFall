#include <Arduino.h>
#include <Color.h>
#include <ColorQueue.h>
#include <Strands.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(285 , PIN, NEO_GRB + NEO_KHZ800);
Strands str = Strands(6);
ColorQueue Queue = ColorQueue(0,0);

void setup() {
  uint8_t Lights[] = {60, 50, 45, 60, 30, 40};  
  //uint32_t Cs[] = {0xFF0000, 0xCCDF00, 0xFFEE00, 0x00FF00, 0x0000FF, 0xB000FF, 0xFF00FF}; //7
  //uint32_t Cs[] = {0x0000FF, 0xBF00FF, 0x6600FF, 0x0099FF, 0x0033FF, 0x00FFFF}; //6
  //uint32_t Cs[] = {0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF, 0xFF0000}; // 16
  //uint32_t Cs[] = {0xFF0000, 0xFF00}; //2
  uint32_t Cs[] = {0x210000, 0x332100, 0x273300, 0x3200, 0x33, 0x110033, 0x210027}; //7
  uint8_t NumOfColors = 7;

  //Initialize Strands
  str.StrandList[0].init(0, Lights[0], 0);
  uint32_t LightCounter = 0;
  for(uint8_t i = 1; i < str.NumOfStrands; i++){
    LightCounter += Lights[i - 1];
    str.StrandList[i].init(((i-1) * 12) + 7, Lights[i], LightCounter);
  }

  //Initialize Color Queue
  Queue = ColorQueue(100, NumOfColors); 
  Queue._FadeAmount = 1;
  for(int i = 0; i < Queue.MaxColors; i++){
    Queue.ColorList[i].SetColor(Cs[i]);
  }
  
  //Serial.begin(9600);
  strip.begin();
  strip.show();
    
}

void loop() {
  Queue.Next();
  for(uint8_t i = 0; i < str.NumOfStrands; i++){
    for(uint32_t c = 0; c <= str.StrandList[i].NumOfLights; c++){
      strip.setPixelColor(str.StrandList[i].LightStartPos + c, Queue.GetColor(str.StrandList[i].Offset + c)->RGB());
    }
  }
  strip.show();
  delay(50);
}
