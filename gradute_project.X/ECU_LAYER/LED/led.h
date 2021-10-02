/* 
 * File:   led.h
 * Author: Taha
 *
 * Created on December 17, 2020, 9:37 PM
 */



#ifndef LED_H
#define	LED_H

/* section : includes */
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
/*Section : Macro Declaration  */



/*Section : Macro Function  Declaration  */
 /*Section : Data Type Declaration  */
typedef enum{
    LED_OFF,
    LED_ON
}led_status_t;
typedef struct{
    pin_config_t led; 
}led_config_t;
 /*Section : Function Declaration  */
std_ReturnType led_init(const led_config_t *_led);
std_ReturnType led_on(const led_config_t *_led);
std_ReturnType led_off(const led_config_t *_led);
std_ReturnType led_toggle(const led_config_t *_led);

#include "../../MCAL_LAYER/GPIO/hal_gpio.h"

#endif	/* LED_H */

