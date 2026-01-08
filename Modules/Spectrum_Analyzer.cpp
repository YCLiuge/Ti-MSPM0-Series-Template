//On MCU;
#include <stdio.h>  
#include <math.h>  
  
#define PI 3.14159265358979323846  
#define SIGNAL_LENGTH 256  
#define SAMPLE_RATE 1000  
  
typedef struct {  
    float real;  
    float imag;  
} Complex;  
  
Complex complex_multiply(Complex a, Complex b) {  
    Complex result;  
    result.real = a.real * b.real - a.imag * b.imag;  
    result.imag = a.real * b.imag + a.imag * b.real;  
    return result;  
}  
  
Complex complex_add(Complex a, Complex b) {  
    Complex result;  
    result.real = a.real + b.real;  
    result.imag = a.imag + b.imag;  
    return result;  
}  
  
Complex complex_subtract(Complex a, Complex b) {  
    Complex result;  
    result.real = a.real - b.real;  
    result.imag = a.imag - b.imag;  
    return result;  
}  
  
void bit_reversal_permutation(Complex *x, int n) {  
    int i, j, k;  
    int rev;  
    for (i = 0; i < n; ++i) {  
        rev = 0;  
        for (k = 0; k < 8; ++k) {  // Assuming n is always 256, so we hardcode log2(n) as 8  
            rev = (rev << 1) | ((i >> k) & 1);  
        }  
        if (rev > i) {  
            Complex temp = x[i];  
            x[i] = x[rev];  
            x[rev] = temp;  
        }  
    }  
}  
  
void fft(Complex *x, int n) {  
    bit_reversal_permutation(x, n);  
  
    for (int s = 1; s <= 8; ++s) { // Hardcoded 8 stages for 256 points  
        int m = 1 << s;  
        int m2 = m >> 1;  
        Complex w = {1, 0};  
        Complex wm = {cos(-2 * PI / m), sin(-2 * PI / m)};  
        for (int j = 0; j < m2; ++j) {  
            for (int k = j; k < n; k += m) {  
                Complex t = complex_multiply(w, x[k + m2]);  
                Complex u = x[k];  
                x[k] = complex_add(u, t);  
                x[k + m2] = complex_subtract(u, t);  
            }  
            w = complex_multiply(w, wm);  
        }  
    }  
}  
  
void spectrum_analyzer(Complex *signal, int signal_length, int fs) {  
    fft(signal, signal_length);  
  
    for (int i = 0; i < signal_length / 2; i++) {  
        float amplitude = sqrt(signal[i].real * signal[i].real + signal[i].imag * signal[i].imag);  
        printf("Frequency %d Hz: Amplitude %f\n", i * (fs / signal_length), amplitude);  
    }  
}  
  
int main() {  
    Complex signal[SIGNAL_LENGTH];  
    int i;  
  
    for (i = 0; i < SIGNAL_LENGTH; i++) {  
        signal[i].real = sin(2 * PI * 50 * i / SAMPLE_RATE);  // 50 Hz sine wave  
        signal[i].imag = 0.0;  
    }  
  
    spectrum_analyzer(signal, SIGNAL_LENGTH, SAMPLE_RATE);  
  
    return 0;  
}

/*
//On PC;
#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
  
#define PI 3.14159265358979323846  
  
// 复数结构体  
typedef struct {  
    double real;  
    double imag;  
} Complex;  
  
// 计算复数的乘法  
Complex complex_multiply(Complex a, Complex b) {  
    Complex result;  
    result.real = a.real * b.real - a.imag * b.imag;  
    result.imag = a.real * b.imag + a.imag * b.real;  
    return result;  
}  
  
// 计算复数的加法  
Complex complex_add(Complex a, Complex b) {  
    Complex result;  
    result.real = a.real + b.real;  
    result.imag = a.imag + b.imag;  
    return result;  
}  
  
// 计算复数的减法  
Complex complex_subtract(Complex a, Complex b) {  
    Complex result;  
    result.real = a.real - b.real;  
    result.imag = a.imag - b.imag;  
    return result;  
}  
  
// 位逆序置换  
void bit_reversal_permutation(Complex *x, int n) {  
    int i, j, k;  
    for (i = 0; i < n; ++i) {  
        j = 0;  
        for (k = 0; k < (int)log2(n); ++k) {  
            j = (j << 1) | ((i >> k) & 1);  
        }  
        if (j > i) {  
            Complex temp = x[i];  
            x[i] = x[j];  
            x[j] = temp;  
        }  
    }  
}  
  
// 迭代FFT算法  
void fft(Complex *x, int n) {  
    // 位逆序置换  
    bit_reversal_permutation(x, n);  
  
    // FFT迭代  
    for (int s = 1; s <= log2(n); ++s) {  
        int m = 1 << s; // 2的s次方  
        int m2 = m >> 1; // m的一半  
        Complex w = {1, 0};  
        Complex wm = {cos(-2 * PI / m), sin(-2 * PI / m)};  
        for (int j = 0; j < m2; ++j) {  
            for (int k = j; k < n; k += m) {  
                Complex t = complex_multiply(w, x[k + m2]);  
                Complex u = x[k];  
                x[k] = complex_add(u, t);  
                x[k + m2] = complex_subtract(u, t);  
            }  
            w = complex_multiply(w, wm);  
        }  
    }  
}  
  
// 计算信号的频谱并打印结果  
void spectrum_analyzer(Complex *signal, int signal_length, int fs) {  
    // 执行FFT  
    fft(signal, signal_length);  
  
    // 计算频谱幅度并打印  
    printf("Frequency (Hz)\tAmplitude\n");  
    for (int i = 0; i < signal_length / 2; i++) {  
        double amplitude = sqrt(signal[i].real * signal[i].real + signal[i].imag * signal[i].imag);  
        printf("%d\t\t%f\n", i * (fs / signal_length), amplitude);  
    }  
}  
  
// 主函数  
int main() {  
    // 示例信号：一个简单的正弦波  
    int fs = 1000;  // 采样频率  
    int signal_length = 256;  // 信号长度，必须是2的幂  
    Complex *signal = (Complex*)malloc(sizeof(Complex) * signal_length);  
    int i;  
  
    // 生成正弦波信号  
    for (i = 0; i < signal_length; i++) {  
        signal[i].real = sin(2 * PI * 50 * i / fs);  // 50Hz的正弦波  
        signal[i].imag = 0.0;  
    }  
  
    // 调用频谱分析仪  
    spectrum_analyzer(signal, signal_length, fs);  
  
    // 释放内存  
    free(signal);  
  
    return 0;  
}

*/
