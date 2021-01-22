#pragma once
#include <WString.h>
class Clock {
private:
	char sttIn;
	int sttLed[29];
	int digit[7];
	int h1, h2, m1, m2,t1,t2;

public:
	Clock();
	~Clock();
	void inputDigit(int number);
	void inputTime(int hour, int minute);
	void outputClock(String a, int stt);
  int outputArr(int i);  
  void inputTemp(int temp);
};
