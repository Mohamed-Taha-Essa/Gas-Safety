/* 
 * File:   hal_gpio.c
 * Author: Taha
 *
 * Created on December 3, 2020, 10:43 AM
 */
#include "hal_gpio.h"
/*Reference to the Data Direction Control Registers*/
volatile uint8 *tris_registers[] = { &TRISA , &TRISB , &TRISC , &TRISD , &TRISE };
/*Reference to the Data Latch Registers(Read & Write Data Latch)*/
volatile uint8 *lat_registers[]  = { &LATA , &LATB , &LATC , &LATD , &LATE };
/*Reference to Port status Registers*/
volatile uint8 *port_registers[] = { &PORTA , &PORTB , &PORTC , &PORTD , &PORTE };

/*function initialize pin to be input or output*/

#if GPIO_PORT_PIN_CONFIGURATIOS == CONFIG_ENABLE 

 std_ReturnType gpio_pin_initialize(const pin_config_t *pin_config)
 {
     std_ReturnType ret = E_Ok ;
      if(NULL == pin_config ||pin_config->pin > PORT_PIN_MAX_NUMBER -1 )
    {
     ret = E_NOT_Ok ;  
    }
    else
    {
        ret =  gpio_pin_direction_initialize(pin_config);
        ret = gpio_pin_write_logic(pin_config ,pin_config->logic) ;
    
    }
     
   return ret ;  
 }
#endif 

/**
 * 
 * @param pin_config
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATIOS == CONFIG_ENABLE 
std_ReturnType gpio_pin_direction_initialize(const pin_config_t *pin_config){
    std_ReturnType ret = E_Ok ;
    if(NULL == pin_config ||pin_config->pin > PORT_PIN_MAX_NUMBER -1 )
    {
     ret = E_NOT_Ok ;  
    }
    else {
        switch(pin_config->direction)
           {
                case GPIO_DIRECTION_OUTPUT  :
                    CLEAR_BIT(*tris_registers[pin_config->Port] ,pin_config->pin);
                break ;

                case GPIO_DIRECTION_INPUT : 
                    SET_BIT (*tris_registers[pin_config->Port] , pin_config->pin);
                break;
                default : ret = E_NOT_Ok;
           }     
        }
      
    return ret ;        
}   
#endif
/**
 * 
 * @param pin_config
 * @param direc_status
 * @return 
 */


#if GPIO_PORT_PIN_CONFIGURATIOS == CONFIG_ENABLE 

std_ReturnType gpio_pin_get_direction_status(const pin_config_t *pin_config , direction_t *direc_status){
    std_ReturnType ret = E_Ok ;
    if(NULL == pin_config || NULL == direc_status ||pin_config->pin > PORT_PIN_MAX_NUMBER -1)
    {
         ret = E_NOT_Ok ; 
    }

    else 
    {
       *direc_status =  READ_BIT (*tris_registers[pin_config->Port] ,pin_config->pin) ;
    }
     return ret ; 
}
#endif
/**
 * 
 * @param pin_config
 * @param logic
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATIOS == CONFIG_ENABLE 

std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config , logic_t logic)
{
    std_ReturnType ret = E_Ok ;
    if(NULL == pin_config ||pin_config->pin > PORT_PIN_MAX_NUMBER -1 )
    {
        ret = E_NOT_Ok ; 
    }

    else 
    {
        switch(logic)
        {
            case GPIO_LOW :
                CLEAR_BIT(*lat_registers[pin_config->Port] ,pin_config->pin);
                
                break ;
            
            case GPIO_HIGH :
                SET_BIT(*lat_registers[pin_config->Port] ,pin_config->pin);

                break ;
                
            default : ret = E_NOT_Ok;
        }
    }
     return ret ; 
}
#endif
/**
 * 
 * @param pin_config
 * @param logic
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATIOS == CONFIG_ENABLE 

 std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config , logic_t *logic)
 {
    std_ReturnType ret = E_Ok ;
    if(NULL == pin_config || NULL == logic || pin_config->pin > PORT_PIN_MAX_NUMBER -1)
      {
        ret = E_NOT_Ok ; 
      }

    else 
      {
              *logic =  READ_BIT (*port_registers[pin_config->Port] ,pin_config->pin) ;

      }
     return ret ; 
}
 #endif
 /**
  * 
  * @param pin_config
  * @return 
  */
 #if GPIO_PORT_PIN_CONFIGURATIOS == CONFIG_ENABLE 

 std_ReturnType gpio_pin_toggle_logic( const pin_config_t *pin_config )
 {
    std_ReturnType ret = E_Ok ;
    if(NULL == pin_config || pin_config->pin > PORT_PIN_MAX_NUMBER -1 )
     {
      ret = E_NOT_Ok ; 
     }

    else 
     {
        TOGGLE_BIT(*lat_registers[pin_config->Port] ,pin_config->pin);
     }

     return ret ; 
}
 #endif
 /**
  * 
  * @param port
  * @param direction
  * @return 
  */
#if GPIO_PORT_CONFIGURATIOS   ==   CONFIG_ENABLE

std_ReturnType gpio_port_direction_initialize(port_index_t port , uint8 direction)
{
    std_ReturnType ret = E_Ok ;
    if(port > PORT_MAX_NUMBER -1)
    {
        ret = E_NOT_Ok  ;
    }
    else 
    {
        *tris_registers[port] = direction ;
    }
     return ret ; 
}
#endif
/**
 * 
 * @param port
 * @param direc_status
 * @return 
 */
#if GPIO_PORT_CONFIGURATIOS   ==   CONFIG_ENABLE

std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *direction_status )
{
    std_ReturnType ret = E_Ok ;
    if((NULL == direction_status) || (port > PORT_MAX_NUMBER -1))
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         *direction_status = *tris_registers[port] ;
       }
     return ret ; 
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
#if GPIO_PORT_CONFIGURATIOS   ==   CONFIG_ENABLE

std_ReturnType gpio_port_write_logic(port_index_t port , uint8 logic)
{
    std_ReturnType ret = E_Ok ;
    if (port  >PORT_MAX_NUMBER -1 )
    {
          ret = E_NOT_Ok ; 
    }
    else 
    {
        *lat_registers[port] = logic ;
    }
     return ret ; 
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return 
 */

#if GPIO_PORT_CONFIGURATIOS   ==   CONFIG_ENABLE

std_ReturnType gpio_port_read_logic(port_index_t port , uint8 *logic)
{
    std_ReturnType ret = E_Ok ;

    if( NULL == logic || (port > PORT_MAX_NUMBER - 1) )

    {
       ret = E_NOT_Ok ; 
    }
    else 
    {
        *logic = *lat_registers[port] ;
    }
     return ret ; 
}
#endif

/**
 * 
 * @param port
 * @return 
 */
#if GPIO_PORT_CONFIGURATIOS   ==   CONFIG_ENABLE

std_ReturnType gpio_port_toggle_logic(port_index_t port )
{
    std_ReturnType ret = E_Ok ;
    if ( port > PORT_MAX_NUMBER - 1)
    {
            ret = E_NOT_Ok ;    
    }
    else 
    {
        *lat_registers[port] ^= PORTC_MASK ;
    }
     return ret ; 
}
#endif