#include <LPC213X.H>
#include "led.h"


#define LED0_bm (1<<16)//0x10000
#define LED1_bm (1<<17)//0x20000
#define LED2_bm (1<<18)//0x40000
#define LED3_bm (1<<19)//0x80000




void LedInit(void){

	IO1DIR = IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks){

	IO1CLR = (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	
	switch(ucLedIndeks){
		case 0:
			IO1SET = LED0_bm;
			break;
		case 1:
			IO1SET = LED1_bm;
			break;
		case 2:
			IO1SET = LED2_bm;
			break;
		case 3:
			IO1SET = LED3_bm;
			break;
	}
}

enum LedDirection {LEFT, RIGHT};
void LedStep(enum LedDirection eDirection){

	static unsigned int uiLedCounter = 0;
	
	switch(eDirection) {
	case LEFT:
		uiLedCounter = (uiLedCounter + 1) % 4;
		break;
	case RIGHT:
		uiLedCounter = (uiLedCounter - 1) % 4;
		break;
	}
	LedOn(uiLedCounter);
}

void LedStepLeft(void){

	LedStep(LEFT);
}

void LedStepRight(void){

	LedStep(RIGHT);
}
