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
#include "DAC_Internal.h"
/*
 * DAC12 static output voltage in mV
 *  Adjust output as needed and check in DAC_OUT pin
 * 
 * Set output voltage:
 *  DAC value (12-bits) = DesiredOutputVoltage x 4095
 *                          -----------------------
 *                              ReferenceVoltage
 */
#define DAC12_REF_VOLTAGE_mV (3300)
uint16_t DAC12_value;

void DAC12_OutputVol_mV(const uint16_t Voltage){
		DL_DMA_disableChannel(DMA, DAC_DMA_CHAN_ID);
		DAC12_value = (Voltage * 4095) / DAC12_REF_VOLTAGE_mV;
    //换算，把测量的1000换算到12bit精度下（0-4095）间的数。
    DL_DAC12_output12(DAC0, DAC12_value);//输出 12 位数据值
		
}
void DAC12_OutputWave(const uint16_t Signals[],const uint16_t length){
		DL_DMA_setSrcAddr(
        DMA, DAC_DMA_CHAN_ID, (uint32_t) & Signals[0]);
    DL_DMA_setDestAddr(DMA, DAC_DMA_CHAN_ID, (uint32_t) & (DAC0->DATA0));
    DL_DMA_setTransferSize(
        DMA, DAC_DMA_CHAN_ID, length);
    DL_DMA_enableChannel(DMA, DAC_DMA_CHAN_ID);
}
