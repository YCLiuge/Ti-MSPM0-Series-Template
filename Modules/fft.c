#include "FFT.h"

Complex data_of_N_FFT[FFT_N];			//����洢��Ԫ��ԭʼ�����븴�������ʹ��֮ 
double SIN_TABLE_of_N_FFT[FFT_N / 4 + 1];

//�������Һ����� ��ʼ��FFT���� 
void Init_FFT(void)
{
	int i;
	for (i = 0; i <= FFT_N / 4; i++)
	{
		SIN_TABLE_of_N_FFT[i] = sin(2 * i * PI / FFT_N);
	}
}

double Sin_find(double x)
{
	int i = (int)(FFT_N * x);	//ע�⣺i�Ѿ�ת��Ϊ0~N֮��������ˣ� 
	i = i >> 1;					// i = i / 2;
	if (i > FFT_N / 4)
	{	//����FFT��ع�ʽ��sin()�������ᳬ��PI�� ��i���ᳬ��N/2 
		i = FFT_N / 2 - i;//i = i - 2*(i-Npart4);
	}
	return SIN_TABLE_of_N_FFT[i];
}

double Cos_find(double x)
{
	int i = (int)(FFT_N*x);//ע�⣺i�Ѿ�ת��Ϊ0~N֮��������ˣ� 
	i = i >> 1;
	if (i < FFT_N / 4)
	{ //���ᳬ��N/2 
		return SIN_TABLE_of_N_FFT[FFT_N / 4 - i];
	}
	else //i > Npart4 && i < N/2 
	{
		return -SIN_TABLE_of_N_FFT[i - FFT_N / 4];
	}
}

//��ַ 
void ChangeSeat(Complex *DataInput)
{
	int nextValue, nextM, i, k, j = 0;
	Complex temp;

	nextValue = FFT_N / 2;					//��ַ���㣬������Ȼ˳���ɵ�λ�򣬲����׵��㷨
	nextM = FFT_N - 1;

	for (i = 0; i < nextM; i++)
	{
		if (i < j)							//���i<j,�����б�ַ
		{
			temp = DataInput[j];
			DataInput[j] = DataInput[i];
			DataInput[i] = temp;
		}
		k = nextValue;						//��j����һ����λ��
		while (k <= j)						//���k<=j,��ʾj�����λΪ1
		{
			j = j - k;						//�����λ���0
			k = k / 2;						//k/2���Ƚϴθ�λ���������ƣ�����Ƚϣ�ֱ��ĳ��λΪ0
		}
		j = j + k;							//��0��Ϊ1
	}
}

//FFT���㺯�� 
void FFT(double x[])
{
	int L = FFT_N, B, J, K, M_of_N_FFT;
	int step, KB;
	double angle;
	Complex W, Temp_XX;

	ChangeSeat(data_of_N_FFT);				//��ַ 
											//CREATE_SIN_TABLE();
	for (M_of_N_FFT = 1; (L = L >> 1) != 1; ++M_of_N_FFT);	//������μ���
	for (L = 1; L <= M_of_N_FFT; L++)
	{
		step = 1 << L;						//2^L
		B = step >> 1;						//B=2^(L-1)
		for (J = 0; J < B; J++)
		{
			//P = (1<<(M-L))*J;//P=2^(M-L) *J 
			angle = (double)J / B;			//���ﻹ�����Ż� 
			W.real = Cos_find(angle); 		//ʹ��C++ʱ�ú���������Ϊinline W.real =  cos(angle*PI);
			W.imag = -Sin_find(angle);		//ʹ��C++ʱ�ú���������Ϊinline W.imag = -sin(angle*PI);

			for (K = J; K < FFT_N; K = K + step)
			{
				KB = K + B;
				//Temp_XX = XX_complex(data[KB],W); ����������ֱ�Ӽ��㸴���˷���ʡȥ�������ÿ��� 
				Temp_XX.real = data_of_N_FFT[KB].real * W.real - data_of_N_FFT[KB].imag*W.imag;
				Temp_XX.imag = W.imag*data_of_N_FFT[KB].real + data_of_N_FFT[KB].imag*W.real;

				data_of_N_FFT[KB].real = data_of_N_FFT[K].real - Temp_XX.real;
				data_of_N_FFT[KB].imag = data_of_N_FFT[K].imag - Temp_XX.imag;

				data_of_N_FFT[K].real = data_of_N_FFT[K].real + Temp_XX.real;
				data_of_N_FFT[K].imag = data_of_N_FFT[K].imag + Temp_XX.imag;
			}
		}
	}
    FFT_result(x);
}

//IFFT���㺯�� 
void IFFT(double x[])
{
	int L = FFT_N, B, J, K, M_of_N_FFT;
	int step, KB;
	double angle;
	Complex W, Temp_XX;

	ChangeSeat(data_of_N_FFT);//��ַ 

	for (M_of_N_FFT = 1; (L = L >> 1) != 1; ++M_of_N_FFT);	//������μ���
	for (L = 1; L <= M_of_N_FFT; L++)
	{
		step = 1 << L;						//2^L
		B = step >> 1;						//B=2^(L-1)
		for (J = 0; J<B; J++)
		{
			angle = (double)J / B;			//���ﻹ�����Ż�  
			W.real = Cos_find(angle);		//ʹ��C++ʱ�ú���������Ϊinline W.real = cos(angle*PI);
			W.imag = Sin_find(angle);		//ʹ��C++ʱ�ú���������Ϊinline W.imag = sin(angle*PI);

			for (K = J; K < FFT_N; K = K + step)
			{
				KB = K + B;
				//����������ֱ�Ӽ��㸴���˷���ʡȥ�������ÿ��� 
				Temp_XX.real = data_of_N_FFT[KB].real * W.real - data_of_N_FFT[KB].imag*W.imag;
				Temp_XX.imag = W.imag*data_of_N_FFT[KB].real + data_of_N_FFT[KB].imag*W.real;

				data_of_N_FFT[KB].real = data_of_N_FFT[K].real - Temp_XX.real;
				data_of_N_FFT[KB].imag = data_of_N_FFT[K].imag - Temp_XX.imag;

				data_of_N_FFT[K].real = data_of_N_FFT[K].real + Temp_XX.real;
				data_of_N_FFT[K].imag = data_of_N_FFT[K].imag + Temp_XX.imag;
			}
		}
	}
    IFFT_RESULT(x);
}

/*****************************************************************
����ԭ�ͣ�void Refresh_Data(int id, double wave_data)
�������ܣ���������
���������id: ���; wave_data: һ�����ֵ
�����������
*****************************************************************/
void Refresh_Data(int id, double wave_data)
{
	data_of_N_FFT[id].real = wave_data;
	data_of_N_FFT[id].imag = 0;
}
//ȡֵ����

void FFT_result(double x[])
{
    for(int id=0;id<FFT_N;id++)
	    x[id]=data_of_N_FFT[id].real*data_of_N_FFT[id].real+data_of_N_FFT[id].imag*data_of_N_FFT[id].imag;
}
double FFT_read_single(int id)
{
    return data_of_N_FFT[id].real*data_of_N_FFT[id].real+data_of_N_FFT[id].imag*data_of_N_FFT[id].imag;
}
void IFFT_RESULT(double x[])
{
    for(int id=0;id<FFT_N;id++)
        x[id]=data_of_N_FFT[id].real / FFT_N;
}
double IFFT_read_single(int id)
{
    return data_of_N_FFT[id].real / FFT_N;
}