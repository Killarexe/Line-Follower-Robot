#include "defines.h"
#include "ultrasonic.h"
#include "ir_array.h"
#include "motor.h"

const int16_t LEFT_MOTOR_SPEED_FROM_DIRECTION[] = {-255, -128, -255, -64, 64, 0};
const int16_t RIGHT_MOTOR_SPEED_FROM_DIRECTION[] = {64, -64, -255, -128, -255, 0};

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
    set_motor_speed(LEFT_MOTOR_SPEED_FROM_DIRECTION[current_state], RIGHT_MOTOR_SPEED_FROM_DIRECTION[current_state]);
  }
}