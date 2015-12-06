#include "Arduino.h"
#include "Color.h"

Color::Color(uint32_t rgb){
	SetColor(rgb);
}
Color::Color(){
	R = 0x00; G = 0x00; B = 0x00;
};
Color::Color(uint8_t r, uint8_t g, uint8_t b){
	R = r; G = g; B = b; 
};
void Color::SetColor(uint32_t rgb){
	R = (rgb >> 16) & 0xFF;
	G = (rgb >> 8) & 0xFF;
	B = rgb & 0xFF;
};
uint32_t Color::RGB(){
	uint32_t tmpR = R;
	uint32_t tmpG = G;
	return ((tmpR << 16) | (tmpG << 8) | B) & 0x00FFFFFF;
};
void Color::NextFadeStep(Color *Target, uint8_t FadeAmount){
	R = (Target->R > R) ? R + FadeAmount : ((Target->R < R) ? R - FadeAmount : R);
	G = (Target->G > G) ? G + FadeAmount : ((Target->G < G) ? G - FadeAmount : G);
	B = (Target->B > B) ? B + FadeAmount : ((Target->B < B) ? B - FadeAmount : B);
}