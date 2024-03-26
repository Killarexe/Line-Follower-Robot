#include "motor.h"

void start_motors() {
	//Set all motors pins as OUTPUT.
	pinMode(MOTOR_1_DIRECTION, OUTPUT);
	pinMode(MOTOR_1_SPEED, OUTPUT);
	pinMode(MOTOR_1_BRAKE, OUTPUT);
	
	pinMode(MOTOR_2_DIRECTION, OUTPUT);
	pinMode(MOTOR_2_SPEED, OUTPUT);
	pinMode(MOTOR_2_BRAKE, OUTPUT);
	
	set_break(false);	//Disable breaks.
}

void set_motor_speed(int16_t left_speed, int16_t right_speed) {
	//Get motors direction by checking if the input value is negative or not.
	bool left_direction = left_speed >> 15;
	bool right_direction = right_speed >> 15;
	
	//Set motors direction.
	digitalWrite(MOTOR_1_DIRECTION, !left_direction);
	digitalWrite(MOTOR_2_DIRECTION, !right_direction);

	//Get the absolute value of the input value to get the speed for each motors.
	uint8_t left_speed_value = left_direction ? -left_speed & 0xFF : left_speed & 0xFF;
	uint8_t right_speed_value = right_direction ? -right_speed & 0xFF : right_speed & 0xFF;

	//Debug prints...
	#if DEBUG_MODE
		Serial.print("Left Direction: ");
		Serial.println(left_direction);
		Serial.print("Right Direction: ");
		Serial.println(right_direction);
		Serial.print("Left Speed: ");
		Serial.println(left_speed_value);
		Serial.print("Right Speed: ");
		Serial.println(right_speed_value);
	#endif

	//Set motors speed.
	analogWrite(MOTOR_1_SPEED, left_speed_value);
	analogWrite(MOTOR_2_SPEED, right_speed_value);
}

void set_break(bool value) {
	//Enable break for each motors...
	digitalWrite(MOTOR_1_BRAKE, value);
	digitalWrite(MOTOR_2_BRAKE, value);
}
