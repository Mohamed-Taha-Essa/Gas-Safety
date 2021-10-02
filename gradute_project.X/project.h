      /* 
 * File:   project.h
 * Author: moham
 *
 * Created on March 27, 2021, 11:40 AM
 */

#ifndef PROJECT_H
#define	PROJECT_H

/* section : includes */
#include "ECU_LAYER/ecu_init.h"
#include "MCAL_LAYER/Mcal_init.h"
#include "MCAL_LAYER/USART/hal_USART.h"
#include "ECU_LAYER/gsm.h"

/*Section : Macro Declaration  */

/*Section : Macro Function  Declaration  */
 /*Section : Data Type Declaration ecu layer*/
extern pin_config_t dc_pin_high;
extern pin_config_t solenoid_pin_high;


extern keypad_t keypad1 ;
extern dc_motor_t dc_motor_1;
extern dc_motor_t dc_motor_2;

extern char_lcd_8bit_t lcd_2;
extern char_lcd_4bit_t lcd_1;

extern led_config_t led_1;
extern led_config_t led_2;
extern led_config_t led_3;
extern led_config_t led_4;
extern usart_t  usart_interrupt_obj ;


 /*Section : Data Type Declaration mcal layer*/

extern adc_conf_t adc_1;
extern adc_conf_t adc_2;


 /*Section : Function Declaration  */
void project_initialize(void);

void ADC_DEFAULT_INTERRUPT_HANDLER(void);
#endif	/* PROJECT_H */

