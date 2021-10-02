/* 
 * File:   ecu_character_lcd.h
 * Author: Mohamed Essa
 *
 * Created on April 9, 2021, 5:13 PM
 */

#ifndef ECU_CHARACTER_LCD_H
#define	ECU_CHARACTER_LCD_H

/* ----------------------section : includes -----------------*/
#include "ecu_character_lcd_cfg.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
/*-----------------------Section : Macro Declaration -------------- */

#define _LCD_CLEAR                               0X01
#define _LCD_RETURN_HOME                         0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF            0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON             0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF            0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON             0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT              0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT             0x14
#define _LCD_DISPLAY_SHIFT_LEFT                  0x18
#define _LCD_DISPLAY_SHIFT_RIGHT                 0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE                    0x38
#define _LCD_4BIT_MODE_2_LINE                    0x28

#define _LCD_CGRAM_START                         0x40
#define _LCD_DDRAM_START                         0x80

#define row1 1 
#define row2 2 
#define row3 3 
#define row4 4 

/*-----------------------Section : Macro Function  Declaration--------  */
/*---------------------- Section : Data Type Declaration layer---------*/
typedef struct {
    pin_config_t lcd_regester_select;
    pin_config_t lcd_enable ;             
    pin_config_t lcd_data[4];
}char_lcd_4bit_t;

typedef struct {
    pin_config_t lcd_regester_select;
    pin_config_t lcd_enable ;
    pin_config_t lcd_data[8];
}char_lcd_8bit_t;


 /*-----------------------Section : Function Declaration---------------------  */
std_ReturnType lcd_4bit_intialize(const char_lcd_4bit_t *lcd);
std_ReturnType lcd_4bit_send_command(const char_lcd_4bit_t *lcd, uint8 command);
std_ReturnType lcd_4bit_send_char_data(const char_lcd_4bit_t *lcd, uint8 data);
std_ReturnType lcd_4bit_send_char_data_pos(const char_lcd_4bit_t *lcd,uint8 row, uint8 column, uint8 data);
std_ReturnType lcd_4bit_send_string(const char_lcd_4bit_t *lcd, uint8 *str);
std_ReturnType lcd_4bit_send_string_pos(const char_lcd_4bit_t *lcd, uint8 row, uint8 column, uint8 *str);
std_ReturnType lcd_4bit_send_custom_char(const char_lcd_4bit_t *lcd, uint8 row, uint8 column, 
                                         const uint8 _chr[], uint8 mem_pos);

std_ReturnType lcd_8bit_intialize(const char_lcd_8bit_t *lcd);
std_ReturnType lcd_8bit_send_command(const char_lcd_8bit_t *lcd, uint8 command);
std_ReturnType lcd_8bit_send_char_data(const char_lcd_8bit_t *lcd, uint8 data);
std_ReturnType lcd_8bit_send_char_data_pos(const char_lcd_8bit_t *lcd,uint8 row, uint8 column, uint8 data);
std_ReturnType lcd_8bit_send_string(const char_lcd_8bit_t *lcd, uint8 *str);
std_ReturnType lcd_8bit_send_string_pos(const char_lcd_8bit_t *lcd, uint8 row, uint8 column, uint8 *str);
std_ReturnType lcd_8bit_send_custom_char(const char_lcd_8bit_t *lcd, uint8 row, uint8 column, 
                                         const uint8 _chr[], uint8 mem_pos);

std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str);
std_ReturnType convert_uint16_to_string(uint16 value, uint8 *str);
std_ReturnType convert_uint32_to_string(uint32 value, uint8 *str);
#endif	/* ECU_CHARACTER_LCD_H */

