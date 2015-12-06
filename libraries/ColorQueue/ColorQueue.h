#ifndef ColorQueue_h
#define ColorQueue_h

#include "Arduino.h"

class ColorQueue{
public:
  Color *History;
  Color *ColorList;
  uint8_t MaxColors;
  uint8_t _FadeAmount;


  ColorQueue(uint8_t MaxHistory, uint8_t _MaxColors);
  Color *GetColor(uint8_t offset);
  Color *GetNextColor();
  void FadeCorrection(Color *clr);
  void Next();
private:
  uint8_t _MaxHistory;
  uint8_t _NewestHistory;
  

  uint8_t _NextColor;


};


#endif // ColorFalls_h
