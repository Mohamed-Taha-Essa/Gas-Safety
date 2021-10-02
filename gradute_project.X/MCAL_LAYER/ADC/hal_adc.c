/* 
 * File:   hal_adc.c
 * Author: Mouhamed Essa
 */

#include "hal_adc.h"
#include "../Interrupt/mcal_internal_interrupt.h"


 #if ADC_INTERRUPT_FEATURE_ENABLE ==INTERRUPT_FEATURE_ENABLE 
static void (*ADC_Interrupt_handler)(void) = NULL;

#endif 

static inline void adc_input_channel_port_configure(const adc_channel_select_t _channel );
static inline void select_result_format(const adc_conf_t *_adc );
static inline void select_voltage_refrence(const adc_conf_t *_adc );
/**
 * @Summary Initializes the ADC
 * @Description This routine initializes the ADC.
 *              This routine must be called before any other ADC routine is called.
 *              This routine should only be called once during system initialization.
 * @Preconditions None
 * @param _adc Pointer to the ADC configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType ADC_Init(const adc_conf_t *_adc){
    
    std_ReturnType ret = E_Ok ;
     if(NULL == _adc )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
             /* Disable the ADC */
         ADC_CONVERTER_DISABLE();
         
          /* Configure the acquisition time */
           ADCON2bits.ACQT = _adc->adc_acquisition_time;
           /* Configure the conversion clock */
         ADCON2bits.ADCS = _adc->adc_conversion_clock ;
          /* Configure the default channel */
          ADCON0bits.CHS = _adc->adc_channel ;
          adc_input_channel_port_configure(_adc->adc_channel);
          /* Configure the interrupt */
          #if ADC_INTERRUPT_FEATURE_ENABLE ==INTERRUPT_FEATURE_ENABLE 
              ADC_InterruptEnable();
              ADC_InterruptFlagClear();
              #if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
              if (  INTERRUPT_HIGH_PRIORITy == _adc->priority){ ADC_HighPrioritySet() ;}
              else if (  INTERRRUPT_LOW_PRIORITY == _adc->priority){ ADC_LowPrioritySet() ;}
              else (\*  nothing *\)
             #endif 
          ADC_Interrupt_handler = _adc->ADC_InterruptHandler;
          #endif 
         /* Configure the result format */
         select_result_format(_adc);
         /* Configure the voltage reference */
         select_voltage_refrence(_adc);
           /* Enable the ADC */
         ADC_CONVERTER_ENABLE();
       }
     return ret ; 
  
}
/**
 * @Summary De-Initializes the ADC
 * @param _adc Pointer to the ADC configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType ADC_DeInit(const adc_conf_t *_adc){
    
    std_ReturnType ret = E_Ok ;
     if(NULL == _adc )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
          /* Disable the ADC */
         ADC_CONVERTER_DISABLE();
         /* Configure the interrupt */
        #if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE 

         ADC_InterruptDisable()   ;
        #endif 
       }
     return ret ; 
  
}
/**
 * @Summary Allows selection of a channel for conversion
 * @Description This routine is used to select desired channel for conversion.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 * @param _adc Pointer to the ADC configurations
 * @param channel Defines the channel available for conversion.
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType ADC_Select_Channel(const adc_conf_t *_adc ,adc_channel_select_t _channel ){
    
    std_ReturnType ret = E_Ok ;
     if(NULL == _adc )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
          ADCON0bits.CHS = _channel ;
          adc_input_channel_port_configure(_channel);
       }
     return ret ; 
  
}
/**
 * @Summary Starts conversion
 * @Description This routine is used to start conversion of desired channel.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 * @param _adc Pointer to the ADC configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType ADC_Start_Conversion(const adc_conf_t *_adc  ){
    
    std_ReturnType ret = E_Ok ;
     if(NULL == _adc )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         ADC_START_CONVERSION();
       }
     return ret ; 
  
}
/**
 * @Summary Returns true when the conversion is completed otherwise false.
 * @Description This routine is used to determine if conversion is completed.
 *              When conversion is complete routine returns true. It returns false otherwise.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 *                ADC_StartConversion() should have been called before calling this function.
 * @param _adc Pointer to the ADC configurations
 * @param conversion_status The conversion status
 *          true  - If conversion is complete
 *          false - If conversion is not completed
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType ADC_IsConversion_Done(const adc_conf_t *_adc, uint8 *conversion_status){
    
    std_ReturnType ret = E_Ok ;
     if((NULL == _adc) || (NULL== conversion_status) )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         *conversion_status = (uint8)(!ADCON0bits.GO_nDONE) ;
       }
     return ret ; 
  
}
/**
 * @Summary Returns the ADC conversion value.
 * @Description This routine is used to get the analog to digital converted value.
 *              This routine gets converted values from the channel specified.
 * @Preconditions   This routine returns the conversion value only after the conversion is complete.
 *                  Completion status can be checked using ADC_IsConversionDone() routine.
 * @param _adc Pointer to the ADC configurations
 * @param conversion_result The converted value.
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType ADC_Get_Conversion_Resulst(const adc_conf_t *_adc ,adc_result_t *conversion_result){
    
    std_ReturnType ret = E_Ok ;
     if((NULL == _adc) || (NULL== conversion_result))
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
          if(ADC_RESULT_FORMAT_RIGHT == _adc->result_format){
               *conversion_result = (adc_result_t)((ADRESH << 8) + ADRESL) ; 
            }     
            else if(ADC_RESULT_FORMAT_LEFT == _adc->result_format){
               *conversion_result = (adc_result_t)(((ADRESH << 8) + ADRESL)>>6) ; 

            }    
            else {
                ADC_RESULT_RIGHT();}
         
       }
     return ret ; 
  
}
/**
 * @Summary Returns the ADC conversion value, also allows selection of a channel for conversion.
 * @Description This routine is used to select desired channel for conversion.
 *              This routine is get the analog to digital converted value.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 * @param _adc Pointer to the ADC configurations
 * @param channel Defines the channel available for conversion.
 * @param conversion_result The converted value.
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType ADC_Get_Conversion_Blocking(const adc_conf_t *_adc ,adc_channel_select_t _channel
                                                    ,adc_result_t *conversion_result){
    
    std_ReturnType ret = E_Ok ;
    //uint8  l_conversion_status = ZERO_INIT ;
     if((NULL == _adc) || (NULL== conversion_result) )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         /*-------select A/D channel---------------- */
         ret = ADC_Select_Channel(_adc ,_channel );
         
          /*-------start A/D conversion---------------- */
         
         ret= ADC_Start_Conversion(_adc );
         
           /*-------check if A/D conversion is completed--(blocking)-------------- */
         while(ADCON0bits.GO_nDONE);
                 ret = ADC_Get_Conversion_Resulst(_adc ,conversion_result );
                 
                 //not blocking use in interrupt
//         ret= ADC_IsConversion_Done(_adc , &l_conversion_status);
//         if(ADC_CONVERSION_COMPLETED == l_conversion_status){
//             ret = ADC_Get_Conversion_Resulst(_adc ,conversion_result );
//         }
//         else {
//             ret = E_NOT_Ok ;
//         }

       }
     return ret ; 
  
}
/**
 * 
 * @param _channel
 * @Description :Helper function
 * @Description :take channel and make the pin of channel work as input by SET_BIT 
 */
static inline void adc_input_channel_port_configure(const adc_channel_select_t _channel ){
    switch(_channel){
            case ADC_CHANNEL_0 : SET_BIT(TRISA , _TRISA_RA0_POSN);break;
            case ADC_CHANNEL_1 : SET_BIT(TRISA , _TRISA_RA1_POSN);break;
            case ADC_CHANNEL_2 : SET_BIT(TRISA , _TRISA_RA2_POSN);break;
            case ADC_CHANNEL_3 : SET_BIT(TRISA , _TRISA_RA3_POSN);break;
            case ADC_CHANNEL_4 : SET_BIT(TRISA , _TRISA_RA5_POSN);break;
            case ADC_CHANNEL_5 : SET_BIT(TRISA , _TRISE_RE0_POSN);break;
            case ADC_CHANNEL_6 : SET_BIT(TRISA , _TRISE_RE1_POSN);break;
            case ADC_CHANNEL_7 : SET_BIT(TRISA , _TRISE_RE2_POSN);break;
            case ADC_CHANNEL_8 : SET_BIT(TRISA , _TRISB_RB2_POSN);break;
            case ADC_CHANNEL_9 : SET_BIT(TRISA , _TRISB_RB3_POSN);break;
            case ADC_CHANNEL_10: SET_BIT(TRISA , _TRISB_RB1_POSN);break;
            case ADC_CHANNEL_11: SET_BIT(TRISA , _TRISB_RB4_POSN);break;
            case ADC_CHANNEL_12: SET_BIT(TRISA , _TRISB_RB0_POSN);break;
            default :/*no thing */;
    }
}
/**
 * 
 * @param _adc
 * @Description :Helper function
 * @Description :select format right or left

 */
static inline void select_result_format(const adc_conf_t *_adc ){
 if(ADC_RESULT_FORMAT_RIGHT == _adc->result_format){
     ADC_RESULT_RIGHT();
 }     
 else if(ADC_RESULT_FORMAT_LEFT == _adc->result_format){
     ADC_RESULT_LEFT();
 }    
 else {
     ADC_RESULT_RIGHT();}
}
/**
 * 
 * @param _adc
 * @Description :Helper function
 * @Description :select_voltage_refrence enable or disable 

 */
static inline void select_voltage_refrence(const adc_conf_t *_adc ){
 if(ADC_VOLTAGE_REFERENCE_ENABLED == _adc->voltage_reference){
     ADC_ENABLE_VOLTAGE_REFERENCE();
 }     
 else if(ADC_VOLTAGE_REFERENCE_DISABLED == _adc->voltage_reference){
     ADC_DISABLE_VOLTAGE_REFERENCE();
 }    
 else{ADC_DISABLE_VOLTAGE_REFERENCE();}
}
/**
 * @Summary Returns the ADC conversion value, also allows selection of a channel for conversion.
 * @Description This routine is used to select desired channel for conversion.
 *              This routine is get the analog to digital converted value.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 * @param _adc Pointer to the ADC configurations
 * @param channel Defines the channel available for conversion.
 * @param conversion_result The converted value.
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType ADC_Start_Conversion_Interrupt(const adc_conf_t *_adc ,adc_channel_select_t _channel){
    
    std_ReturnType ret = E_Ok ;
    //uint8  l_conversion_status = ZERO_INIT ;
     if((NULL == _adc) )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         /*-------select A/D channel---------------- */
         ret = ADC_Select_Channel(_adc ,_channel );
         
          /*-------start A/D conversion---------------- */
         
         ret= ADC_Start_Conversion(_adc );

                 
                 //not blocking use in interrupt
//         ret= ADC_IsConversion_Done(_adc , &l_conversion_status);
//         if(ADC_CONVERSION_COMPLETED == l_conversion_status){
//             ret = ADC_Get_Conversion_Resulst(_adc ,conversion_result );
//         }
//         else {
//             ret = E_NOT_Ok ;
//         }

       }
     return ret ; 
  
}
void ADC_ISR(void){
       ADC_InterruptFlagClear();
       if (ADC_Interrupt_handler)
       {
           ADC_Interrupt_handler();
       }
}