#ifndef __OLED_SPI_H
#define __OLED_SPI_H
#pragma once
#include "ti_msp_dl_config.h"

#define OLED_CMD 0  // 写命令
#define OLED_DATA 1 // 写数据
#define OLED_MODE 0

#define  u8  unsigned char 
#define  u32 unsigned int 


//-----------------OLED端口定义----------------
// 要是SPI名字设的不一样在这改下就行,例如下面这样
//#define SPI_OLED_INST SPI_1_INST

//// Using external CS(3-Wire Structure);
//#define OLED_CS_Clr()  DL_GPIO_clearPins(OLED_PORT,OLED_CS_PIN)
//#define OLED_CS_Set()  DL_GPIO_setPins(OLED_PORT,OLED_CS_PIN)

//硬件SPI Syscofig 设置 SPI0
//				PICO only;
//				CLK; SPI
//				PICO; SPI
//				CS; SPI
//				DC; GPIO
//				RST; GPIO
//任意IO
//#define OLED_DC_Clr() DL_GPIO_clearPins(OLED_PORT, OLED_DC_PIN)
//#define OLED_DC_Set() DL_GPIO_setPins(OLED_PORT, OLED_DC_PIN)

#define OLED_DC_Clr() DL_GPIO_clearPins(OLED_PORT, OLED_DC_PIN)
#define OLED_DC_Set() DL_GPIO_setPins(OLED_PORT, OLED_DC_PIN)

//任意IO
#define OLED_RST_Clr()  
#define OLED_RST_Set()  




// OLED模式设置
// 0:4线串行模式
// 1:并行8080模式

#define CPU_Frq 80000	//Unit:kHz
#define SIZE 12
#define XLevelL 0x02
#define XLevelH 0x10
#define Max_Column 128
#define Max_Row 64
#define Brightness 0xFF
#define X_WIDTH 128
#define Y_WIDTH 64


// OLED控制用函数
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,char chr);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size2);
void OLED_ShowSignedNum(u8 x, u8 y, int32_t num, u8 len, u8 size2);
void OLED_ShowString(u8 x,u8 y, char *p);	 
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(u8 x,u8 y,u8 no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,const unsigned char BMP[]);





//// PB3
//#define OLED_CS_Clr()  DL_GPIO_clearPins(OLED_CS_PORT,OLED_CS_PIN)
//#define OLED_CS_Set()  DL_GPIO_setPins(OLED_CS_PORT,OLED_CS_PIN)



////PA11
//#define OLED_DC_Clr() DL_GPIO_clearPins(OLED_DC_PORT, OLED_DC_PIN)
//#define OLED_DC_Set() DL_GPIO_setPins(OLED_DC_PORT, OLED_DC_PIN)



//#define OLED_SCLK_Clr() DL_GPIO_clearPins(OLED_DC_PORT,OLED_SCLK_PIN)
//#define OLED_SCLK_Set() DL_GPIO_setPins(OLED_DC_PORT,OLED_SCLK_PIN )

//#define OLED_SDIN_Clr() DL_GPIO_clearPins(OLED_DC_PORT,OLED_SDIN_PIN)
//#define OLED_SDIN_Set() DL_GPIO_setPins(OLED_DC_PORT,OLED_SDIN_PIN )


////OLED模式设置
////0:4线串行模式
////1:并行8080模式

//#define SIZE 16
//#define XLevelL		0x02
//#define XLevelH		0x10
//#define Max_Column	128
//#define Max_Row		64
//#define	Brightness	0xFF 
//#define X_WIDTH 	128
//#define Y_WIDTH 	64	    						  
////-----------------OLED端口定义----------------  					   
// 		     

////OLED控制用函数
//void OLED_WR_Byte(u8 dat,u8 cmd);	    
//void OLED_Display_On(void);
//void OLED_Display_Off(void);	   							   		    
//void OLED_Init(void);
//void OLED_Clear(void);
//void OLED_DrawPoint(u8 x,u8 y,u8 t);
//void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
//void OLED_ShowChar(u8 x,u8 y,u8 chr);
//void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size2);
//void OLED_ShowString(u8 x,u8 y, u8 *p);	 
//void OLED_Set_Pos(unsigned char x, unsigned char y);
//void OLED_ShowCHinese(u8 x,u8 y,u8 no);
//void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
//void OLED_Show_int32(u8 x,u8 y,int32_t num,u8 len,u8 size2);
//void OLED_Show_float(u8 x,u8 y,float num,u8 len_1,u8 len_2);
#endif
