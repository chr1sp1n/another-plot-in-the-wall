#include <Arduino.h>
#include <configuration.h>
#include <Stepper.h>
#include <IRremote.h>

Stepper stepperLeft(LEFT_STEP_PIN_1, LEFT_STEP_PIN_2, LEFT_STEP_PIN_3, LEFT_STEP_PIN_4, STEPS_PER_REVOLUTION, 10, HALF_STEPS);
Stepper stepperRight(RIGHT_STEP_PIN_1, RIGHT_STEP_PIN_2, RIGHT_STEP_PIN_3, RIGHT_STEP_PIN_4, STEPS_PER_REVOLUTION, 10, HALF_STEPS);
IRrecv irrecv(IR_RECEIVER);

long millimeters = 10;
long steps = 500;
void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	irrecv.enableIRIn();
	Serial.begin(9600);
	stepperLeft.setStepsPerMillimeter(STEPS_PER_MM);
	stepperRight.setStepsPerMillimeter(STEPS_PER_MM);
	stepperLeft.setMillimeters(millimeters);
	stepperRight.setMillimeters(millimeters);
}

int dirLeft = 1;
int dirRight = 1;
unsigned long waitBase = 50000;
unsigned long waitLeft = waitBase;
unsigned long waitRight = waitBase;
void loop() {

	if(stepperLeft.run() == 0){
		--waitLeft;
		if(waitLeft < 1){
			waitLeft = waitBase;
			dirLeft = dirLeft > 0 ? -1 : 1;
			stepperLeft.setMillimeters(millimeters * dirLeft);
		}
	}

	if(stepperRight.run() == 0){
		--waitRight;
		if(waitRight < 1){
			waitRight = waitBase;
			dirRight = dirRight > 0 ? -1 : 1;
			stepperRight.setMillimeters(millimeters * dirRight);
		}
	}

	// decode_results results
  // if (irrecv.decode(&results)){
	//   results.value;
  //   irrecv.resume();
  // }

	// if(results.value){
	// 	digitalWrite(LED_BUILTIN, HIGH);
	// 	switch(what){
	// 		case IR_UP:
	// 			// Serial.println("UP");
	// 			break;
	// 		case IR_DOWN:
	// 			// Serial.println("DOWN");
	// 			break;
	// 		case IR_LEFT:
	// 			// Serial.println("LEFT");
	// 			myStepperLeft.step( stepsPerMM * -10 );
	// 			myStepperRight.step( stepsPerMM * -10 );
	// 			break;
	// 		case IR_RIGHT:
	// 			// Serial.println("RIGHT");
	// 			myStepperLeft.step( stepsPerMM * 10 );
	// 			myStepperRight.step( stepsPerMM * 10 );
	// 			break;
	// 		case IR_OK:
	// 			// Serial.println("OK");
	// 			break;
	// 	}
	// }else{
	// 	digitalWrite(LED_BUILTIN, LOW);
	// 	delay(100);
	// }



}
