#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/MCAL/DIO/DIO_Interface.h"

#include "../include/HAL/LED/LED_Interface.h"
#include "../include/HAL/SSD/SSD_Interface.h"
#define F_CPU 8000000UL


int main (void)
{
	MDIO_voidInit();
	while(1)
	{
		HSSD_voidDisplayAscending(PORTA, 700);
	}
}
