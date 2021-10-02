/* 
 * File:   ecu_init.c
 * Author: mohamed Essa
 *
 * Created on March 31, 2021, 12:03 AM
 */
#include "ecu_init.h"
#include "LED/led.h"

pin_config_t dc_pin_high ={
    .Port = PORTD_INDEX,
    .direction =GPIO_DIRECTION_OUTPUT ,
    .pin =  GPIO_PIN0 ,
    .logic =GPIO_LOW 
};

pin_config_t solenoid_pin_high ={
    .Port = PORTD_INDEX,
    .direction =GPIO_DIRECTION_OUTPUT ,
    .pin =  GPIO_PIN1 ,
    .logic =GPIO_HIGH
};


led_config_t led_1={
    .led.Port = PORTC_INDEX ,
    .led.pin = GPIO_PIN0 ,
    .led.direction =GPIO_DIRECTION_OUTPUT,
    .led.logic = GPIO_LOW
};
/*
led_config_t led_2={
    .led.Port = PORTD_INDEX ,
    .led.pin = GPIO_PIN1 ,
    .led.direction =GPIO_DIRECTION_OUTPUT,
    .led.logic = GPIO_LOW
};
led_config_t led_3_motor={
    .led.Port = PORTD_INDEX ,
    .led.pin = GPIO_PIN2 ,
    .led.direction =GPIO_DIRECTION_OUTPUT,
    .led.logic = GPIO_LOW
};*/
/*
led_config_t led_3={
    .led.Port = PORTD_INDEX ,
    .led.pin = GPIO_PIN2 ,
    .led.direction =GPIO_DIRECTION_OUTPUT,
    .led.logic = GPIO_LOW
};
led_config_t led_4={
    .led.Port = PORTD_INDEX ,
    .led.pin = GPIO_PIN3 ,
    .led.direction =GPIO_DIRECTION_OUTPUT,
    .led.logic = GPIO_LOW
};

char_lcd_4bit_t lcd_1 = {
    .lcd_regester_select.Port =PORTD_INDEX ,
    .lcd_regester_select.pin = GPIO_PIN2 ,
    .lcd_regester_select.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_regester_select.logic = GPIO_LOW ,
    
    .lcd_enable.Port =PORTD_INDEX ,
    .lcd_enable.pin = GPIO_PIN3 ,
    .lcd_enable.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_enable.logic = GPIO_LOW ,
    
    .lcd_data[0].Port =PORTD_INDEX ,
    .lcd_data[0].pin =  GPIO_PIN4 ,
    .lcd_data[0].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[0].logic =  GPIO_LOW ,
    
    .lcd_data[1].Port =PORTD_INDEX ,
    .lcd_data[1].pin =  GPIO_PIN5 ,
    .lcd_data[1].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[1].logic =  GPIO_LOW ,
    
    .lcd_data[2].Port =PORTD_INDEX ,
    .lcd_data[2].pin =  GPIO_PIN6 ,
    .lcd_data[2].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[2].logic =  GPIO_LOW ,
    
    .lcd_data[3].Port =PORTD_INDEX ,
    .lcd_data[3].pin =  GPIO_PIN7 ,
    .lcd_data[3].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[3].logic =  GPIO_LOW ,
};
relay_t soenoid ={
  .relay_port =  PORTD_INDEX,
  .relay_pin =   GPIO_PIN2 ,
 .relay_status  =RELAY_ON_STATUS 
};*/
/*
char_lcd_8bit_t lcd_2 = {
   .lcd_regester_select.Port =PORTB_INDEX ,
    .lcd_regester_select.pin = GPIO_PIN0 ,
    .lcd_regester_select.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_regester_select.logic = GPIO_LOW ,
    
    .lcd_enable.Port =PORTB_INDEX ,
    .lcd_enable.pin = GPIO_PIN1 ,
    .lcd_enable.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_enable.logic = GPIO_LOW ,
    
    .lcd_data[0].Port =PORTA_INDEX ,
    .lcd_data[0].pin =  GPIO_PIN4 ,
    .lcd_data[0].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[0].logic =  GPIO_LOW ,
    
    .lcd_data[1].Port =PORTA_INDEX ,
    .lcd_data[1].pin =  GPIO_PIN5 ,
    .lcd_data[1].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[1].logic =  GPIO_LOW ,
    
    .lcd_data[2].Port =PORTA_INDEX ,
    .lcd_data[2].pin =  GPIO_PIN6 ,
    .lcd_data[2].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[2].logic =  GPIO_LOW ,
    
    .lcd_data[3].Port =PORTA_INDEX ,
    .lcd_data[3].pin =  GPIO_PIN7 ,
    .lcd_data[3].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[3].logic =  GPIO_LOW ,
    
    .lcd_data[4].Port =PORTB_INDEX  ,
    .lcd_data[4].pin =  GPIO_PIN3 ,
    .lcd_data[4].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[4].logic =  GPIO_LOW ,
    
    .lcd_data[5].Port =PORTB_INDEX , 
    .lcd_data[5].pin =  GPIO_PIN4 ,
    .lcd_data[5].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[5].logic =  GPIO_LOW ,
    
    .lcd_data[6].Port =PORTB_INDEX  ,
    .lcd_data[6].pin =  GPIO_PIN5 ,
    .lcd_data[6].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[6].logic =  GPIO_LOW ,
    
    .lcd_data[7].Port =PORTB_INDEX  ,
    .lcd_data[7].pin =  GPIO_PIN6 ,
    .lcd_data[7].direction =  GPIO_DIRECTION_OUTPUT ,
    .lcd_data[7].logic =  GPIO_LOW ,
};
dc_motor_t dc_motor_1 = {
   
    .dc_motor_pin[0].Port = PORTC_INDEX,
    .dc_motor_pin[0].pin = GPIO_PIN2,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pin[1].Port = PORTC_INDEX,
    .dc_motor_pin[1].pin = GPIO_PIN3,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT
};
 */
/*
dc_motor_t dc_motor_2 = {
    .dc_motor_pin[0].Port = PORTC_INDEX,
    .dc_motor_pin[0].pin = GPIO_PIN2,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pin[1].Port = PORTC_INDEX,
    .dc_motor_pin[1].pin = GPIO_PIN3,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT
};
*/
void ecu_layer_initialize(void){
     std_ReturnType ret = E_NOT_Ok   ;
     ret =gpio_pin_initialize(&dc_pin_high);
          ret =gpio_pin_initialize(&solenoid_pin_high);

 //ret  = dc_motor_initialize(&dc_motor_1);
 //ret = dc_motor_initialize(&dc_motor_2);
//ret = lcd_4bit_intialize(&lcd_1);
  //  ret = lcd_8bit_intialize(&lcd_2);
//ret =  relay_initialization(&soenoid);
   ret = led_init(&led_1);
   //ret = led_init(&led_2);
    // ret = led_init(&led_3_motor);
     //ret = led_init(&led_4);

}
void EUSART_RX_interrupt_counter(void){
        std_ReturnType ret = E_NOT_Ok   ;

    uint16 usart_rx_read ;
   // usart_rx_read ++;
    usart_rx_read =RCREG;
//    ret = lcd_4bit_send_string_pos(&lcd_1 ,1,1,usart_rx_read);
    
}
void EUSART_TX_interrupt_counter(void){
    std_ReturnType ret = E_NOT_Ok   ;
   
    uint8 usart_tx_read  ;
    uint8 pos=0;
        pos++;
    
  usart_tx_read = TXREG ;
  //lcd_4bit_send_command(&lcd_1,_LCD_CLEAR);
    //ret = lcd_4bit_send_string_pos(&lcd_1 ,1,1,usart_tx_read);
   
}

