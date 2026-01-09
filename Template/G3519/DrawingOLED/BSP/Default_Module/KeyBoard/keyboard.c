#include "KeyBoard/keyboard.h"

void keyboard_init(void)
{
//	    DL_GPIO_initDigitalOutputFeatures(KEY_H1_IOMUX,
//		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

//    DL_GPIO_initDigitalOutputFeatures(KEY_H2_IOMUX,
//		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

//    DL_GPIO_initDigitalOutputFeatures(KEY_H3_IOMUX,
//		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

//    DL_GPIO_initDigitalOutputFeatures(KEY_H4_IOMUX,
//		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

//    DL_GPIO_initDigitalInputFeatures(KEY_V1_IOMUX,
//		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

//    DL_GPIO_initDigitalInputFeatures(KEY_V2_IOMUX,
//		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

//    DL_GPIO_initDigitalInputFeatures(KEY_V3_IOMUX,
//		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

//    DL_GPIO_initDigitalInputFeatures(KEY_V4_IOMUX,
//		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

//    DL_GPIO_setPins(GPIOA, KEY_H1_PIN |
//		KEY_H2_PIN);
//    DL_GPIO_enableOutput(GPIOA, KEY_H1_PIN |
//		KEY_H2_PIN);
//    DL_GPIO_setPins(GPIOB, KEY_H3_PIN |
//		KEY_H4_PIN);
//    DL_GPIO_enableOutput(GPIOB, KEY_H3_PIN |
//		KEY_H4_PIN);
}




char get_keyboard_value(void)
{
    int h_arr[4] = {keyboard_H1_PIN, keyboard_H2_PIN, keyboard_H3_PIN, keyboard_H4_PIN};
    int v_arr[4] = {keyboard_V1_PIN, keyboard_V2_PIN, keyboard_V3_PIN, keyboard_V4_PIN};
	char board[16]={'1','4','7','*','2','5','8','0','3','6','9','#','A','B','C','D'};

    int i = 0;
		int j = 0;
    int key_value = 0;
    for (i = 0; i < 4; i++)
    {
        DL_GPIO_clearPins((i>1) ? GPIOB:GPIOB, h_arr[i]);
        DL_GPIO_setPins(((i+1)%4>1) ? GPIOB:GPIOB, h_arr[(i + 1) % 4]);
        DL_GPIO_setPins(((i+2)%4>1) ? GPIOB:GPIOB, h_arr[(i + 2) % 4]);
        DL_GPIO_setPins(((i+3)%4>1) ? GPIOB:GPIOB, h_arr[(i + 3) % 4]);

        delay_cycles(5);

        for (j = 0; j < 4; j++)
        {
            if (DL_GPIO_readPins(keyboard_PORT, v_arr[j]) == 0)
            {
                key_value = j * 4 + i + 1;
            }
        }

    }
	switch(key_value)
	{
		case 1: set_led_buzzer(466,50,50);break;
		case 2: set_led_buzzer(630,50,50);break;
		case 3: set_led_buzzer(880,50,50);break;
		case 5: set_led_buzzer(523,50,50);break;
		case 6: set_led_buzzer(698,50,50);break;
		case 9: set_led_buzzer(587,50,50);break;
		case 10: set_led_buzzer(784,50,50);break;
		default :set_led_buzzer(400,0,100);
	}

    return board[key_value-1]; 
}









































//void scan_keyR_init(void)
//{
//    DL_GPIO_initDigitalInputFeatures(R1__IOMUX,													// 初始化R1__IOMUX为数字输入
//                                     DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,		// 禁止输入信号反转，配置下拉电阻
//                                     DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);		// 禁用输入迟滞，禁用唤醒功能
//    DL_GPIO_initDigitalInputFeatures(R2__IOMUX,													//其他同理
//                                     DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
//                                     DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
//    DL_GPIO_initDigitalInputFeatures(R3__IOMUX,
//                                     DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
//                                     DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
//    DL_GPIO_initDigitalInputFeatures(R4__IOMUX,
//                                     DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
//                                     DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

//    DL_GPIO_initDigitalOutputFeatures(C4__IOMUX,
//                                      DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//                                      DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
//    DL_GPIO_initDigitalOutputFeatures(C3__IOMUX,
//                                      DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//                                      DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
//    DL_GPIO_initDigitalOutputFeatures(C2__IOMUX,
//                                      DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//                                      DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
//    DL_GPIO_initDigitalOutputFeatures(C1__IOMUX,
//                                      DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//                                      DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
//}

//void scan_keyC_init(void)
//{
//    DL_GPIO_initDigitalInputFeatures(C4__IOMUX,													// 初始化C4__IOMUX为数字输入
//                                     DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,		// 禁止输入信号反转，配置下拉电阻
//                                     DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);		//禁用输入迟滞，禁用唤醒功能
//    DL_GPIO_initDigitalInputFeatures(C3__IOMUX,													//其他同理
//                                     DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
//                                     DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
//    DL_GPIO_initDigitalInputFeatures(C2__IOMUX,
//                                     DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
//                                     DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
//    DL_GPIO_initDigitalInputFeatures(C1__IOMUX,
//                                     DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
//                                     DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

//    DL_GPIO_initDigitalOutputFeatures(R4__IOMUX,
//                                      DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//                                      DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
//    DL_GPIO_initDigitalOutputFeatures(R3__IOMUX,
//                                      DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//                                      DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
//    DL_GPIO_initDigitalOutputFeatures(R2__IOMUX,
//                                      DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//                                      DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
//    DL_GPIO_initDigitalOutputFeatures(R1__IOMUX,
//                                      DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
//                                      DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
//}

//#define keyboard_delay delay_cycles(200000)
//int keyboard_scan(void)
//{
//    uint32_t Cpins = 0;							// 初始化读取的列引脚状态变量
//    scan_keyR_init();							// 初始化行扫描
//    keyboard_delay;						// 延时，确保信号稳定
//	
//	// 检查每一行是否有按键按下
//    if (DL_GPIO_readPins(R1_PORT, R1__PIN))		// 如果R1行有按键按下，则检查列
//    {
//        scan_keyC_init();
//        keyboard_delay;
//        Cpins = DL_GPIO_readPins(GPIOB, C1__PIN | C2__PIN | C3__PIN | C4__PIN);
//        if (Cpins & C1__PIN)
//            return 1;
//        else if (Cpins & C2__PIN)
//            return 2;
//        else if (Cpins & C3__PIN)
//            return 3;
//        else if (Cpins & C4__PIN)
//            return 4;
//    }
//    else if (DL_GPIO_readPins(R2_PORT, R2__PIN))	// 如果R2行有按键按下，则检查列
//    {
//        scan_keyC_init();
//        keyboard_delay;
//        Cpins = DL_GPIO_readPins(GPIOB, C1__PIN | C2__PIN | C3__PIN | C4__PIN);
//        if (Cpins & C1__PIN)
//            return 5;
//        else if (Cpins & C2__PIN)
//            return 6;
//        else if (Cpins & C3__PIN)
//            return 7;
//        else if (Cpins & C4__PIN)
//            return 8;
//    }

//    else if (DL_GPIO_readPins(R3_PORT, R3__PIN))	// 如果R3行有按键按下，则检查列
//    {
//        scan_keyC_init();
//        keyboard_delay;
//        Cpins = DL_GPIO_readPins(GPIOB, C1__PIN | C2__PIN | C3__PIN | C4__PIN);
//        if (Cpins & C1__PIN)
//            return 9;
//        else if (Cpins & C2__PIN)
//            return 10;
//        else if (Cpins & C3__PIN)
//            return 11;
//        else if (Cpins & C4__PIN)
//            return 12;
//    }

//    else if (DL_GPIO_readPins(R4_PORT, R4__PIN))	// 如果R4行有按键按下，则检查列
//    {
//        scan_keyC_init();
//        keyboard_delay;
//        Cpins = DL_GPIO_readPins(GPIOB, C1__PIN | C2__PIN | C3__PIN | C4__PIN);
//        if (Cpins & C1__PIN)
//            return 13;
//        else if (Cpins & C2__PIN)
//            return 14;
//        else if (Cpins & C3__PIN)
//            return 15;
//        else if (Cpins & C4__PIN)
//            return 16;
//    }
//    return 0;								// 如果R2行有按键按下，则检查列
//}
