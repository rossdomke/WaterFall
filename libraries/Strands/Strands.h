#ifndef Strands_h
#define Strands_h

#include "Arduino.h"


class Strand{
public: 
	uint8_t Offset;
	uint8_t NumOfLights;
	uint32_t LightStartPos;
	uint8_t LastLightPosition();
	Strand();
	void init(uint8_t o, uint8_t n, uint32_t p);
	Strand(uint8_t o, uint8_t n);
private: 
};


class Strands{
public:
	Strand *StrandList;
	uint8_t NumOfStrands;
	uint8_t LongestHist();

	Strands(uint8_t Num);
private: 
};


#endif 