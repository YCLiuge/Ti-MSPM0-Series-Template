#include "TimerG6_PWM_RGB/timerG6_pwm_rgb.h"


void TRNG_init(void)
{
//	DL_TRNG_reset(TRNG);
//	DL_TRNG_enablePower(TRNG);

//	DL_TRNG_setClockDivider(TRNG, DL_TRNG_CLOCK_DIVIDE_4);

//	DL_TRNG_sendCommand(TRNG, DL_TRNG_CMD_NORM_FUNC);
//	while (!DL_TRNG_isCommandDone(TRNG))
//		;
//	DL_TRNG_clearInterruptStatus(TRNG, DL_TRNG_INTERRUPT_CMD_DONE_EVENT);

//	DL_TRNG_setDecimationRate(TRNG, DL_TRNG_DECIMATION_RATE_4);
}

uint32_t get_TRNG(void)
{
	uint32_t data = 0;
	DL_TRNG_clearInterruptStatus(
		TRNG, DL_TRNG_INTERRUPT_CAPTURE_RDY_EVENT);
	data = DL_TRNG_getCapture(TRNG);
	return data;
}


///*
// * Timer clock configuration to be sourced by  / 1 (80000000 Hz)
// * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
// *   80000000 Hz = 80000000 Hz / (1 * (0 + 1))
// */
//static const DL_TimerA_ClockConfig gRGB_PWMClockConfig = {
//	.clockSel = DL_TIMER_CLOCK_BUSCLK,
//	.divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
//	.prescale = 0U};

//static const DL_TimerA_PWMConfig gRGB_PWMConfig = {
//	.pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
//	.period = 100,
//	.isTimerWithFourCC = true,
//	.startTimer = DL_TIMER_STOP,
//};

/*PWM频率800k*/
void timerg6_pwm_rgb_init(void)
{
//	TRNG_init();
//	DL_TimerA_reset(TimerG6_PWM_INST);
//	DL_TimerA_enablePower(TimerG6_PWM_INST);

//	/* 引脚设置 */
//	DL_GPIO_initPeripheralOutputFunction(GPIO_RGB_PWM_C0_IOMUX, GPIO_RGB_PWM_C0_IOMUX_FUNC);
//	DL_GPIO_enableOutput(GPIO_RGB_PWM_C0_PORT, GPIO_RGB_PWM_C0_PIN);

//	/* 定时器A1时钟设置 */
//	DL_TimerA_setClockConfig(
//		TimerG6_PWM_INST, (DL_TimerA_ClockConfig *)&gRGB_PWMClockConfig);

//	/* 定时器A1功能设置 */
//	DL_TimerA_initPWMMode(
//		TimerG6_PWM_INST, (DL_TimerA_PWMConfig *)&gRGB_PWMConfig);

//	DL_TimerA_setCounterControl(TimerG6_PWM_INST, DL_TIMER_CZC_CCCTL0_ZCOND, DL_TIMER_CAC_CCCTL0_ACOND, DL_TIMER_CLC_CCCTL0_LCOND);

//	/* 对应通道 0 设置· */
//	DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, 99, DL_TIMER_CC_0_INDEX);						   // 对应通道 0 比较值设置
//	DL_TimerA_setCaptureCompareOutCtl(TimerG6_PWM_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,					   // 捕捉比较输出控制设置
//									  DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL, // 起始电平低，无反转， 信号发生器数值
//									  DL_TIMERA_CAPTURE_COMPARE_0_INDEX);
//	DL_TimerA_setCaptCompUpdateMethod(TimerG6_PWM_INST,															   // 配置捕捉比较影子寄存器更新方法
//									  DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_0_INDEX); // 写入 CCACT.SWFRCACT 寄存器的值立即生效

//	/* 使能定时器A0时钟 */
//	DL_TimerA_enableClock(TimerG6_PWM_INST);

//	/* 设置 CCP 方向 */
//	DL_TimerA_setCCPDirection(TimerG6_PWM_INST, DL_TIMER_CC0_OUTPUT);

//	DL_TimerA_enableInterrupt(TimerG6_PWM_INST, DL_TIMER_INTERRUPT_LOAD_EVENT);

	/*启动计时器*/
	DL_TimerG_startCounter(TimerG6_PWM_INST);
	NVIC_EnableIRQ(TimerG6_PWM_INST_INT_IRQN);
}

int RGB_num = 1;
struct
{
	uint8_t G7;
	uint8_t G6;
	uint8_t G5;
	uint8_t G4;
	uint8_t G3;
	uint8_t G2;
	uint8_t G1;
	uint8_t G0;

	uint8_t R7;
	uint8_t R6;
	uint8_t R5;
	uint8_t R4;
	uint8_t R3;
	uint8_t R2;
	uint8_t R1;
	uint8_t R0;

	uint8_t B7;
	uint8_t B6;
	uint8_t B5;
	uint8_t B4;
	uint8_t B3;
	uint8_t B2;
	uint8_t B1;
	uint8_t B0;
} RGB_data;

void set_RGB(uint8_t G, uint8_t R, uint8_t B)
{
	memset(&RGB_data, 75, sizeof(RGB_data));
	if (G & 0x80)
		RGB_data.G7 = 50;
	if (G & 0x40)
		RGB_data.G6 = 50;
	if (G & 0x20)
		RGB_data.G5 = 50;
	if (G & 0x10)
		RGB_data.G4 = 50;
	if (G & 0x08)
		RGB_data.G3 = 50;
	if (G & 0x04)
		RGB_data.G2 = 50;
	if (G & 0x02)
		RGB_data.G1 = 50;
	if (G & 0x01)
		RGB_data.G0 = 50;

	if (R & 0x80)
		RGB_data.R7 = 50;
	if (R & 0x40)
		RGB_data.R6 = 50;
	if (R & 0x20)
		RGB_data.R5 = 50;
	if (R & 0x10)
		RGB_data.R4 = 50;
	if (R & 0x08)
		RGB_data.R3 = 50;
	if (R & 0x04)
		RGB_data.R2 = 50;
	if (R & 0x02)
		RGB_data.R1 = 50;
	if (R & 0x01)
		RGB_data.R0 = 50;

	if (B & 0x80)
		RGB_data.B7 = 50;
	if (B & 0x40)
		RGB_data.B6 = 50;
	if (B & 0x20)
		RGB_data.B5 = 50;
	if (B & 0x10)
		RGB_data.B4 = 50;
	if (B & 0x08)
		RGB_data.B3 = 50;
	if (B & 0x04)
		RGB_data.B2 = 50;
	if (B & 0x02)
		RGB_data.B1 = 50;
	if (B & 0x01)
		RGB_data.B0 = 50;
	NVIC_EnableIRQ(TimerG6_PWM_INST_INT_IRQN);
	//DL_TimerG_startCounter(TimerG6_PWM_INST);
}


void set_RGB_TRNG(void)
{
	memset(&RGB_data, 75, sizeof(RGB_data));
	uint32_t TRNG_RGB=get_TRNG();
	uint8_t G=TRNG_RGB>>16;
	uint8_t R=TRNG_RGB>>8;
	uint8_t B=TRNG_RGB>>0;
	if (G & 0x80)
		RGB_data.G7 = 50;
	if (G & 0x40)
		RGB_data.G6 = 50;
	if (G & 0x20)
		RGB_data.G5 = 50;
	if (G & 0x10)
		RGB_data.G4 = 50;
	if (G & 0x08)
		RGB_data.G3 = 50;
	if (G & 0x04)
		RGB_data.G2 = 50;
	if (G & 0x02)
		RGB_data.G1 = 50;
	if (G & 0x01)
		RGB_data.G0 = 50;

	if (R & 0x80)
		RGB_data.R7 = 50;
	if (R & 0x40)
		RGB_data.R6 = 50;
	if (R & 0x20)
		RGB_data.R5 = 50;
	if (R & 0x10)
		RGB_data.R4 = 50;
	if (R & 0x08)
		RGB_data.R3 = 50;
	if (R & 0x04)
		RGB_data.R2 = 50;
	if (R & 0x02)
		RGB_data.R1 = 50;
	if (R & 0x01)
		RGB_data.R0 = 50;

	if (B & 0x80)
		RGB_data.B7 = 50;
	if (B & 0x40)
		RGB_data.B6 = 50;
	if (B & 0x20)
		RGB_data.B5 = 50;
	if (B & 0x10)
		RGB_data.B4 = 50;
	if (B & 0x08)
		RGB_data.B3 = 50;
	if (B & 0x04)
		RGB_data.B2 = 50;
	if (B & 0x02)
		RGB_data.B1 = 50;
	if (B & 0x01)
		RGB_data.B0 = 50;
	NVIC_EnableIRQ(TimerG6_PWM_INST_INT_IRQN);
	//DL_TimerG_startCounter(TimerG6_PWM_INST);
}

void TimerG6_PWM_INST_IRQHandler(void)
{
	if (RGB_num >= 26)
		RGB_num--;
	else if (RGB_num == 25)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.G7, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 24)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.G6, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 23)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.G5, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 22)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.G4, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 21)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.G3, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 20)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.G2, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 19)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.G1, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 18)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.G0, DL_TIMER_CC_0_INDEX), RGB_num--;

	else if (RGB_num == 17)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.R7, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 16)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.R6, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 15)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.R5, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 14)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.R4, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 13)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.R3, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 12)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.R2, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 11)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.R1, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 10)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.R0, DL_TIMER_CC_0_INDEX), RGB_num--;

	else if (RGB_num == 9)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.B7, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 8)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.B6, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 7)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.B5, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 6)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.B4, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 5)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.B3, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 4)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.B2, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 3)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.B1, DL_TIMER_CC_0_INDEX), RGB_num--;
	else if (RGB_num == 2)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, RGB_data.B0, DL_TIMER_CC_0_INDEX), RGB_num--;

	else if (RGB_num == 1)
		DL_TimerG_setCaptureCompareValue(TimerG6_PWM_INST, 99, DL_TIMER_CC_0_INDEX), RGB_num = 100, NVIC_DisableIRQ(TimerG6_PWM_INST_INT_IRQN);//DL_TimerG_stopCounter(TimerG6_PWM_INST);
	;
}


