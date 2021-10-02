/* 
 * File:   mcal_interrupt_gen_cfg.h
 * Author: moham
 *
 * Created on May 23, 2021, 2:38 PM
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H

/* ----------------- Includes -----------------*/
/* ----------------- Macro Declarations -----------------*/
#define INTERRUPT_FEATURE_ENABLE   1
#define INTERRUPT_FEATURE_DISABLE  0

/* ----------controlling in interrupt feature-------------*/

//#define INTERRUPT_PRIORITY_LEVELS_ENABLE               INTERRUPT_FEATURE_ENABLE

/* ----------controlling in external interrupt feature-------------*/
//#define EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE        INTERRUPT_FEATURE_ENABLE
/* ----------controlling in on change interrupt feature-------------*/
#define EXTERNAL_INTERRUPT_ONCHANGE_FEATURE_ENABLE    INTERRUPT_FEATURE_ENABLE

/* -----------controlling on ADC interrupt enable or disable it */
#define ADC_INTERRUPT_FEATURE_ENABLE                INTERRUPT_FEATURE_ENABLE


/* -------controlling on TX_INTERRUPT enable or disable it */
#define EUSART_TX_INTERRUPT_FEATURE_ENABLE            INTERRUPT_FEATURE_ENABLE

/* -------controlling on RX_INTERRUPT enable or disable it */
#define EUSART_RX_INTERRUPT_FEATURE_ENABLE            INTERRUPT_FEATURE_ENABLE
/* ----------------- Macro functionvDeclarations -----------------*/

/* ----------------- Software Interfaces Declarations -----------------*/


#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

