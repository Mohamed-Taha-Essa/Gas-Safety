/* 
 * File:   mcal_interrupt_manager.h
 * Author: moham
 *
 * Created on May 23, 2021, 11:53 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H
/* ----------------- Includes -----------------*/
#include "mcal_interrupt_config.h"

/* ----------------- Macro Declarations -----------------*/


/* ----------------- Software Interfaces Declarations -----------------*/

void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

void EUSART_TX_ISR(void);
void EUSART_RX_ISR(void);

void ADC_ISR(void);

#endif	/* MCAL_INTERRUPT_MANAGER_H */

