#ifndef IR_ARRAY_H
#define IR_ARRAY_H

#include "Arduino.h"
#include "defines.h"

#define IR_STATES_NAMES {"Full Left", "Left", "Middle", "Right", "Full Right", "Unknown"}

typedef enum Direction {
  FULL_LEFT,
  LEFT,
  FORWARD,
  RIGHT,
  FULL_RIGHT,
  ERROR,
  UNKNOWN
} Direction;

/****************************************
 * Setup pins fot the IR Array component.
 * @see defines.h to configure the pins.
 ****************************************/
void setup_ir_array();

/***********************************
 * Get a Direction from the IR array.
 * @return a Direction.
 ***********************************/
Direction get_current_direction();

#endif