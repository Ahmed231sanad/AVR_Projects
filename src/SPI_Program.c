
/***************************************************/
/*              Library Directives                 */
/***************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../Include/MCAL/SPI/SPI_Interface.h"
#include "../Include/MCAL/SPI/SPI_Private.h"
#include "../Include/MCAL/SPI/SPI_Configuration.h"




void MSPI_voidInit (void)
{
	/* Data Order = MSB First */
	CLR_BIT (SPI_SPCR_REG,5);
	/* Choose CPOL and CPHA => Falling / Raising, Setup, Sample  */
	SET_BIT (SPI_SPCR_REG,3);
	SET_BIT (SPI_SPCR_REG,2);

#if (SPI_MODE == SPI_MASTER_MODE)
	/*Select Master Mode*/
	SET_BIT (SPI_SPCR_REG,4);
	/*Select Clk => Fosc/64  */
	SET_BIT (SPI_SPCR_REG,1);
	CLR_BIT (SPI_SPCR_REG,0);

#elif (SPI_MODE == SPI_SLAVE_MODE)
	/*Select SLAVE Mode*/
	CLR_BIT (SPI_SPCR_REG,4);
#endif
	/* Enable SPI */
	SET_BIT (SPI_SPCR_REG,6);
}


u8 MSPI_u8TransReceive (u8 copy_u8Data)
{
	/* Set Data to be sent into data register */
	SPI_SPDR_REG= copy_u8Data;
	/* wait until data transmission end */
	while ((GET_BIT(SPI_SPSR_REG,7))==0);
	/* return data received */
	return SPI_SPDR_REG;
}
