/*
*###########################################################################
*
* FILE:   DSP2833x_EPwm.c
*
* TITLE:  DSP2833x ePWM Initialization & Support Functions.
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
* InitEPwm - This function initializes the ePWM(s) to a known state.
*/
void InitEPwm(void)
{
    /*
    * Initialize ePWM1/2/3/4/5/6
    */
}

/*
* InitEPwmGpio - This function initializes GPIO pins to function as ePWM pins
*
* Each GPIO pin can be configured as a GPIO pin or up to 3 different
* peripheral functional pins. By default all pins come up as GPIO
* inputs after reset.  
*/ 
void InitEPwmGpio(void)
{
    InitEPwm1Gpio();
    InitEPwm2Gpio();
    InitEPwm3Gpio();
#if DSP28_EPWM4
    InitEPwm4Gpio();
#endif /* endif DSP28_EPWM4*/
#if DSP28_EPWM5    
    InitEPwm5Gpio();
#endif /* endif DSP28_EPWM5*/
#if DSP28_EPWM6
    InitEPwm6Gpio();
#endif /* endif DSP28_EPWM6 */
}

/*
* InitEPwm1Gpio - This function initializes GPIO pins to function as ePWM1
*/ 
void InitEPwm1Gpio(void)
{
    EALLOW;

    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user. 
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0U;    /* Enable pull-up on GPIO0 (EPWM1A)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0U;    /* Enable pull-up on GPIO1 (EPWM1B)*/ 

    /*
    * Configure ePWM-1 pins using GPIO regs
    * This specifies which of the possible GPIO pins will be ePWM1 functional 
    * pins. Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1U;   /* Configure GPIO0 as EPWM1A*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1U;   /* Configure GPIO1 as EPWM1B*/

    EDIS;
}

/*
* InitEPwm2Gpio - This function initializes GPIO pins to function as ePWM2
*/
void InitEPwm2Gpio(void)
{
    EALLOW;

    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user. 
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0U;    /* Enable pull-up on GPIO2 (EPWM2A)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0U;    /* Enable pull-up on GPIO3 (EPWM3B)*/

    /*
    * Configure ePWM-2 pins using GPIO regs
    * This specifies which of the possible GPIO pins will be ePWM2 functional 
    * pins. Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1U;   /* Configure GPIO2 as EPWM2A*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1U;   /* Configure GPIO3 as EPWM2B*/

    EDIS;
}

/*
* InitEPwm3Gpio - This function initializes GPIO pins to function as ePWM3
*/
void InitEPwm3Gpio(void)
{
    EALLOW;

    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user. 
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0U;    /* Enable pull-up on GPIO4 (EPWM3A)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0U;    /* Enable pull-up on GPIO5 (EPWM3B)*/

    /*
    * Configure ePWM-3 pins using GPIO regs
    * This specifies which of the possible GPIO pins will be ePWM3 functional
    * pins. Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1U;   /* Configure GPIO4 as EPWM3A*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1U;   /* Configure GPIO5 as EPWM3B*/

    EDIS;
}

#if DSP28_EPWM4
/*
* InitEPwm4Gpio - This function initializes GPIO pins to function as ePWM4
*/
void InitEPwm4Gpio(void)
{
    EALLOW;
    
    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user. 
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0U;    /* Enable pull-up on GPIO6 (EPWM4A)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0U;    /* Enable pull-up on GPIO7 (EPWM4B)*/

    /*
    * Configure ePWM-4 pins using GPIO regs
    * This specifies which of the possible GPIO pins will be ePWM4 functional 
    * pins. Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1U;   /* Configure GPIO6 as EPWM4A*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1U;   /* Configure GPIO7 as EPWM4B*/

    EDIS;
}
#endif /* endif DSP28_EPWM4  */

#if DSP28_EPWM5
/*
* InitEPwm5Gpio - This function initializes GPIO pins to function as ePWM5
*/
void InitEPwm5Gpio(void)
{
    EALLOW;
    
    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user. 
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0U;    /* Enable pull-up on GPIO8 (EPWM5A)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0U;    /* Enable pull-up on GPIO9 (EPWM5B)*/

    /*
    * Configure ePWM-5 pins using GPIO regs
    * This specifies which of the possible GPIO pins will be ePWM5 functional 
    * pins. Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1U;   /* Configure GPIO8 as EPWM5A*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1U;   /* Configure GPIO9 as EPWM5B*/

    EDIS;
}
#endif /* endif DSP28_EPWM5*/

#if DSP28_EPWM6
/*
* InitEPwm6Gpio - This function initializes GPIO pins to function as ePWM6
*/
void InitEPwm6Gpio(void)
{
    EALLOW;

    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user. 
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0U;    /* Enable pull-up on GPIO10 (EPWM6A)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0U;    /* Enable pull-up on GPIO11 (EPWM6B)*/

    /*
    * Configure ePWM-6 pins using GPIO regs
    * This specifies which of the possible GPIO pins will be ePWM6 functional 
    * pins. Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1U;   /* Configure GPIO10 as EPWM6A*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1U;   /* Configure GPIO11 as EPWM6B*/

    EDIS;
}
#endif /* endif DSP28_EPWM6 */

/*
* InitEPwmSyncGpio - This function initializes GPIO pins to function as ePWM 
* Synch pins
*/
void InitEPwmSyncGpio(void)
{
    EALLOW;
    
    /*
    * Configure EPWMSYNCI
    */

    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user. 
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
#if !defined(EPWMSYNCI)    
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0U;  /*Enable pull-up on GPIO6 (EPWMSYNCI)*/
#else
    GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0U;/*Enable pull-up on GPIO32 (EPWMSYNCI)*/  
#endif

    /*
    * Set qualification for selected pins to asynch only
    * This will select synch to SYSCLKOUT for the selected pins.
    * Comment out other unwanted lines.
    */
#if !defined(EPWMSYNCI)        
    /*
    * Synch to SYSCLKOUT GPIO6 (EPWMSYNCI)
    */
    GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0U;
#else    
    /*
    *Synch to SYSCLKOUT GPIO32 (EPWMSYNCI)
    */
    GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 0U;   
#endif

    /*
    * Configure EPwmSync pins using GPIO regs
    * This specifies which of the possible GPIO pins will be EPwmSync 
    * functional pins. Comment out other unwanted lines.
    */
#if !defined(EPWMSYNCI)        
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 2U;  /*Enable pull-up on GPIO6(EPWMSYNCI)*/
#else    
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 2U;/*Enable pull-up on GPIO32(EPWMSYNCI)*/
#endif

    /*
    * Configure EPWMSYNC0
    */

    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user. 
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
#if defined(EPWMSYNC0)        
    /*
    * Enable pull-up on GPIO6 (EPWMSYNC0)
    */
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0U;
    
    /*
    * Enable pull-up on GPIO6 (EPWMSYNC0)
    */
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 3U;
#else    
    /*
    * Enable pull-up on GPIO33 (EPWMSYNC0)
    */
    GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0U;
    
    /*
    * Enable pull-up on GPIO33 (EPWMSYNC0)
    */
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 2U;
#endif    
    EDIS;
}

/*
* InitTzGpio -  This function initializes GPIO pins to function as Trip Zone
* (TZ) pins
*
* Each GPIO pin can be configured as a GPIO pin or up to 3 different
* peripheral functional pins. By default all pins come up as GPIO
* inputs after reset.  
*/ 
void InitTzGpio(void)
{
    EALLOW;

    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user. 
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0U;    /* Enable pull-up on GPIO12 (TZ1)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0U;    /* Enable pull-up on GPIO13 (TZ2)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0U;    /* Enable pull-up on GPIO14 (TZ3)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0U;    /* Enable pull-up on GPIO15 (TZ4)*/
#if !defined(TZ5)
    GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0U;    /* Enable pull-up on GPIO16 (TZ5)*/
#else
    GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0U;    /* Enable pull-up on GPIO28 (TZ5)*/
#endif
#if !defined(TZ6)
    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0U;    /* Enable pull-up on GPIO17 (TZ6) */
#else    
    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0U;    /* Enable pull-up on GPIO29 (TZ6)*/
#endif

    /*
    * Set qualification for selected pins to asynch only
    * Inputs are synchronized to SYSCLKOUT by default.  
    * This will select asynch (no qualification) for the selected pins.
    * Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 3U;  /* Asynch input GPIO12 (TZ1)*/
    GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 3U;  /* Asynch input GPIO13 (TZ2)*/
    GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3U;  /* Asynch input GPIO14 (TZ3)*/
    GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3U;  /* Asynch input GPIO15 (TZ4)*/
#if  !defined(TZ5)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3U;  /* Asynch input GPIO16 (TZ5)*/
#else
    GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3U;  /* Asynch input GPIO28 (TZ5)*/
#endif
#if !defined(TZ6)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3U;  /* Asynch input GPIO17 (TZ6) */
#else    
    GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 3U;  /* Asynch input GPIO29 (TZ6) */ 
#endif

    /*
    * Configure TZ pins using GPIO regs
    * This specifies which of the possible GPIO pins will be TZ functional 
    * pins. Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 1U;  /* Configure GPIO12 as TZ1*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 1U;  /* Configure GPIO13 as TZ2*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 1U;  /* Configure GPIO14 as TZ3*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 1U;  /* Configure GPIO15 as TZ4*/
#if !defined(TZ5)
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 3U;  /* Configure GPIO16 as TZ5*/
#else
    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3U;  /* Configure GPIO28 as TZ5*/
#endif
#if !defined(TZ6)
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 3U;  /* Configure GPIO17 as TZ6*/           
#else
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 3U;  /* Configure GPIO29 as TZ6*/  
#endif
    EDIS;
}

/*
* End of file
*/

