#include"Clock.h"

Clock::Clock()
{
	sttIn = 0;
	/*sttLed[29] PROGMEM = {
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,
		0,
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0 };
	digit[7] PROGMEM = {0,0,0,0,0,0,0};*/
	h1 = 0, h2 = 0, m1 = 0, m2 = 0,t1=0,t2=0;
}
Clock::~Clock() {}
void Clock::inputDigit(int number) {
	
	if (number == 0) {
	 digit[0] =0 ;
   digit[1] =1 ;
   digit[2] =1 ;
   digit[3] =1 ;
   digit[4] =1 ;
   digit[5] =1 ;
   digit[6] =1 ;
	}
	if (number == 1) {
	
   digit[0] =0 ;
   digit[1] =1 ;
   digit[2] =0 ;
   digit[3] =0 ;
   digit[4] =0 ;
   digit[5] =0 ;
   digit[6] =1 ;
	}
	if (number == 2) {
		
   digit[0] =1 ;
   digit[1] =1 ;
   digit[2] =1 ;
   digit[3] =0 ;
   digit[4] =1 ;
   digit[5] =1 ;
   digit[6] =0 ;
	}
	if (number == 3) {
		
   digit[0] =1 ;
   digit[1] =1 ;
   digit[2] =1 ;
   digit[3] =0 ;
   digit[4] =0 ;
   digit[5] =1 ;
   digit[6] =1 ;
	}
	if (number == 4) {
		
   digit[0] =1 ;
   digit[1] =1 ;
   digit[2] =0 ;
   digit[3] =1 ;
   digit[4] =0 ;
   digit[5] =0 ;
   digit[6] =1 ;
	}
	if (number == 5) {
		
   digit[0] =1 ;
   digit[1] =0 ;
   digit[2] =1 ;
   digit[3] =1 ;
   digit[4] =0 ;
   digit[5] =1 ;
   digit[6] =1 ;
	}
	if (number == 6) {
		
   digit[0] =1 ;
   digit[1] =0 ;
   digit[2] =1 ;
   digit[3] =1 ;
   digit[4] =1 ;
   digit[5] =1 ;
   digit[6] =1 ;
	}
	if (number == 7) {
		
   digit[0] =0 ;
   digit[1] =1 ;
   digit[2] =1 ;
   digit[3] =0 ;
   digit[4] =0 ;
   digit[5] =0 ;
   digit[6] =1 ;
	}
	if (number == 8) {
		
   digit[0] =1 ;
   digit[1] =1 ;
   digit[2] =1 ;
   digit[3] =1 ;
   digit[4] =1 ;
   digit[5] =1 ;
   digit[6] =1 ;
	}
	if (number == 9) {
		
   digit[0] =1 ;
   digit[1] =1 ;
   digit[2] =1 ;
   digit[3] =1 ;
   digit[4] =0 ;
   digit[5] =1 ;
   digit[6] =1 ;
	}
}
void Clock::inputTime(int hour, int minute) {
	if (hour >= 10) {
		h1 = hour / 10;
		h2 = hour % 10;
	}
 else{
  h1=0;
  h2=hour;
  }
	if (minute >= 10) {
		m1 =  minute/ 10;
		m2 =  minute % 10;
	}
 else{
  m1=0;
  m2=minute;
  
 }
}
void Clock::outputClock(String a, int stt) {
	if(a=="Time"){
	inputDigit(h1);
	for (int i = 0; i < 7; i++) {
		sttLed[i] = digit[i];
	}
	inputDigit(h2);
	for (int i = 0; i < 7; i++) {
		sttLed[i+7] = digit[i];
	}
  if(stt==0){
     sttLed[14]=0;
  }else if(stt==1){
     sttLed[14]=1;
  }
 
	inputDigit(m1);
	for (int i = 0; i < 7; i++) {
		sttLed[i+15] = digit[i];
	}
	inputDigit(m2);
	for (int i = 0; i < 7; i++) {
		sttLed[i+22] = digit[i];
	}
	}
 if(a=="Temp"){
  inputDigit(t1);
  for (int i = 0; i < 7; i++) {
    sttLed[i] = digit[i];
  }
  inputDigit(t2);
  for (int i = 0; i < 7; i++) {
    sttLed[i+7] = digit[i];
  }
  sttLed[14]=0;
  sttLed[15]=1;
  sttLed[16]=1;
  sttLed[17]=1;
  sttLed[18]=1;
  sttLed[19]=0;
  sttLed[20]=0;
  sttLed[21]=0;
  sttLed[22]=0;
  sttLed[23]=0;
  sttLed[24]=1;
  sttLed[25]=1;
  sttLed[26]=1;
  sttLed[27]=1;
  sttLed[28]=0;
 }
}
int Clock::outputArr(int i){
  return sttLed[i];
}
void Clock::inputTemp(int temp){
  if (temp >= 10) {
    t1 = temp / 10;
    t2 = temp % 10;
  }
 else{
  t1=0;
  t2=temp;
  }
}
