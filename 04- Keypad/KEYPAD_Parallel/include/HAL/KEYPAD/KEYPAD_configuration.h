

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_

#define KEYPAD_PORT PORTA

#define ROW_NO 4
#define COL_NO 4

u8 Global_u8ArrOfKeyValues [ROW_NO][COL_NO]={
											 {'1','2','3','+'},
											 {'4','5','6','-'},
											 {'7','8','9','*'},
											 {'C','0','=','/'}
											};
#define KEY_NOT_PRESSED 255

#define ROW0	PIN0
#define ROW1	PIN1
#define ROW2	PIN2
#define ROW3	PIN3

#define COL0	PIN4
#define COL1	PIN5
#define COL2	PIN6
#define COL3	PIN7

#define KEYPAD_ROWS {ROW0,ROW1,ROW2,ROW3}
#define KEYPAD_COLS {COL0,COL1,COL2,COL3}

#define KEYPAD_DEBOUNCING_DELAY 30
#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_ */
