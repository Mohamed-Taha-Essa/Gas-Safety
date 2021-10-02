
/* 
 * File:   ecu_relay.h
 * Author: moham
 *
 * Created on March 29, 2021, 1:28 PM
 */

/* section : includes */
#include "ecu_relay.h"

std_ReturnType relay_initialization(const relay_t *_relay){
    std_ReturnType ret = E_Ok ;
     if(NULL == _relay )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         pin_config_t pin_obj = { .Port = _relay->relay_port ,.pin  = _relay->relay_pin ,
                              .direction = GPIO_DIRECTION_OUTPUT , .logic= _relay->relay_status      
             
         };
         
         gpio_pin_initialize(&pin_obj);
       }
    return ret ;
}
std_ReturnType relay_turn_on(const relay_t *_relay){
    std_ReturnType ret = E_Ok ;
     if(NULL == _relay )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
          pin_config_t pin_obj = { .Port = _relay->relay_port ,.pin  = _relay->relay_pin ,
                              .direction = GPIO_DIRECTION_OUTPUT , .logic= _relay->relay_status      
             
          };
                    gpio_pin_write_logic(&pin_obj , GPIO_HIGH);

    }
    return ret ;
}

std_ReturnType relay_turn_off(const relay_t *_relay){
    std_ReturnType ret = E_Ok ;
     if(NULL == _relay )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
          pin_config_t pin_obj = { .Port = _relay->relay_port ,.pin  = _relay->relay_pin ,
                              .direction = GPIO_DIRECTION_OUTPUT , .logic= _relay->relay_status      
             
                                 };
                       gpio_pin_write_logic(&pin_obj , GPIO_LOW);

       }

    return ret ;
}