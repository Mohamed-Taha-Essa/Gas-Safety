/* 
 * File:   ecu_keypad.h
 * Author: moham
 *
 * Created on March 29, 2021, 4:17 PM
 */

#include "ecu_keypad.h"

uint8 btn_values[ECU_KEYPAD_ROW][ECU_KEYPAD_COLUMN] = {
                         {'7','8','9','/'},
                         {'4','5','6','*'},
                         {'1','2','3','-'},
                         {'#','0','=','+'}

                       };

std_ReturnType keypad_initialize(const keypad_t *_keypad_obj){
    std_ReturnType ret = E_Ok ;
    uint8 counter_row =ZERO_INIT ,counter_column= ZERO_INIT;
     if(NULL == _keypad_obj )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         for(counter_row = ZERO_INIT ; counter_row < ECU_KEYPAD_ROW ; counter_row++)
         {
             ret = gpio_pin_initialize(&(_keypad_obj->keypad_row_pins[counter_row]));
         }
           for(counter_column = ZERO_INIT ; counter_column < ECU_KEYPAD_COLUMN ; counter_column++)
         {
              ret = gpio_pin_direction_initialize(&(_keypad_obj->keypad_row_pins[counter_column]));
         }
       }
     return ret ; 
}
std_ReturnType keypad_get_value(const keypad_t *_keypad_obj , uint8 *value){
    std_ReturnType ret = E_Ok ;
    uint8 column_logic;
     if((NULL == _keypad_obj) || (NULL == value))
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
             uint8 l_counter_row =ZERO_INIT ,l_counter_column= ZERO_INIT ,l_counter=ZERO_INIT ;

         for(l_counter_row = ZERO_INIT ; l_counter_row < ECU_KEYPAD_ROW ; l_counter_row++)
         {
              
             for(l_counter = ZERO_INIT ; l_counter < ECU_KEYPAD_ROW ; l_counter++)
             {
                  gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[l_counter]),GPIO_LOW);      
             }
             
              gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[l_counter_row]),GPIO_HIGH);
              
             for(l_counter_column = ZERO_INIT ; l_counter_column < ECU_KEYPAD_COLUMN ; l_counter_column++)
             {
                 ret =  gpio_pin_read_logic(&(_keypad_obj->keypad_columns_pins[l_counter_column]),&column_logic);
                 if (GPIO_HIGH == column_logic) 
                 {
                       *value =  btn_values[l_counter_row][l_counter_column];
                 }
             }
         
         }
         
       }
     return ret ; 
}
