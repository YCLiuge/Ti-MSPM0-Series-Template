#ifndef KEY_H
#define KEY_H

#include "bsp.h"

//#define KEY_PORT (GPIOB)

///* Defines for PIN_0: GPIOB.23 with pinCMx 51 on package pin 22 */
//// pins affected by this interrupt request:["PIN_0"]
//#define KEY_INT_IRQN (GPIOB_INT_IRQn)
//#define KEY_INT_IIDX (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
//#define KEY_B23_IIDX (DL_GPIO_IIDX_DIO23)
//#define KEY_B23_PIN (DL_GPIO_PIN_23)
//#define KEY_B23_IOMUX (IOMUX_PINCM51)

#define KEY GPIO_read(KEY_PORT, KEY_B23_PIN)
void key_init(void);
extern uint8_t key_flag;
#endif
