/* 
 * File:   gsm.h
 * Author: moham
 *
 * Created on July 23, 2021, 10:25 PM
 */

#ifndef GSM_H
#define	GSM_H
#include "../MCAL_LAYER/mcal_std_types.h"
#include "../MCAL_LAYER/USART/hal_USART.h"
#include "../ECU_LAYER/character_lcd/ecu_character_lcd.h"

uint16 data;
std_ReturnType gsm_make_call(void);
std_ReturnType gsm_send_message(void);
std_ReturnType gsm_send_data_to_server(uint16 data_gas ,uint16 data_heat);





#endif	/* GSM_H */

