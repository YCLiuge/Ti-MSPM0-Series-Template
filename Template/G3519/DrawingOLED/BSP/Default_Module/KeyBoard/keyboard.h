#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_
#include "bsp.h"

/* Defines for H1: GPIOA.17 with pinCMx 39 on package pin 10 */
#define KEY_H1_PORT                                                      (GPIOA)
#define KEY_H1_PIN                                              (DL_GPIO_PIN_17)
#define KEY_H1_IOMUX                                             (IOMUX_PINCM39)
/* Defines for H2: GPIOA.22 with pinCMx 47 on package pin 18 */
#define KEY_H2_PORT                                                      (GPIOA)
#define KEY_H2_PIN                                              (DL_GPIO_PIN_22)
#define KEY_H2_IOMUX                                             (IOMUX_PINCM47)
/* Defines for H3: GPIOB.10 with pinCMx 27 on package pin 62 */
#define KEY_H3_PORT                                                      (GPIOB)
#define KEY_H3_PIN                                              (DL_GPIO_PIN_10)
#define KEY_H3_IOMUX                                             (IOMUX_PINCM27)
/* Defines for H4: GPIOB.11 with pinCMx 28 on package pin 63 */
#define KEY_H4_PORT                                                      (GPIOB)
#define KEY_H4_PIN                                              (DL_GPIO_PIN_11)
#define KEY_H4_IOMUX                                             (IOMUX_PINCM28)
/* Defines for V1: GPIOB.20 with pinCMx 48 on package pin 19 */
#define KEY_V1_PORT                                                      (GPIOB)
#define KEY_V1_PIN                                              (DL_GPIO_PIN_20)
#define KEY_V1_IOMUX                                             (IOMUX_PINCM48)
/* Defines for V2: GPIOB.21 with pinCMx 49 on package pin 20 */
#define KEY_V2_PORT                                                      (GPIOB)
#define KEY_V2_PIN                                              (DL_GPIO_PIN_21)
#define KEY_V2_IOMUX                                             (IOMUX_PINCM49)
/* Defines for V3: GPIOB.22 with pinCMx 50 on package pin 21 */
#define KEY_V3_PORT                                                      (GPIOB)
#define KEY_V3_PIN                                              (DL_GPIO_PIN_22)
#define KEY_V3_IOMUX                                             (IOMUX_PINCM50)
/* Defines for V4: GPIOB.23 with pinCMx 51 on package pin 22 */
#define KEY_V4_PORT                                                      (GPIOB)
#define KEY_V4_PIN                                              (DL_GPIO_PIN_23)
#define KEY_V4_IOMUX                                             (IOMUX_PINCM51)


void keyboard_init(void);
char get_keyboard_value(void);

#endif
