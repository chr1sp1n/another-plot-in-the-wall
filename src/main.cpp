#include <Arduino.h>
#include <configuration.h>
#include <Stepper.h>
#include <IRremote.h>
#include <gcode.h>

Stepper stepperLeft(LEFT_STEP_PIN_1, LEFT_STEP_PIN_2, LEFT_STEP_PIN_3, LEFT_STEP_PIN_4, STEPS_PER_REVOLUTION, 13, HALF_STEPS);
Stepper stepperRight(RIGHT_STEP_PIN_1, RIGHT_STEP_PIN_2, RIGHT_STEP_PIN_3, RIGHT_STEP_PIN_4, STEPS_PER_REVOLUTION, 13, HALF_STEPS);
IRrecv irrecv(IR_RECEIVER);
gcode Commands;

long millimeters = 100;
int dirLeft = -1;
int dirRight = -1;

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	irrecv.enableIRIn();
	Serial.begin(9600);
	stepperLeft.setStepsPerMillimeter(STEPS_PER_MM);
	stepperRight.setStepsPerMillimeter(STEPS_PER_MM);
}

void loop() {

	if(Commands.available()){
    double left = 0;
		double right = 0;
    if(Commands.availableValue('L') && Commands.availableValue('R')) {
			left = Commands.GetValue('L');
			right = Commands.GetValue('R');
			Commands.comment("MOVE (left, right): "+String(left)+","+String(right));
		}
		if(Commands.availableValue('A')) {
			left = -20;
			right = -20;
			Commands.comment("MOVE (left, right): "+String(left)+","+String(right));
		}
		if(Commands.availableValue('D')) {
			left = 20;
			right = 20;
			Commands.comment("MOVE (left, right): "+String(left)+","+String(right));
		}
		if(Commands.availableValue('W')) {
			left = -10;
			right = 10;
			Commands.comment("MOVE (left, right): "+String(left)+","+String(right));
		}
		if(Commands.availableValue('S')) {
			left = 10;
			right = -10;
			Commands.comment("MOVE (left, right): "+String(left)+","+String(right));
		}

		if(left != 0) stepperLeft.setMillimeters(left);
		if(right != 0) stepperRight.setMillimeters(right);
	}

	stepperLeft.run();
	stepperRight.run();

}
