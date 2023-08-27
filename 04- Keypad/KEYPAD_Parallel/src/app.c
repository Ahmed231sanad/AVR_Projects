#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"

#define F_CPU 8000000UL

u8 customChar[] = {
  0b00000,
  0b01010,
  0b10101,
  0b01010,
  0b00100,
  0b00000,
  0b00000,
  0b0000
};

int main (void)
{
	MDIO_voidInit();
	HLCD_voidInit();
//	HLCD_voidSendString("Abdelrahman");
	HLCD_voidSendSpecialCharacter(customChar,0,ROW1, COL7);
	while(1)
	{

	}
}
