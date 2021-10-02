/* 
 * File:   mcal_external_interrupt.h
 * Author: mohamed
 *
 * Created on May 23, 2021, 2:36 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H


/* ----------------- Includes -----------------*/
#include "mcal_interrupt_config.h"
/* ----------------- Macro Declarations -----------------*/
/* ----------------- Macro function vDeclarations -----------------*/

#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE ==   INTERRUPT_FEATURE_ENABLE
/*This routine set the interrupt enable for the external interrupt , INT0*/
#define EXT_INT0_interrupt_enable()     (INTCONbits.INT0IE = 1)
/*This routine clears the interrupt enable for the external interrupt , INT0*/
#define EXT_INT0_interrupt_disable()    (INTCONbits.INT0IE = 0)
/*This routine clears the interrupt flag for the external interrupt , INT0*/
#define EXT_INT0_flag_clear()           (INTCONbits.INT0IF = 0)
/*This routine set the edge detect for external interrupt rising edge , INT0*/
#define EXT_INT0_rising_edg_set()       (INTCON2bits.INTEDG0 = 1)
/*This routine set the edge detect for external interrupt falling edge , INT0*/
#define EXT_INT0_falling_edg_set()      (INTCON2bits.INTEDG0 = 0)

/*This routine set the interrupt enable for the external interrupt , INT1*/
#define EXT_INT1_interrupt_enable()     (INTCON3bits.INT1IE = 1)
/*This routine clears the interrupt enable for the external interrupt , INT1*/
#define EXT_INT1_interrupt_disable()    (INTCON3bits.INT1IE = 0)
/*This routine clears the interrupt flag for the external interrupt , INT1*/
#define EXT_INT1_flag_clear()           (INTCON3bits.INT1IF = 0)
/*This routine set the edge detect for external interrupt rising edge , INT1*/
#define EXT_INT1_rising_edg_set()       (INTCON2bits.INTEDG1 = 1)
/*This routine set the edge detect for external interrupt falling edge , INT1*/
#define EXT_INT1_falling_edg_set()      (INTCON2bits.INTEDG1 = 0)

/*This routine set the interrupt enable for the external interrupt , INT0*/
#define EXT_INT2_interrupt_enable()     (INTCON3bits.INT2IE = 1)
/*This routine clears the interrupt enable for the external interrupt , INT0*/
#define EXT_INT2_interrupt_disable()    (INTCON3bits.INT2IE = 0)
/*This routine clears the interrupt flag for the external interrupt , INT0*/
#define EXT_INT2_flag_clear()           (INTCON3bits.INT2IF = 0)
/*This routine set the edge detect for external interrupt rising edge , INT0*/
#define EXT_INT2_rising_edg_set()       (INTCON2bits.INTEDG2 = 1)
/*This routine set the edge detect for external interrupt falling edge , INT0*/
#define EXT_INT2_falling_edg_set()      (INTCON2bits.INTEDG2 = 0)


#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the INT1 External Interrupt Priority to be High priority */
  #define EXT_INT1_high_priority()       (INTCON3bits.INT1IP = 1)
/* This routine set the INT1 External Interrupt Priority to be Low priority */
  #define EXT_INT1_low_priority()       (INTCON3bits.INT1IP = 0)
/* This routine set the INT2 External Interrupt Priority to be High priority */
  #define EXT_INT2_high_priority()       (INTCON3bits.INT2IP = 1)
/* This routine set the INT1 External Interrupt Priority to be Low priority */
  #define EXT_INT2_low_priority()       (INTCON3bits.INT2IP = 0)
#endif

#endif

#if EXTERNAL_INTERRUPT_ONCHANGE_FEATURE_ENABLE  ==  INTERRUPT_FEATURE_ENABLE

/*This routine set the interrupt enable for ON change (port B) external interrupt , RBx*/
#define EXT_RBx_interrupt_enable()     (INTCONbits.RBIE = 1)
/*This routine clears the interrupt disable for ON change (port B) external interrupt , RBx*/
#define EXT_RBX_interrupt_disable()    (INTCONbits.RBIE = 0)
/*This routine clears the interrupt flag for the external interrupt ON change (port B) , RBx*/
#define EXT_RBX_flag_clear()           (INTCONbits.RBIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the INT1 External Interrupt Priority to be High priority */
  #define EXT_INT_RBx_high_priority()       (INTCON2bits.RBIP = 1)
/* This routine set the INT1 External Interrupt Priority to be Low priority */
  #define EXT_INT_RBx_low_priority()       (INTCON2bits.RBIP = 0)
#endif

#endif

/* ----------------- Data Type Declarations -----------------*/
typedef enum{
    INTERRUPT_FALLING_EDGE,
            INTERRUPT_RISING_EDGE
}interrupt_INTx_edge;
typedef enum{
    INTERRUPT_EXTERNAL_INT0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2
}interrupt_INTx_source;
typedef struct{
    void(*EXTERNAL_interrupt_handler)(void);
     pin_config_t mcu_pin ;
    interrupt_INTx_edge  edge ;
    interrupt_INTx_source source ;
    interrupt_priority_cfg_t priority ;
}interrupt_Intx_t;

typedef struct{
        void(*EXTERNAL_interrupt_handler)(void);
        pin_config_t mcu_pin ;
        interrupt_priority_cfg_t priority ;

}interrupt_RBx_t;

/* ----------------- Software Interfaces Declarations -----------------*/

std_ReturnType Interrupt_Intx_init(const interrupt_Intx_t *interr_obj);
std_ReturnType Interrupt_Intx_deinit(const interrupt_Intx_t *interr_obj);

std_ReturnType Interrupt_RBx_init(const interrupt_RBx_t *interr_obj);
std_ReturnType Interrupt_RBx_deinit(const interrupt_RBx_t *interr_obj);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

