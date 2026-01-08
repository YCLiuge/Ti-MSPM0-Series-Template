/*
Program Keyboard;
Author 0x91f aka Lzy;
Description{
	Keyboard realization on mspm0L1306.Easy to transplant to other devices;
	Keyboard Scanning settings:
		PA 0,1,7,12 : Signal receiver as KR(KeyboardReceiver);
		PA 13,14,17,18 : Signal Emitter as KE(KeyboardEmitter);
	
}
*/
#ifndef __KEYBOARD_H
#define __KEYBOARD_H			
#pragma once
#include "ti_msp_dl_config.h"
//#include "sys.h"
//#include "stdlib.h"	  

static const char Keys[17] = {0x00,'7','4','1','x','8','5','2','0','9','6','3','.','+','-','*','/'};
																//  1		2		3		4		5		6		7		8		9		10	11	12	13	14	15	16

//#define
#define CPU_Frq 80000 	//Unit:kHz
	#define delay_level 0 	//Unit:ms
 		     

//Keyboard¿ØÖÆº¯Êý

void Keyboard_init();
inline bool readButton(size_t B);

uint16_t KeySCInput();	//Key-scanning-input;
//uint16_t KeyIRInput();	//Key-Interrupt-input;Not good to use.

#endif  
	 

