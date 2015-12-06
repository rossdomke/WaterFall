#ifndef Color_h
#define Color_h
#include "Arduino.h"
class Color{
public:
	uint8_t R;
	uint8_t G;
	uint8_t B;

	Color();
	Color(uint32_t rgb);
	Color(uint8_t r, uint8_t g, uint8_t b);
	uint32_t RGB();
	void SetColor(uint32_t rgb);
	void NextFadeStep(Color *Target, uint8_t FadeAmount);
private: 
};

#endif //Color_h