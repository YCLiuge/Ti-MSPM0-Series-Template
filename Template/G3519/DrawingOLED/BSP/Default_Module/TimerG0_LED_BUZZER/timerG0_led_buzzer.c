#include "TIMERG0_LED_BUZZER/timerG0_led_buzzer.h"



/*
 * Timer clock configuration to be sourced by  / 8 (5000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   50000 Hz = 5000000 Hz / (8 * (99 + 1))
 */
static const DL_TimerG_ClockConfig gPWM_LED_BuzzerClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 99U
};

static const DL_TimerG_PWMConfig gPWM_LED_BuzzerConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 100,
    .isTimerWithFourCC = true,
    .startTimer = DL_TIMER_START,
};

void timg0_led_buzzer_init(void)
{
//	DL_TimerG_reset(PWM_LED_Buzzer_INST);
//	DL_TimerG_enablePower(PWM_LED_Buzzer_INST);
//	
//    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_LED_Buzzer_C0_IOMUX,GPIO_PWM_LED_Buzzer_C0_IOMUX_FUNC);
//    DL_GPIO_enableOutput(GPIO_PWM_LED_Buzzer_C0_PORT, GPIO_PWM_LED_Buzzer_C0_PIN);
//    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_LED_Buzzer_C1_IOMUX,GPIO_PWM_LED_Buzzer_C1_IOMUX_FUNC);
//    DL_GPIO_enableOutput(GPIO_PWM_LED_Buzzer_C1_PORT, GPIO_PWM_LED_Buzzer_C1_PIN);	

//    DL_TimerG_setClockConfig(
//        PWM_LED_Buzzer_INST, (DL_TimerG_ClockConfig *) &gPWM_LED_BuzzerClockConfig);

//    DL_TimerG_initPWMMode(
//        PWM_LED_Buzzer_INST, (DL_TimerG_PWMConfig *) &gPWM_LED_BuzzerConfig);

//    // Set Counter control to the smallest CC index being used
//    DL_TimerG_setCounterControl(PWM_LED_Buzzer_INST,DL_TIMER_CZC_CCCTL0_ZCOND,DL_TIMER_CAC_CCCTL0_ACOND,DL_TIMER_CLC_CCCTL0_LCOND);

//    DL_TimerG_setCaptureCompareOutCtl(PWM_LED_Buzzer_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
//		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
//		DL_TIMERG_CAPTURE_COMPARE_0_INDEX);

//    DL_TimerG_setCaptCompUpdateMethod(PWM_LED_Buzzer_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_0_INDEX);
//    DL_TimerG_setCaptureCompareValue(PWM_LED_Buzzer_INST, 100, DL_TIMER_CC_0_INDEX);

//    DL_TimerG_setCaptureCompareOutCtl(PWM_LED_Buzzer_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
//		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
//		DL_TIMERG_CAPTURE_COMPARE_1_INDEX);

//    DL_TimerG_setCaptCompUpdateMethod(PWM_LED_Buzzer_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_1_INDEX);
//    DL_TimerG_setCaptureCompareValue(PWM_LED_Buzzer_INST, 100, DL_TIMER_CC_1_INDEX);

//    DL_TimerG_enableClock(PWM_LED_Buzzer_INST);

//    DL_TimerG_setCCPDirection(PWM_LED_Buzzer_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT );
}


void set_led_buzzer(uint16_t hz,uint16_t led_duty,uint16_t buzzer_duty)
{

    uint16_t count=50000/hz;
    TIMG0->COUNTERREGS.LOAD=count;
    DL_TimerG_setCaptureCompareValue(TimerG0_PWM_INST,(count*led_duty)/100,GPIO_TimerG0_PWM_C0_IDX);
    DL_TimerG_setCaptureCompareValue(TimerG0_PWM_INST,(count*buzzer_duty)/100,GPIO_TimerG0_PWM_C1_IDX);
}














