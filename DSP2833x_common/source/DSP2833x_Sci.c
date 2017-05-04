/*
*###########################################################################
*
* FILE:	DSP2833x_Sci.c
*
* TITLE:	DSP2833x SCI Initialization & Support Functions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http:/*www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
/*
* Included Files
*/
#include "DSP2833x_Device.h"     /* DSP2833x Headerfile Include File*/
#include "DSP2833x_Examples.h"   /* DSP2833x Examples Include File*/

/*
* InitSci - This function initializes the SCI(s) to a known state.
*/
void InitSci(void)
{
    /*
    * Initialize SCI-A
    */

    /*
    * Initialize SCI-B
    */

    /*
    * Initialize SCI-C
    */
}	

/*
* InitSciGpio - This function initializes GPIO to function as SCI-A, SCI-B, or
* SCI-C
*
* Each GPIO pin can be configured as a GPIO pin or up to 3 different
* peripheral functional pins. By default all pins come up as GPIO
* inputs after reset.  
* 
* Caution: 
* Only one GPIO pin should be enabled for SCITXDA/B operation.
* Only one GPIO pin shoudl be enabled for SCIRXDA/B operation. 
* Comment out other unwanted lines.
*/
void InitSciGpio(void)
{
    InitSciaGpio();
#if DSP28_SCIB   
    InitScibGpio();
#endif /* if DSP28_SCIB*/  

#if DSP28_SCIC
    InitScicGpio();
#endif /* if DSP28_SCIC*/
}

/*
* InitSciaGpio - This function initializes GPIO pins to function as SCI-A pins
*/
void InitSciaGpio(void)
{
    EALLOW;

    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled disabled by the user.  
    * This will enable the pullups for the specified pins.
    */
    GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0U;  /* Enable pull-up for GPIO28 (SCIRXDA)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0U;	 /* Enable pull-up for GPIO29 (SCITXDA)*/

    /*
    * Set qualification for selected pins to asynch only
    * Inputs are synchronized to SYSCLKOUT by default.  
    * This will select asynch (no qualification) for the selected pins.
    */
    GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3U;  /* Asynch input GPIO28 (SCIRXDA)*/
    
    /*
    * Configure SCI-A pins using GPIO regs
    * This specifies which of the possible GPIO pins will be SCI functional
    * pins.
    */
    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1U;   /* Configure GPIO28 to SCIRXDA */
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1U;   /* Configure GPIO29 to SCITXDA */

    EDIS;
}

#if DSP28_SCIB
/*
* InitScibGpio - This function initializes GPIO pins to function as SCI-B pins
*/
void InitScibGpio(void)
{
    EALLOW;

    /*
    * Enable internal pull-up for the selected pins 
    * Pull-ups can be enabled or disabled disabled by the user.  
    * This will enable the pullups for the specified pins.
    */
#if defined(SCIB1)    
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0U; /*Enable pull-up for GPIO14 (SCITXDB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0U; /*Enable pull-up for GPIO15 (SCIRXDB)*/
#elif defined(SCIB2)
    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0U;	 /*Enable pull-up for GPIO18 (SCITXDB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0U;	 /*Enable pull-up for GPIO19 (SCIRXDB)*/
#elif defined(SCIB3)
    GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0U; /*Enable pull-up for GPIO22 (SCITXDB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0U; /*Enable pull-up for GPIO23 (SCIRXDB)*/
#else
    GpioCtrlRegs.GPAPUD.bit.GPIO9  = 0U;  /*Enable pull-up for GPIO9  (SCITXDB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0U; /*Enable pull-up for GPIO11 (SCIRXDB)*/
#endif    

    /*
    * Set qualification for selected pins to asynch only
    * This will select asynch (no qualification) for the selected pins.
    */
#if defined(SCIB1)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3U;  /* Asynch input GPIO15 (SCIRXDB)*/
#elif defined(SCIB2)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 3U;  /* Asynch input GPIO19 (SCIRXDB)*/
#elif defined(SCIB3)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 3U;  /* Asynch input GPIO23 (SCIRXDB)*/
#else
    GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 3U;  /* Asynch input GPIO11 (SCIRXDB)*/
#endif

    /*
    * Configure SCI-B pins using GPIO regs
    * This specifies which of the possible GPIO pins will be SCI functional 
    * pins.
    */
#if defined(SCIB1)    
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 2U; /*Configure GPIO14 to SCITXDB*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 2U;  /*Configure GPIO15 for SCIRXDB*/
#elif defined(SCIB2)
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 2U;  /*Configure GPIO18 to SCITXDB*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 2U;   /*Configure GPIO19 for SCIRXDB*/
#elif defined(SCIB3)
    GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 3U; /*Configure GPIO22 to SCITXDB*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 3U;  /*Configure GPIO23 for SCIRXDB*/
#else    
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 2U;  /*Configure GPIO11 for SCIRXDB*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO9  = 2U;  /*Configure GPIO9 to SCITXDB */
#endif
    EDIS;
}
#endif /* if DSP28_SCIB */

#if DSP28_SCIC
/*
* InitScicGpio - This function initializes GPIO pins to function as SCI-C pins
*/
void InitScicGpio(void)
{
    EALLOW;

    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled disabled by the user.  
    * This will enable the pullups for the specified pins.
    */
    GpioCtrlRegs.GPBPUD.bit.GPIO62 = 0U;  /* Enable pull-up for GPIO62 (SCIRXDC)*/
    GpioCtrlRegs.GPBPUD.bit.GPIO63 = 0U;	 /* Enable pull-up for GPIO63 (SCITXDC)*/

    /*
    * Set qualification for selected pins to asynch only
    * Inputs are synchronized to SYSCLKOUT by default.  
    * This will select asynch (no qualification) for the selected pins.
    */
    GpioCtrlRegs.GPBQSEL2.bit.GPIO62 = 3U;  /* Asynch input GPIO62 (SCIRXDC)*/

    /*
    * Configure SCI-C pins using GPIO regs
    * This specifies which of the possible GPIO pins will be SCI functional 
    * pins.
    */
    GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 1U;   /* Configure GPIO62 to SCIRXDC*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 1U;   /* Configure GPIO63 to SCITXDC*/

    EDIS;
}
#endif /* if DSP28_SCIC */
	
/*
* End of file
*/

