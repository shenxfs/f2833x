/*
*###########################################################################
*
* FILE:   DSP2833x_ECap.c
*
* TITLE:  DSP2833x eCAP Initialization & Support Functions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################

/*
* Included Files
*/
#include "DSP2833x_Device.h"     /* DSP2833x Headerfile Include File*/
#include "DSP2833x_Examples.h"   /* DSP2833x Examples Include File*/

/*
* InitECap - This function initializes the eCAP(s) to a known state.
*/
void InitECap(void)
{
    /*
    * Initialize eCAP1/2/3
    */
}

/*
* InitECapGpio - This function initializes GPIO pins to function as ECAP pins
*
* Each GPIO pin can be configured as a GPIO pin or up to 3 different
* peripheral functional pins. By default all pins come up as GPIO
* inputs after reset.
*
* Caution:
* For each eCAP peripheral
* Only one GPIO pin should be enabled for ECAP operation.
* Comment out other unwanted lines.
*/
void InitECapGpio(void)
{
    InitECap1Gpio();
#if (DSP28_ECAP2)
    InitECap2Gpio();
#endif /* endif DSP28_ECAP2*/
#if (DSP28_ECAP3)
    InitECap3Gpio();
#endif /* endif DSP28_ECAP3*/
#if (DSP28_ECAP4)
    InitECap4Gpio();
#endif /* endif DSP28_ECAP4*/
#if (DSP28_ECAP5)
    InitECap5Gpio();
#endif /* endif DSP28_ECAP5*/
#if (DSP28_ECAP6)
    InitECap6Gpio();
#endif /* endif DSP28_ECAP6*/
}

/*
* InitECap1Gpio - 
*/
void InitECap1Gpio(void)
{
    EALLOW;
    
    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user.
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
#if defined(CAP11)    
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0U;    /* Enable pull-up on GPIO5 (CAP1)*/
#elif defined(CAP12)
    GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0U;     /* Enable pull-up on GPIO24 (CAP1)*/
#else
    GpioCtrlRegs.GPBPUD.bit.GPIO34 = 0U;   /* Enable pull-up on GPIO34 (CAP1)*/
#endif

    /*
    * Inputs are synchronized to SYSCLKOUT by default.
    * Comment out other unwanted lines.
    */
#if defined(CAP11)    
    GpioCtrlRegs.GPAQSEL1.bit.GPIO5 = 0U;   /*Synch to SYSCLKOUT GPIO5 (CAP1)*/
#elif defined(CAP12)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 0U;   /*Synch to SYSCLKOUT GPIO24 (CAP1)*/
#else
    GpioCtrlRegs.GPBQSEL1.bit.GPIO34 = 0U;  /*Synch to SYSCLKOUT GPIO34 (CAP1)*/
#endif

    /*
    * Configure eCAP-1 pins using GPIO regs
    * This specifies which of the possible GPIO pins will be eCAP1 functional pins.
    * Comment out other unwanted lines.
    */
#if defined(CAP11)    
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 3U;    /* Configure GPIO5 as CAP1*/
#elif defined(CAP12)
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 1U;    /* Configure GPIO24 as CAP1*/
#else
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 1U;   /* Configure GPIO24 as CAP1*/
#endif
    EDIS;
}

#if DSP28_ECAP2
/*
* InitECap2Gpio -
*/
void InitECap2Gpio(void)
{
    EALLOW;
    
    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user.
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
#if defined(CAP21)    
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0U;     /* Enable pull-up on GPIO7 (CAP2)*/
#elif defined(CAP22)
    GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0U;    /* Enable pull-up on GPIO25 (CAP2)*/
#else    
    GpioCtrlRegs.GPBPUD.bit.GPIO37 = 0U;    /* Enable pull-up on GPIO37 (CAP2)*/
#endif

    /*
    * Inputs are synchronized to SYSCLKOUT by default.
    * Comment out other unwanted lines.
    */
#if defibed(CAP21)    
    GpioCtrlRegs.GPAQSEL1.bit.GPIO7 = 0U;    /*Synch to SYSCLKOUT GPIO7 (CAP2)*/
#elif defined(CAP22)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 0U;  /*Synch to SYSCLKOUT GPIO25 (CAP2)*/
#else
    GpioCtrlRegs.GPBQSEL1.bit.GPIO37 = 0U;  /*Synch to SYSCLKOUT GPIO37 (CAP2)*/
#endif

    /*
    * Configure eCAP-2 pins using GPIO regs
    * This specifies which of the possible GPIO pins will be eCAP2 functional 
    * pins. Comment out other unwanted lines.
    */
#if defined(CAP21)    
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 3U;    /* Configure GPIO7 as CAP2*/
#elif defined(CAP22)    
    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 1U;   /* Configure GPIO25 as CAP2*/
#else    
    GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 3U;   /* Configure GPIO37 as CAP2*/
#endif
    EDIS;
}
#endif /* endif DSP28_ECAP2*/

#if DSP28_ECAP3
/*
* InitECap3Gpio - 
*/
void InitECap3Gpio(void)
{
   EALLOW;
/*
* Enable internal pull-up for the selected pins 
* Pull-ups can be enabled or disabled by the user.
* This will enable the pullups for the specified pins.
* Comment out other unwanted lines.
*/
#if defined(CAP31)
   GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0U;      /* Enable pull-up on GPIO9 (CAP3)*/
#else
   GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0U;     /* Enable pull-up on GPIO26 (CAP3)*/
#endif

/*
* Inputs are synchronized to SYSCLKOUT by default.
* Comment out other unwanted lines.
*/
#if defined(CAP31)
   GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 0U;    /* Synch to SYSCLKOUT GPIO9 (CAP3)*/
#else
   GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 0U;   /* Synch to SYSCLKOUT GPIO26 (CAP3)*/
#endif

/*
* Configure eCAP-3 pins using GPIO regs
* This specifies which of the possible GPIO pins will be eCAP3 functional pins.
* Comment out other unwanted lines.
*/
#if defined(CAP31)
   GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 3U;     /* Configure GPIO9 as CAP3*/
#else
   GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 1U;    /* Configure GPIO26 as CAP3*/
#endif
    EDIS;
}
#endif /* endif DSP28_ECAP3*/


#if DSP28_ECAP4
void InitECap4Gpio(void)
{
   EALLOW;
/*
* Enable internal pull-up for the selected pins 
* Pull-ups can be enabled or disabled by the user.
* This will enable the pullups for the specified pins.
* Comment out other unwanted lines.
*/
#if defined(CAP41)
   GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0U;   /* Enable pull-up on GPIO11 (CAP4)*/
#else
   GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0U;   /* Enable pull-up on GPIO27 (CAP4)*/
#endif

/*
* Inputs are synchronized to SYSCLKOUT by default.
* Comment out other unwanted lines.
*/
#if defined(CAP41)
   GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 0U; /* Synch to SYSCLKOUT GPIO11 (CAP4)*/
#else   
   GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 0U; /* Synch to SYSCLKOUT GPIO27 (CAP4)*/
#endif

/*
* Configure eCAP-4 pins using GPIO regs
* This specifies which of the possible GPIO pins will be eCAP4 functional pins.
* Comment out other unwanted lines.
*/
#if defined(CAP41)
   GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 3U;  /* Configure GPIO11 as CAP4*/
#else   
   GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 1U;  /* Configure GPIO27 as CAP4*/
#endif
    EDIS;
}
#endif /* endif DSP28_ECAP4*/


#if DSP28_ECAP5
void InitECap5Gpio(void)
{
   EALLOW;
/*
* Enable internal pull-up for the selected pins 
* Pull-ups can be enabled or disabled by the user.
* This will enable the pullups for the specified pins.
* Comment out other unwanted lines.
*/
#if defined(CAP51)
   GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0U;     /* Enable pull-up on GPIO3 (CAP5)*/
#else
   GpioCtrlRegs.GPBPUD.bit.GPIO48 = 0U;    /* Enable pull-up on GPIO48 (CAP5)*/
#endif

/*
* Inputs are synchronized to SYSCLKOUT by default.
* Comment out other unwanted lines.
*/
#if defined(CAP51)
   GpioCtrlRegs.GPAQSEL1.bit.GPIO3 = 0U;  /* Synch to SYSCLKOUT GPIO3 (CAP5)*/
#else
   GpioCtrlRegs.GPBQSEL2.bit.GPIO48 = 0U; /* Synch to SYSCLKOUT GPIO48 (CAP5)*/
#endif

/*
* Configure eCAP-5 pins using GPIO regs
* This specifies which of the possible GPIO pins will be eCAP5 functional pins.
* Comment out other unwanted lines.
*/
#if defined(CAP51)
   GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 2U;   /* Configure GPIO3 as CAP5*/
#else
   GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 1U;  /* Configure GPIO48 as CAP5*/
#endif
    EDIS;
}
#endif /* endif DSP28_ECAP5*/


#if DSP28_ECAP6
void InitECap6Gpio(void)
{
   EALLOW;
/*
* Enable internal pull-up for the selected pins 
* Pull-ups can be enabled or disabled by the user.
* This will enable the pullups for the specified pins.
* Comment out other unwanted lines.
*/
#if defined(CAP61)
   GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0U;     /* Enable pull-up on GPIO1 (CAP6)*/
#else   
   GpioCtrlRegs.GPBPUD.bit.GPIO49 = 0U;    /* Enable pull-up on GPIO49 (CAP6)*/
#endif

/*
* Inputs are synchronized to SYSCLKOUT by default.
* Comment out other unwanted lines.
*/
#if defined(CAP61)
   GpioCtrlRegs.GPAQSEL1.bit.GPIO1 = 0U;  /* Synch to SYSCLKOUT GPIO1 (CAP6)*/
#else   
   GpioCtrlRegs.GPBQSEL2.bit.GPIO49 = 0U; /* Synch to SYSCLKOUT GPIO49 (CAP6)*/
#endif

/*
* Configure eCAP-5 pins using GPIO regs
* This specifies which of the possible GPIO pins will be eCAP6 functional pins.
* Comment out other unwanted lines.
*/
#if defined(CAP61)
   GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 2U;   /* Configure GPIO1 as CAP6*/
#else   
   GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 1U;  /* Configure GPIO49 as CAP6*/
#endif
    EDIS;
}
#endif /* endif DSP28_ECAP6*/

/*===========================================================================
* End of file.
*===========================================================================*/
