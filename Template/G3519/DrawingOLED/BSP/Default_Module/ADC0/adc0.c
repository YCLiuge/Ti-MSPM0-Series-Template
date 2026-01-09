#include "ADC0/adc0.h"


volatile bool gCheckADC;


void adc0_init(void)
{

	NVIC_EnableIRQ(ADC0_INST_INT_IRQN);
	gCheckADC  = false;
}



void get_adc0_num_val(uint32_t *adc0)
{

	DL_ADC12_startConversion(ADC0_INST);
    /* Wait until all data channels have been loaded. */
    while (gCheckADC == false) {
        }
	
    *adc0 =
            DL_ADC12_getMemResult(ADC0_INST, DL_ADC12_MEM_IDX_0);
    *(adc0+1) =
            DL_ADC12_getMemResult(ADC0_INST, DL_ADC12_MEM_IDX_1); 
    *(adc0+2) =
            DL_ADC12_getMemResult(ADC0_INST, DL_ADC12_MEM_IDX_2);
    *(adc0+3) =
            DL_ADC12_getMemResult(ADC0_INST, DL_ADC12_MEM_IDX_3);
//    *(adc0+4) =
//            DL_ADC12_getMemResult(ADC0_INST, DL_ADC12_MEM_IDX_4);
//    *(adc0+5) =
//            DL_ADC12_getMemResult(ADC0_INST, DL_ADC12_MEM_IDX_5);
    gCheckADC = false;
    DL_ADC12_enableConversions(ADC0_INST);
}




/* Check for the last result to be loaded then change boolean */
void ADC0_INST_IRQHandler(void)
{
    switch (DL_ADC12_getPendingInterrupt(ADC0_INST)) {
        case DL_ADC12_IIDX_MEM3_RESULT_LOADED:
            gCheckADC = true;
            break;
        default:
            break;
    }
}



