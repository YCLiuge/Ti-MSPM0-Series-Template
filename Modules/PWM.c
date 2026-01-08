/*
Program PWM;
Author 0x91f aka Lzy;
Enable what you wanna use, and Disable what you don't;

*/
#include "ti_msp_dl_config.h"
#include "PWM.h"


void PWM_init(){
		DL_Timer_startCounter(MOTOR_INST);
		NVIC_EnableIRQ(MOTOR_INST_INT_IRQN);
		DL_Timer_startCounter(Servo_INST);
		NVIC_EnableIRQ(Servo_INST_INT_IRQN);
		SetLeftMotor(2000,1980);
		SetRightMotor(2000,1980);
}
void SetLeftMotor(uint16_t Period,uint16_t CCPvalue){
	//length_Unit: ms;
	//PA3
	if(Period <= 0) Period = CCPvalue = 1;
	DL_Timer_setLoadValue(MOTOR_INST, Period);DL_Timer_setCaptureCompareValue(MOTOR_INST,CCPvalue,DL_TIMER_CC_0_INDEX);
}
void SetRightMotor(uint16_t Period,uint16_t CCPvalue){
	//length_Unit: ms;
	//PA2
	if(Period <= 0) Period = CCPvalue = 1;
	DL_Timer_setLoadValue(MOTOR_INST, Period);DL_Timer_setCaptureCompareValue(MOTOR_INST,CCPvalue,DL_TIMER_CC_1_INDEX);
}

void SetServo(uint16_t Period,uint16_t CCPvalue){
	//length_Unit: ms;
	//PA10
	if(Period <= 0) Period = CCPvalue = 1;
	DL_Timer_setLoadValue(Servo_INST, Period);DL_Timer_setCaptureCompareValue(Servo_INST,CCPvalue,DL_TIMER_CC_0_INDEX);
}
/*
 * 示例：pwm_set_freq(TIMG7, 5000);
 * Example: pwm_set_freq(TIMG7, 5000);
 * 设置 PWM 频率。
 * Set the PWM frequency.
 * @param gptimer: GPTIMER 寄存器指针
 *                GPTIMER register pointer
 * @param frequency: 频率值
 *                   Frequency value
 * 注意：在调整频率时会将占空比置零，因此在使用示波器查看频率时，需要设置一个大于0的占空比。如果为边缘下降计数，可能会导致占空比为100%。
 * Note: Adjusting the frequency will reset the duty cycle to zero. When using an oscilloscope to check the frequency, set a duty cycle greater than 0. If edge-aligned down counting is used, the duty cycle may be 100%.
 */
void pwm_set_freq(GPTIMER_Regs *gptimer, uint32_t frequency) // Sysconfig 中请将 PWM mode 设置为 Edge-aligned Up Counting
                                                            // In Sysconfig, please set PWM mode to Edge-aligned Up Counting
{
    if (frequency < 1) frequency = 1;

    uint16_t period_temp = 0;    // 周期值
                                 // Period value
    uint16_t freq_div = 0;       // 分频值
                                 // Frequency division value
    freq_div = (uint16_t)((CLOCK_SOURCE_COUNT / frequency) >> 16); // 计算分频值
                                                                   // Calculate frequency division value
    period_temp = (uint16_t)(CLOCK_SOURCE_COUNT / (frequency * (freq_div + 1))); // 计算周期
                                                                                // Calculate period value

    (gptimer->COUNTERREGS.CTRCTL) &= ~(GPTIMER_CTRCTL_EN_ENABLED); // 关闭定时器
                                                                   // Disable the timer
    (gptimer->COMMONREGS.CPS) = freq_div;                          // 设置时钟预分频寄存器，范围 0-255
                                                                   // Set clock pre-division register, range 0-255
    (gptimer->COUNTERREGS.LOAD) = period_temp;                     // 设置加载值
                                                                   // Set load value

    // 将两通道占空比置为0
    // Set the duty cycle of both channels to 0
    DL_Timer_setCaptureCompareValue(gptimer, 0, DL_TIMER_CC_0_INDEX);
    DL_Timer_setCaptureCompareValue(gptimer, 0, DL_TIMER_CC_1_INDEX);
    if (TIMA0 == gptimer) {
        DL_Timer_setCaptureCompareValue(gptimer, 0, DL_TIMER_CC_2_INDEX); // G3507 中仅 TIMA0 有四通道
                                                                          // Only TIMA0 in G3507 has four channels
        DL_Timer_setCaptureCompareValue(gptimer, 0, DL_TIMER_CC_3_INDEX);
    }
    (gptimer->COUNTERREGS.CTRCTL) |= (GPTIMER_CTRCTL_EN_ENABLED); // 启动定时器
                                                                  // Start the timer
}

/*
 * 示例：pwm_set_duty(TIMG7, 5000, M0GPWMCH0); 10000 为最大占空比
 * Example: pwm_set_duty(TIMG7, 5000, M0GPWMCH0); 10000 is the maximum duty cycle
 * 设置 PWM 占空比。
 * Set the PWM duty cycle.
 * @param gptimer: GPTIMER 寄存器指针
 *                GPTIMER register pointer
 * @param duty: 占空比，范围 0-10000
 *             Duty cycle, range 0-10000
 * @param ch: PWM 通道
 *           PWM channel
 */
void pwm_set_duty(GPTIMER_Regs *gptimer, int32_t duty, pwmChannelEnum ch)
{
    uint16_t match_temp;
    uint16_t period_temp;
    DL_TIMER_CC_INDEX tempIndex = DL_TIMER_CC_0_INDEX;

    if (duty > PWM_DUTY_MAX) duty = PWM_DUTY_MAX; // 防止溢出
                                   // Prevent overflow
    else if (duty < 0) duty = 0;

    // 根据通道选择对应的 CC 索引
    // Select the corresponding CC index based on the channel
    switch (ch)
    {
        case M0GPWMCH0: tempIndex = DL_TIMER_CC_0_INDEX; break;
        case M0GPWMCH1: tempIndex = DL_TIMER_CC_1_INDEX; break;
        case M0GPWMCH2: tempIndex = DL_TIMER_CC_2_INDEX; break;
        case M0GPWMCH3: tempIndex = DL_TIMER_CC_3_INDEX; break;
        case M0GPWMCH4: tempIndex = DL_TIMER_CC_4_INDEX; break;
        case M0GPWMCH5: tempIndex = DL_TIMER_CC_5_INDEX; break;
        default: tempIndex = DL_TIMER_CC_0_INDEX; break;
    }

    period_temp = (gptimer->COUNTERREGS.LOAD & GPTIMER_LOAD_LD_MAXIMUM); // 获取周期值
                                                                         // Get period value
    match_temp = period_temp * duty / PWM_DUTY_MAX; // 计算匹配值
                                                    // Calculate match value

    DL_Timer_setCaptureCompareValue(gptimer, match_temp, tempIndex); // 设置捕获比较值
                                                                     // Set capture compare value
}
