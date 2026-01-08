/*
Program uart_bluetooth;
Author 0x91f aka Lzy;
}
*/
#ifndef __UART_H
#define __UART_H 	   
#pragma once
#include "ti_msp_dl_config.h"

void UART_init();
void MCUTransData8(const UART_Regs * UART_Port, const char *data, const uint16_t length);
void MCUTransData16(const UART_Regs * UART_Port, const uint16_t *data, const uint16_t length);

#endif
