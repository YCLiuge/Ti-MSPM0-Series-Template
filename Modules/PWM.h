/*
Program PWM;
Author 0x91f aka Lzy;
Enable what you wanna use, and Disable what you don't;

*/
#ifndef __PWM_H
#define __PWM_H 	 
#pragma once  
#include "ti_msp_dl_config.h"

#define CPU_Frq 80000	//Unit:kHz;
#define CLOCK_SOURCE_COUNT (80000000)
#define PWM_DUTY_MAX (10000)
typedef enum
{
	M0GPWMCH0 = 0,
	M0GPWMCH1 = 1,
	M0GPWMCH2 = 2,
	M0GPWMCH3 = 3,
	M0GPWMCH4 = 4,
	M0GPWMCH5 = 5,//G3507库中有六个INDEX,但是Sysconfig中都最多只有四个通道
	M0GPWMCH6 = 6
}pwmChannelEnum;


void PWM_init();
void SetLeftMotor(uint16_t Period,uint16_t CCPvalue);
void SetRightMotor(uint16_t Period,uint16_t CCPvalue);
void SetServo(uint16_t Period,uint16_t CCPvalue);
void pwm_set_freq(GPTIMER_Regs *gptimer,uint32_t frequency);
void pwm_set_duty(GPTIMER_Regs *gptimer, int32_t duty, pwmChannelEnum ch);


/*
    //! Index associated to Capture Compare 0 //
    DL_TIMER_CC_0_INDEX = 0,
    //! Index associated to Capture Compare 1 //
    DL_TIMER_CC_1_INDEX = 1,
    //! Index associated to Capture Compare 2 //
    DL_TIMER_CC_2_INDEX = 2,
    //! Index associated to Capture Compare 3 //
    DL_TIMER_CC_3_INDEX = 3,
    //! Index associated to Capture Compare 4 //
    DL_TIMER_CC_4_INDEX = 4,
    //! Index associated to Capture Compare 5 //
    DL_TIMER_CC_5_INDEX = 5,
*/


#endif
