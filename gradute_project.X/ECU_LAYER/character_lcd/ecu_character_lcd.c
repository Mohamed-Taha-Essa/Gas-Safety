/* 
 * File:   ecu_character_lcd.c
 * Author: Mohamed Essa
 *
 * Created on April 9, 2021, 5:13 PM
 */
#include "ecu_character_lcd.h"

//helper function 4bit_lcd
static std_ReturnType lcd_send_4bit (const char_lcd_4bit_t *lcd ,uint8 _data_command );
static std_ReturnType lcd_4bit_set_enable_signal (const char_lcd_4bit_t *lcd);
static std_ReturnType lcd_4bit_set_cursor (const char_lcd_4bit_t *lcd , uint8 row , uint8 column);

//helper function 8bit_lcd
static std_ReturnType lcd_send_8bit (const char_lcd_4bit_t *lcd ,uint8 _data_command );
static std_ReturnType lcd_8bit_set_enable_signal (const char_lcd_8bit_t *lcd);
static std_ReturnType lcd_8bit_set_cursor (const char_lcd_8bit_t *lcd , uint8 row , uint8 column);


////////////////////////////////////////////////////////////////////////////////////////////
/**
 * 
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_intialize(const char_lcd_4bit_t *lcd){
    std_ReturnType ret = E_Ok ;
    uint8 l_data_counter = ZERO_INIT;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         ret = gpio_pin_initialize(&lcd->lcd_regester_select);
         ret = gpio_pin_initialize(&lcd->lcd_enable);
         for(l_data_counter = ZERO_INIT ; l_data_counter<4 ;l_data_counter++ ){
              ret = gpio_pin_initialize(&(lcd->lcd_data[l_data_counter]));
         }
         //send command to initialize lcd (from data sheet)
            //initialization steps from data sheet 
      __delay_ms(20);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_4bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_4bit_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(lcd, 0x80);
      

    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_send_command(const char_lcd_4bit_t *lcd, uint8 command){
    std_ReturnType ret = E_Ok ;
     if(NULL == lcd )
      {
          /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
        /* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
        ret = gpio_pin_write_logic(&(lcd->lcd_regester_select), GPIO_LOW);
        /* Send the Command through the (4-Pins" Data lines */
        ret = lcd_send_4bit(lcd, command >> 4);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_4bit_set_enable_signal(lcd);
        /* Send the Command through the (4-Pins" Data lines */
        ret = lcd_send_4bit(lcd, command);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_4bit_set_enable_signal(lcd);
      }
    else 
       {
         //make select register = 0  to know i will send command not data (send to instruction register in
         //                                                                 microcontroller inside lcd )
         ret = gpio_pin_write_logic(&(lcd->lcd_regester_select),GPIO_LOW);
         //send command high 4 bit (4 bit in left side frome register 8 bit)
         ret = lcd_send_4bit(lcd ,command>>4);
         //set bit enable every once send data or command
         ret = lcd_4bit_set_enable_signal(lcd) ;
        //send command low 4 bit (4 bit in right side frome register 8 bit)

         ret = lcd_send_4bit(lcd ,command);
         //set bit enable every once send data or command
         ret = lcd_4bit_set_enable_signal(lcd) ;
      
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_send_char_data(const char_lcd_4bit_t *lcd, uint8 data){
    std_ReturnType ret = E_Ok ;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
           //make select register = 1 to know i will send command not data (send to data register in
         //                                                                 microcontroller inside lcd )
         ret = gpio_pin_write_logic(&(lcd->lcd_regester_select),GPIO_HIGH);
         //send command high 4 bit (4 bit in left side frome register 8 bit)
         ret = lcd_send_4bit(lcd ,data >> 4);
         //set bit enable every once send data or command
         ret = lcd_4bit_set_enable_signal(lcd) ;
        //send command low 4 bit (4 bit in right side frome register 8 bit)

         ret = lcd_send_4bit(lcd ,data);
         //set bit enable every once send data or command
         ret = lcd_4bit_set_enable_signal(lcd) ;
      
      
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_send_char_data_pos(const char_lcd_4bit_t *lcd,uint8 row, uint8 column, uint8 data){
    std_ReturnType ret = E_Ok ;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         ret =  lcd_4bit_set_cursor(lcd ,row , column);
         ret =  lcd_4bit_send_char_data(lcd ,data );
         
      
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_send_string(const char_lcd_4bit_t *lcd, uint8 *str){
    std_ReturnType ret = E_Ok ;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
          while(*str){
         ret = lcd_4bit_send_char_data(lcd ,*str) ;
         str++;
         }
         
      
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_send_string_pos(const char_lcd_4bit_t *lcd, uint8 row, uint8 column, uint8 *str){
    std_ReturnType ret = E_Ok ;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
          ret =  lcd_4bit_set_cursor(lcd ,row , column);

          while(*str){
         ret = lcd_4bit_send_char_data(lcd ,*str) ;
         str++;
         }
      
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_send_custom_char(const char_lcd_4bit_t *lcd, uint8 row, uint8 column, 
                                         const uint8 _chr[], uint8 mem_pos){
    std_ReturnType ret = E_Ok ;
    uint8 l_counter =ZERO_INIT ;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         ret= lcd_4bit_send_command (lcd ,(_LCD_CGRAM_START +(8* mem_pos))); 
         for(l_counter = 0 ;l_counter < 8 ; l_counter++){
             
             ret = lcd_4bit_send_char_data(lcd ,_chr[l_counter] ) ; 
         }
         ret = lcd_4bit_send_char_data_pos (lcd ,row ,column ,mem_pos );
         
      
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_intialize(const char_lcd_8bit_t *lcd){
    std_ReturnType ret = E_Ok ;
    uint8 l_data_counter = ZERO_INIT;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
          ret = gpio_pin_initialize(&lcd->lcd_regester_select);
         ret = gpio_pin_initialize(&lcd->lcd_enable);
         for(l_data_counter = ZERO_INIT ; l_data_counter<8 ;l_data_counter++ ){
              ret = gpio_pin_initialize(&(lcd->lcd_data[l_data_counter]));
         }
         //initialization steps from data sheet 
      __delay_ms(20);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        
        ret = lcd_8bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_8bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(lcd, 0x80);
      
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_send_command(const char_lcd_8bit_t *lcd, uint8 command){
    std_ReturnType ret = E_Ok ;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         //make select register = 0  to know i will send command not data (send to instruction register in
         //                                                                 microcontroller inside lcd )
         ret = gpio_pin_write_logic(&(lcd->lcd_regester_select),GPIO_LOW);
         //send 8 bit 
         ret = lcd_send_8bit(lcd ,command);
         //set bit enable every once send data or command
         ret = lcd_8bit_set_enable_signal(lcd) ;
       
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_send_char_data(const char_lcd_8bit_t *lcd, uint8 data){
    std_ReturnType ret = E_Ok ;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
          //make select register = 0  to know i will send command not data (send to instruction register in
         //                                                                 microcontroller inside lcd )
         ret = gpio_pin_write_logic(&(lcd->lcd_regester_select),GPIO_HIGH);
         //send 8 bit 
         ret = lcd_send_8bit(lcd ,data);
         //set bit enable every once send data or command
         ret = lcd_8bit_set_enable_signal(lcd) ;
       
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_send_char_data_pos(const char_lcd_8bit_t *lcd,uint8 row, uint8 column, uint8 data){
    std_ReturnType ret = E_Ok ;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         ret =  lcd_8bit_set_cursor(lcd ,row , column);
         ret =  lcd_8bit_send_char_data(lcd ,data );
      
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */ 
std_ReturnType lcd_8bit_send_string(const char_lcd_8bit_t *lcd, uint8 *str){
    std_ReturnType ret = E_Ok ;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         while(*str){
         ret = lcd_8bit_send_char_data(lcd ,*str) ;
         str++;
         }
      
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_send_string_pos(const char_lcd_8bit_t *lcd, uint8 row, uint8 column, uint8 *str){
    std_ReturnType ret = E_Ok ;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
           ret =  lcd_8bit_set_cursor(lcd ,row , column);

         while(*str){
         ret = lcd_8bit_send_char_data(lcd ,*str) ;
         str++;
         }
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_send_custom_char(const char_lcd_8bit_t *lcd, uint8 row, uint8 column, 
                                         const uint8 _chr[], uint8 mem_pos){
    std_ReturnType ret = E_Ok ;
    uint8 l_counter = ZERO_INIT ;
     if(NULL == lcd )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         ret= lcd_8bit_send_command (lcd ,(_LCD_CGRAM_START +(8* mem_pos))); 
         for(l_counter = 0 ;l_counter < 8 ; l_counter++){
             
             ret = lcd_8bit_send_char_data(lcd ,_chr[l_counter] ) ; 
         }
         ret = lcd_8bit_send_char_data_pos (lcd ,row ,column ,mem_pos );
       }
     return ret ; 
  
}
/**
 * 
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str){
    std_ReturnType ret = E_Ok ;
     if(NULL == str )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
           memset(str, '\0', 4);
        sprintf(str, "%i", value);
      
       }
     return ret ; 
  
}
/**
 * 
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType convert_uint16_to_string(uint16 value, uint8 *str){
    std_ReturnType ret = E_Ok ;
     if(NULL == str )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
            memset(str, '\0', 6);
        sprintf(str, "%i", value);
      
    }
     return ret ; 
  
}
/**
 * 
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType convert_uint32_to_string(uint32 value, uint8 *str){
    std_ReturnType ret = E_Ok ;
     if(NULL == str )
      {
         ret = E_NOT_Ok ; 
      }
    else 
       {
         
         memset(str, '\0', 11);
        sprintf(str, "%i", value);
    }
     return ret ; 
  
}
/**
 * 
 * @param lcd
 * @param _data_command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_send_4bit (const char_lcd_4bit_t *lcd ,uint8 _data_command ){
    std_ReturnType ret = E_Ok ;
    uint8 l_bit_position = ZERO_INIT ;
    for(l_bit_position = ZERO_INIT ;l_bit_position <4 ;l_bit_position++){
    ret = gpio_pin_write_logic(&(lcd->lcd_data[l_bit_position]) ,(_data_command >> l_bit_position) & (uint8)0x01);
    }
         return ret ; 

}
/**
 * 
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_4bit_set_enable_signal (const char_lcd_4bit_t *lcd){
    std_ReturnType ret = E_Ok ;
    ret = gpio_pin_write_logic(&(lcd->lcd_enable) , GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_enable), GPIO_LOW);
    __delay_us(5);

    return ret ; 
}
/**
 * 
 * @param lcd
 * @param _data_command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_send_8bit (const char_lcd_4bit_t *lcd ,uint8 _data_command ){
    std_ReturnType ret = E_Ok ;
    uint8 l_bit_position = ZERO_INIT ;
    for(l_bit_position = ZERO_INIT ;l_bit_position < 8 ;l_bit_position++){
    ret = gpio_pin_write_logic(&(lcd->lcd_data[l_bit_position]) ,(_data_command >> l_bit_position) & (uint8)0x01);
    }
         return ret ; 

}
/**
 * 
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_8bit_set_enable_signal (const char_lcd_8bit_t *lcd){
    std_ReturnType ret = E_Ok ;
    ret = gpio_pin_write_logic(&(lcd->lcd_enable) , GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_enable), GPIO_LOW);
    __delay_us(5);

    return ret ; 
}

/**
 * 
 * @param lcd Pointer to the LCD configuration parameters defined by the user
 * @param row Which row you need to print your character
 * @param coulmn Which column you need to print your character
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_8bit_set_cursor (const char_lcd_8bit_t *lcd , uint8 row , uint8 column){
        std_ReturnType ret = E_Ok ;
    column--;

    switch(row){
        case row1 :  ret = lcd_8bit_send_command(lcd, (0x80+column));break ;
        case row2 :  ret = lcd_8bit_send_command(lcd, (0xc0+column));break ;
        case row3 :  ret = lcd_8bit_send_command(lcd, (0x94+column));break ;
        case row4 :  ret = lcd_8bit_send_command(lcd, (0xd4+column));break ;
        default : ;

    }
        return ret ; 

}
/**
 * 
 * @param lcd
 * @param row
 * @param coulmn
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_4bit_set_cursor (const char_lcd_4bit_t *lcd , uint8 row , uint8 column){
        std_ReturnType ret = E_Ok ;
    column--;
    switch(row){
        case row1 :  ret = lcd_4bit_send_command(lcd, (0x80+column));break ;
        case row2 :  ret = lcd_4bit_send_command(lcd, (0xc0+column));break ;
        case row3 :  ret = lcd_4bit_send_command(lcd, (0x94+column));break ;
        case row4 :  ret = lcd_4bit_send_command(lcd, (0xd4+column));break ;
        default : ;
    }
        return ret ; 

}