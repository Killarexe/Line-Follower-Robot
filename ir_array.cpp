#include "ir_array.h"

void setup_ir_array() {
	//Set all IR's pins as INPUT.
	pinMode(IR1_PIN, INPUT);
	pinMode(IR2_PIN, INPUT);
	pinMode(IR3_PIN, INPUT);
	pinMode(IR4_PIN, INPUT);
	pinMode(IR5_PIN, INPUT);
}

Direction get_current_direction() {
	//Get each value from IR's.
	bool is_full_left = !digitalRead(IR1_PIN);
	bool is_left = !digitalRead(IR2_PIN);
	bool is_middle = !digitalRead(IR3_PIN);
	bool is_right = !digitalRead(IR4_PIN);
	bool is_full_right = !digitalRead(IR5_PIN);
	
	//Return a direction depending from the values.
	//WARNING: There is a priority system. The MIDDLE direction is the less priorized...
	if(is_full_left && is_full_right && is_left && is_right && is_middle) {
		return UNKNOWN;
	}
	if(is_full_left && is_left) {
		return LEFT;
	}
	if(is_full_right && is_right) {
		return RIGHT;
	}
	if(is_full_right) {
		return FULL_RIGHT;
	}
	if(is_full_left) {
		return FULL_LEFT;
	}
	if(is_right) {
		return MIDDLE_RIGHT;
	}
	if(is_left) {
		return MIDDLE_LEFT;
	}
	if(is_middle) {
		return MIDDLE;
	}
	return UNKNOWN;
}