/* 
 * File:   mcal_interrupt_manager.h
 * Author: mohamed
 *
 * Created on May 23, 2021, 11:53 PM
 */

#include "mcal_interrupt_manager.h"



#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 

void __interrupt() Interrupt_manager_high(void){
    
}
void __interrupt(low_priority)Interrupt_manager_low(void){
    
}
   
    
#else
void __interrupt() Interrupt_manager_high(void){
    if((INTCONbits.INT0IE == INTERRRUPT_ENABLE)&& (INTCONbits.INT0IF == INTERRRUPT_OCCUR)){
        INT0_ISR();
    } else {/*No thing */}
    
     if((INTCON3bits.INT1IE == INTERRRUPT_ENABLE)&& (INTCON3bits.INT1IF == INTERRRUPT_OCCUR)){
        INT1_ISR();
    }else {/*No thing */}
  
    if((INTCON3bits.INT2IE == INTERRRUPT_ENABLE)&& (INTCON3bits.INT2IF == INTERRRUPT_OCCUR)){
        INT2_ISR();
    }
     else {/*No thing */}
    
    if((PIE1bits.TXIE == INTERRRUPT_ENABLE)&& (PIR1bits.TXIF == INTERRRUPT_OCCUR)){
       EUSART_TX_ISR();
      } else {/*No thing */}
    
  if((PIE1bits.RCIE== INTERRRUPT_ENABLE)&& (PIR1bits.RCIF == INTERRRUPT_OCCUR)){
       EUSART_RX_ISR();

    } else {/*No thing */}
     
    if((INTERRRUPT_ENABLE == PIE1bits.ADIE)&& (INTERRRUPT_OCCUR == PIR1bits.ADIF )){
   
   ADC_ISR();
    }    else {/*No thing */}
}

#endif