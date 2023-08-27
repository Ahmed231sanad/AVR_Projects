
#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

typedef enum{
	DIO_INPUT=0,
	DIO_OUTPUT
}PIN_DIRECTION;


typedef enum{
	DIO_RESET=0,    // LOW
	DIO_SET=1,      // HIGH
	DIO_FLOATING=0,
	DIO_PULLUP=1
}PIN_STATUS;

typedef enum{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_PINS;

typedef enum{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD
}DIO_PORTS;

void MDIO_voidInit(void);
void MDIO_voidSetPinDirection (DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin, PIN_DIRECTION A_PinDirection);
void MDIO_voidSetPinStatus (DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin, PIN_STATUS A_PinStatus);
void MDIO_voidTogglePinValue (DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin);
PIN_STATUS MDIO_PinStatusGetPinValue (DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin);
void MDIO_voidSetPortDirection (DIO_PORTS A_DIOPort, u8 A_u8PortDirection);
void MDIO_voidSetPortValue (DIO_PORTS A_DIOPort, u8 A_u8PortValue);

#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
