#include <LPC213X.H>
#include "keyboard.h"

#define BUTTON0_bm (1<<4)
#define BUTTON2_bm (1<<5)
#define BUTTON1_bm (1<<6)
#define BUTTON3_bm (1<<7)
enum ButtonState{RELEASEd, PRESSED};
enum ButtonState ReadButton1(){

	if ((IO0PIN & BUTTON1_bm) == 0){
		return PRESSED;  
	} 
	else{
		return RELEASEd;  
	}
}

void KeyboardInit(void){
	
	IO0DIR = IO0DIR & ~(BUTTON0_bm | BUTTON1_bm | BUTTON2_bm | BUTTON3_bm);
}


enum KeyboardState eKeyboardRead(void){
	
	if ((IO0PIN & BUTTON0_bm) == 0){ 
		return BUTTON_0; 
	} 
	else if ((IO0PIN & BUTTON1_bm) == 0){ 
		return BUTTON_1; 
	} 
	else if ((IO0PIN & BUTTON2_bm) == 0){
		return BUTTON_2; 
	} 
	else if ((IO0PIN & BUTTON3_bm) == 0){
		return BUTTON_3; 
	} 
	else 
		return RELEASED; 
}
