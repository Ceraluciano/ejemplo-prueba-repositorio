#include <Wire.h>

#ifndef TEA5767Radio_h
#define TEA5767Radio_h


class TEA5767Radio
{
private:
	int _address;

public:
  TEA5767Radio();
  TEA5767Radio(int address);
  void setFrequency(float frequency);
  void setFrequency();
};


#endif