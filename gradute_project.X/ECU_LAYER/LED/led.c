/* 
 * File:   led.c
 * Author: Taha
 *
 * Created on December 3, 2020, 10:43 AM
 */
#include "led.h"

std_ReturnType led_init(const led_config_t *_led){
    std_ReturnType ret = E_Ok ;
     if(NULL == _led )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
        
         ret = gpio_pin_initialize(&(_led->led));
       }
     return ret ; 
}
std_ReturnType led_on(const led_config_t *_led){
    std_ReturnType ret = E_Ok ;
     if(NULL == _led )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
          ret = gpio_pin_write_logic(&(_led->led) ,GPIO_HIGH);
       }
     return ret ; 
}
std_ReturnType led_off(const led_config_t *_led){
    std_ReturnType ret = E_Ok ;
     if(NULL == _led )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
                  ret = gpio_pin_write_logic(&(_led->led) ,GPIO_LOW);

       }
     return ret ; 
}
std_ReturnType led_toggle(const led_config_t *_led){
    std_ReturnType ret = E_Ok ;
     if(NULL == _led )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         ret = gpio_pin_toggle_logic(&(_led->led));
       }
     return ret ; 
}
#include "led.h"
