#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "defines.h"
#include "Arduino.h"

typedef struct Ultrasonic {
  uint8_t pin;
} Ultrasonic;

Ultrasonic* setup_ultrasonic(uint8_t pin);

long get_distance(Ultrasonic* ultrasonic);

#endif
