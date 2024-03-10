#include "ultrasonic.h"

Ultrasonic* setup_ultrasonic(uint8_t pin) {
  Ultrasonic* ultrasonic = malloc(sizeof(Ultrasonic));
  ultrasonic->pin = pin;
  return ultrasonic;
}

long get_distance(Ultrasonic* ultrasonic, uint32_t timeout = 1000000L) {
  pinMode(ultrasonic->pin, OUTPUT);
  digitalWrite(ultrasonic->pin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonic->pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ultrasonic->pin, LOW);
  return pulseIn(ultrasonic->pin, HIGH, timeout);
}
