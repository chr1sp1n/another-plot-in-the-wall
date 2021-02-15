#include <Arduino.h>

// IR REMOTE
	#define IR_RECEIVER 7
	#define IR_UP 		551486205
	#define IR_DOWN 	551518845
	#define IR_LEFT 	551542815
	#define IR_RIGHT 	551510175
	#define IR_OK 		551494365
//

// SERVO
	#define SERVO_PIN           2
	#define PEN_UP              100
	#define PEN_DOWN            75
	#define USE_SMOOTH_SERVO
//

// STEPPER
	#define LEFT_STEP_PIN_1     6
	#define LEFT_STEP_PIN_2     5
	#define LEFT_STEP_PIN_3     4
	#define LEFT_STEP_PIN_4     3

	#define RIGHT_STEP_PIN_1    8
	#define RIGHT_STEP_PIN_2    9
	#define RIGHT_STEP_PIN_3    10
	#define RIGHT_STEP_PIN_4    11

	#define HALF_STEPS					true

	#define STEPS_PER_REVOLUTION 2048
	#define STEPS_PER_MM (STEPS_PER_REVOLUTION / ((2 * 3.14) * 10 )) // STEPS_PER_MM = Steps per revolution * circumference
//

