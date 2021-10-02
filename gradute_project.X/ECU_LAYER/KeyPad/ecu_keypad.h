/* 
 * File:   ecu_keypad.h
 * Author: moham
 *
 * Created on March 29, 2021, 4:17 PM
 */

#ifndef ESU_KEYPAD_H
#define	ESU_KEYPAD_H
/* section : includes */

#include "ecu_keypad_cfg.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"


/*Section : Macro Declaration  */

#define ECU_KEYPAD_ROW     4 
#define ECU_KEYPAD_COLUMN 4
/*Section : Macro Function  Declaration  */
 /*Section : Data Type Declaration  */
typedef struct{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROW];
    pin_config_t keypad_columns_pins[ECU_KEYPAD_COLUMN];
}keypad_t;
 /*Section : Function Declaration  */
std_ReturnType keypad_initialize(const keypad_t *_keypad_obj);
std_ReturnType keypad_get_value(const keypad_t *_keypad_obj , uint8 *value);

#endif	/* ECU_KEYPAD_H */

