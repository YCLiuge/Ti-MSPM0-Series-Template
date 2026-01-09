#ifndef W25Q64_H
#define W25Q64_H
#include "bsp.h"
#define SPI1_CS_W25Q64(x) ((x) ? DL_GPIO_setPins(W25Q64_PORT, W25Q64_CS_W25Q64_PIN) : DL_GPIO_clearPins(W25Q64_PORT, W25Q64_CS_W25Q64_PIN))
uint16_t W25Q64_readID(void);
void W25Q64_read(uint8_t* buffer,uint32_t read_addr,uint16_t read_length);
void W25Q64_write(uint8_t* buffer, uint32_t addr, uint16_t numbyte);
#endif
