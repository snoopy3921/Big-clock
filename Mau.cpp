#include"Mau.h"




 Mau::Mau() {
	Red = 0;
	Green = 0;
	Blue = 0;
 
}
Mau::~Mau(){
  
}
 void Mau::stringToRGB(String rgb) {
	int s1 = rgb.indexOf('.');
	int s2 = rgb.indexOf('.', s1 + 1);
	int s3 = rgb.indexOf('.', s2 + 1);
	String R = rgb.substring(0, s1);
	String G = rgb.substring(s1 + 1, s2);
	String B = rgb.substring(s2 + 1, s3);
	Red = R.toInt();
	Green = G.toInt();
	Blue = B.toInt();
}
 int Mau::getRed() {
	return Red;
}
 int Mau::getGreen() {
	return Green;
}
 int Mau::getBlue() {
	return Blue;
}
