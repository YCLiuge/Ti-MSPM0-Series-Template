#ifndef __MYI2C_H
#define __MYI2C_H
#include "bsp.h"



/* Defines for I2C_1 */
#define I2C_1_INST                                                          I2C0
#define I2C_1_INST_IRQHandler                                    I2C0_IRQHandler
#define I2C_1_INST_INT_IRQN                                        I2C0_INT_IRQn
#define GPIO_I2C_1_SDA_PORT                                                GPIOA
#define GPIO_I2C_1_SDA_PIN                                         DL_GPIO_PIN_0
#define GPIO_I2C_1_IOMUX_SDA                                      (IOMUX_PINCM1)
#define GPIO_I2C_1_IOMUX_SDA_FUNC                       IOMUX_PINCM1_PF_I2C0_SDA
#define GPIO_I2C_1_SCL_PORT                                                GPIOA
#define GPIO_I2C_1_SCL_PIN                                         DL_GPIO_PIN_1
#define GPIO_I2C_1_IOMUX_SCL                                      (IOMUX_PINCM2)
#define GPIO_I2C_1_IOMUX_SCL_FUNC                       IOMUX_PINCM2_PF_I2C0_SCL



#define READ_SDA	DL_GPIO_readPins(GPIO_I2C_1_SDA_PORT, GPIO_I2C_1_SDA_PIN)

u8 IIC_Wait_Ack(void);
void IIC_Ack(void);
void IIC_NAck(void);
void IIC_Send_Byte(u8 txd);
u8 IIC_Read_Byte(unsigned char ack);

void IIC_Start(void);
void IIC_Stop(void);
void MyI2C_Init(void);
void MyI2C_Start(void);
void MyI2C_Stop(void);
void MyI2C_SendByte(uint8_t Byte);
uint8_t MyI2C_R_SDA(void);
uint8_t MyI2C_ReceiveByte(void);
void MyI2C_SendAck(uint8_t AckBit);
uint8_t MyI2C_ReceiveAck(void);
void MyI2C_W_SCL(uint8_t BitValue);
void MyI2C_W_SDA(uint8_t BitValue);
void Delay_us(uint16_t us);
void Delay_ms(uint16_t ms);
void SDA_OUT(void);  
void SCL_OUT(void);
uint8_t MyI2C_ReceiveByte_(void);
int8_t sensirion_i2c_read(uint8_t* data, uint16_t count);
void AT240C2_WriteReg(uint8_t RegAddress, uint8_t Data);
uint8_t AT240C2_ReadReg(uint8_t RegAddress);
uint8_t AT24C02_ReadReg(uint8_t RegAddress);
uint8_t read_AT24C02_byte(uint8_t memAddr);
#endif
