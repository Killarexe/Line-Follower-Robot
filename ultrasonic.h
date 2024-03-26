#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "defines.h"
#include "Arduino.h"

typedef struct Ultrasonic {
  uint8_t pin;
} Ultrasonic;

/*************************************************************
 * A simple function to just get an Ultrasonic struct pointer.
 *************************************************************/
Ultrasonic* setup_ultrasonic(uint8_t pin);

/***************************************
 * Get a distance value from Ultrasonic.
 * No units is returned.
 * 50 ~= 1cm;
 ***************************************/
long get_distance(Ultrasonic* ultrasonic, uint32_t timeout = 1000000L);

#endif
