#pragma once
#include <WString.h>
class Mau {

private: 
	int Red, Green, Blue;
  
public:
  Mau();
  ~Mau();
	void stringToRGB(String rgb);
	int getRed();
	int getGreen();
	int getBlue();
};
		
	
