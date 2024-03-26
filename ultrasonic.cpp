#include "Arduino.h"
#include "ultrasonic.h"

Ultrasonic* setup_ultrasonic(uint8_t pin) {
	//Create an Ultrasonic struct.
	Ultrasonic* ultrasonic = malloc(sizeof(Ultrasonic));
	ultrasonic->pin = pin;
	return ultrasonic;
}

long get_distance(Ultrasonic* ultrasonic, uint32_t timeout = 1000000L) {
	//Send a signal to the Ultrasonic to get the output value.
	pinMode(ultrasonic->pin, OUTPUT);
	digitalWrite(ultrasonic->pin, LOW);
	delayMicroseconds(2);
	digitalWrite(ultrasonic->pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(ultrasonic->pin, LOW);
  pinMode(ultrasonic->pin, INPUT);
	return pulseIn(ultrasonic->pin, HIGH, timeout);	//Read output value from ultrasonic.
}
