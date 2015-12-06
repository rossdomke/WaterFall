#include "Arduino.h"
#include "Color.h"
#include "ColorQueue.h"

ColorQueue::ColorQueue(uint8_t maxhistory, uint8_t maxcolors){
  _MaxHistory = maxhistory;
  MaxColors = maxcolors;
  _NewestHistory = 0;
  _NextColor = 0;
  _FadeAmount = 5;
  History = new Color[_MaxHistory];
  ColorList = new Color[MaxColors];
  return;
};

Color *ColorQueue::GetColor(uint8_t offset){
	int8_t indx = _NewestHistory - offset;
	indx = (indx < 0) ? _MaxHistory + indx : indx;
	return &History[indx];
}
Color *ColorQueue::GetNextColor(){
	Color *CurrentColor = GetColor(0), *TargetColor = &ColorList[_NextColor];
	FadeCorrection(TargetColor);
	if (CurrentColor->RGB() == TargetColor->RGB()){
		_NextColor = (_NextColor + 1) % MaxColors;
	}
	return &ColorList[_NextColor];
}

void ColorQueue::Next(){
	Color *nRGB;
	nRGB = GetNextColor();
	History[(_NewestHistory + 1) % _MaxHistory].SetColor(GetColor(0)->RGB());
	_NewestHistory = (_NewestHistory + 1) % _MaxHistory;
	History[_NewestHistory].NextFadeStep(nRGB, _FadeAmount);
}

void ColorQueue::FadeCorrection(Color *clr){
	uint8_t cc = _FadeAmount - (clr->R % _FadeAmount);
	clr->R += (cc != _FadeAmount) ? (((cc + clr->R) > 255) ? -1 * cc : cc) : 0;
	cc = _FadeAmount - (clr->G % _FadeAmount);
	clr->G += (cc != _FadeAmount) ? (((cc + clr->G) > 255) ? -1 * cc : cc) : 0;
	cc = _FadeAmount - (clr->B % _FadeAmount);
	clr->B += (cc != _FadeAmount) ? (((cc + clr->B) > 255) ? -1 * cc : cc) : 0;
}