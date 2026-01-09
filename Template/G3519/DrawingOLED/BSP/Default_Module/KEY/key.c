#include "KEY/key.h"

void key_init(void)
{

//	DL_GPIO_initDigitalInputFeatures(KEY_B23_IOMUX,
//									 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//									 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

//	DL_GPIO_setUpperPinsPolarity(KEY_PORT, DL_GPIO_PIN_23_EDGE_FALL);
//	DL_GPIO_clearInterruptStatus(KEY_PORT, KEY_B23_PIN);
//	DL_GPIO_enableInterrupt(KEY_PORT, KEY_B23_PIN);
	NVIC_EnableIRQ(key_INT_IRQN); // 开启中断
}

uint8_t key_flag=0;
void GROUP1_IRQHandler(void)
{
	/*收集可以产生触发中断的引脚*/
	uint32_t IRQn_key = DL_GPIO_getEnabledInterruptStatus(key_PORT, key_user_PIN);
	/*根据不同引脚执行对应中断代码*/
	if ((IRQn_key & key_user_PIN) == key_user_PIN)
	{	
		key_flag=!key_flag;
		LED2_toggle;
	}
}
