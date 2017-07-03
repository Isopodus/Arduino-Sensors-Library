#include "Arduino.h"
#include "ARD_Sensors.h"

//Water sensor
WaterSensor::WaterSensor(int pin)
{
	this->pin = pin;
	pinMode(this->pin, INPUT);
}

int WaterSensor::getValue()
{
	return analogRead(pin);
}

//Distance sensor (HC-SR04)
HCSR04::HCSR04(int echoPin, int trigPin)
{
	this->echoPin = echoPin;
	this->trigPin = trigPin;
	pinMode(this->trigPin, OUTPUT);
	pinMode(this->echoPin, INPUT);
}

//Units: 1-cm, 2-mm, 3-inch
int HCSR04::getDistance(int units)
{
	int duration, cm, mm, inch;
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	cm = duration / 58;
	mm = duration / 5.8;
	inch = duration / 148;
	
	if (units == 1)
	{
		return cm;
	}
	else if (units == 2)
	{
		return mm;
	}
	else if (units == 3)
	{
		return inch;
	}
	else
	{
		return -1;
	}
}

//LM35 Sensor
LM35::LM35(int pin)
{
	this->pin = pin;
	pinMode(this->pin, INPUT);
}

//Units: 1-Celsius, 2-Fahrenheit
float LM35::getTempetature(int units)
{
	int value = analogRead(pin);
	float m = (value / 1024.0) * 5000;
	float c = m / 10;
	float f = (c * 9) / 5 + 32;

	if (units == 1)
	{
		return c;
	}
	else if (units == 2)
	{
		return f;
	}
	else
	{
		return -1;
	}
}
