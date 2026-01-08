/*
Program uart_bluetooth;
Author 0x91f aka Lzy;
Enable what you wanna use, and Disable what you don't;
For L1306:
	UART0 is for wireless tasks;
	UART1 is for USB communication;
For G3507:
	UART0 is for USB communication;
	UART1 is for wireless tasks;

*/
#include "UART.h"


#define FRAME_HEADER 0xFF
#define FRAME_TAIL   0xFE


void UART_init(){
	NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
	NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
}


void MCUTransData8(const UART_Regs * UART_Port,const char *data,const uint16_t length) { //发送数据到uart
	//Warning: This Function varies depending on which MCU you are using
    for(uint16_t i = 0;i < length;++i){
        DL_UART_transmitDataBlocking(UART_Port,data[i]);
    }
		DL_UART_transmitDataBlocking(UART_Port,'\n');
}
void MCUTransData16(const UART_Regs * UART_Port,const uint16_t *data,const uint16_t length) { //发送数据到uart
	//Warning: This Function varies depending on which MCU you are using
    for(uint16_t i = 0;i < length;++i){
				uint8_t byte_tmp = (data[i] >> 8) & 0xFF;
        DL_UART_transmitDataBlocking(UART_Port,byte_tmp);
				byte_tmp = data[i] & 0xFF;
				DL_UART_transmitDataBlocking(UART_Port,byte_tmp);
    }
		DL_UART_transmitDataBlocking(UART_Port,'\n');
}

//Wireless Interrupt(L1306);
//USB Interrupt(G3507);
//Copy this function and paste it in the main.c file;
//Or using extern method to induce this function.
/*
void UART_0_INST_IRQHandler(){
		volatile uint8_t data;
		switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)){
				case  DL_UART_MAIN_IIDX_RX:
				data = DL_UART_Main_receiveData(UART_0_INST);
				if (!receivingFrame){
						if (UART_graystatus == FRAME_HEADER) {
								receivingFrame = true;
                }
            } else {
								if (data == FRAME_TAIL) {
                    receivingFrame = false; 
                } else {
										UART_graystatus = data;
								}
            }
            break;
        default:
            break;
    }
	
}
*/
