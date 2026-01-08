/*
Program PWM;
Author 0x91f aka Lzy;
Enable what you wanna use, and Disable what you don't;

*/
#include "oled_spi_V0.2.h"
#include "ti/driverlib/m0p/dl_core.h"
#include "ti_msp_dl_config.h"
//#include <cstdint>
#include <stdint.h>
#include <math.h>
#include "Servo_2D.h"




void PWM_init(){
		//DL_Timer_startCounter(MOTOR_INST);
		//NVIC_EnableIRQ(MOTOR_INST_INT_IRQN);
		DL_Timer_startCounter(Servo_INST);
		NVIC_EnableIRQ(Servo_INST_INT_IRQN);
		//SetLeftMotor(2000,1980);
		//SetRightMotor(2000,1980);
}
/*
void SetLeftMotor(uint16_t Period,uint16_t CCPvalue){
	//length_Unit: ms;
	//PA3
	if(Period <= 0) Period = CCPvalue = 1;
	DL_Timer_setLoadValue(MOTOR_INST, Period);DL_Timer_setCaptureCompareValue(MOTOR_INST,CCPvalue,DL_TIMER_CC_0_INDEX);
}
void SetRightMotor(uint16_t Period,uint16_t CCPvalue){
	//length_Unit: ms;
	//PA2
	if(Period <= 0) Period = CCPvalue = 1;
	DL_Timer_setLoadValue(MOTOR_INST, Period);DL_Timer_setCaptureCompareValue(MOTOR_INST,CCPvalue,DL_TIMER_CC_1_INDEX);
}
*/

void SetServoX(uint16_t CCPvalue){
	if(CCPvalue <= 0) CCPvalue = 1;
	DL_Timer_setCaptureCompareValue(Servo_INST,CCPvalue,DL_TIMER_CC_0_INDEX);
}
void SetServoY(uint16_t CCPvalue){
	//length_Unit: ms;
	//PA10
	if(CCPvalue <= 0) CCPvalue = 1;
	DL_Timer_setCaptureCompareValue(Servo_INST,CCPvalue,DL_TIMER_CC_1_INDEX);
}
void SetXDegree(double Degree){ //Unit: Degree, NOT RAD
	//length_Unit: 1 Degree;
	uint16_t CCPvalue = round(42500 + Degree*500/9);
	SetServoX(CCPvalue);
}
void SetYDegree(double Degree){ //Unit: Degree, NOT RAD
	//length_Unit: 1 Degree;
    Degree += 5;
	uint16_t CCPvalue = round((42500*pi - Degree*500/9)/pi);
	SetServoY(CCPvalue);
}
void SetXPos(double Position){ //Unit: Degree, NOT RAD
	//Unit:1;
    SetXDegree(atan(Position/Distance)*180/pi);
}
void SetYPos(double x_offset_degree,double Position){ //Unit: Degree, NOT RAD
	//length_Unit: 1;
    //double check = atan(Position*cos(x_offset_degree*pi/180)/Distance), H = tan(check)*Distance/cos(x_offset_degree*pi/180);
    SetYDegree(atan(Position*cos(x_offset_degree*pi/180)/Distance)*180/pi);
}
void TestFrontier(){
    //SetXDegree(LeftFrontier);
    SetXPos(LeftFrontier);
    SetYPos(atan(LeftFrontier/Distance)*180/pi,TopFrontier);
    delay_cycles(CPU_Frq*200);
    for(float i = LeftFrontier;i <= RightFrontier;i += Xstep ){
        SetXPos(i);
        //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
        SetYPos(atan(i/Distance)*180/pi,TopFrontier);
        delay_cycles(CPU_Frq*8*Xstep);
    }
    SetXPos(RightFrontier);
    SetYPos(atan(RightFrontier/Distance)*180/pi,TopFrontier);
    delay_cycles(CPU_Frq*10);
    for(float i = TopFrontier;i >= BottomFrontier;i -= Ystep){
        SetXPos(RightFrontier);
        //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
        SetYPos(atan(RightFrontier/Distance)*180/pi,i);
        delay_cycles(CPU_Frq*1);
    }
    SetXPos(RightFrontier);
    SetYPos(atan(LeftFrontier/Distance)*180/pi,BottomFrontier);
    delay_cycles(CPU_Frq*10);
    for(float i = RightFrontier;i >= LeftFrontier;i -= Xstep ){
        SetXPos(i);
        //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
        SetYPos(atan(i/Distance)*180/pi,BottomFrontier);
        delay_cycles(CPU_Frq*8*Xstep);
    }
    SetXPos(LeftFrontier);
    SetYPos(atan(LeftFrontier/Distance)*180/pi,BottomFrontier);
    delay_cycles(CPU_Frq*10);
    for(float i = BottomFrontier;i <= TopFrontier;i += Ystep){
        SetXPos(LeftFrontier);
        //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
        SetYPos(atan(LeftFrontier/Distance)*180/pi,i);
        delay_cycles(CPU_Frq*1);
    }
}

void Data_Convertion(const uint16_t Datain[],const uint16_t inLen, int16_t Dest[], uint16_t DestLen){
    DestLen = round((double)(RightFrontier - LeftFrontier) *1.0 / Xstep);
    const uint16_t Height = TopFrontier - BottomFrontier;
    float step = inLen * Repeat / DestLen;
    int16_t MAX = -11451,MIN = 11451, delta,idx = 0;
    for(uint16_t i = 0;i < inLen;++i){
        if (Datain[i] > MAX) MAX = Datain[i];
        if (Datain[i] < MIN) MIN = Datain[i];
    }
    delta = MAX - MIN;MAX = inLen* Repeat;
    for(float i = 0;i <= MAX;i += step){
        Dest[idx] = round((double)Datain[(uint32_t)round(i)%inLen] * 1.0 / delta * Height)  - Height / 2;
        ++idx;
    }
}

void DrawGragh(const uint16_t DACData[],const uint16_t length){
    const uint16_t LEN = round((double)(RightFrontier - LeftFrontier) *1.0 / Xstep);
    int16_t Dest[LEN + 1],idx = 0;
    Data_Convertion(DACData, length, Dest, LEN);
    Dest[LEN] = Dest[LEN - 1];
    SetXPos(LeftFrontier);
    SetYPos(atan(LeftFrontier/Distance)*180/pi,Dest[0]);
    delay_cycles(CPU_Frq*200);
    for(float i = LeftFrontier;i <= RightFrontier;i += Xstep ){
        SetXPos(i);
        //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
        SetYPos(atan(i/Distance)*180/pi,Dest[idx]);
        ++idx;
        delay_cycles(CPU_Frq*30*Xstep);
    }


}

void Data_Convertion_Single(const uint16_t Datain[],const uint16_t inLen, int16_t Dest[], uint16_t DestLen){
    DestLen = round((double)(RightFrontier - LeftFrontier) *1.0 / Xstep);
    const uint16_t Height = TopFrontier - BottomFrontier;
    float step = inLen / DestLen;
    int16_t MAX = -11451,MIN = 11451, delta,idx = 0;
    for(uint16_t i = 0;i < inLen;++i){
        if (Datain[i] > MAX) MAX = Datain[i];
        if (Datain[i] < MIN) MIN = Datain[i];
    }
    delta = MAX - MIN;MAX = inLen;
    for(float i = 0;i <= MAX;i += step){
        Dest[idx] = round(Datain[(uint32_t)round(i)%inLen] * 1.0 / delta * Height)  - Height / 2;
        ++idx;
    }
}

void DrawGragh_Single(const uint16_t DACData[],const uint16_t length){
    const uint16_t LEN = round((double)(RightFrontier - LeftFrontier) *1.0 / Xstep);
    int16_t Dest[LEN + 2],idx = 0;
    Data_Convertion(DACData, length, Dest, LEN);
    Dest[LEN] = Dest[LEN - 1];
    SetXPos(LeftFrontier);
    SetYPos(atan(LeftFrontier/Distance)*180/pi,Dest[0]);
    delay_cycles(CPU_Frq*400);
    for(float i = LeftFrontier;i <= RightFrontier;i += Xstep ){
        SetXPos(i);
        //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
        SetYPos(atan(i/Distance)*180/pi,Dest[idx]);
        ++idx;
        delay_cycles(CPU_Frq*5*Xstep);
    }


}

void DrawSqu(){
    uint16_t idx = 0;
    const uint8_t Boundary = 200;
    SetXPos(LeftFrontier);
    SetYPos(atan(LeftFrontier/Distance)*180/pi,TopFrontier);
    delay_cycles(CPU_Frq*200);
    for(float i = LeftFrontier;i <= RightFrontier;i += Xstep * 1.5 ){
        ++idx;
        if(idx < Boundary){
            SetXPos(i);
            //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
            SetYPos(atan(i/Distance)*180/pi,TopFrontier);
            delay_cycles(CPU_Frq*40*Xstep);
        } else if(idx == Boundary) {
            for(float j = TopFrontier;j >= BottomFrontier;j -= Ystep){
                SetXPos(i);
                //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
                SetYPos(atan(i/Distance)*180/pi,j);
                delay_cycles(CPU_Frq*1);
            }
        } else if(idx < 2 * Boundary) {
            SetXPos(i);
            //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
            SetYPos(atan(i/Distance)*180/pi,BottomFrontier);
            delay_cycles(CPU_Frq*40*Xstep);
        } else if (idx == 2 * Boundary) {
            for(float j = BottomFrontier;j <= TopFrontier;j += Ystep){
                SetXPos(i);
                //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
                SetYPos(atan(i/Distance)*180/pi,j);
                delay_cycles(CPU_Frq*1);
            }
            idx = 0;
        } 
    }
}
void DrawTri(){
    uint16_t idx = 0;
    int16_t nowY = BottomFrontier;
    const uint8_t Boundary = 50,k = (TopFrontier - BottomFrontier)  / Boundary - 7;
    SetXPos(LeftFrontier);
    SetYPos(atan(LeftFrontier/Distance)*180/pi,nowY);
    delay_cycles(CPU_Frq*400);
    for(float i = LeftFrontier;i <= RightFrontier;i += Xstep * 1.2){
        ++idx;
        if(idx < 2 * Boundary){
            nowY += k;
            SetXPos(i);
            //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
            SetYPos(atan(i/Distance)*180/pi,nowY);
            delay_cycles(CPU_Frq*15*Xstep);
        } else if (idx == 2 * Boundary) {
            i -= 15 * Xstep;
            nowY += 400 * k;
            SetXPos(i);
            //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
            SetYPos(atan(i/Distance)*180/pi,nowY);
            delay_cycles(CPU_Frq*25*Xstep);
            nowY -= 400 * k;
        } else if(idx < 4 * Boundary) {
            nowY -= k;
            SetXPos(i);
            //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
            SetYPos(atan(i/Distance)*180/pi,nowY);
            delay_cycles(CPU_Frq*15*Xstep);
        } else if (idx == 4 * Boundary) {
            i -= 15 * Xstep;
            nowY -= 400 * k;
            SetXPos(i);
            //SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
            SetYPos(atan(i/Distance)*180/pi,nowY);
            delay_cycles(CPU_Frq*25*Xstep);
            nowY += 400 * k;
            idx = 0;
        } 
    }
}
void DrawSin(){
    const uint16_t DAC8_Sin64[] = {128,140,153,165,177,189,200,210,219,228,235,241,247,251,254,255,255,255,252,249,244,238,231,223,215,205,194,183,171,159,147,134,121,108,96,84,72,61,50,40,32,24,17,11,6,3,0,0,0,1,4,8,14,20,27,36,45,55,66,78,90,102,115,127};
    DrawGragh_Single(DAC8_Sin64,64);
}

/*
void Data_Convertion(uint16_t Datain[],uint16_t inLen, uint16_t Dest[], uint16_t DestLen){
    float xratio,j = 0;
    if(inLen > DestLen){
        xratio = inLen * 1.0 / DestLen;
        for(uint16_t i = 0;i < DestLen;++i){
            Dest[i] = Datain[(uint16_t)round(j)];
            j += xratio;
        }
    } else {
        uint16_t Icnt = 0,InsertNum = DestLen - inLen;
        xratio = inLen / InsertNum;
        for(uint16_t i = 0;i < DestLen;++i){
            Dest[i] = Datain[i];
            if (Icnt >= xratio) {
                ++i;
                Dest[i] = (Datain[i-1] + Datain[i])/2;
                Icnt = 0;
            }
            ++Icnt;
        }
    }
}

void DrawGragh(const uint16_t Datain[],const uint16_t length){
    uint16_t MAX = 0,MIN = 11451,delta;
    uint16_t target = TopFrontier - BottomFrontier,DestLen = (RightFrontier - LeftFrontier)/10;
    uint16_t Dataout[(RightFrontier - LeftFrontier)/10 + 1];
    Data_Convertion(Datain, length, Dataout, DestLen);
    Dataout[DestLen] = Dataout[DestLen - 1];
    for(uint16_t i = 0;i < DestLen;++i){
        if (Dataout[i] > MAX) MAX = Dataout[i];
        if (Dataout[i] < MIN) MIN = Dataout[i];
    }
    delta = MAX - MIN;
    SetXDegree(LeftFrontier);
    SetYDegree(round(((Dataout[0]) * target / delta)) - target / 2);
    delay_cycles(CPU_Frq*500);
    for(int16_t i = LeftFrontier;i <= RightFrontier;i += 10){
        SetXDegree(i);
        SetYDegree(round(((Dataout[(i-LeftFrontier)/10]) * target / delta)) - target / 2);
        delay_cycles(CPU_Frq*10);
    }
}
*/
/*
void DrawGragh(const uint16_t DACData[],const uint16_t length){
    uint16_t MAX = 0,MIN = 11451,delta,index = 0;
    uint16_t target = TopFrontier - BottomFrontier;
    float step = (RightFrontier - LeftFrontier)* 1.0 / (length * 1.0);
    for(uint16_t i = 0;i < length;++i){
        if (DACData[i] > MAX) MAX = DACData[i];
        if (DACData[i] < MIN) MIN = DACData[i];
    }
    delta = MAX - MIN;
    SetXDegree(LeftFrontier);
    delay_cycles(CPU_Frq*200);
    for(float i = LeftFrontier;i <= RightFrontier;i = LeftFrontier + step * index){
        SetXDegree(round(i));
        SetYDegree(round(((DACData[index]) * target * 100 / delta))/100 - target / 2);
        
        if (length < 512) {delay_cycles(CPU_Frq*10);++index;}
        else if (length < 512) {delay_cycles(CPU_Frq*10);index += 2;}
    }
}
*/

/*
 * ʾ����pwm_set_freq(TIMG7, 5000);
 * Example: pwm_set_freq(TIMG7, 5000);
 * ���� PWM Ƶ�ʡ�
 * Set the PWM frequency.
 * @param gptimer: GPTIMER �Ĵ���ָ��
 *                GPTIMER register pointer
 * @param frequency: Ƶ��ֵ
 *                   Frequency value
 * ע�⣺�ڵ���Ƶ��ʱ�Ὣռ�ձ����㣬������ʹ��ʾ�����鿴Ƶ��ʱ����Ҫ����һ������0��ռ�ձȡ�����Ϊ��Ե�½����������ܻᵼ��ռ�ձ�Ϊ100%��
 * Note: Adjusting the frequency will reset the duty cycle to zero. When using an oscilloscope to check the frequency, set a duty cycle greater than 0. If edge-aligned down counting is used, the duty cycle may be 100%.
 */
void pwm_set_freq(GPTIMER_Regs *gptimer, uint32_t frequency) // Sysconfig ���뽫 PWM mode ����Ϊ Edge-aligned Up Counting
                                                            // In Sysconfig, please set PWM mode to Edge-aligned Up Counting
{
    if (frequency < 1) frequency = 1;

    uint16_t period_temp = 0;    // ����ֵ
                                 // Period value
    uint16_t freq_div = 0;       // ��Ƶֵ
                                 // Frequency division value
    freq_div = (uint16_t)((CLOCK_SOURCE_COUNT / frequency) >> 16); // ������Ƶֵ
                                                                   // Calculate frequency division value
    period_temp = (uint16_t)(CLOCK_SOURCE_COUNT / (frequency * (freq_div + 1))); // ��������
                                                                                // Calculate period value

    (gptimer->COUNTERREGS.CTRCTL) &= ~(GPTIMER_CTRCTL_EN_ENABLED); // �رն�ʱ��
                                                                   // Disable the timer
    (gptimer->COMMONREGS.CPS) = freq_div;                          // ����ʱ��Ԥ��Ƶ�Ĵ�������Χ 0-255
                                                                   // Set clock pre-division register, range 0-255
    (gptimer->COUNTERREGS.LOAD) = period_temp;                     // ���ü���ֵ
                                                                   // Set load value

    // ����ͨ��ռ�ձ���Ϊ0
    // Set the duty cycle of both channels to 0
    DL_Timer_setCaptureCompareValue(gptimer, 0, DL_TIMER_CC_0_INDEX);
    DL_Timer_setCaptureCompareValue(gptimer, 0, DL_TIMER_CC_1_INDEX);
    if (TIMA0 == gptimer) {
        DL_Timer_setCaptureCompareValue(gptimer, 0, DL_TIMER_CC_2_INDEX); // G3507 �н� TIMA0 ����ͨ��
                                                                          // Only TIMA0 in G3507 has four channels
        DL_Timer_setCaptureCompareValue(gptimer, 0, DL_TIMER_CC_3_INDEX);
    }
    (gptimer->COUNTERREGS.CTRCTL) |= (GPTIMER_CTRCTL_EN_ENABLED); // ������ʱ��
                                                                  // Start the timer
}

/*
 * ʾ����pwm_set_duty(TIMG7, 5000, M0GPWMCH0); 10000 Ϊ����ռ�ձ�
 * Example: pwm_set_duty(TIMG7, 5000, M0GPWMCH0); 10000 is the maximum duty cycle
 * ���� PWM ռ�ձȡ�
 * Set the PWM duty cycle.
 * @param gptimer: GPTIMER �Ĵ���ָ��
 *                GPTIMER register pointer
 * @param duty: ռ�ձȣ���Χ 0-10000
 *             Duty cycle, range 0-10000
 * @param ch: PWM ͨ��
 *           PWM channel
 */
void pwm_set_duty(GPTIMER_Regs *gptimer, int32_t duty, pwmChannelEnum ch)
{
    uint16_t match_temp;
    uint16_t period_temp;
    DL_TIMER_CC_INDEX tempIndex = DL_TIMER_CC_0_INDEX;

    if (duty > PWM_DUTY_MAX) duty = PWM_DUTY_MAX; // ��ֹ����
                                   // Prevent overflow
    else if (duty < 0) duty = 0;

    // ����ͨ��ѡ����Ӧ�� CC ����
    // Select the corresponding CC index based on the channel
    switch (ch)
    {
        case M0GPWMCH0: tempIndex = DL_TIMER_CC_0_INDEX; break;
        case M0GPWMCH1: tempIndex = DL_TIMER_CC_1_INDEX; break;
        case M0GPWMCH2: tempIndex = DL_TIMER_CC_2_INDEX; break;
        case M0GPWMCH3: tempIndex = DL_TIMER_CC_3_INDEX; break;
        case M0GPWMCH4: tempIndex = DL_TIMER_CC_4_INDEX; break;
        case M0GPWMCH5: tempIndex = DL_TIMER_CC_5_INDEX; break;
        default: tempIndex = DL_TIMER_CC_0_INDEX; break;
    }

    period_temp = (gptimer->COUNTERREGS.LOAD & GPTIMER_LOAD_LD_MAXIMUM); // ��ȡ����ֵ
                                                                         // Get period value
    match_temp = period_temp * duty / PWM_DUTY_MAX; // ����ƥ��ֵ
                                                    // Calculate match value

    DL_Timer_setCaptureCompareValue(gptimer, match_temp, tempIndex); // ���ò����Ƚ�ֵ
                                                                     // Set capture compare value
}
