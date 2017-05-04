/*
*###########################################################################
*
* FILE:   DSP2833x_Xintf.c
*
* TITLE:   DSP2833x Device External Interface Init & Support Functions.
*
* DESCRIPTION:
*
*          Example initialization function for the external interface (XINTF).
*          This example configures the XINTF to its default state.  For an
*          example of how this function being used refer to the
*          examples/run_from_xintf project.
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
* InitXINTF - This function initializes the External Interface the default 
* reset state.
*
* Do not modify the timings of the XINTF while running from the XINTF.  Doing
* so can yield unpredictable results
*/
void InitXintf(void)
{
    /*
    * This shows how to write to the XINTF registers.  The
    * values used here are the default state after reset.
    * Different hardware will require a different configuration.
    */

    /*
    * For an example of an XINTF configuration used with the
    * F28335 eZdsp, refer to the examples/run_from_xintf project.
    */

    /*
    * Any changes to XINTF timing should only be made by code
    * running outside of the XINTF.
    */

    /*
    *                       All Zones
    * Timing for all zones based on XTIMCLK = 1/2 SYSCLKOUT
    */
    EALLOW;
    XintfRegs.XINTCNF2.bit.XTIMCLK = 1U;
    
    /*
    * No write buffering
    */
    XintfRegs.XINTCNF2.bit.WRBUFF = 0U;
    
    /*
    * XCLKOUT is enabled
    */
    XintfRegs.XINTCNF2.bit.CLKOFF = 0U;
    
    /*
    * XCLKOUT = XTIMCLK/2
    */
    XintfRegs.XINTCNF2.bit.CLKMODE = 1U;

    /*
    *                       Zone 0
    * When using ready, ACTIVE must be 1 or greater
    * Lead must always be 1 or greater
    * Zone write timing
    */
    XintfRegs.XTIMING0.bit.XWRLEAD = 3U;
    XintfRegs.XTIMING0.bit.XWRACTIVE = 7U;
    XintfRegs.XTIMING0.bit.XWRTRAIL = 3U;
    
    /*
    * Zone read timing
    */
    XintfRegs.XTIMING0.bit.XRDLEAD = 3U;
    XintfRegs.XTIMING0.bit.XRDACTIVE = 7U;
    XintfRegs.XTIMING0.bit.XRDTRAIL = 3U;

    /*
    * double all Zone read/write lead/active/trail timing
    */
    XintfRegs.XTIMING0.bit.X2TIMING = 1U;

    /*
    * Zone will sample XREADY signal
    */
    XintfRegs.XTIMING0.bit.USEREADY = 1U;
    XintfRegs.XTIMING0.bit.READYMODE = 1U;  /* sample asynchronous*/

    /*
    * Size must be either:
    * 0,1 = x32 or
    * 1,1 = x16 other values are reserved
    */
    XintfRegs.XTIMING0.bit.XSIZE = 3U;

    /*
    *                  Zone 6
    * When using ready, ACTIVE must be 1 or greater
    * Lead must always be 1 or greater
    * Zone write timing
    */
    XintfRegs.XTIMING6.bit.XWRLEAD = 3U;
    XintfRegs.XTIMING6.bit.XWRACTIVE = 7U;
    XintfRegs.XTIMING6.bit.XWRTRAIL = 3U;
    
    /*
    * Zone read timing
    */
    XintfRegs.XTIMING6.bit.XRDLEAD = 3U;
    XintfRegs.XTIMING6.bit.XRDACTIVE = 7U;
    XintfRegs.XTIMING6.bit.XRDTRAIL = 3U;

    /*
    * double all Zone read/write lead/active/trail timing
    */
    XintfRegs.XTIMING6.bit.X2TIMING = 1U;

    /*
    * Zone will sample XREADY signal
    */
    XintfRegs.XTIMING6.bit.USEREADY = 1U;
    XintfRegs.XTIMING6.bit.READYMODE = 1U;  /* sample asynchronous*/

    /*
    * Size must be either:
    * 0,1 = x32 or
    * 1,1 = x16 other values are reserved
    */
    XintfRegs.XTIMING6.bit.XSIZE = 3U;

    /*
    *                 Zone 7
    * When using ready, ACTIVE must be 1 or greater
    * Lead must always be 1 or greater
    * Zone write timing
    */
    XintfRegs.XTIMING7.bit.XWRLEAD = 3U;
    XintfRegs.XTIMING7.bit.XWRACTIVE = 7U;
    XintfRegs.XTIMING7.bit.XWRTRAIL = 3U;
    
    /*
    * Zone read timing
    */
    XintfRegs.XTIMING7.bit.XRDLEAD = 3U;
    XintfRegs.XTIMING7.bit.XRDACTIVE = 7U;
    XintfRegs.XTIMING7.bit.XRDTRAIL = 3U;

    /*
    * double all Zone read/write lead/active/trail timing
    */
    XintfRegs.XTIMING7.bit.X2TIMING = 1U;

    /*
    * Zone will sample XREADY signal
    */
    XintfRegs.XTIMING7.bit.USEREADY = 1U;
    XintfRegs.XTIMING7.bit.READYMODE = 1U;  /* sample asynchronous*/

    /*
    * Size must be either:
    * 0,1 = x32 or
    * 1,1 = x16 other values are reserved
    */
    XintfRegs.XTIMING7.bit.XSIZE = 3U;

    /*
    * Bank switching
    * Assume Zone 7 is slow, so add additional BCYC cycles
    * when ever switching from Zone 7 to another Zone.
    * This will help avoid bus contention.
    */
    XintfRegs.XBANK.bit.BANK = 7U;
    XintfRegs.XBANK.bit.BCYC = 7U;
    EDIS;
    
    /*
    * Force a pipeline flush to ensure that the write to the last register 
    * configured occurs before returning.
    */
    InitXintf16Gpio();
    /*InitXintf32Gpio();*/

    RPTNOP;
}

/*
* InitXintf32Gpio - 
*/
void InitXintf32Gpio(void)
{
    EALLOW;
    GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 3U;  /* XD31*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 3U;  /* XD30*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 3U;  /* XD29*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 3U;  /* XD28*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 3U;  /* XD27*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 3U;  /* XD26*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 3U;  /* XD25*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 3U;  /* XD24*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 3U;  /* XD23*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 3U;  /* XD22*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 3U;  /* XD21*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 3U;  /* XD20*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 3U;  /* XD19*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 3U;  /* XD18*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 3U;  /* XD17*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 3U;  /* XD16*/

    GpioCtrlRegs.GPBQSEL2.bit.GPIO48 = 3U;  /* XD31 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO49 = 3U;  /* XD30 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO50 = 3U;  /* XD29 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO51 = 3U;  /* XD28 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO52 = 3U;  /* XD27 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO53 = 3U;  /* XD26 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 3U;  /* XD25 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 3U;  /* XD24 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO56 = 3U;  /* XD23 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO57 = 3U;  /* XD22 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO58 = 3U;  /* XD21 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO59 = 3U;  /* XD20 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO60 = 3U;  /* XD19 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO61 = 3U;  /* XD18 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO62 = 3U;  /* XD17 asynchronous input*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO63 = 3U;  /* XD16 asynchronous input*/

    InitXintf16Gpio();
}

/*
* InitXintf16Gpio -
*/
void InitXintf16Gpio(void)
{
    EALLOW;
    GpioCtrlRegs.GPCMUX1.bit.GPIO64 = 3U;  /* XD15*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO65 = 3U;  /* XD14*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO66 = 3U;  /* XD13*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO67 = 3U;  /* XD12*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO68 = 3U;  /* XD11*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO69 = 3U;  /* XD10*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO70 = 3U;  /* XD19*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO71 = 3U;  /* XD8*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO72 = 3U;  /* XD7*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO73 = 3U;  /* XD6*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO74 = 3U;  /* XD5*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO75 = 3U;  /* XD4*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO76 = 3U;  /* XD3*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO77 = 3U;  /* XD2*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO78 = 3U;  /* XD1*/
    GpioCtrlRegs.GPCMUX1.bit.GPIO79 = 3U;  /* XD0*/

    GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 3U;  /* XA0/XWE1n*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 3U;  /* XA1*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 3U;  /* XA2*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 3U;  /* XA3*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO44 = 3U;  /* XA4*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO45 = 3U;  /* XA5*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO46 = 3U;  /* XA6*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO47 = 3U;  /* XA7*/

    GpioCtrlRegs.GPCMUX2.bit.GPIO80 = 3U;  /* XA8*/
    GpioCtrlRegs.GPCMUX2.bit.GPIO81 = 3U;  /* XA9*/
    GpioCtrlRegs.GPCMUX2.bit.GPIO82 = 3U;  /* XA10*/
    GpioCtrlRegs.GPCMUX2.bit.GPIO83 = 3U;  /* XA11*/
    GpioCtrlRegs.GPCMUX2.bit.GPIO84 = 3U;  /* XA12*/
    GpioCtrlRegs.GPCMUX2.bit.GPIO85 = 3U;  /* XA13*/
    GpioCtrlRegs.GPCMUX2.bit.GPIO86 = 3U;  /* XA14*/
    GpioCtrlRegs.GPCMUX2.bit.GPIO87 = 3U;  /* XA15*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO39 = 3U;  /* XA16*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 3U;  /* XA17*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 3U;  /* XA18*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 3U;  /* XA19*/

    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 3U;  /* XREADY*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 3U;  /* XRNW*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO38 = 3U;  /* XWE0*/

    GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 3U;  /* XZCS0*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 3U;  /* XZCS7*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3U;  /* XZCS6*/
    EDIS;
}

/*
* End of File
*/

