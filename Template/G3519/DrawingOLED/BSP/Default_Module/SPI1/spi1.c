#include "SPI1/spi1.h"
#include "bsp.h"



uint8_t spi1_read_write_byte(uint8_t dat)
{
    uint8_t data = 0;

    // 发送数据
    DL_SPI_transmitData8(SPI_1_INST, dat);
    // 等待SPI总线空闲
    while (DL_SPI_isBusy(SPI_1_INST))
        ;
    // 接收数据
    data = DL_SPI_receiveData8(SPI_1_INST);
    // 等待SPI总线空闲
    while (DL_SPI_isBusy(SPI_1_INST))
        ;

    return data;
}

