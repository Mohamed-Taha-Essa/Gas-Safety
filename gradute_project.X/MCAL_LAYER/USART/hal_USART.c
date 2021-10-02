/* 
 * File:   mcal_USART.c
 * Author: mohamed
 *
 * Created on April 30, 2021, 6:43 AM
 */


/* ----------------- Includes -----------------*/
#include "hal_USART.h"

/*-----------------------helper function -------------------------------*/

static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart);
static void EUSART_ASYNC_TX_INIT(const usart_t *_eusart) ;
static void EUSART_ASYNC_RX_INIT(const usart_t *_eusart) ;

/*-----------------------pointer to function use in call back -------------------------------*/
#if EUSART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    static void  (*EUSART_tx_interrupt_handler) (void) = NULL ;
#endif  
#if EUSART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE   
    static void  (*EUSART_rx_interrupt_handler) (void)  = NULL ;
    static void  (*EUSART_framming_error_handler) (void)= NULL ;
    static void  (*EUSART_over_interrupt_handler) (void)= NULL ;
#endif     
/*-----------------------EUSART function -------------------------------*/
/**
 * 
 * @param _eusart
 * @return 
 */
std_ReturnType EUSART_ASYNC_Init(const usart_t *_eusart){
   
    std_ReturnType ret = E_NOT_Ok ;
    if(NULL ==_eusart ){
         ret = E_NOT_Ok ;
    }
    else {
        /*disable EUSART Module*/ 
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE;
        /*write 1 on pin 7,6 as input and usart can make it input or putput any time*/
        TRISCbits.RC7 = 1 ;
        TRISCbits.RC6 = 1 ;

         /*determine the baud rate for EUSART Module*/ 
        EUSART_Baud_Rate_Calculation(_eusart) ;
         /*initialize TX pin in EUSART Module*/ 
        EUSART_ASYNC_TX_INIT(_eusart);
         /*initialize RX pin in EUSART Module*/ 
        EUSART_ASYNC_RX_INIT(_eusart);
         /*ENable EUSART Module*/  
         RCSTAbits.SPEN = EUSART_MODULE_ENABLE;

    }
    return ret ;
}
/**
 * it make Serial port disabled (held in Reset) 
 * @param _eusart
 * @return 
 */
std_ReturnType EUSART_ASYNC_DeInit(const usart_t *_eusart){
   
    std_ReturnType ret = E_NOT_Ok ;
    if(NULL ==_eusart ){
        ret = E_NOT_Ok ;
    }
    else {
         RCSTAbits.SPEN = EUSART_MODULE_DISABLE;
    }
    return ret ;
}
/**
 * 
 * @param _data
 * @return 
 */
std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data){
      
  //PIR1bits.RCIF automatic set if recieved one byte

    std_ReturnType ret = E_NOT_Ok ;
     
        while(!PIR1bits.RCIF) {}
          *_data = RCREG;
   
    return ret ;
}
/**
 * 
 * @param _data
 * @return 
 */
std_ReturnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *_data){
    //in main function check on ret if ok that mean it receive byte 
    //PIR1bits.RCIF automatic set if recieved one byte
    std_ReturnType ret = E_NOT_Ok ;
    if(1 ==PIR1bits.RCIF){
         *_data = RCREG;
         ret = E_Ok ;
    }
    else {
        ret = E_NOT_Ok ;
    }
    return ret ;
}

/**
 * 
 * @param _data
 * @return 
 */
std_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 _data){
   
    std_ReturnType ret = E_Ok ;
   while(!TXSTAbits.TRMT){}//transmit shift register not empty =1   empty = 0 
    #if EUSART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
   EUSART_TX_InterruptEnable() ;
#endif
       TXREG = _data ; 
       
    return ret ;
}

/**
 * 
 * @param _data
 * @return 
 */
std_ReturnType EUSART_ASYNC_WriteByteNonBlocking(uint8 _data){
       //in main function check on ret if ok that mean it receive byte 

    std_ReturnType ret = E_NOT_Ok ;
     if(1 == TXSTAbits.TRMT){  //transmit shift register not empty =1   empty = 0
         EUSART_TX_InterruptEnable() ;
           TXREG =_data ;
            ret = E_Ok ;
    }
    else {
        ret = E_NOT_Ok ;
    }
    return ret ;
    
    return ret ;
}

/**
 * 
 * @param _data
 * @param str_len
 * @return 
 */
std_ReturnType EUSART_ASYNC_WriteStringBlocking(uint8 *_data, uint16 str_len){
    uint16 count_str ;
    std_ReturnType ret = E_NOT_Ok ;
    if(NULL ==_data ){
        ret = E_NOT_Ok ;
    }
    else { 
        
      for(count_str = ZERO_INIT ; count_str < str_len ; count_str++){
          EUSART_ASYNC_WriteByteBlocking(*_data++); 
          
      } 
    }
    return ret ;
}

/**
 * 
 * @param _data
 * @param str_len
 * @return 
 */
std_ReturnType EUSART_ASYNC_WriteStringNonBlocking(uint8 *_data, uint16 str_len){
   
   uint16 count_str ;
    std_ReturnType ret = E_NOT_Ok ;
    if(NULL ==_data ){
        ret = E_NOT_Ok ;
    }
    else { 
        
      for(count_str = ZERO_INIT ; count_str < str_len ; count_str++){
          EUSART_ASYNC_WriteByteNonBlocking(*_data++); 
          
      } 
    }
    return ret ;
}
 
/*helper function */
/**
 *  
 * @param _eusart
 */

std_ReturnType EUSART_ASYNC_RX_Restart(void){
   
    std_ReturnType ret = E_NOT_Ok ;
    
    
    
    return ret ;
}

/*================================HELPER FUNCTION======================================*/
static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart){
     
           float Baud_Rate_Temp = 0;
    switch(_eusart->baudrate_gen_gonfig){
        case BAUDRATE_ASYN_8BIT_lOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 64) - 1;

            	   break;
        case BAUDRATE_ASYN_8BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 16) - 1;
            break;
        case BAUDRATE_ASYN_16BIT_lOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 16) - 1;
            break;
        case BAUDRATE_ASYN_16BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        case BAUDRATE_SYN_8BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        case BAUDRATE_SYN_16BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        default : ;
    }
    SPBRG = (uint8)((uint32)Baud_Rate_Temp);
    SPBRGH = (uint8)(((uint32)Baud_Rate_Temp) >> 8);
}
/**
 * 
 * @param _eusart
 */
 static void EUSART_ASYNC_TX_INIT(const usart_t *_eusart)  {
     if (EUSART_ASYNCHRONOUS_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_enable ){
         
         TXSTAbits.TXEN = EUSART_ASYNCHRONOUS_TX_ENABLE ;
          /*   EUSART INTERRUPT transmit configuration   */ 
            if ( EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_enable ){
              //  PIE1bits.TXIE = EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE;
#if EUSART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
               EUSART_TX_InterruptEnable()   ;
               EUSART_tx_interrupt_handler = _eusart->EUSART_TxDefaultInterruptHandler;
    #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE             
               if(  INTERRUPT_HIGH_PRIORITy == _eusart->usart_tx_cfg.usart_tx_int_priority){
                     EUSART_TX_HighPrioritySet() ;
                     /*must here clear flag but it clear automatic*/
               }
               else if(INTERRRUPT_LOW_PRIORITY   == _eusart->usart_tx_cfg.usart_tx_int_priority){
                   EUSART_TX_LowPrioritySet() ;
                     /*must here clear flag but it clear automatic*/
               }
     #else   
               INTERRRUPT_global_interrupt_enable();
               INTERRRUPT_peripheral_interrupt_enable();
   #endif  
#endif
            }
            else  if ( EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE == _eusart->usart_tx_cfg.usart_tx_enable ){
                 PIE1bits.TXIE = EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE;
            }
            else { /* No thing  */  }

            /* EUSART 9bit transmit configuration  */    
             if (EUSART_ASYNCHRONOUS_9Bit_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_9bit_enable  ){
                         TXSTAbits.TX9 =   EUSART_ASYNCHRONOUS_9Bit_TX_ENABLE;

             }
            else if (EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE == _eusart->usart_tx_cfg.usart_tx_9bit_enable){
                        TXSTAbits.TX9  =EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE;
            }
            else { /*  No thing  */  }
     }
      else { /*  No thing  */  }
 }
/**
 * 
 * @param _eusart
 */
 static void EUSART_ASYNC_RX_INIT(const usart_t *_eusart)  {
      if (EUSART_ASYNCHRONOUS_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_enable ){
          RCSTAbits.CREN = EUSART_ASYNCHRONOUS_RX_ENABLE ; 
          /*   EUSART INTERRUPT transmit configuration   */ 
            if ( EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_enable ){
                //PIE1bits.RCIE = EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE ;
#if EUSART_RX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
               EUSART_RX_InterruptEnable()   ;
               EUSART_rx_interrupt_handler =_eusart->EUSART_RxDefaultInterruptHandler;
               EUSART_framming_error_handler =_eusart->EUSART_FramingErrorHandler;
               EUSART_over_interrupt_handler = _eusart->EUSART_OverrunErrorHandler;
                       
    #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE             
               if(  INTERRUPT_HIGH_PRIORITy == _eusart->usart_rx_cfg.usart_rx_int_priority){
                   EUSART_RX_HighPrioritySet() ;
                     /*must here clear flag but it clear automatic*/
               }
               else if(INTERRRUPT_LOW_PRIORITY   == _eusart->usart_rx_cfg.usart_rx_int_priority){
                   EUSART_RX_LowPrioritySet() ;
                     /*must here clear flag but it clear automatic*/
               }
    #else 
               INTERRRUPT_global_interrupt_enable();
               INTERRRUPT_peripheral_interrupt_enable();
    #endif                        
#endif                
            }
            else  if ( EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE == _eusart->usart_rx_cfg.usart_rx_enable ){
                 PIE1bits.RCIE = EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE ;
            }
            else { /* No thing  */  }

            /* EUSART 9bit transmit configuration  */    
             if (EUSART_ASYNCHRONOUS_9Bit_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_9bit_enable  ){
                 RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9Bit_RX_ENABLE ;

             }
            else if (EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE == _eusart->usart_rx_cfg.usart_rx_9bit_enable){
                        RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE ;
            }
            else { /*  No thing  */  }
     }
      else { /*  No thing  */  }
 }

void EUSART_TX_ISR(){
    /* EUSART_TX interrupt occurred (clear automatic when sent data)*/
    #if EUSART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
   EUSART_TX_InterruptDisable()  ; 
#endif
    /*code */
    #if EUSART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

    /*callback function gets called every time this ISR executes*/
    if( EUSART_tx_interrupt_handler){EUSART_tx_interrupt_handler();}
     else {/*no thing*/}
#endif
} 

void EUSART_RX_ISR(){
    /* EUSART_TX interrupt occurred (clear automatic when sent data)*/
    
    /*code */
     #if EUSART_RX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    /*callback function gets called every time this ISR executes*/
    
    if( EUSART_rx_interrupt_handler){EUSART_rx_interrupt_handler();}
     else {/*no thing*/}
     if( EUSART_framming_error_handler){EUSART_framming_error_handler();}
     else {/*no thing*/}
    if( EUSART_over_interrupt_handler){EUSART_over_interrupt_handler();}
    else {/*no thing*/}
#endif
}