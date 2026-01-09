#ifndef UART0_H
#define UART0_H

#include "bsp.h"

///* Defines for UART_0 */
//#define UART_0_INST UART0
//#define UART_0_INST_FREQUENCY 32768
//#define UART_0_INST_IRQHandler UART0_IRQHandler
//#define UART_0_INST_INT_IRQN UART0_INT_IRQn
//#define GPIO_UART_0_RX_PORT GPIOA
//#define GPIO_UART_0_TX_PORT GPIOA
//#define GPIO_UART_0_RX_PIN DL_GPIO_PIN_11
//#define GPIO_UART_0_TX_PIN DL_GPIO_PIN_10
//#define GPIO_UART_0_IOMUX_RX (IOMUX_PINCM22)
//#define GPIO_UART_0_IOMUX_TX (IOMUX_PINCM21)
//#define GPIO_UART_0_IOMUX_RX_FUNC IOMUX_PINCM22_PF_UART0_RX
//#define GPIO_UART_0_IOMUX_TX_FUNC IOMUX_PINCM21_PF_UART0_TX
//#define UART_0_BAUD_RATE (9600)
//#define UART_0_IBRD_33_kHZ_9600_BAUD (1)
//#define UART_0_FBRD_33_kHZ_9600_BAUD (9)

void uart0_init(uint32_t baud);
void doubleToStr(double value, char *str, int precision);
void delay_ms(uint32_t ms);
void delay_us(uint32_t us);
#endif
