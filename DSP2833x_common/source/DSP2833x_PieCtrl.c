/*
*###########################################################################
*
* FILE:	DSP2833x_PieCtrl.c
*
* TITLE:	DSP2833x Device PIE Control Register Initialization Functions.
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
* InitPieCtrl - This function initializes the PIE control registers to a known
* state.
*/
void InitPieCtrl(void)
{
    /*
    * Disable Interrupts at the CPU level
    */
    DINT;
    
    /*
    * Disable the PIE
    */
    PieCtrlRegs.PIECTRL.bit.ENPIE = 0U;

    /*
    * Clear all PIEIER registers
    */
    PieCtrlRegs.PIEIER1.all = 0U;
    PieCtrlRegs.PIEIER2.all = 0U;
    PieCtrlRegs.PIEIER3.all = 0U;	
    PieCtrlRegs.PIEIER4.all = 0U;
    PieCtrlRegs.PIEIER5.all = 0U;
    PieCtrlRegs.PIEIER6.all = 0U;
    PieCtrlRegs.PIEIER7.all = 0U;
    PieCtrlRegs.PIEIER8.all = 0U;
    PieCtrlRegs.PIEIER9.all = 0U;
    PieCtrlRegs.PIEIER10.all = 0U;
    PieCtrlRegs.PIEIER11.all = 0U;
    PieCtrlRegs.PIEIER12.all = 0U;

    /*
    * Clear all PIEIFR registers
    */
    PieCtrlRegs.PIEIFR1.all = 0U;
    PieCtrlRegs.PIEIFR2.all = 0U;
    PieCtrlRegs.PIEIFR3.all = 0U;	
    PieCtrlRegs.PIEIFR4.all = 0U;
    PieCtrlRegs.PIEIFR5.all = 0U;
    PieCtrlRegs.PIEIFR6.all = 0U;
    PieCtrlRegs.PIEIFR7.all = 0U;
    PieCtrlRegs.PIEIFR8.all = 0U;
    PieCtrlRegs.PIEIFR9.all = 0U;
    PieCtrlRegs.PIEIFR10.all = 0U;
    PieCtrlRegs.PIEIFR11.all = 0U;
    PieCtrlRegs.PIEIFR12.all = 0U;
}	

/*
* EnableInterrupts - This function enables the PIE module and CPU interrupts
*/
void EnableInterrupts(void)
{
    /*
    * Enable the PIE
    */
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1U;

    /*
	* Enables PIE to drive a pulse into the CPU 
    */
	PieCtrlRegs.PIEACK.all = 0xFFFFU;  

    /*
	* Enable Interrupts at the CPU level 
    */
    EINT;
}

/*
* End of file
*/

