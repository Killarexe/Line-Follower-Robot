/***********************************************
 * Here is the configuration of the robot.
 * You can modify to correspond to your setup...
 ***********************************************/
#ifndef DEFINES_H
#define DEFINES_H

/***************************
 * Motor configuration/pins.
 ***************************/
#define MOTOR_1_DIRECTION 12
#define MOTOR_1_SPEED 3
#define MOTOR_1_BRAKE 9

#define MOTOR_2_DIRECTION 13
#define MOTOR_2_SPEED 11
#define MOTOR_2_BRAKE 8

/******************************
 * IR array configuration/pins.
 ******************************/
#define IR1_PIN 2
#define IR2_PIN 4
#define IR3_PIN 5
#define IR4_PIN 6
#define IR5_PIN 7

/*************************
 * Ultrasonic default pin.
 *************************/
#define ULTRASONIC_PIN 10

/*
 *  Set this program in debug mode.
 *  Witch adds multiple print statements and slow down the process...
 */
#define DEBUG_MODE false

#endif