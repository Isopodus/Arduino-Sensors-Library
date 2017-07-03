/*            Arduino Sensors Library
Include 1 library -- use 5 sensors at the same time!

Sensors included: Water level sensor, HCR04 Ultrasonic distance sensor, LM35 Temperature sensor. ---> Written by me (Eugene Turchik). 

MPU6050 Gyroscope and accelerometer --> Written by Jeff Rowberg, and DHT Temperature and humidity sensor --> Written by Adafruit Industries.
*/		

#include "Arduino.h"
#include "DHT.h"
#include "MPU6050.h"
#ifndef ARD_Sensors_h
#define ARD_Sensors_h
#endif

class WaterSensor
{
public:
	WaterSensor(int pin);
	int getValue();
private:
	int pin;
};

class HCSR04
{
public:
	HCSR04(int echoPin, int trigPin);
	
	int getDistance(int units);
private:
	int echoPin;
	int trigPin;
};

class LM35
{
public:
	LM35(int pin);
	float getTempetature(int units);
private:
	int pin;
};