#include "DHT.h"



#include "FastLED.h"
#include "Mau.h"
#include "Clock.h"
#include <Wire.h> 
#include "RTClib.h"

#include <SoftwareSerial.h>
#define DHTPIN 4
#define DHTTYPE DHT11   // DHT 11// what digital pin we're connected to
RTC_DS1307 rtc;
DHT dht(DHTPIN, DHTTYPE);
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const byte NumberOfFields = 7;
const int rxPin = 2;
const int txPin = 3;
bool rainbow =0;
SoftwareSerial hc06(rxPin, txPin);
#define NUM_LEDS 30
#define DATA_PIN 12
String rgb = "";
String copyRgb="";
int stt=0;
unsigned long t;
CRGBArray<NUM_LEDS> leds;




void setup() {
  
delay(2000);
t=millis();
Wire.begin();
rtc.begin();
dht.begin();
//rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
Serial.begin(9600);

hc06.begin(9600); // đặt baudrate giao tiếp hc06
FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

}

void loop() {
   
  static uint8_t hue;

 
  Clock x;
  //x.inputTime(now.hour(),now.minute());
    //x.outputClock("Time");

  
  
  Mau a;
  if(rainbow==0){
    if(millis()-t<7000){
     for(int i=0;i<NUM_LEDS;i++){      
             leds[i] = CRGB(0,0,0);//dinh dang dung la CRGB(blue, red, green).
           }     
   
     
   x.inputTime(rtc.now().hour(),rtc.now().minute());
  x.outputClock("Time",(int)rtc.now().second()%2);
    hue++;
    for(int i = 0; i < NUM_LEDS; i++) {   
     
   if(x.outputArr(i)==1){
    // let's set an led value
    leds[i] = CHSV(hue+10*i,255,255);
   }if(x.outputArr(i)==0){
      leds[i] = CRGB(0,0,0);
     }
    
    
    
  }
  FastLED.delay(8);
      
  
  
    }else{
      if(millis()-t>7000){
     for(int i=0;i<NUM_LEDS;i++){      
             leds[i] = CRGB(0,0,0);//dinh dang dung la CRGB(blue, red, green).
           }     
  
     
     x.inputTemp((int)dht.readTemperature());
  x.outputClock("Temp",0);
    hue++;
    for(int i = 0; i < NUM_LEDS; i++) {   
     
   if(x.outputArr(i)==1){
    // let's set an led value
    leds[i] = CHSV(hue+10*i,255,255);
   }if(x.outputArr(i)==0){
      leds[i] = CRGB(0,0,0);
     }
    if(millis()-t>10000) t=millis();
    
    
  }
  FastLED.delay(8);
      
    


    
  
  }
    }
  }
  if(rainbow==1){
     a.stringToRGB(copyRgb);
    for(int i=0;i<NUM_LEDS;i++){      
             leds[i] = CRGB(0,0,0);//dinh dang dung la CRGB(blue, red, green).
           }     
   x.inputTime(rtc.now().hour(),rtc.now().minute());
  x.outputClock("Time",(int)rtc.now().second()%2);
    for(int i=0;i<NUM_LEDS;i++){      
      if(x.outputArr(i)==1){
        leds[i] = CRGB(a.getBlue(),a.getRed(),a.getGreen());//dinh dang dung la CRGB(blue, red, green).
        
        }
        if(x.outputArr(i)==0){
      leds[i] = CRGB(0,0,0);
     }
    
        
      }     
     
    
    FastLED.show();
  }
  while(hc06.available()){
  char r=(char)hc06.read();
  if(r==')'){
    stt=1;
    break;
  }if(r=='a'){
    stt=2;
    break;
  }
  if(r=='b'){
    stt=3;
    break;
  }
  if(r=='c'){
    stt=4;
    break;
  }
  if(r=='d'){
    stt=5;
    break;
  }
  if(r=='e'){
    stt=6;
    break;
  }
  if(r=='f'){
    stt=7;
  }
  if(r=='g'){
    stt=8;
    break;
  }
  else{
    rgb+=r;
    
  }
  
  }
  if(stt==1){
    rainbow=1;
     
   
    stt=0;
    copyRgb=rgb;
    rgb="";
    
  }
  if(stt==2){
    while(!hc06.available()){
        x.inputTime(rtc.now().hour(),rtc.now().minute());
  x.outputClock("Time",(int)rtc.now().second()%2);
    hue++;
    
    for(int i = 0; i < NUM_LEDS; i++) {   
     
   if(x.outputArr(i)==1){
    // let's set an led value
    leds[i] = CHSV(hue,255,255);
   }if(x.outputArr(i)==0){
      leds[i] = CRGB(0,0,0);
     }
    
    
    
  }
  FastLED.delay(40);
    }
  }
   if(stt==3){
    for(int i=0;i<NUM_LEDS;i++){      
             leds[i] = CRGB(0,0,0);//dinh dang dung la CRGB(blue, red, green).
           }  
    
    hue=50;
    static int s=0;
    while(!hc06.available()){
  x.inputTime(rtc.now().hour(),rtc.now().minute());
  x.outputClock("Time",(int)rtc.now().second()%2);
   
    if(hue>170) s=1;
     if(hue<50) s=0;
    for(int i = 0; i < NUM_LEDS; i++) { 
    
    if(x.outputArr(i)==1){
  
    // let's set an led value
    leds[i] = CHSV(hue,255,255);
       
    }if(x.outputArr(i)==0){
      leds[i] = CRGB(0,0,0);
     }
    
    
    
    }
   if(s==0)hue++;
     else hue--;
   FastLED.delay(25);
   }
    }
   


    if(stt==4){
      for(int i=0;i<NUM_LEDS;i++){      
             leds[i] = CRGB(0,0,0);//dinh dang dung la CRGB(blue, red, green).
           }  
    
    hue=170;
    static int s=0;
    while(!hc06.available()){
      x.inputTime(rtc.now().hour(),rtc.now().minute());
  x.outputClock("Time",(int)rtc.now().second()%2);
    if(hue>245) s=1;
     if(hue<170) s=0;
    for(int i = 0; i < NUM_LEDS; i++) { 
    
    if(x.outputArr(i)==1){
  
    // let's set an led value
    leds[i] = CHSV(hue,255,255);
     
    }if(x.outputArr(i)==0){
      leds[i] = CRGB(0,0,0);
     }
    
    
    
   }
   if(s==0)hue++;
     else hue--;
   FastLED.delay(25);
    }
   }
   if(stt==5){
      for(int i=0;i<NUM_LEDS;i++){      
             leds[i] = CRGB(0,0,0);//dinh dang dung la CRGB(blue, red, green).
           }  
           static int s=0;
           int br=0;   
    while(!hc06.available()){
      if(br>=255) s=1;
     if(br<=0) s=0;
   x.inputTime(rtc.now().hour(),rtc.now().minute());
  x.outputClock("Time",(int)rtc.now().second()%2);
  
    
    for(int i = 0; i < NUM_LEDS; i++) {   
     
   if(x.outputArr(i)==1){
    // let's set an led value
    leds[i] = CHSV(hue,255,br);
   }if(x.outputArr(i)==0){
      leds[i] = CRGB(0,0,0);
     }
    
    
    
  }
  hue++;
  if(s==0)br++;
     else br--;
  FastLED.delay(30);
  

  
      
  
  }
   }
   if(stt==6){
    for(int i=0;i<NUM_LEDS;i++){      
             leds[i] = CRGB(0,0,0);//dinh dang dung la CRGB(blue, red, green).
           }  
           static int s=0;
           
    while(!hc06.available()){
   
   x.inputTemp((int)dht.readTemperature());
  x.outputClock("Temp",(int)rtc.now().second()%2);
  
    
    for(int i = 0; i < NUM_LEDS; i++) {   
     
   if(x.outputArr(i)==1){
    // let's set an led value
    leds[i] = CHSV(hue+10*i,255,255);
   }if(x.outputArr(i)==0){
      leds[i] = CRGB(0,0,0);
     }
    
    
    
  }
  hue++;
  
  FastLED.delay(30);
  

  
      
  
  }
   }
   if(stt==7){
    for(int i=0;i<NUM_LEDS;i++){      
             leds[i] = CRGB(0,0,0);//dinh dang dung la CRGB(blue, red, green).
           }     
    while(!hc06.available()){
     
   x.inputTime(rtc.now().hour(),rtc.now().minute());
  x.outputClock("Time",(int)rtc.now().second()%2);
    
    for(int i = 0; i < NUM_LEDS; i++) {   
     
   if(x.outputArr(i)==1){
    // let's set an led value
    leds[i] = CRGB(random(0,255),random(0,255),random(0,255));
   }if(x.outputArr(i)==0){
      leds[i] = CRGB(0,0,0);
     }
    
    
    
  }
  FastLED.delay(800);
      
  
  }
   }
    
  
}
