
/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

/****************************************************/
/* DIO Directives		     					    */
/****************************************************/
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/DIO/DIO_Private.h"
#include "../include/MCAL/DIO/DIO_Cfg.h"

void MDIO_voidInit()
{
	DDRA_REG = CONC_BIT (PORTA_PIN7_DIRECTION,PORTA_PIN6_DIRECTION,PORTA_PIN5_DIRECTION,
						 PORTA_PIN4_DIRECTION,PORTA_PIN3_DIRECTION,PORTA_PIN2_DIRECTION,
						 PORTA_PIN1_DIRECTION,PORTA_PIN0_DIRECTION);

	DDRB_REG = CONC_BIT (PORTB_PIN7_DIRECTION,PORTB_PIN6_DIRECTION,PORTB_PIN5_DIRECTION,
						 PORTB_PIN4_DIRECTION,PORTB_PIN3_DIRECTION,PORTB_PIN2_DIRECTION,
						 PORTB_PIN1_DIRECTION,PORTB_PIN0_DIRECTION);

	DDRC_REG = CONC_BIT (PORTC_PIN7_DIRECTION,PORTC_PIN6_DIRECTION,PORTC_PIN5_DIRECTION,
						 PORTC_PIN4_DIRECTION,PORTC_PIN3_DIRECTION,PORTC_PIN2_DIRECTION,
						 PORTC_PIN1_DIRECTION,PORTC_PIN0_DIRECTION);

	DDRD_REG = CONC_BIT (PORTD_PIN7_DIRECTION,PORTD_PIN6_DIRECTION,PORTD_PIN5_DIRECTION,
						 PORTD_PIN4_DIRECTION,PORTD_PIN3_DIRECTION,PORTD_PIN2_DIRECTION,
						 PORTD_PIN1_DIRECTION,PORTD_PIN0_DIRECTION);

	PORTA_REG = CONC_BIT(PORTA_PIN7_VALUE,PORTA_PIN6_VALUE,PORTA_PIN5_VALUE,
						 PORTA_PIN4_VALUE,PORTA_PIN3_VALUE,PORTA_PIN2_VALUE,
						 PORTA_PIN1_VALUE,PORTA_PIN0_VALUE);

	PORTB_REG = CONC_BIT(PORTB_PIN7_VALUE,PORTB_PIN6_VALUE,PORTB_PIN5_VALUE,
						 PORTB_PIN4_VALUE,PORTB_PIN3_VALUE,PORTB_PIN2_VALUE,
						 PORTB_PIN1_VALUE,PORTB_PIN0_VALUE);

	PORTC_REG = CONC_BIT(PORTC_PIN7_VALUE,PORTC_PIN6_VALUE,PORTC_PIN5_VALUE,
						 PORTC_PIN4_VALUE,PORTC_PIN3_VALUE,PORTC_PIN2_VALUE,
						 PORTC_PIN1_VALUE,PORTC_PIN0_VALUE);

	PORTA_REG = CONC_BIT(PORTD_PIN7_VALUE,PORTD_PIN6_VALUE,PORTD_PIN5_VALUE,
						 PORTD_PIN4_VALUE,PORTD_PIN3_VALUE,PORTD_PIN2_VALUE,
						 PORTD_PIN1_VALUE,PORTD_PIN0_VALUE);
}


void MDIO_voidSetPinDirection (DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin, PIN_DIRECTION A_PinDirection)
{
	// Input validation
	if ((A_DIOPort <= PORTD)&&(A_DIOPin<=PIN7)&&(A_PinDirection<=DIO_OUTPUT))
	{
		switch (A_DIOPort)
		{
		case PORTA:
					switch(A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRA_REG,A_DIOPin); break;
					case DIO_INPUT:  CLR_BIT(DDRA_REG,A_DIOPin); break;
					}
					break;
		case PORTB:
					switch(A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRB_REG,A_DIOPin); break;
					case DIO_INPUT:  CLR_BIT(DDRB_REG,A_DIOPin); break;
					}
					break;
		case PORTC:
					switch(A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRC_REG,A_DIOPin); break;
					case DIO_INPUT:  CLR_BIT(DDRC_REG,A_DIOPin); break;
					}
					break;
		case PORTD:
					switch(A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRD_REG,A_DIOPin); break;
					case DIO_INPUT:  CLR_BIT(DDRD_REG,A_DIOPin); break;
					}
					break;
		default: break;
		}
	}
}

void MDIO_voidSetPinStatus (DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin, PIN_STATUS A_PinStatus)
{
	// Input validation
	if ((A_DIOPort <= PORTD)&&(A_DIOPin<=PIN7)&&(A_PinStatus<=DIO_SET))
	{
		switch (A_DIOPort)
		{
		case PORTA:
					switch(A_PinStatus)
					{
					case DIO_SET:   SET_BIT(PORTA_REG,A_DIOPin); break;
					case DIO_RESET: CLR_BIT(PORTA_REG,A_DIOPin); break;
					}
					break;
		case PORTB:
					switch(A_PinStatus)
					{
					case DIO_SET:   SET_BIT(PORTB_REG,A_DIOPin); break;
					case DIO_RESET: CLR_BIT(PORTB_REG,A_DIOPin); break;
					}
					break;
		case PORTC:
					switch(A_PinStatus)
					{
					case DIO_SET:   SET_BIT(PORTC_REG,A_DIOPin); break;
					case DIO_RESET: CLR_BIT(PORTC_REG,A_DIOPin); break;
					}
					break;
		case PORTD:
					switch(A_PinStatus)
					{
					case DIO_SET:   SET_BIT(PORTD_REG,A_DIOPin); break;
					case DIO_RESET: CLR_BIT(PORTD_REG,A_DIOPin); break;
					}
					break;
		default: break;
		}
	}
}

void MDIO_voidTogglePinValue (DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin)
{
	if ((A_DIOPort <= PORTD)&&(A_DIOPin<=PIN7))
		{
			switch (A_DIOPort)
			{
			case PORTA:
						TOGGLE_BIT(PORTA_REG,A_DIOPin);
						break;
			case PORTB:
						TOGGLE_BIT(PORTB_REG,A_DIOPin);
						break;
			case PORTC:
						TOGGLE_BIT(PORTC_REG,A_DIOPin);
						break;
			case PORTD:
						TOGGLE_BIT(PORTD_REG,A_DIOPin);
						break;
			default: break;
			}
		}
}

PIN_STATUS MDIO_PinStatusGetPinValue (DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin)
{
	PIN_STATUS PinValue;
	if ((A_DIOPort <= PORTD)&&(A_DIOPin<=PIN7))
	{
		switch (A_DIOPort)
		{
		case PORTA:
			PinValue = GET_BIT(PINA_REG,A_DIOPin);
					break;
		case PORTB:
			PinValue = GET_BIT(PINB_REG,A_DIOPin);
					break;
		case PORTC:
			PinValue = GET_BIT(PINC_REG,A_DIOPin);
					break;
		case PORTD:
			PinValue = GET_BIT(PIND_REG,A_DIOPin);
					break;
		default: break;
		}
	}
	return PinValue;
}


void MDIO_voidSetPortDirection (DIO_PORTS A_DIOPort, u8 A_u8PortDirection)
{
	if ((A_DIOPort <= PORTD))
	{
		switch (A_DIOPort)
		{
		case PORTA:
					DDRA_REG = A_u8PortDirection;
					break;
		case PORTB:
					DDRB_REG = A_u8PortDirection;
					break;
		case PORTC:
					DDRC_REG = A_u8PortDirection;
					break;
		case PORTD:
					DDRD_REG = A_u8PortDirection;
					break;
		default: break;
		}
	}
}
void MDIO_voidSetPortValue (DIO_PORTS A_DIOPort, u8 A_u8PortValue)
{
	if ((A_DIOPort <= PORTD))
	{
		switch (A_DIOPort)
		{
		case PORTA:
					PORTA_REG = A_u8PortValue;
					break;
		case PORTB:
					PORTB_REG = A_u8PortValue;
					break;
		case PORTC:
					PORTC_REG = A_u8PortValue;
					break;
		case PORTD:
					PORTD_REG = A_u8PortValue;
					break;
		default: break;
		}
	}
}
