/*
*###########################################################################
*
* FILE:	DSP2833x_Gpio.c
*
* TITLE:	DSP2833x General Purpose I/O Initialization & Support Functions.
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
* InitGpio - This function initializes the Gpio to a known (default) state.
*
* For more details on configuring GPIO's as peripheral functions,
* refer to the individual peripheral examples and/or GPIO setup example. 
*/
void InitGpio(void)
{
    EALLOW;

    /*
    * Each GPIO pin can be: 
    * a) a GPIO input/output
    * b) peripheral function 1
    * c) peripheral function 2
    * d) peripheral function 3
    * By default, all are GPIO Inputs 
    */
    GpioCtrlRegs.GPAMUX1.all = 0x0000U;     /* GPIO functionality GPIO0-GPIO15*/
    GpioCtrlRegs.GPAMUX2.all = 0x0000U;     /* GPIO functionality GPIO16-GPIO31*/
    GpioCtrlRegs.GPBMUX1.all = 0x0000U;     /* GPIO functionality GPIO32-GPIO39*/
    GpioCtrlRegs.GPBMUX2.all = 0x0000U;     /* GPIO functionality GPIO48-GPIO63*/
    GpioCtrlRegs.GPCMUX1.all = 0x0000U;     /* GPIO functionality GPIO64-GPIO79*/
    GpioCtrlRegs.GPCMUX2.all = 0x0000U;     /* GPIO functionality GPIO80-GPIO95*/

    GpioCtrlRegs.GPADIR.all = 0x0000U;      /* GPIO0-GPIO31 are inputs*/
    GpioCtrlRegs.GPBDIR.all = 0x0000U;      /* GPIO32-GPIO63 are inputs */  
    GpioCtrlRegs.GPCDIR.all = 0x0000U;      /* GPI064-GPIO95 are inputs*/

    /*
    * Each input can have different qualification
    * a) input synchronized to SYSCLKOUT
    * b) input qualified by a sampling window
    * c) input sent asynchronously (valid for peripheral inputs only)
    */
    GpioCtrlRegs.GPAQSEL1.all = 0x0000U;    /* GPIO0-GPIO15 Synch to SYSCLKOUT*/
    GpioCtrlRegs.GPAQSEL2.all = 0x0000U;    /* GPIO16-GPIO31 Synch to SYSCLKOUT*/
    GpioCtrlRegs.GPBQSEL1.all = 0x0000U;    /* GPIO32-GPIO39 Synch to SYSCLKOUT*/
    GpioCtrlRegs.GPBQSEL2.all = 0x0000U;    /* GPIO48-GPIO63 Synch to SYSCLKOUT*/

    /*
    * Pull-ups can be enabled or disabled
    */
#ifndef NOPULLUPS    
    GpioCtrlRegs.GPAPUD.all = 0x0000U;      /* Pullup's enabled GPIO0-GPIO31*/
    GpioCtrlRegs.GPBPUD.all = 0x0000U;      /* Pullup's enabled GPIO32-GPIO63*/
    GpioCtrlRegs.GPCPUD.all = 0x0000U;      /* Pullup's enabled GPIO64-GPIO79*/
#else
    GpioCtrlRegs.GPAPUD.all = 0xFFFFU;    /* Pullup's disabled GPIO0-GPIO31*/
    GpioCtrlRegs.GPBPUD.all = 0xFFFFU;    /* Pullup's disabled GPIO32-GPIO34*/
    GpioCtrlRegs.GPCPUD.all = 0xFFFFU;    /* Pullup's disabled GPIO64-GPIO79*/
#endif
    EDIS;
}	
	
/*
* End of file
*/

