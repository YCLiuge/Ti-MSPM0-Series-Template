/*
Program MPU6500_SPI;
Author 0x91f aka Lzy;
Description{
	SPI Driver for MPU6500;
	Set SPI name as MPU.
	MPU6500 SPI通信原理：
		SPI操作写入与读取靠最高位区分：0为写入，1为读取；
		以单次SPI通信为例：
			I. 一次写入需要以下过程：
				1.写入地址（寄存器），读取返回值；
				2.写入数据，读取返回值；
			II. 一次读取需要以下过程：
				1.写入地址，读取返回值；
}
*/
#ifndef __MPU6500_SPI_H
#define __MPU6500_SPI_H 	 
#pragma once  
#include "ti_msp_dl_config.h"
#include "MPU6500_Regs.h"

#define CPU_Frq 80000	//Unit:kHz;
static const double GUnit[4] = {131.0,65.5,32.8,16.4};	//Sensitivity Scale Factor;
static const double AUnit[4] = {16384.0,8192.0,4096.0,2048.0};

struct MPUInfo{
		double xAcc,yAcc,zAcc;				//三轴加速度;
		double xGypo,yGypo,zGypo;			//三轴角加速度;
		double temp;									//温度;
};


inline uint8_t ReadWriteByte(SPI_Regs *spi, uint8_t byte);	//Basic Function to realize SPI IO;


uint8_t MPU6500_Write_Byte(uint8_t reg,uint8_t data);				//SPI write a byte;


uint8_t MPU6500_Read_Byte(uint8_t reg);											//SPI read a byte;


int16_t AEncoder(int16_t Origin);

int16_t ADecoder(int16_t complement);


uint8_t MPU6500_Init(void);


struct MPUInfo MPU6500_Calibration();


//设置MPU6500陀螺仪传感器满量程范围
//fsr:0,±250dps;1,±500dps;2,±1000dps;3,±2000dps
//返回值:0,设置成功
//    其他,设置失败 
uint8_t MPU6500_Set_Gyro_Fsr(uint8_t fsr);


//设置MPU6500加速度传感器满量程范围
//fsr:0,±2g;1,±4g;2,±8g;3,±16g
//返回值:0,设置成功
//    其他,设置失败 
uint8_t MPU6500_Set_Accel_Fsr(uint8_t fsr);


//设置MPU6500的数字低通滤波器
//lpf:数字低通滤波频率(Hz)
//返回值:0,设置成功
//    其他,设置失败 
uint8_t MPU6500_Set_LPF(uint16_t lpf);


//设置MPU6500的采样率(假定Fs=1KHz)
//rate:4~1000(Hz)
//返回值:0,设置成功
//    其他,设置失败 
uint8_t MPU6500_Set_Rate(uint16_t rate);


uint8_t MPU6500_Read_Len(uint8_t reg, uint8_t len,uint8_t *buf);

uint8_t MPU6500_Set_xAOFFSET(int16_t xoffset);
uint8_t MPU6500_Set_yAOFFSET(int16_t yoffset);
uint8_t MPU6500_Set_zAOFFSET(int16_t zoffset);
uint8_t MPU6500_Set_xGOFFSET(int16_t xoffset);
uint8_t MPU6500_Set_yGOFFSET(int16_t yoffset);
uint8_t MPU6500_Set_zGOFFSET(int16_t zoffset);
struct MPUInfo MPU6500_getRawData();
struct MPUInfo MPU6500_getData();
void MPU6500_UARTDebugger();
#endif
