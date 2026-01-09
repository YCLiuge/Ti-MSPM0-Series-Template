#ifndef TIMERG6_PWM_RGB_H
#define TIMERG6_PWM_RGB_H

#include "bsp.h"

/* Defines for RGB_PWM */
#define RGB_PWM_INST TIMA1
#define RGB_PWM_INST_IRQHandler TIMA1_IRQHandler
#define RGB_PWM_INST_INT_IRQN (TIMA1_INT_IRQn)
#define RGB_PWM_INST_CLK_FREQ 80000000
/* GPIO defines for channel 0 */
#define GPIO_RGB_PWM_C0_PORT GPIOB
#define GPIO_RGB_PWM_C0_PIN DL_GPIO_PIN_0
#define GPIO_RGB_PWM_C0_IOMUX (IOMUX_PINCM12)
#define GPIO_RGB_PWM_C0_IOMUX_FUNC IOMUX_PINCM12_PF_TIMA1_CCP0
#define GPIO_RGB_PWM_C0_IDX DL_TIMER_CC_0_INDEX

void timerg6_pwm_rgb_init(void);
void set_RGB(uint8_t G, uint8_t R, uint8_t B);
void TRNG_init(void);
uint32_t get_TRNG(void);
void set_RGB_TRNG(void);
#endif
