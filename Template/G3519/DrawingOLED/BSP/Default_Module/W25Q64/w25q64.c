#include "W25Q64/w25q64.h"





//Read the chip ID
//// 0XEF16 indicates that the chip model is W25Q64
uint16_t W25Q64_readID(void)
{
    uint16_t  ID = 0;
    SPI1_CS_W25Q64(0);
    spi1_read_write_byte(0x90);
    spi1_read_write_byte(0x00);
    spi1_read_write_byte(0x00);
    spi1_read_write_byte(0x00);
    ID |= spi1_read_write_byte(0xFF)<<8;
    ID |= spi1_read_write_byte(0xFF);
    SPI1_CS_W25Q64(1);
    return ID;
}


void W25Q64_write_enable(void)
{
    SPI1_CS_W25Q64(0);
    spi1_read_write_byte(0x06);
    SPI1_CS_W25Q64(1);
}



void W25Q64_wait_busy(void)
{
    unsigned char byte = 0;
    do
     {
        SPI1_CS_W25Q64(0);
        spi1_read_write_byte(0x05);
        byte = spi1_read_write_byte(0Xff);
        SPI1_CS_W25Q64(1);
     }while( ( byte & 0x01 ) == 1 );
}




void W25Q64_erase_sector(uint32_t addr)
{
        addr *= 4096;
        W25Q64_write_enable();
        W25Q64_wait_busy();
        SPI1_CS_W25Q64(0);
        spi1_read_write_byte(0x20);
        spi1_read_write_byte((uint8_t)((addr)>>16));
        spi1_read_write_byte((uint8_t)((addr)>>8));
        spi1_read_write_byte((uint8_t)addr);
        SPI1_CS_W25Q64(1);

        W25Q64_wait_busy();
}



void W25Q64_write(uint8_t* buffer, uint32_t addr, uint16_t numbyte)
{
    unsigned int i = 0;
    W25Q64_erase_sector(addr/4096);
    W25Q64_write_enable();
    W25Q64_wait_busy();
    SPI1_CS_W25Q64(0);
    spi1_read_write_byte(0x02);
    spi1_read_write_byte((uint8_t)((addr)>>16));
    spi1_read_write_byte((uint8_t)((addr)>>8));
    spi1_read_write_byte((uint8_t)addr);
    for(i=0;i<numbyte;i++)
    {
        spi1_read_write_byte(buffer[i]);
    }
    SPI1_CS_W25Q64(0);
    W25Q64_wait_busy();
}






void W25Q64_read(uint8_t* buffer,uint32_t read_addr,uint16_t read_length)
{
        uint16_t i;

        SPI1_CS_W25Q64(0);
        spi1_read_write_byte(0x03);
        spi1_read_write_byte((uint8_t)((read_addr)>>16));
        spi1_read_write_byte((uint8_t)((read_addr)>>8));
        spi1_read_write_byte((uint8_t)read_addr);
        for(i=0;i<read_length;i++)
        {
            buffer[i]= spi1_read_write_byte(0XFF);
        }
        SPI1_CS_W25Q64(1);
}


