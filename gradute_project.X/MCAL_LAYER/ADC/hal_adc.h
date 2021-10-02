/* 
 * File:   hal_adc.h
 * Author: Mouhamed_Essa
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H

/* ----------------- Includes -----------------*/
#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "../GPIO/hal_gpio.h"
#include "hal_adc_cfg.h"
#include "../Interrupt/mcal_interrupt_config.h"

/* ----------------- Macro Declarations -----------------*/
#define ADC_ALL_PINS_ANALOG_FUNCTIONALITY     0x00U
#define ADC_AN0_ANALOG_FUNCTIONALITY          0x0EU
#define ADC_AN1_ANALOG_FUNCTIONALITY          0x0DU
#define ADC_AN2_ANALOG_FUNCTIONALITY          0x0CU
#define ADC_AN3_ANALOG_FUNCTIONALITY          0x0BU
#define ADC_AN4_ANALOG_FUNCTIONALITY          0x0AU
#define ADC_AN5_ANALOG_FUNCTIONALITY          0x09U
#define ADC_AN6_ANALOG_FUNCTIONALITY          0x08U
#define ADC_AN7_ANALOG_FUNCTIONALITY          0x07U
#define ADC_AN8_ANALOG_FUNCTIONALITY          0x06U
#define ADC_AN9_ANALOG_FUNCTIONALITY          0x05U
#define ADC_AN10_ANALOG_FUNCTIONALITY         0x04U
#define ADC_AN11_ANALOG_FUNCTIONALITY         0x03U
#define ADC_AN12_ANALOG_FUNCTIONALITY         0x02U
#define ADC_ALL_PINS_DIGITAL_FUNCTIONALITY    0x0FU

#define ADC_RESULT_FORMAT_RIGHT 0x01U
#define ADC_RESULT_FORMAT_LEFT  0x00U

#define ADC_CONVERSION_COMPLETED  0x01U
#define ADC_CONVERSION_INPROGRESS 0x00U


#define ADC_VOLTAGE_REFERENCE_ENABLED       0x01U
#define ADC_VOLTAGE_REFERENCE_DISABLED      0x00U

#define ADC_CONVERSION_COMPLETED  0x01U
#define ADC_CONVERSION_INPROGRESS 0x00U

/* ----------------- Macro functionvDeclarations -----------------*/
/* A/D Conversion Status : A/D conversion in progress / A/D Idle */
#define ADC_CONVERSION_STATUS()  (ADCON0bits.GO_nDONE)

/**
 * @brief Start the Analog-To-Digital Conversion ->(ADCON0bits.GO_DONE = 1)
 * @brief  the Analog-To-Digital Conversion = A/D Idle-> (ADCON0bits.GO_DONE = 0)
 */
#define  ADC_START_CONVERSION()     (ADCON0bits.GO_DONE = 1)
#define  ADC_CONVERSION_IN_Idle()   (ADCON0bits.GO_DONE = 0)

/**
 * @brief  Analog-To-Digital Control
 * @note   ADC_CONVERTER_ENABLE()  : Enable the Analog-To-Digital
 *         ADC_CONVERTER_DISABLE() : Disable the Analog-To-Digital
 */
#define  ADC_CONVERTER_ENABLE()  (ADCON0bits.ADON = 1)
#define  ADC_CONVERTER_DISABLE() (ADCON0bits.ADON = 0)

/**
 * @brief  Voltage Reference Configuration
 * @note   ADC_ENABLE_VOLTAGE_REFERENCE()  : Voltage Reference is VREF- & VREF+
 *         ADC_DISABLE_VOLTAGE_REFERENCE() : Voltage Reference is VSS & VDD
 */
#define ADC_ENABLE_VOLTAGE_REFERENCE()  do{ADCON1bits.VCFG1  = 1;\
                                           ADCON1bits.VCFG0  = 1;\
                                        }while(0)
#define ADC_DISABLE_VOLTAGE_REFERENCE() do{ADCON1bits.VCFG1  = 0;\
                                           ADCON1bits.VCFG0  = 0;\
                                        }while(0)

/**
 * @brief  Analog-To-Digital Port Configuration Control
 * @note   Example : ADC_ANALOG_DIGITAL_PORT_CONFIG(ADC_AN4_ANALOG_FUNCTIONALITY);
		   When ADC_AN4_ANALOG_FUNCTIONALITY is configured, this means
 *         AN4,AN3,AN2,AN1,AN0 are Analog functionality.
 *         @ref Analog-To-Digital Port Configuration Control
 */
#define ADC_ANALOG_DIGITAL_PORT_CONFIG(_config) {ADCON1bits.PCFG = _config}

/**right
 * @brief  A/D Result Format Select 
 * @note right ->represent 10 bit in 2 register from right to left 1022 =0000 00/11 1111 1110
 * @note right ->represent 10 bit in 2 register from right to left  but start from bit 6 in right register 
 *  @note                                                                1022 =1111 1111 10/00 0000
 * @note  in the second option we make >>6 to represent the same number 
 */
#define ADC_RESULT_RIGHT() (ADCON2bits.ADFM = 1 )
#define ADC_RESULT_LEFT()  (ADCON2bits.ADFM = 0 )

/*------------Section : Data Type Declaration-------------  */
/**
 * @brief  A/D Acquisition Time Select 
 * @note   Acquisition time (sampling time) is the time required for the (ADC) to 
 *         capture the input voltage during sampling.
 * @note   Acquisition time of a Successive Approximation Register (SAR) ADC is the amount of time 
 *         required to charge the holding capacitor (CHOLD) on the front end of an ADC
 */
typedef enum {
    ADC_0_TAD = 0 , 
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD,
    ADC_16_TAD,
    ADC_20_TAD
}adc_acquisition_time_t;

/**
 * @brief Analog Channel Select
 */
typedef enum {
         ADC_CHANNEL_0 ,
         ADC_CHANNEL_1 ,
         ADC_CHANNEL_2 ,
         ADC_CHANNEL_3 ,
         ADC_CHANNEL_4 ,
         ADC_CHANNEL_5 ,
         ADC_CHANNEL_6 ,
         ADC_CHANNEL_7 ,
         ADC_CHANNEL_8 ,
         ADC_CHANNEL_9 ,
         ADC_CHANNEL_10 ,
         ADC_CHANNEL_11 ,
         ADC_CHANNEL_12,
}adc_channel_select_t;
/**
 * @brief  A/D Conversion Clock Select
 * @note   If the A/D FRC clock source is selected, a delay of one TCY (instruction cycle) 
 *         is added before the A/D clock starts.
 * @note   This allows the SLEEP instruction to be executed before starting a conversion.
 */
typedef enum {
    ADC_CONVERSION_CLOCK_FOSC_DIV_2 = 0,
    ADC_CONVERSION_CLOCK_FOSC_DIV_8 ,
    ADC_CONVERSION_CLOCK_FOSC_DIV_32 ,
    ADC_CONVERSION_CLOCK_FOSC_DIV_FRC ,
    ADC_CONVERSION_CLOCK_FOSC_DIV_4 ,
    ADC_CONVERSION_CLOCK_FOSC_DIV_16 ,
    ADC_CONVERSION_CLOCK_FOSC_DIV_64
}adc_conversion_clock_t;
/**
 * ADC Configurations
 */
typedef struct{
#if ADC_INTERRUPT_FEATURE_ENABLE ==INTERRUPT_FEATURE_ENABLE 
    void (* ADC_InterruptHandler)(void);
      interrupt_priority_cfg_t priority ;

#endif 
    adc_acquisition_time_t adc_acquisition_time ; /* @ref adc_acquisition_time_t */
    adc_channel_select_t adc_channel ;            /* @ref adc_channel_select_t */
    adc_conversion_clock_t adc_conversion_clock;  /* @ref adc_conversion_clock_t */ 
    uint8 voltage_reference : 1;                  /* Voltage Reference Configuration */
    uint8 result_format : 1;                      /* A/D Result Format Select */
    uint8 ADC_Reserved  : 6;
}adc_conf_t;

/* ----------------- Software Interfaces Declarations -----------------*/
/**
 * Result size of an A/D conversion = 10bit
 */
typedef uint16 adc_result_t ;

std_ReturnType ADC_Init(const adc_conf_t *_adc);
std_ReturnType ADC_DeInit(const adc_conf_t *_adc);

std_ReturnType ADC_Select_Channel(const adc_conf_t *_adc ,adc_channel_select_t _channel );
std_ReturnType ADC_Start_Conversion(const adc_conf_t *_adc );
std_ReturnType ADC_IsConversion_Done(const adc_conf_t *_adc, uint8 *conversion_status);

std_ReturnType ADC_Get_Conversion_Resulst(const adc_conf_t *_adc ,adc_result_t *conversion_result);

std_ReturnType ADC_Get_Conversion_Blocking(const adc_conf_t *_adc ,adc_channel_select_t _channel
                                                    ,adc_result_t *conversion_result);



std_ReturnType ADC_Start_Conversion_Interrupt(const adc_conf_t *_adc ,adc_channel_select_t _channel);



#endif	/* HAL_ADC_H */
