/* 
 * File:   ecu_init.h
 * Author: moham
 *
 * Created on March 31, 2021, 12:03 AM
 */

#ifndef ECU_INIT_H
#define	ECU_INIT_H
/* section : includes */

#include "LED/led.h"
#include "7_segment/ecu_seven_segment.h"
#include "ecu_dc_motor/ecu_dc_motor.h"
#include "Relay/ecu_relay.h"
#include "KeyPad/ecu_keypad.h"
#include "../MCAL_LAYER/Mcal_init.h"
#include "character_lcd/ecu_character_lcd.h"


 /*Section : Function Declaration  */
void ecu_layer_initialize(void);


//#define _XTAL_FREQ 4000000UL 

#endif	/* ECU_INIT_H */

