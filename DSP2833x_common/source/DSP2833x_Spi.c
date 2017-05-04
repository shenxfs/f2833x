/*
*###########################################################################
*
* FILE:   DSP2833x_Spi.c
*
* TITLE:  DSP2833x SPI Initialization & Support Functions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
/*
* Included Files
*/
#include "DSP2833x_Device.h"     /* DSP2833x Headerfile Include File*/
#include "DSP2833x_Examples.h"   /* DSP2833x Examples Include File*/

/*
* InitSPI - This function initializes the SPI(s) to a known state.
*/
void InitSpi(void)
{
    /*
    * Initialize SPI-A/B/C/D
    */
}

/*
* InitSpiGpio - This function initializes GPIO pins to function as SPI pins
*
* Each GPIO pin can be configured as a GPIO pin or up to 3 different
* peripheral functional pins. By default all pins come up as GPIO
* inputs after reset.  
* 
* Caution: 
* For each SPI peripheral
* Only one GPIO pin should be enabled for SPISOMO operation.
* Only one GPIO pin should be enabled for SPISOMI operation. 
* Only one GPIO pin should be enabled for SPICLKA operation. 
* Only one GPIO pin should be enabled for SPISTEA operation. 
* Comment out other unwanted lines.
*/
void InitSpiGpio(void)
{
    InitSpiaGpio();
}

/*
* InitSpiaGpio - This function initializes GPIO poins to function as SPI pins
*/
void InitSpiaGpio(void)
{
    EALLOW;
    
    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user.  
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
#ifndef SPIA
    GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0U;   /*Enable pull-up on GPIO16 (SPISIMOA)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0U;   /*Enable pull-up on GPIO17 (SPISOMIA)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0U;   /*Enable pull-up on GPIO18 (SPICLKA)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0U;   /*Enable pull-up on GPIO19 (SPISTEA)*/
#else
    GpioCtrlRegs.GPBPUD.bit.GPIO54 = 0U; /*Enable pull-up on GPIO54 (SPISIMOA)*/
    GpioCtrlRegs.GPBPUD.bit.GPIO55 = 0U; /*Enable pull-up on GPIO55 (SPISOMIA)*/
    GpioCtrlRegs.GPBPUD.bit.GPIO56 = 0U; /*Enable pull-up on GPIO56 (SPICLKA)*/
    GpioCtrlRegs.GPBPUD.bit.GPIO57 = 0U; /*Enable pull-up on GPIO57 (SPISTEA)*/
#endif

    /*
    * Set qualification for selected pins to asynch only
    * This will select asynch (no qualification) for the selected pins.
    * Comment out other unwanted lines.
    */
#ifndef SPIA
    GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3U; /* Asynch input GPIO16 (SPISIMOA)*/
    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3U; /* Asynch input GPIO17 (SPISOMIA)*/
    GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 3U; /* Asynch input GPIO18 (SPICLKA)*/
    GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 3U; /* Asynch input GPIO19 (SPISTEA)*/
#else
    GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 3U; /* Asynch input GPIO16 (SPISIMOA)*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 3U; /* Asynch input GPIO17 (SPISOMIA)*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO56 = 3U; /* Asynch input GPIO18 (SPICLKA)*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO57 = 3U; /* Asynch input GPIO19 (SPISTEA)*/
#endif

    /*
    * Configure SPI-A pins using GPIO regs
    * This specifies which of the possible GPIO pins will be SPI 
    * functional pins.
    * Comment out other unwanted lines.
    */
#ifndef SPIA    
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1U; /* Configure GPIO16 as SPISIMOA*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1U; /* Configure GPIO17 as SPISOMIA*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1U; /* Configure GPIO18 as SPICLKA*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 1U; /* Configure GPIO19 as SPISTEA*/
#else
    GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 1U; /* Configure GPIO54 as SPISIMOA*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 1U; /* Configure GPIO55 as SPISOMIA*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 1U; /* Configure GPIO56 as SPICLKA*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 1U; /* Configure GPIO57 as SPISTEA*/
#endif
    EDIS;
}

/*
* End of file
*/

