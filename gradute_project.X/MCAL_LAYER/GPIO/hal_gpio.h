/* 
 * File  :   hal_gpio.h
 * Author: Taha
 *
 * Created on December 17, 2020, 9:09 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* section : includes */

#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h" 
#include "hal_gpio_cfg.h"
/*Section : Macro Declaration  */
#define _XTAL_FREQ 8000000UL 


#define BIT_MASK    (uint8)1

#define PORT_PIN_MAX_NUMBER  8 
#define PORT_MAX_NUMBER      5
#define PORTC_MASK           0xFF

#define GPIO_PORT_PIN_CONFIGURATIOS  CONFIG_ENABLE 
#define GPIO_PORT_CONFIGURATIOS      CONFIG_ENABLE

/*Section : Macro Function  Declaration  */

#define HWREG(_X)       (*((volatile uint8*)(_X)))

#define SET_BIT(REG , BIT_POSITION)         (REG |= (BIT_MASK << BIT_POSITION))
#define CLEAR_BIT(REG , BIT_POSITION)       (REG &=~ (BIT_MASK << BIT_POSITION))
#define TOGGLE_BIT(REG , BIT_POSITION)       (REG ^= (BIT_MASK << BIT_POSITION))
#define READ_BIT(REG , BIT_POSITION)       ((REG >> BIT_POSITION) & (BIT_MASK ))

/*Section : Data Type Declaration  */
typedef enum {
    GPIO_LOW = 0 ,
    GPIO_HIGH
}logic_t;

typedef enum {
    GPIO_DIRECTION_OUTPUT = 0 ,
    GPIO_DIRECTION_INPUT
}direction_t;

typedef enum {
    GPIO_PIN0 = 0 ,
    GPIO_PIN1 ,
    GPIO_PIN2 ,
    GPIO_PIN3 ,
    GPIO_PIN4 ,
    GPIO_PIN5 ,
    GPIO_PIN6 ,
    GPIO_PIN7    
}pint_index_t;

typedef enum {
    PORTA_INDEX = 0 ,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX           
}port_index_t;

typedef struct {
    uint8 Port       :3;// 101
    uint8 pin        :3;
    uint8 direction  :1; //0 1
    uint8 logic      :1; //0 1
}pin_config_t;

/*Section : Function Declaration  */
std_ReturnType gpio_pin_direction_initialize(const pin_config_t *pin_config);
std_ReturnType gpio_pin_get_direction_status(const pin_config_t *pin_config , direction_t *direc_status);
std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config , logic_t logic);
 std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config , logic_t *logic);
 std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_config );
 std_ReturnType gpio_pin_initialize(const pin_config_t *pin_config);

 
 
std_ReturnType gpio_port_direction_initialize(port_index_t port ,uint8 direction);
std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *direction_status );
std_ReturnType gpio_port_write_logic(port_index_t port , uint8 logic);
std_ReturnType gpio_port_read_logic(port_index_t port , uint8 *logic);
std_ReturnType gpio_port_toggle_logic(port_index_t port );






#endif	/* HAL_GPIO_H */

