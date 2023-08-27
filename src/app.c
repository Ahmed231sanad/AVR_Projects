
#include <util/delay.h>

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_interface.h"

#include "../Include/MCAL/SPI/SPI_Interface.h"

#include "../Include/HAL/LED/LED_interface.h"

#define F_CPU 8000000UL


int main (void)
{
	// (PB4 --> SS --> I/P) , (PB5--> MOSI --> I/P) , (PB6--> MISO--> O/P), (PB7--> SCK --> I/P) , (PA0 --> O/P)
	MDIO_voidInit();
	MSPI_voidInit();
	u8 x=0;
	while (1)
	{
			x= MSPI_u8TransReceive('1');
			if (x=='5')
			{
				HLED_voidToggleLed(DIO_PORTA,PIN0);
			}
			_delay_ms(2000);
	}
}
