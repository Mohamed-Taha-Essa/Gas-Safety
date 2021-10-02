/* 
 * File:   mcal_external_interrupt.c
 * Author: mohamed
 *
 * Created on May 23, 2021, 2:36 PM
 */
#include "mcal_external_interrupt.h"
static void (*INT0_Interrupt_handler)(void) = NULL;
static void (*INT1_Interrupt_handler)(void) = NULL;
static void (*INT2_Interrupt_handler)(void) = NULL;

static std_ReturnType Interrupt_Intx_enable(const interrupt_Intx_t *interr_obj);
static std_ReturnType Interrupt_Intx_disable(const interrupt_Intx_t *interr_obj);
static std_ReturnType Interrupt_Intx_priority_init(const interrupt_Intx_t *interr_obj);
static std_ReturnType Interrupt_Intx_edge_init(const interrupt_Intx_t *interr_obj);
static std_ReturnType Interrupt_Intx_pin_init(const interrupt_Intx_t *interr_obj);
static std_ReturnType Interrupt_Intx_clear_flag(const interrupt_Intx_t *interr_obj);

static std_ReturnType INT0_set_interrupt_handler(void (*INT_Interrupt_handler)(void));
static std_ReturnType INT1_set_interrupt_handler(void (*INT_Interrupt_handler)(void));
static std_ReturnType INT2_set_interrupt_handler(void (*INT_Interrupt_handler)(void));
/*will call any one from  INT0 or INT1 or INT2 _set_interrupt_handler 
 * consist of value of  INT_Interrupt_handler */
static std_ReturnType  Interrupt_Intx_set_interrupt_handler(const interrupt_Intx_t *interr_obj);
/*=============================interrupt function=========================================*/
/**
 * 
 * @param interr_obj
 * @return 
 */
std_ReturnType Interrupt_Intx_init(const interrupt_Intx_t *interr_obj){
     std_ReturnType ret = E_NOT_Ok;
    if( NULL==interr_obj ){
       ret = E_NOT_Ok;
    }
    else {
       /*disable the external interrupt*/
        ret = Interrupt_Intx_disable(interr_obj);
        /*clear the interrupt flag :external interrupt didn't occur*/
        ret = Interrupt_Intx_clear_flag(interr_obj) ;
        /*configure external interrupt edge */
        ret =Interrupt_Intx_edge_init(interr_obj);
        #if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
        /*configure external interrupt priority */
        ret =Interrupt_Intx_priority_init(interr_obj);
        /*configure external interrupt I/O pin */
        #endif
        ret =Interrupt_Intx_pin_init(interr_obj);
        /*configure external default interrupt callback */
          ret =  Interrupt_Intx_set_interrupt_handler(interr_obj);
        /*enable the external interrupt*/
        ret =Interrupt_Intx_enable(interr_obj);
    }
     return ret ;
}

void INT0_ISR(void){
  #if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE    ==    INTERRUPT_FEATURE_ENABLE

    /*the INT0 external interrupt occurred (must be cleared in software)*/
    EXT_INT1_flag_clear();
#endif
    /*code */
    
    /*callback function gets called every time this ISR executes*/
    if( INT0_Interrupt_handler){
         INT0_Interrupt_handler() ;
    }
}
void INT1_ISR(void){
  #if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE    ==    INTERRUPT_FEATURE_ENABLE

    /*the INT1 external interrupt occurred (must be cleared in software)*/
    EXT_INT1_flag_clear();
    /*code */
#endif
    /*callback function gets called every time this ISR executes*/
    if( INT1_Interrupt_handler){
         INT1_Interrupt_handler() ;
    }
}
void INT2_ISR(void){
     /*the INT2 external interrupt occurred (must be cleared in software)*/
#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE    ==    INTERRUPT_FEATURE_ENABLE

    EXT_INT1_flag_clear();
    /*code */
#endif 
    /*callback function gets called every time this ISR executes*/
    if( INT2_Interrupt_handler){
         INT2_Interrupt_handler() ;
    }
}
/**
 * 
 * @param interr_obj
 * @return 
 */
std_ReturnType Interrupt_Intx_deinit(const interrupt_Intx_t *interr_obj){
    std_ReturnType  ret = E_NOT_Ok;
    if( NULL==interr_obj ){
       ret = E_NOT_Ok;
    }
    else {
        ret = Interrupt_Intx_disable(interr_obj);
    }
    return ret ;
}
std_ReturnType Interrupt_RBx_init(const interrupt_RBx_t *interr_obj){
    
}
std_ReturnType Interrupt_RBx_deinit(const interrupt_RBx_t *interr_obj){
        
}

/*----------------------  HELPER FUNCTION-----------------------------------*/
//enable int0 ,int1 ,int2
/**
 * 
 * @param interr_obj
 * @return 
 */
static std_ReturnType Interrupt_Intx_enable(const interrupt_Intx_t *interr_obj){
    std_ReturnType ret = E_NOT_Ok;
    if( NULL==interr_obj ){
       ret = E_NOT_Ok;
    }
    else {
        switch(interr_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
                EXT_INT0_interrupt_enable();
                #if INTERRUPT_PRIORITY_LEVELS_ENABLE  !=   INTERRUPT_FEATURE_ENABLE
                INTERRRUPT_global_interrupt_enable();
                INTERRRUPT_peripheral_interrupt_enable();
                #endif 
                ret= E_Ok;

            break;
            case INTERRUPT_EXTERNAL_INT1 : EXT_INT1_interrupt_enable();
                 #if INTERRUPT_PRIORITY_LEVELS_ENABLE  !=   INTERRUPT_FEATURE_ENABLE
                INTERRRUPT_global_interrupt_enable();
                INTERRRUPT_peripheral_interrupt_enable();
                #endif 
                 ret= E_Ok;
                 break;
            case INTERRUPT_EXTERNAL_INT2:
                EXT_INT2_interrupt_enable();
                #if INTERRUPT_PRIORITY_LEVELS_ENABLE  !=   INTERRUPT_FEATURE_ENABLE
                INTERRRUPT_global_interrupt_enable();
                INTERRRUPT_peripheral_interrupt_enable();
               #endif 
                ret= E_Ok;
                break; 
           default: ret = E_NOT_Ok; ; 
         }
       }
    return ret ;
}
/**
 * 
 * @param interr_obj
 * @return 
 */
static std_ReturnType Interrupt_Intx_disable(const interrupt_Intx_t *interr_obj){
     std_ReturnType ret = E_NOT_Ok;
    if( NULL==interr_obj ){
       ret = E_NOT_Ok;
    }
    else {
       switch(interr_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : EXT_INT0_interrupt_disable();ret= E_Ok; break;
            case INTERRUPT_EXTERNAL_INT1 : EXT_INT1_interrupt_disable();ret= E_Ok; break;
            case INTERRUPT_EXTERNAL_INT2: EXT_INT2_interrupt_disable();ret= E_Ok; break; 
            default: ret = E_NOT_Ok; ; 
         }
    }
    return ret ;
}

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/**
 * 
 * @param interr_obj
 * @return 
 */
static std_ReturnType Interrupt_Intx_priority_init(const interrupt_Intx_t *interr_obj){
     std_ReturnType ret = E_NOT_Ok;
    if( NULL==interr_obj ){
       ret = E_NOT_Ok;
    }
    else {
        switch(interr_obj->source){
            
            case INTERRUPT_EXTERNAL_INT1 : 
                if(INTERRRUPT_LOW_PRIORITY==interr_obj->priority ){
                    EXT_INT1_low_priority();
                  
                }
                else if(INTERRUPT_HIGH_PRIORITy == interr_obj->priority){
                    EXT_INT1_high_priority();
                    
                }
                else{/*NO thing*/}
                ret = E_Ok;
                        break;
            case INTERRUPT_EXTERNAL_INT2:  
                if(INTERRRUPT_LOW_PRIORITY==interr_obj->priority ){
                    EXT_INT2_low_priority();
               
                }
                else if(INTERRUPT_HIGH_PRIORITy == interr_obj->priority){
                    EXT_INT2_high_priority();
                }
                else{/*NO thing*/} break; 
                 ret = E_Ok;

            default: ret = E_NOT_Ok; ; 
    
        }
    }
    return ret ;
}
#endif
/**
 * 
 * @param interr_obj
 * @return 
 */
static std_ReturnType Interrupt_Intx_edge_init(const interrupt_Intx_t *interr_obj){
     std_ReturnType ret = E_NOT_Ok;
    if( NULL==interr_obj ){
       ret = E_NOT_Ok;
    }
    else {
     switch(interr_obj->source){
            
          case INTERRUPT_EXTERNAL_INT0 : 
                if(INTERRUPT_FALLING_EDGE==interr_obj->edge ){
                   EXT_INT0_falling_edg_set() ;
                  
                }
                else if(INTERRUPT_RISING_EDGE==interr_obj->edge){
                    EXT_INT0_rising_edg_set() ;
                    
                }
                else{/*NO thing*/}
                ret = E_Ok;
                        break;
            case INTERRUPT_EXTERNAL_INT1 : 
                if(INTERRUPT_FALLING_EDGE==interr_obj->edge ){
                   EXT_INT1_falling_edg_set() ;
                  
                }
                else if(INTERRUPT_RISING_EDGE==interr_obj->edge){
                    EXT_INT1_rising_edg_set() ;
                    
                }
                else{/*NO thing*/}
                ret = E_Ok;
                        break;
            case INTERRUPT_EXTERNAL_INT2 : 
                if(INTERRUPT_FALLING_EDGE==interr_obj->edge ){
                   EXT_INT2_falling_edg_set() ;
                  
                }
                else if(INTERRUPT_RISING_EDGE==interr_obj->edge){
                    EXT_INT2_rising_edg_set() ;
                    
                }
                else{/*NO thing*/}
                ret = E_Ok;
                        break;
                 ret = E_Ok;

            default: ret = E_NOT_Ok; ; 
    
        }
        }
    
    return ret ;
}
/**
 * 
 * @param interr_obj
 * @return 
 */
static std_ReturnType Interrupt_Intx_pin_init(const interrupt_Intx_t *interr_obj){
     std_ReturnType ret = E_NOT_Ok;
    if( NULL==interr_obj ){
       ret = E_NOT_Ok;
    }
    else {
        ret = gpio_pin_direction_initialize(&(interr_obj->mcu_pin));
    }
    return ret ;
}
/**
 * 
 * @param interr_obj
 * @return 
 */
static std_ReturnType Interrupt_Intx_clear_flag(const interrupt_Intx_t *interr_obj){
     std_ReturnType ret = E_NOT_Ok;
    if( NULL==interr_obj ){
       ret = E_NOT_Ok;
    }
    else {
       switch(interr_obj->source){
            
          case INTERRUPT_EXTERNAL_INT0 : 
                 EXT_INT0_flag_clear();
                ret = E_Ok;
                        break;
            case INTERRUPT_EXTERNAL_INT1 : 
                 EXT_INT1_flag_clear();
                ret = E_Ok;
                        break;
            case INTERRUPT_EXTERNAL_INT2 : 
                EXT_INT2_flag_clear();
                    ret = E_Ok;
                        break;
             

            default: ret = E_NOT_Ok; ; 
    
        }
    }
    return ret ;
}
/**
 * 
 * @param INT_Interrupt_handler
 * @return 
 */
static std_ReturnType INT0_set_interrupt_handler(void (*INT_Interrupt_handler)(void)){
     std_ReturnType ret = E_NOT_Ok;
    if( NULL == INT_Interrupt_handler){
       ret = E_NOT_Ok;
    }
    else {
        INT0_Interrupt_handler = INT_Interrupt_handler;
         ret = E_NOT_Ok;
    }
    return ret ;
}
/**
 * 
 * @param INT_Interrupt_handler
 * @return 
 */
static std_ReturnType INT1_set_interrupt_handler(void (*INT_Interrupt_handler)(void)){
     std_ReturnType ret = E_NOT_Ok;
    if( INT_Interrupt_handler){
       ret = E_NOT_Ok;
    }
    else {
       INT1_Interrupt_handler = INT_Interrupt_handler;
         ret = E_NOT_Ok;
    }
    return ret ;
}
/**
 * 
 * @param INT_Interrupt_handler
 * @return 
 */
static std_ReturnType INT2_set_interrupt_handler(void (*INT_Interrupt_handler)(void)){
     std_ReturnType ret = E_NOT_Ok;
    if( INT_Interrupt_handler){
       ret = E_NOT_Ok;
    }
    else {
       INT2_Interrupt_handler = INT_Interrupt_handler;
         ret = E_NOT_Ok;
    }
    return ret ;
}
/**
 * 
 * @param interr_obj
 * @return 
 */
static std_ReturnType  Interrupt_Intx_set_interrupt_handler(const interrupt_Intx_t *interr_obj){
     std_ReturnType ret = E_NOT_Ok;
    if( NULL==interr_obj ){
       ret = E_NOT_Ok;
    }
    else {
       switch(interr_obj->source){
           case INTERRUPT_EXTERNAL_INT0:
          ret = INT0_set_interrupt_handler(interr_obj->EXTERNAL_interrupt_handler);
                ret = E_Ok;
                        break;
            case INTERRUPT_EXTERNAL_INT1 : 
               ret =  INT1_set_interrupt_handler(interr_obj->EXTERNAL_interrupt_handler);
                ret = E_Ok;
                        break;
            case INTERRUPT_EXTERNAL_INT2 : 
               ret = INT2_set_interrupt_handler(interr_obj->EXTERNAL_interrupt_handler);
               ret = E_Ok;
                        break;
                 

            default: ret = E_NOT_Ok; ; 
    
        }
    }
    return ret ;
}