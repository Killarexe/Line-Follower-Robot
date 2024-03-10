#include "ir_array.h"

void setup_ir_array() {
	pinMode(IR1_PIN, INPUT);
	pinMode(IR2_PIN, INPUT);
	pinMode(IR3_PIN, INPUT);
	pinMode(IR4_PIN, INPUT);
	pinMode(IR5_PIN, INPUT);
}

Direction get_current_direction() {
	bool is_full_left = digitalRead(IR1_PIN);
	bool is_left = digitalRead(IR2_PIN);
	bool is_middle = digitalRead(IR3_PIN);
	bool is_right = digitalRead(IR4_PIN);
	bool is_full_right = digitalRead(IR5_PIN);
	
  //FIXME: There is a priotity system witch makes results wrong.
	
	if(is_right) {
		return RIGHT;
	}
	if(is_left) {
		return LEFT;
	}
	if(is_full_right) {
		return FULL_RIGHT;
	}
	if(is_full_left) {
		return FULL_LEFT;
	}
	if(is_middle) {
		return FORWARD;
	}
	
	return UNKNOWN;
}