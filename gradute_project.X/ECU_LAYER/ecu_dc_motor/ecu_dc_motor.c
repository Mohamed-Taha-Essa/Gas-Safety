/* 
 * File:   ecu_dc_motor.h
 * Author: moham
 *
 * Created on March 27, 2021, 6:29 PM
 */

#include "ecu_dc_motor.h"



std_ReturnType dc_motor_initialize(const dc_motor_t *dc_motor){
    std_ReturnType ret = E_Ok ;
     if(NULL == dc_motor )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         
           
        gpio_pin_initialize(&(dc_motor->dc_motor_pin[0]));
        gpio_pin_initialize(&(dc_motor->dc_motor_pin[1]));

         
     /* pin_config_t  motor_pin1 ={ .Port = dc_motor->dc_motor[0].dc_motor_port,
                                     .pin = dc_motor->dc_motor[0].dc_motor_pin,
                                     .direction = GPIO_DIRECTION_OUTPUT   ,
                                     .logic = dc_motor->dc_motor[0].dc_motor_pin_status
                                   };
       pin_config_t motor_pin2 ={ .Port = dc_motor->dc_motor[1].dc_motor_port,
                                     .pin = dc_motor->dc_motor[1].dc_motor_pin,
                                     .direction = GPIO_DIRECTION_OUTPUT   ,
                                     .logic = dc_motor->dc_motor[1].dc_motor_pin_status
                                   };*/
    }
     return ret ; 
  
}
std_ReturnType dc_motor_move_right(const dc_motor_t *dc_motor){
    std_ReturnType ret = E_Ok ;
     if(NULL == dc_motor )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]) ,GPIO_HIGH );
          gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]),GPIO_LOW );
       }
     return ret ; 
  
}
std_ReturnType dc_motor_move_left(const dc_motor_t *dc_motor){
    std_ReturnType ret = E_Ok ;
     if(NULL == dc_motor )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
            gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]) , GPIO_LOW );
          gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]), GPIO_HIGH );

       }
     return ret ; 
  
}
std_ReturnType dc_motor_stop(const dc_motor_t *dc_motor){
    std_ReturnType ret = E_Ok ;
     if(NULL == dc_motor )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
           gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]), GPIO_LOW );
          gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]), GPIO_LOW );

       }
     return ret ; 
  
}