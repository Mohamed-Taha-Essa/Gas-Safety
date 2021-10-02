/* 
 * File:   ecu_relay.h
 * Author: moham
 *
 * Created on March 29, 2021, 1:28 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H
/* section : includes */
#include "ecu_relay_cfg.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"

/*----------Section : Macro Declaration--------------  */
#define RELAY_ON_STATUS  0x01U
#define RELAY_OFF_STATUS 0x00U

#define RELAY_PIN1 0x00U
//#define RELAY_PIN2 0x01U

/*-------Section : Macro Function  Declaration-------  */
 /*--------------- Data Type Declaration-----------  */

typedef struct {
    uint8 relay_port : 4 ;
    uint8 relay_pin : 3  ;
    uint8 relay_status :1 ;
}relay_t;
 /*---------------SOFTWARE_INTERFACES_DECLARATION------------------   */
std_ReturnType relay_initialization(const relay_t *_relay);
std_ReturnType relay_turn_on(const relay_t *_relay);
std_ReturnType relay_turn_off(const relay_t *_relay);

#endif	/* ECU_RELAY_H */

