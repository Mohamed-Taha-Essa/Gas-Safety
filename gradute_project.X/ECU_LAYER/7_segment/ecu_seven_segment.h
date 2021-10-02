/* 
 * File:   ecu_seven_segment.h
 * Author: moham
 *
 * Created on March 25, 2021, 12:07 AM
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H

/* section : includes */
#include "../../MCAL_LAYER/GPIO/hal_gpio.h" 
#include "ecu_seven_segment_cfg.h"

/*Section : Macro Declaration  */
#define SEGMENT_PINT0  0
#define SEGMENT_PINT1  1
#define SEGMENT_PINT2  2
#define SEGMENT_PINT3  3

/*Section : Macro Function  Declaration  */
 /*Section : Data Type Declaration  */
typedef enum {
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE          
}sgment_type_t;

typedef struct {
    pin_config_t segment_pins[4];
    sgment_type_t segment_type;
}segment_t;
 /*Section : Function Declaration  */
std_ReturnType seven_segment_initialize(const segment_t *segment);
std_ReturnType seven_segment_write_number(const segment_t *segment ,uint8 number);


#endif	/* ECU_SEVEN_SEGMENT_H */

