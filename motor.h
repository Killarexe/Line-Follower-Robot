#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "defines.h"

/************************************
 * Setup motor pins.
 * @see defines.h to configure the pins.
 ************************************/
void start_motors();

/**************************************************************************************************
 * A simple function to set the speed of the motors.
 * Attention even if the parameters are 16 bit, the value needs to respect this range: [-255, 255].
 * @param left_speed Speed of the left motor. Range [-255, 255]
 * @param right_speed Speed of the right motor. Range [-255, 255]
 **************************************************************************************************/
void set_motor_speed(int16_t left, int16_t right);

/********************************************
 * Enable or disable the break in the motors.
 ********************************************/
void set_break(bool value);
#endif