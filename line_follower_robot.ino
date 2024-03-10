/************************************************************************************************************************************
 * This program is dependent from a library called 'UltrasonicRanger': https://github.com/Seeed-Studio/Seeed_Arduino_UltrasonicRanger
 ************************************************************************************************************************************/

#include "defines.h"
#include "Ultrasonic.h"
#include "ir_array.h"
#include "motor.h"

const int16_t LEFT_MOTOR_SPEED_FROM_DIRECTION] = {-255, -192, -255, -64, 0, 0};
const int16_t RIGHT_MOTOR_SPEED_FROM_DIRECTION[] = {0, -64, -255, -192, -255, 0};

void setup(){
	setup_ir_array();
	start_motors();
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
      Serial.println(IR_STATES_NAMES[current_state]);
    #endif
    set_break(current_state == Direction::UNKNOWN);
    set_motor_speed(LEFT_MOTOR_SPEED_FROM_IR_STATE[current_state], RIGHT_MOTOR_SPEED_FROM_IR_STATE[current_state]);
  }
}