/* 
 * File:   Mcal_init.h
 * Author: moham
 *
 * Created on April 6, 2021, 4:32 PM
 */

#ifndef MCAL_INIT_H
#define	MCAL_INIT_H


/* section : includes */
#include "ADC/hal_adc.h"
#include "GPIO/hal_gpio.h"
#include "mcal_std_types.h"

/*Section : Function Declaration  */
void mcal_layer_initialize(void);

void EUSART_TX_interrupt_counter(void);
void EUSART_RX_interrupt_counter(void);

#endif	/* MCAL_INIT_H */

