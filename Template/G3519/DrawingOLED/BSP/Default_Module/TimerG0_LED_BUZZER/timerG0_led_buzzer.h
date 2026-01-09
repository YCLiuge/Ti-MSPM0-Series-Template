#ifndef TIMERG0_LED_BUZZER_H
#define TIMERG0_LED_BUZZER_H
#include "bsp.h"




void timg0_led_buzzer_init(void);
void set_led_buzzer(uint16_t hz,uint16_t led_duty,uint16_t buzzer_duty);
#endif