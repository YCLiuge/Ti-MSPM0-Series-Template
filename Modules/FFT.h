#ifndef FFT_H_
#define FFT_H_

#include <math.h>

#define PI				3.14159265358979323846264338327950288419716939937510	//Բ����

#define FFT_N			512		//����Ҷ�任�ĵ��� 

#define FFT_Hz(x, Sample_Frequency)		((double)(x * Sample_Frequency) / FFT_N)

typedef struct						//���帴���ṹ�� 
{
	double real, imag;
}Complex;

extern Complex data_of_N_FFT[];	
extern double SIN_TABLE_of_N_FFT[];

void Init_FFT(void);
void FFT(double x[]);
void IFFT(double x[]);
void Refresh_Data(int id, double wave_data);
void FFT_result(double x[]);
void IFFT_RESULT(double x[]);
double FFT_read_single(int id);
double IFFT_read_single(int id);
#endif // !FFT_H_