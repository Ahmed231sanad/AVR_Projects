
/****************************************************/
/* Library Directives							    */
/****************************************************/
#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#define F_CPU 8000000UL

/****************************************************/
/* DIO Directives		     					    */
/****************************************************/
#include "../include/MCAL/DIO/DIO_Interface.h"


/****************************************************/
/* DIO Directives		     					    */
/****************************************************/
#include "../include/HAL/SSD/SSD_Interface.h"
#include "../include/HAL/SSD/SSD_Private.h"
#include "../include/HAL/SSD/SSD_Cfg.h"


HSSD_voidDisplayNumber(DIO_PORTS A_DIOPort,u8 A_u8Number)
{
	switch (A_u8Number)
	{
	case 0: MDIO_voidSetPortValue(A_DIOPort, ZERO); break;
	case 1: MDIO_voidSetPortValue(A_DIOPort, ONE); break;
	case 2: MDIO_voidSetPortValue(A_DIOPort, TWO); break;
	case 3: MDIO_voidSetPortValue(A_DIOPort, THREE); break;
	case 4: MDIO_voidSetPortValue(A_DIOPort, FOUR); break;
	case 5: MDIO_voidSetPortValue(A_DIOPort, FIVE); break;
	case 6: MDIO_voidSetPortValue(A_DIOPort, SIX); break;
	case 7: MDIO_voidSetPortValue(A_DIOPort, SEVEN); break;
	case 8: MDIO_voidSetPortValue(A_DIOPort, EIGHT); break;
	case 9: MDIO_voidSetPortValue(A_DIOPort, NINE); break;
	default: break;
	}
}

void HSSD_voidDisplayAscending(DIO_PORTS A_DIOPort, u16 A_u16DelayinMs)
{
	for (u8 i=0; i<10; i++)
	{
		HSSD_voidDisplayNumber(A_DIOPort, i);
		_delay_ms(A_u16DelayinMs);
	}
}

void HSSD_voidDisplayDescending(DIO_PORTS A_DIOPort,u16 A_u16DelayinMs)
{
	for (s8 i=9; i>=0; i--)
	{
		HSSD_voidDisplayNumber(A_DIOPort, i);
		_delay_ms(A_u16DelayinMs);
	}
}
