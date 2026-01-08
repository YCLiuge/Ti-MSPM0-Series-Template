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
#include "ADC_Internal.h"


#if (ADC_mode == 1)
		void ADC12_init(uint16_t adcData[]){
				DL_DMA_setSrcAddr(DMA, ADC_DMA_CHAN_ID, (uint32_t) DL_ADC12_getMemResultAddress(ADC12_0_INST,0));
				DL_DMA_setDestAddr(DMA, ADC_DMA_CHAN_ID, (uint32_t) &adcData[0]);
				DL_DMA_enableChannel(DMA, ADC_DMA_CHAN_ID);
				NVIC_EnableIRQ(ADC12_0_INST_INT_IRQN);
				DL_ADC12_startConversion(ADC12_0_INST);
		}
		/*
		//Copy this Function into main file;
		void ADC12_0_INST_IRQHandler(void){
				switch (DL_ADC12_getPendingInterrupt(ADC12_0_INST)) 
						case DL_ADC12_IIDX_DMA_DONE:
								//DL_TimerA_stopCounter(TIMER_0_INST);
								//数据处理部分，此处无
		
								DL_DMA_setSrcAddr(DMA, DMA_CH1_CHAN_ID, (uint32_t) DL_ADC12_getMemResultAddress(ADC12_0_INST,0));
								DL_DMA_setDestAddr(DMA, DMA_CH1_CHAN_ID, (uint32_t) &adcData[0]);
								DL_DMA_enableChannel(DMA, DMA_CH1_CHAN_ID);
								//NVIC_EnableIRQ(ADC12_0_INST_INT_IRQN);
								DL_ADC12_startConversion(ADC12_0_INST);
		
								//DL_TimerA_stopCounter(TIMER_0_INST);
								break;
						default:
								break;
				}
		}
		*/
		
#elif (ADC_mode == 2)
		void ADC12_init(uint16_t adcData[]){
				DL_DMA_setSrcAddr(
						DMA, ADC_DMA_CHAN_ID, (uint32_t) DL_ADC12_getFIFOAddress(ADC12_0_INST));
				DL_DMA_setDestAddr(DMA, ADC_DMA_CHAN_ID, (uint32_t) &adcData[0]);
				DL_DMA_setTransferSize(
						DMA, ADC_DMA_CHAN_ID, sizeof(adcData) / sizeof(uint16_t));
				DL_DMA_enableChannel(DMA, ADC_DMA_CHAN_ID);
		}
		/*
		Note: UnTested;
		void ADC12_0_INST_IRQHandler(void){
		//ADC的中断函数
				switch (DL_ADC12_getPendingInterrupt(ADC12_0_INST)) {
        
//						case DL_ADC12_IIDX_MEM0_RESULT_LOADED://如果MEM0（对应通道0）中有数据写入，则存储其数据进入数组adcdata
							//Basic usage;
//								gCheckADC = true;	
//								adcData[j]=DL_ADC12_getMemResult(ADC12_0_INST, DL_ADC12_MEM_IDX_0);
//								j++;
//								j=j%1024;
//								break;
						case DL_ADC12_IIDX_DMA_DONE://如果DMA中有数据写入，则存储其数据进入数组adcdata
								gCheckADC = true;	
								//Data is transfered by DMA;
								j++;
								j=j%1024;
								break;
						default:
								break;
				}
		}
		*/
#endif
