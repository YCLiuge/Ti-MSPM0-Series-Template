#include "TimerA1/TimerA1.h"
#include "bsp.h"

uint32_t nowtime = 0;
void TimerA1_INST_IRQHandler(void)
{

	switch( DL_TimerA_getPendingInterrupt(TimerA1_INST))
	{
		case DL_TIMERA_IIDX_LOAD:
			nowtime++;
		if((nowtime%5000)==0)
			LED1_toggle;
		break;
		default:
			break;
	}
}

void TimerA1_init(void)
{

	NVIC_ClearPendingIRQ(TimerA1_INST_INT_IRQN);
	NVIC_EnableIRQ(TimerA1_INST_INT_IRQN);
}



