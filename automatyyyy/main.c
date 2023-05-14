#include "led.h"
#include "keyboard.h"

void Delay(unsigned int uiDelayBase){

	unsigned int uiDelayCounter;
	
	for (uiDelayCounter = 0; uiDelayCounter < (5454*uiDelayBase); uiDelayCounter++);
}

	enum LedState{Stop,GoingRight,GoingLeft};
	enum LedState eLedState = Stop;

int main(){
	


KeyboardInit();
LedInit();

	while(1){
		
		switch (eLedState){
		
			case Stop:
				if(eKeyboardRead() == BUTTON_0){
					eLedState= GoingLeft;
					}
				else if(eKeyboardRead() == BUTTON_2){
					eLedState = GoingRight;
				}
				else{
					eLedState = Stop; 
				}
			break;
				
			case GoingLeft:
				LedStepLeft();
				if(eKeyboardRead() == BUTTON_1){
					eLedState = Stop;
				}
				else{
				eLedState = GoingLeft;
				}
			break;

			case GoingRight:
				LedStepRight();
				if(eKeyboardRead() == BUTTON_1){
					eLedState=Stop;
				}
				else{
				eLedState = GoingRight;
				}
			break;
				
			default:
			break;

		}
		Delay(250);
	}
}

