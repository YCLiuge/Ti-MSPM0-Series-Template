/*
Program DAC_Internal;
Author 0x91f aka Lzy;
Sysconfig:
		Enable DAC;
		Enable FIFO;
		DMA:
			Block addr to Fixed addr;
			Source Length: Half Word;
			Addr Dir: Inc;
			Dest Length: Half Word;
			Transfer Mode: Repeat Single;(Read Sysconfig manual WORD BY WORD)
			FIFO Thershold: 2/4th
			Sample Time Generator Rate: 1 MSPS;
			Enable Output;
		Advanced Config:
			RES:12 bits;
			Amplifer: ON;
		Interrupt:
			Acknowledgement to the DMA;	
*/
#ifndef __DAC_INTERNAL_H
#define __DAC_INTERNAL_H 	
#pragma once
#include "ti_msp_dl_config.h"

#define DAC_DMA_CHAN_ID DMA_CH0_CHAN_ID
void DAC12_OutputVol_mV(const uint16_t Voltage);
void DAC12_OutputWave(const uint16_t Signals[],const uint16_t length);


#endif
