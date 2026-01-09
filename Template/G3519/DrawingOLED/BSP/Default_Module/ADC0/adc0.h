#ifndef ADC0_H
#define ADC0_H
#include "bsp.h"




///* Defines for ADC0 */
//#define ADC0_INST                                                           ADC0
//#define ADC0_INST_IRQHandler                                     ADC0_IRQHandler
//#define ADC0_INST_INT_IRQN                                       (ADC0_INT_IRQn)
//#define ADC0_ADCMEM_0                                         DL_ADC12_MEM_IDX_0
//#define ADC0_ADCMEM_0_REF                        DL_ADC12_REFERENCE_VOLTAGE_VDDA
//#define ADC0_ADCMEM_0_REF_VOLTAGE_V                                          3.3
//#define ADC0_ADCMEM_1                                         DL_ADC12_MEM_IDX_1
//#define ADC0_ADCMEM_1_REF                        DL_ADC12_REFERENCE_VOLTAGE_VDDA
//#define ADC0_ADCMEM_1_REF_VOLTAGE_V                                          3.3
//#define ADC0_ADCMEM_2                                         DL_ADC12_MEM_IDX_2
//#define ADC0_ADCMEM_2_REF                        DL_ADC12_REFERENCE_VOLTAGE_VDDA
//#define ADC0_ADCMEM_2_REF_VOLTAGE_V                                          3.3
//#define ADC0_ADCMEM_3                                         DL_ADC12_MEM_IDX_3
//#define ADC0_ADCMEM_3_REF                        DL_ADC12_REFERENCE_VOLTAGE_VDDA
//#define ADC0_ADCMEM_3_REF_VOLTAGE_V                                          3.3
//#define ADC0_ADCMEM_4                                         DL_ADC12_MEM_IDX_4
//#define ADC0_ADCMEM_4_REF                        DL_ADC12_REFERENCE_VOLTAGE_VDDA
//#define ADC0_ADCMEM_4_REF_VOLTAGE_V                                          3.3
//#define ADC0_ADCMEM_5                                         DL_ADC12_MEM_IDX_5
//#define ADC0_ADCMEM_5_REF                        DL_ADC12_REFERENCE_VOLTAGE_VDDA
//#define ADC0_ADCMEM_5_REF_VOLTAGE_V                                          3.3
//#define GPIO_ADC0_C0_PORT                                                  GPIOA
//#define GPIO_ADC0_C0_PIN                                          DL_GPIO_PIN_27
//#define GPIO_ADC0_C1_PORT                                                  GPIOA
//#define GPIO_ADC0_C1_PIN                                          DL_GPIO_PIN_26
//#define GPIO_ADC0_C2_PORT                                                  GPIOA
//#define GPIO_ADC0_C2_PIN                                          DL_GPIO_PIN_25
//#define GPIO_ADC0_C3_PORT                                                  GPIOA
//#define GPIO_ADC0_C3_PIN                                          DL_GPIO_PIN_24
//#define GPIO_ADC0_C4_PORT                                                  GPIOB
//#define GPIO_ADC0_C4_PIN                                          DL_GPIO_PIN_25
//#define GPIO_ADC0_C5_PORT                                                  GPIOB
//#define GPIO_ADC0_C5_PIN                                          DL_GPIO_PIN_24
void adc0_init(void);
void get_adc0_num_val(uint32_t *adc0);
#endif