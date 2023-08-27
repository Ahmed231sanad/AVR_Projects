

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

/****************************************************/
/* DIO Directives		     					    */
/****************************************************/
#include "../include/MCAL/DIO/DIO_Interface.h"

/****************************************************/
/* KEYPAD Directives		     					*/
/****************************************************/
#include "../include/HAL/KEYPAD/KEYPAD_interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_private.h"
#include "../include/HAL/KEYPAD/KEYPAD_configuration.h"

u8 static Global_u8ArrOfRows [ROW_NO] = KEYPAD_ROWS;
u8 static Global_u8ArrOfCols [ROW_NO] = KEYPAD_COLS;


u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 local_u8KeyValue = KEY_NOT_PRESSED;

	u8 local_u8RowCounter=0, local_u8ColCounter=0, local_u8PinValue, local_u8Flag=FLAG_DOWN;

	for (local_u8RowCounter=0; local_u8RowCounter < ROW_NO; local_u8RowCounter++)
	{
		// Activate One Row
		MDIO_voidSetPinStatus(KEYPAD_PORT, Global_u8ArrOfRows[local_u8RowCounter], DIO_RESET);

		for (local_u8ColCounter=0; local_u8ColCounter < COL_NO; local_u8ColCounter++)
		{
			// Read Col
			local_u8PinValue = MDIO_PinStatusGetPinValue(KEYPAD_PORT, Global_u8ArrOfCols[local_u8ColCounter]);
			if (local_u8PinValue==KEYPAD_PRESSED)
			{
				// Delay for Bouncing Effect
				_delay_ms(KEYPAD_DEBOUNCING_DELAY);
				local_u8PinValue = MDIO_PinStatusGetPinValue(KEYPAD_PORT, Global_u8ArrOfCols[local_u8ColCounter]);
				if (local_u8PinValue==KEYPAD_PRESSED)
				{
					while (local_u8PinValue==KEYPAD_PRESSED)
					{
						local_u8PinValue = MDIO_PinStatusGetPinValue(KEYPAD_PORT, Global_u8ArrOfCols[local_u8ColCounter]);
					}
					local_u8KeyValue = Global_u8ArrOfKeyValues[local_u8RowCounter][local_u8ColCounter];
					local_u8Flag=FLAG_UP;
					break;
				}
			}
		}// End of Col Loop

		// Deactivate Row
		MDIO_voidSetPinStatus(KEYPAD_PORT, Global_u8ArrOfRows[local_u8RowCounter], DIO_SET);
		if (local_u8Flag == FLAG_UP)
		{
			break;
		}
	}
	return local_u8KeyValue;
}
