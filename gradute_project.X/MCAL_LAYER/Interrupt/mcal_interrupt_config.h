/* 
 * File:   mcal_interrupt_config.h
 * Author: moham
 *
 * Created on May 23, 2021, 2:38 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/* ----------------- Includes -----------------*/
#include "../../MCAL_LAYER/mcal_std_types.h"
#include "pic18f4620.h"
#include "../GPIO/hal_gpio.h"
#include "mcal_interrupt_gen_cfg.h"
/* ----------------- Macro Declarations -----------------*/
#define INTERRRUPT_ENABLE            1
#define INTERRRUPT_DESABLE           0
#define INTERRRUPT_OCCUR             1 
#define INTERRRUPT_NOT_ENABLE        0
#define INTERRRUPT_PRIORITY_ENABLE   1
#define INTERRRUPT_PRIORITY_DISABLE  0

/* ----------------- Macro functionvDeclarations -----------------*/

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/*This macro will enable  priority level*/
#define INTERRRUPT_priority_level_is_enable() (RCONbits.IPEN = 1)
/*This macro will disable  priority level*/
#define INTERRRUPT_priority_level_is_disable() (RCONbits.IPEN = 0)

/*This macro will enable all high priority */ 
/*###if we don't enable priority don't use high or low level (2 function)*/
#define INTERRRUPT_global_interrupt_high_enable() (INTCONbits.GIEH = 1)
/*This macro will disable all high priority */
#define INTERRRUPT_global_interrupt_high_disable() (INTCONbits.GIEH = 0)

/*This macro will enable all LOW priority global interrupt*/
#define INTERRRUPT_global_interrupt_low_enable() (INTCONbits.GIEL = 1)
/*This macro will disable all LOW priority global interrupt */
#define INTERRRUPT_global_interrupt_low_disable() (INTCONbits.GIEL = 0)

#else
/*This macro will enable global interrupt  */ 
#define INTERRRUPT_global_interrupt_enable() (INTCONbits.GIE = 1)
/*This macro will disable global interrupt */
#define INTERRRUPT_global_interrupt_disable() (INTCONbits.GIE = 0)

/*This macro will enable peripheral interrupt */
#define INTERRRUPT_peripheral_interrupt_enable() (INTCONbits.PEIE = 1)
/*This macro will disable peripheral interrupt*/
#define INTERRRUPT_peripheral_interrupt_disable() (INTCONbits.PEIE = 0)
#endif

/* ----------------- Software Interfaces Declarations -----------------*/
typedef enum {
    INTERRRUPT_LOW_PRIORITY,
                INTERRUPT_HIGH_PRIORITy

}interrupt_priority_cfg_t;


/* ----------------- Software Interfaces Declarations -----------------*/

#endif	/* MCAL_INTERRUPT_CONFIG_H */

