/* 
 * File:   ecu_seven_segment.c
 * Author: moham
 *
 * Created on March 25, 2021, 12:07 AM
 */

/* section : includes */
#include "ecu_seven_segment.h"

std_ReturnType seven_segment_initialize(const segment_t *segment){
    
    std_ReturnType ret = E_Ok ;
     if(NULL == segment )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
           ret = gpio_pin_initialize(&(segment->segment_pins[SEGMENT_PINT0]));
           ret = gpio_pin_initialize(&(segment->segment_pins[SEGMENT_PINT1]));

           ret = gpio_pin_initialize(&(segment->segment_pins[SEGMENT_PINT2]));

           ret = gpio_pin_initialize(&(segment->segment_pins[SEGMENT_PINT3]));

       }
     return ret ; 
  
}
std_ReturnType seven_segment_write_number(const segment_t *segment ,uint8 number){
     std_ReturnType ret = E_Ok ;
     if(NULL == segment )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
        ret = gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PINT0]) ,number & 0x01);
        ret =  gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PINT1]) ,(number>>1) & 0x01);
        ret =  gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PINT2]) ,(number>>2) & 0x01);
        ret = gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PINT3]) ,(number>>3) & 0x01);

         
       }
     return ret ; 
  
}