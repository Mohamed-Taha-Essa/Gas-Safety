
#include "gsm.h"
std_ReturnType gsm_send_message(void){
     std_ReturnType ret = E_NOT_Ok   ;
      ret= EUSART_ASYNC_WriteStringBlocking("AT\r\n",4);
     
            __delay_ms(1000);
      
        ret= EUSART_ASYNC_WriteStringBlocking("AT+CMGF=1\r\n",11);
         __delay_ms(1000);
      
 ret= EUSART_ASYNC_WriteStringBlocking("AT+CMGS=\"+21097912260\"\r\n",25);
  __delay_ms(2000);
   ret= EUSART_ASYNC_WriteStringBlocking("I'm gsm\r\n",9);
    __delay_ms(1000);
       ret= EUSART_ASYNC_WriteStringBlocking("\x1a",3);
      __delay_ms(1000);
    
}

std_ReturnType gsm_make_call(void){
     std_ReturnType ret = E_NOT_Ok   ;
      ret= EUSART_ASYNC_WriteStringBlocking("AT\r\n",4);
     
            __delay_ms(2000);
      
        ret= EUSART_ASYNC_WriteStringBlocking("AT+CPIN?\r\n",10);
         __delay_ms(2000);
      
 ret= EUSART_ASYNC_WriteStringBlocking("AT+CSQ\r\n",8);
  __delay_ms(2000);
   ret= EUSART_ASYNC_WriteStringBlocking("AT+COPS?\r\n",10);
    __delay_ms(3000);
       ret= EUSART_ASYNC_WriteStringBlocking("AT+CREG?\r\n",10);
    __delay_ms(3000);

 ret= EUSART_ASYNC_WriteStringBlocking("ATD01097912260;\r\n",17);
 
    __delay_ms(25000);
}

std_ReturnType gsm_send_data_to_server(uint16 data_gas ,uint16 data_heat){
     std_ReturnType ret = E_NOT_Ok   ;
     uint16 Gas,Heat ;
      ret= EUSART_ASYNC_WriteStringBlocking("AT\r\n",4);
            __delay_ms(2000);
        ret= EUSART_ASYNC_WriteStringBlocking("AT+CPIN?\r\n",10);
         __delay_ms(1000);
       ret= EUSART_ASYNC_WriteStringBlocking("AT+CGATT?\r\n",11);
    __delay_ms(1000);
    
    ret= EUSART_ASYNC_WriteStringBlocking("AT+CIPSTATUS\r\n",14);
    __delay_ms(2000);
    ret= EUSART_ASYNC_WriteStringBlocking("AT+CIPMUX=0\r\n",13);
    __delay_ms(2000);
     ret= EUSART_ASYNC_WriteStringBlocking("AT+CSTT=\"mobinilweb\",\"\",\"\"\r\n",28);                //when using sim orange 
      //  ret= EUSART_ASYNC_WriteStringBlocking("AT+CSTT=\"internet.vodafone.net\",\"\",\"\"\r\n",39);//when using sim vodafone
  __delay_ms(1000);
        ret= EUSART_ASYNC_WriteStringBlocking("AT+CIICR\r\n",10);
    __delay_ms(5000);
      ret= EUSART_ASYNC_WriteStringBlocking("AT+CIFSR\r\n",10);
    __delay_ms(5000);
        ret= EUSART_ASYNC_WriteStringBlocking("AT+CIPSTART=\"TCP\",\"3.224.183.135\",80\r\n",38);  // changing ip if it changed when testing 
    __delay_ms(25000);
      ret= EUSART_ASYNC_WriteStringBlocking("AT+CIPSEND=44\r\n",15);
    __delay_ms(5000);
       ret= EUSART_ASYNC_WriteStringBlocking("GET https://gazsafety.herokuapp.com/embaded/60fc55ebb8a5ec0015baec12/",69);
             
       ret = convert_uint32_to_string(data_gas ,&Gas) ;                                          //convert value to string 
      ret= EUSART_ASYNC_WriteStringBlocking(&Gas,4);
      Gas=0;
       ret= EUSART_ASYNC_WriteStringBlocking("/",1);
            ret = convert_uint8_to_string(data_heat ,&Heat);                                      //convert value to string 

             ret= EUSART_ASYNC_WriteStringBlocking(&Heat,4);
             ret= EUSART_ASYNC_WriteStringBlocking("\r\n",2);

            Heat=0;
            __delay_ms(25000);
        
return ret ;
}