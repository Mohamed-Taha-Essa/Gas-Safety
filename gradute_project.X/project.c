/* 
 * File:   project.c
 * Author: Mohamed Abdallah Essa
 *
 * Created on March 27, 2021, 12:05 PM
 */
/* section : includes */
#include "project.h"

volatile uint8 adc_flag;
uint8 rec_eusart ;
uint16 adc_gas,adc_heat;
uint8 str;

int main() {
    std_ReturnType ret = E_NOT_Ok   ;
    project_initialize();
    __delay_ms(5000);
  
    while(1){
             
        // pin for solenoid D1 OPEN SOLENOID (NORMAL CLOSED)
          ret = gpio_pin_write_logic(&solenoid_pin_high ,GPIO_HIGH);      
       /*start to read analog values from sensors and convert it to digital*/
         ret = ADC_Start_Conversion_Interrupt(&adc_1 , ADC_CHANNEL_0);
         ret = ADC_Start_Conversion_Interrupt(&adc_2 , ADC_CHANNEL_1);      
           }
    return (EXIT_SUCCESS);
    }
/*initialize all layers*/
void project_initialize(void){
   mcal_layer_initialize();
   ecu_layer_initialize();
}
/**
* @Summary make tow action .
 * @Description close solenoid if gas leak is bigger than the normal value .
 *               open the motor to open the Kitchen Hoods if 
 */
void ADC_DEFAULT_INTERRUPT_HANDLER(void){
 std_ReturnType ret = E_NOT_Ok   ;
    adc_flag++;   //CHECK IF INTERRUPT HAPPENED in simulation
    uint8 counter = 0;
    ret = ADC_Get_Conversion_Resulst(&adc_1 ,&adc_gas );
     ret = ADC_Get_Conversion_Resulst(&adc_2 ,&adc_heat );
   
    if ((GAS_LEAK_DANGER > adc_gas || HEAT_DANGER > adc_heat)){
           ret = gpio_pin_write_logic(&dc_pin_high ,GPIO_LOW);             //pin for motor D0
         ret = led_off(&led_1);
        ret = gpio_pin_write_logic(&solenoid_pin_high ,GPIO_HIGH);      // pin for solenoid D1
    }
    else{
        ret = led_on(&led_1);                                           //portc pin0
        ret = gpio_pin_write_logic(&dc_pin_high ,GPIO_HIGH);           //pin for motor D0
        ret = gpio_pin_write_logic(&solenoid_pin_high ,GPIO_LOW);      // pin for solenoid D1
        counter++ ;
    }
     
     if (counter != 0 ){
                 ret = gsm_send_data_to_server(adc_gas,adc_heat);              //send data to web server using gsm gprs module
                 counter = 0 ; 
     }
     else{} 
}

