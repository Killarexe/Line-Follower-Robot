#include "defines.h"
#include "ultrasonic.h"
#include "ir_array.h"
#include "motor.h"

const char* DIRECTION_NAMES[] = {"Full Left", "Left", "Middle Left", "Middle", "Middle Right", "Right", "Full Right", "Unknown"};
const int16_t LEFT_MOTOR_SPEED_FROM_DIRECTION[] = {-255, -192, -128, -255, -64, 0, 64, 0};
const int16_t RIGHT_MOTOR_SPEED_FROM_DIRECTION[] = {64, 0, -64, -255, -128, -192, -255, 0};

//Ultrasonic* ultrasonic;

void setup(){
	setup_ir_array();
	start_motors();
  //ultrasonic = setup_ultrasonic(ULTRASONIC_PIN);
	#if DEBUG_MODE
		Serial.begin(9600);
	#endif
}

Direction previous_state = Direction::UNKNOWN;
void loop() {
	Direction current_state = get_current_direction();
	if(current_state != previous_state) {
		previous_state = current_state;
		#if DEBUG_MODE
      Serial.println("Direction Debug:");
			Serial.println(DIRECTION_NAMES[current_state]);
		#endif
		set_break(current_state == Direction::UNKNOWN);
		set_motor_speed(
			LEFT_MOTOR_SPEED_FROM_DIRECTION[current_state],
			RIGHT_MOTOR_SPEED_FROM_DIRECTION[current_state]
		);
	}
  /*long distance = get_distance(ultrasonic);
  #if DEBUG_MODE
    Serial.print("Ultrasonic Debug:\n\tDistance raw: ");
    Serial.println(distance);
    Serial.print("\n\tDistance cm: ");
    Serial.println(distance / 50);
  #endif
  set_break(distance / 50 <= 5);*/
}