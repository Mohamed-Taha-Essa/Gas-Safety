/* 
 * File:   ecu_dc_motor.h
 * Author: moham
 *
 * Created on March 27, 2021, 6:29 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*--------- section : includes -------------------------*/
#include "ecu_dc_motor_cfg.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"

/*----------Section : Macro Declaration--------------  */
#define DC_MOTOR_ON_STATUS 0x01U
#define DC_MOTOR_OFF_STATUS 0x00U

#define DC_MOTOR_PIN1 0x00U
#define DC_MOTOR_PIN2 0x01U



/*-------Section : Macro Function  Declaration-------  */
 /*--------Section : Data Type Declaration-----------  */
/*typedef struct{
    uint8 dc_motor_port : 4 ;
    uint8 dc_motor_pin  : 3 ;
    uint8 dc_motor_pin_status  : 1 ;
    
}dc_motor_pin_t;
*/

typedef struct{
    pin_config_t dc_motor_pin[2];
}dc_motor_t;

 /*---------------Section : Function Declaration------------------   */
std_ReturnType dc_motor_initialize(const dc_motor_t *dc_motor);
std_ReturnType dc_motor_move_right(const dc_motor_t *dc_motor);
std_ReturnType dc_motor_move_left(const dc_motor_t *dc_motor);
std_ReturnType dc_motor_stop(const dc_motor_t *dc_motor);
 
#endif	/* ECU_DC_MOTOR_H */

