/*------------------------------------------------------------------------------
 * File Name： Empty_OLED
 * Description: Empty Programme with OLED and Keyboard support;
 *----------------------------------------------------------------------------*/
#include "ti_msp_dl_config.h"
#include "bsp.h"
#include "oledpicture_V0.2.h"
#include "oled_spi_V0.2.h"
#include <math.h>  // 添加数学库

// 坐标转换宏：将像素Y坐标(0-63)转换为页地址(0-7)
#define Y_PAGE(y) y

int main(void)
{
    SYSCFG_DL_init();
    Keyboard_init();
    OLED_Init();
	delay_cycles(CPU_Frq * 1000);
    OLED_DrawBMP(9, 0, 119, 8, Genshin);    // LOGO
    delay_cycles(CPU_Frq * 1000);
    OLED_Clear();
    OLED_Refresh();
    
    // ============== 测试1: 基础图形 ==============
    // 画一个点
    OLED_DrawPoint(10, 10, 1);
	OLED_Refresh();
    OLED_ShowString(0, Y_PAGE(0), "Point");
    delay_cycles(CPU_Frq * 1000);
    
    // 画一条线
    OLED_Clear();
    OLED_DrawLine(20, 20, 100, 20, 1);
    OLED_Refresh();
	OLED_ShowString(0, Y_PAGE(0), "Line");
    delay_cycles(CPU_Frq * 1000);
    
    // 画一个圆
    OLED_Clear();
    OLED_DrawCircle(64, 32, 20);
	OLED_Refresh();
    OLED_ShowString(0, Y_PAGE(0), "Circle");
    delay_cycles(CPU_Frq * 1000);
    
    // ============== 测试2: 文字显示 ==============
    OLED_Clear();
    OLED_ShowString(10, 0, "OLED Test");
    OLED_ShowNum(10, 1, 12345, 5, 16);
    OLED_ShowSignedNum(10, 2, -5432, 5, 16);
    delay_cycles(CPU_Frq * 2000);
    
    // ============== 测试3: 方框 ==============
    OLED_Clear();
    // 绘制一个方框（使用正确的Y坐标）
    OLED_DrawLine(10, 10, 118, 10, 1);   // 上边
	OLED_Refresh();
    delay_cycles(CPU_Frq * 200);
    OLED_DrawLine(118, 10, 118, 54, 1);  // 右边
	OLED_Refresh();
    delay_cycles(CPU_Frq * 200);
    OLED_DrawLine(118, 54, 10, 54, 1);   // 下边
	OLED_Refresh();
    delay_cycles(CPU_Frq * 200);
    OLED_DrawLine(10, 10, 10, 54, 1);    // 左边
	OLED_Refresh();
    delay_cycles(CPU_Frq * 200);
    // 绘制对角线
    OLED_DrawLine(10, 10, 118, 54, 1);
	OLED_Refresh();
    delay_cycles(CPU_Frq * 200);
    OLED_DrawLine(118, 10, 10, 54, 1);
	OLED_Refresh();
    delay_cycles(CPU_Frq * 200);
    // 在中心画一个点
    OLED_DrawPoint(64, 32, 1);
    // 显示文字（使用页地址）
    OLED_ShowString(20, Y_PAGE(6), "Graphics");
    delay_cycles(CPU_Frq * 2000);
    
    // ============== 测试4: 网格 ==============
    OLED_Clear();
    // 绘制垂直线
    for(int i = 0; i < 128; i += 16) {
        OLED_DrawLine(i, 0, i, 63, 1);
		OLED_Refresh();
    }

    // 绘制水平线
    for(int i = 0; i < 64; i += 16) {
        OLED_DrawLine(0, i, 127, i, 1);
		OLED_Refresh();
    }
    OLED_ShowString(40, Y_PAGE(7), "Grid");
    delay_cycles(CPU_Frq * 2000);
    
    // ============== 测试5: 简单的画点测试 ==============
    OLED_Clear();
    // 测试画点函数
    for(int i = 0; i < 128; i++) {
        OLED_DrawPoint(i, 32, 1);  // 画一条水平线
    }
	OLED_Refresh();
    OLED_ShowString(40, Y_PAGE(0), "Points");
    delay_cycles(CPU_Frq * 1000);
    
    // ============== 测试6: 填充测试 ==============
    OLED_Clear();
    // 使用画线函数创建填充效果
    for(int y = 10; y < 30; y++) {
        OLED_DrawLine(20, y, 80, y, 1);
		OLED_Refresh();
    }
    OLED_ShowString(30, Y_PAGE(4), "Filled");
    delay_cycles(CPU_Frq * 1000);
    
    // ============== 最终显示 ==============
    OLED_Clear();
    OLED_ShowString(20, 0, "Demo Complete");
    OLED_ShowString(10, 1, "OLED Drawing");
    OLED_ShowString(15, 2, "Library Test");
    OLED_ShowString(30, 3, "Done!");
    
    // 画一个笑脸
    // 眼睛
    OLED_DrawPoint(40, 20, 1);
    OLED_DrawPoint(42, 20, 1);
    OLED_DrawPoint(86, 20, 1);
    OLED_DrawPoint(88, 20, 1);
    // 嘴巴
    for(int x = 44; x < 84; x++) {
        OLED_DrawPoint(x, 40, 1);
    }
    
    OLED_Refresh();
    OLED_Clear();
    int key_value;
    while (1) {
        key_value = 0;  
        key_value = KeySCInput();
        OLED_ShowNum(0, 0, key_value, 4, 16);
    }
}