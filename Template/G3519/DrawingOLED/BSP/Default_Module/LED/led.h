#ifndef LED_H
#define LED_H

#include "bsp.h"


/*控制LED1高低电平*/
#define LED1(en)                                      \
    if (en)                                           \
        DL_GPIO_setPins(LED_L1_PORT, LED_L1_PIN);        \
    else                                              \
        DL_GPIO_clearPins(LED_L1_PORT, LED_L1_PIN);

/*控制LED1反转*/
#define LED1_toggle DL_GPIO_togglePins(LED_L1_PORT, LED_L1_PIN);

/*控制LED2高低电平*/
#define LED2(en)                                      \
    if (en)                                           \
        DL_GPIO_setPins(LED_L2_PORT, LED_L2_PIN);        \
    else                                              \
        DL_GPIO_clearPins(LED_L2_PORT, LED_L2_PIN);

/*控制LED2反转*/
#define LED2_toggle DL_GPIO_togglePins(LED_L2_PORT, LED_L2_PIN);

void LED_init(void);

#endif
