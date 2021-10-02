/* 
 * File:   Mcal_init.c
 * Author: moham
 *
 * Created on April 6, 2021, 4:32 PM
 */

#include "Mcal_init.h"
#include "USART/hal_USART.h"
#include "../project.h"

uint32 usart_rx_read= 0 ;
adc_conf_t adc_1 ={
    
    .ADC_InterruptHandler = ADC_DEFAULT_INTERRUPT_HANDLER,
    .adc_acquisition_time = ADC_12_TAD,
    .adc_conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    .adc_channel = ADC_CHANNEL_0 ,
    .result_format = ADC_RESULT_FORMAT_RIGHT,
    .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};
adc_conf_t adc_2 ={
    
    .ADC_InterruptHandler = ADC_DEFAULT_INTERRUPT_HANDLER,
    .adc_acquisition_time = ADC_12_TAD,
    .adc_conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    .adc_channel = ADC_CHANNEL_1 ,
    .result_format = ADC_RESULT_FORMAT_RIGHT,
    .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};


usart_t usart_interrupt_obj ={
   .baudrate = 9600,
   .baudrate_gen_gonfig = BAUDRATE_ASYN_8BIT_lOW_SPEED,   

   .usart_tx_cfg.usart_tx_enable = EUSART_ASYNCHRONOUS_TX_ENABLE ,
   .usart_tx_cfg.usart_tx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE ,
   .usart_tx_cfg.usart_tx_9bit_enable = EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE ,
   
    .usart_rx_cfg.usart_rx_enable = EUSART_ASYNCHRONOUS_RX_ENABLE ,
   .usart_rx_cfg.usart_rx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE,
   .usart_rx_cfg.usart_rx_9bit_enable = EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE ,
   
   .EUSART_FramingErrorHandler = NULL ,
   .EUSART_OverrunErrorHandler =NULL,
   .EUSART_RxDefaultInterruptHandler = NULL,
   .EUSART_TxDefaultInterruptHandler = NULL 
   
    
};



void mcal_layer_initialize(void){
     std_ReturnType ret = E_NOT_Ok   ;
      
      ret = EUSART_ASYNC_Init(&usart_interrupt_obj);

            ret = ADC_Init(&adc_1);
             ret = ADC_Init(&adc_2);
      
     
      
}