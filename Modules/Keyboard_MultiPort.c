/*
Program Keyboard;
Author 0x91f aka Lzy;
Description{
	Keyboard realization on mspm0L1306.Easy to transplant to other devices;
	Keyboard Scanning settings:
		PA 0,1,7,12 : Signal receiver as KR(KeyboardReceiver), Pins need to set to PULL-UP Resistors(This is essential);
		PA 13,14,17,18 : Signal Emitter as KE(KeyboardEmitter);
	
}
*/
#include "Keyboard.h"
//const bool InterruptON = 1;	//Switch of the Interrupt Function;
void Keyboard_init(){
	DL_GPIO_setPins(Keyboard_KE_1_PORT,Keyboard_KE_1_PIN);
	DL_GPIO_setPins(Keyboard_KE_2_PORT,Keyboard_KE_2_PIN);
	DL_GPIO_setPins(Keyboard_KE_3_PORT,Keyboard_KE_3_PIN);
	DL_GPIO_setPins(Keyboard_KE_4_PORT,Keyboard_KE_4_PIN);
    DL_GPIO_setPins(Keyboard_KR_1_PORT,Keyboard_KR_1_PIN);
	DL_GPIO_setPins(Keyboard_KR_2_PORT,Keyboard_KR_2_PIN);
	DL_GPIO_setPins(Keyboard_KR_3_PORT,Keyboard_KR_3_PIN);
	DL_GPIO_setPins(Keyboard_KR_4_PORT,Keyboard_KR_4_PIN);
}

bool readButton(GPIO_Regs * Button_Port,size_t B){
	if(DL_GPIO_readPins(Button_Port,B) == 0){
		if (delay_level != 0) DL_Common_delayCycles(CPU_Frq * delay_level);
		if(DL_GPIO_readPins(Button_Port,B) == 0){
			return 0;
		}
	}
	return 1;
}
uint16_t KeySCInput(){
	//delay_level Unit: ms;
	int x,y,cvt;
	bool flag;
	flag = 1;cvt = x = y = 0;
	DL_GPIO_clearPins(Keyboard_KE_1_PORT,Keyboard_KE_1_PIN);
	//Pins�ı���ѹ��Ҫʱ��
	DL_Common_delayCycles(3200);
	//Delayȷ����ƽ�Ѿ��ı�
	x = 1;
	if(readButton(Keyboard_KR_1_PORT,Keyboard_KR_1_PIN) == 0) y = 1,flag = 0;
	//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_1_PIN) == 0) y = 1,flag = 0;
	if(readButton(Keyboard_KR_2_PORT,Keyboard_KR_2_PIN) == 0) y = 2,flag = 0;
	//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_2_PIN) == 0) y = 2,flag = 0;
	if(readButton(Keyboard_KR_3_PORT,Keyboard_KR_3_PIN) == 0) y = 3,flag = 0;
	//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_3_PIN) == 0) y = 3,flag = 0;
	if(readButton(Keyboard_KR_4_PORT,Keyboard_KR_4_PIN) == 0) y = 4,flag = 0;
	//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_4_PIN) == 0) y = 4,flag = 0;
	DL_GPIO_setPins(Keyboard_KE_1_PORT,Keyboard_KE_1_PIN);
	if (flag){
		DL_GPIO_clearPins(Keyboard_KE_2_PORT,Keyboard_KE_2_PIN);
		DL_Common_delayCycles(3200);
		x = 2;
		if(readButton(Keyboard_KR_1_PORT,Keyboard_KR_1_PIN) == 0) y = 1,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_1_PIN) == 0) y = 1,flag = 0;
		if(readButton(Keyboard_KR_2_PORT,Keyboard_KR_2_PIN) == 0) y = 2,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_2_PIN) == 0) y = 2,flag = 0;
		if(readButton(Keyboard_KR_3_PORT,Keyboard_KR_3_PIN) == 0) y = 3,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_3_PIN) == 0) y = 3,flag = 0;
		if(readButton(Keyboard_KR_4_PORT,Keyboard_KR_4_PIN) == 0) y = 4,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_4_PIN) == 0) y = 4,flag = 0;
		DL_GPIO_setPins(Keyboard_KE_2_PORT,Keyboard_KE_2_PIN);
	}
	if (flag){
		DL_GPIO_clearPins(Keyboard_KE_3_PORT,Keyboard_KE_3_PIN);
		DL_Common_delayCycles(3200);
		x = 3;
		if(readButton(Keyboard_KR_1_PORT,Keyboard_KR_1_PIN) == 0) y = 1,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_1_PIN) == 0) y = 1,flag = 0;
		if(readButton(Keyboard_KR_2_PORT,Keyboard_KR_2_PIN) == 0) y = 2,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_2_PIN) == 0) y = 2,flag = 0;
		if(readButton(Keyboard_KR_3_PORT,Keyboard_KR_3_PIN) == 0) y = 3,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_3_PIN) == 0) y = 3,flag = 0;
		if(readButton(Keyboard_KR_4_PORT,Keyboard_KR_4_PIN) == 0) y = 4,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_4_PIN) == 0) y = 4,flag = 0;
		DL_GPIO_setPins(Keyboard_KE_3_PORT,Keyboard_KE_3_PIN);
	}
	if (flag){
		DL_GPIO_clearPins(Keyboard_KE_4_PORT,Keyboard_KE_4_PIN);
		DL_Common_delayCycles(3200);
		x = 4;
		if(readButton(Keyboard_KR_1_PORT,Keyboard_KR_1_PIN) == 0) y = 1,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_1_PIN) == 0) y = 1,flag = 0;
		if(readButton(Keyboard_KR_2_PORT,Keyboard_KR_2_PIN) == 0) y = 2,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_2_PIN) == 0) y = 2,flag = 0;
		if(readButton(Keyboard_KR_3_PORT,Keyboard_KR_3_PIN) == 0) y = 3,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_3_PIN) == 0) y = 3,flag = 0;
		if(readButton(Keyboard_KR_4_PORT,Keyboard_KR_4_PIN) == 0) y = 4,flag = 0;
		//if(DL_GPIO_readPins(Keyboard_PORT,Keyboard_KR_4_PIN) == 0) y = 4,flag = 0;
		DL_GPIO_setPins(Keyboard_KE_4_PORT,Keyboard_KE_4_PIN);
	}
	if(flag == 0) cvt = (x - 1) * 4 + y;
	return cvt;
}
