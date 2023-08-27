
#ifndef INCLUDE_HAL_LCD_LCD_CFG_H_
#define INCLUDE_HAL_LCD_LCD_CFG_H_


#define LCD_DATA_PORT    PORTD
#define LCD_CONTROL_PORT PORTC

#define LCD_RS_PIN  PIN0
#define LCD_RW_PIN  PIN1
#define LCD_E_PIN   PIN2

// 0 --> 4-bit mode
// 1 --> 8-bit mode
#define LCD_DL	1

// 0 --> 1 Line
// 1 --> 2 Lines
#define LCD_NO_OF_LINES	1

// 0 --> 5 * 7
// 1 --> 5 * 10
#define LCD_CHAR_FONT	0

// 0 --> Off
// 1 --> ON
#define DISPLAY_ON 1

// 0 --> Off
// 1 --> ON
#define CURSOR_DISPLAY 1

// 0 --> Off
// 1 --> ON
#define CURSOR_BLINK 1

// Left to Right --> 1
// Right to Left --> 0
#define DATA_DIRECTION 1
#endif /* INCLUDE_HAL_LCD_LCD_CFG_H_ */
