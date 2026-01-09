#ifndef SPI1_H
#define SPI1_H


#include "bsp.h"

uint8_t spi1_read_write_byte(uint8_t dat);




#define SPI1_CS_IMU(x) ((x) ? DL_GPIO_setPins(IMU_PORT, IMU_CS_IMU_PIN) : DL_GPIO_clearPins(IMU_PORT, IMU_CS_IMU_PIN))







#endif