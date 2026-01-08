/*
Program ADC_Internal;
Author 0x91f aka Lzy;
Sysconfig:
		Mode_1: Disable FIFO;
				using Event Modules to realize Programmable Sampling Rate;
				Conversion Mode: Single;
				Starting Addr: 0;
				Enable Repeat Mode;
				Sampling Mode: Auto;
				Trigger Source: Event;
				ADC Conversion Mem Config:
						Optional Config:
								Trigger Mode: Valid trigger will step to next mem conversion reg;
				Advanced Config:
						RES: 12 bits;
						Disable FIFO;
						Power Down Mode: Manual;
						Desired Sample Time 0: 62.5ns;
				DMA Config:
						Samples Count: 1 (Essential Difference Compared to Enable FIFO Mode;
						Trigger: Mem 0 loaded;
						Addr Mode: Fixed Addr to Fixed Addr;
						Source Len: Half Word;
						Dest Len: Half Word;
						Dest Addr Dir: Inc;
						Transfer Size: 1024(Config it according to your demend;
						Transfer Mode: Single; (Essential Setting according to your demend;
				Event Config:
						Subscriber Channel: 1-Timer_0 => ADC12_0; (Set a Timer and Config its Event Publisher;
		Mode 2: Enable FIFO;
				Conversion Mode: Single;
				Starting Addr: 0;
				Enable Repeat Mode;
				Sampling Mode: Auto;
				Trigger Source: Software; (Essential;
				ADC Conversion Mem Config:
						Optional Config:
								Trigger Mode: Automatic
				Advanced Config:
						RES: 12 bits;
						Enable FIFO;
						Power Down Mode: Manual;
						Desired Sample Time 0: 62.5ns;
				DMA Config:
						Samples Count: 6 (Essential Difference Compared to Disable FIFO Mode;
						Trigger: Mem 10 loaded;
						Addr Mode: Fixed Addr to Fixed Addr;
						Source Len: Word; (Essential
						Dest Len: Word; (Essential
						Dest Addr Dir: Inc;
						Transfer Size: 512(Config it according to your demend;
						Transfer Mode: Single; (Essential Setting according to your demend;
*/
#ifndef __ADC_INTERNAL_H
#define __ADC_INTERNAL_H 	
#pragma once
#include "ti_msp_dl_config.h"

#define ADC_mode 1
//ADC_mode2 unfinished;

#define ADC_DMA_CHAN_ID DMA_CH1_CHAN_ID

#if (ADC_mode == 1)
		void ADC12_init(uint16_t adcData[]);
#elif (ADC_mode == 2)
		void ADC12_init(uint16_t adcData[]);
#endif

#endif
