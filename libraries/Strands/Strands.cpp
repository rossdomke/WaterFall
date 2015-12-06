#include "Arduino.h"
#include "Strands.h"


uint8_t Strand::LastLightPosition(){
	return Offset + NumOfLights;
}
Strand::Strand(){
	Offset = 0;
	NumOfLights = 0;
}

Strand::Strand(uint8_t o, uint8_t n){
	Offset = o;
	NumOfLights = n;
}

void Strand::init(uint8_t o, uint8_t n, uint32_t p){
	Offset = o;
	NumOfLights = n;
	LightStartPos = p;	
}

Strands::Strands(uint8_t Num){
	StrandList = new Strand[Num];
	NumOfStrands = Num;
}
uint8_t Strands::LongestHist(){
	uint8_t Longest = 0;
	for(uint8_t i = 0; i <= NumOfStrands; i++){
		if(StrandList[i].LastLightPosition() > Longest){
			Longest = StrandList[i].LastLightPosition();
		}
	}
}

