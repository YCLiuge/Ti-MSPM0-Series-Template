/**
 * @file pid.h
 * @author cbr (ran13245@outlook.com)
 * @brief PID计算程序
 * @version 0.1
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PID_H_
#define __PID_H_
#pragma once
#include <stdint.h>


typedef struct __pid
{
    float p;              //Kp系数
    float i;              //Ki系数
    float d;              //Kd系数	

    float output_limit_inc;         //增量式PID输出上限
    float output_limit_pos;         //位置式PID输出上限
    float integral_error_limit;     //积分上限
	
    float LastError;     //前一次误差    
    float PrevError;     //前两次误差
    float IntegralError; //误差积分,用于位置式PID
}pid;


void Set_PID(pid* obj, float p, float i, float d);
void Set_PID_Limit(pid*obj, float output_limit_inc, float output_limit_pos, float integral_error_limit);
float PID_Cal_Inc(pid *obj, float current, float target);
float PID_Cal_Pos(pid *obj, float current, float target);
void PID_Clear(pid* obj);

#endif
