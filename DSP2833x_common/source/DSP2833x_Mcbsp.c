/*
*###########################################################################
*
* FILE:	DSP2833x_McBSP.c
*
* TITLE:	DSP2833x Device McBSP Initialization & Support Functions.
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
* MCBSP_INIT_DELAY determines the amount of CPU cycles in the 2 sample rate
* generator (SRG) cycles required for the Mcbsp initialization routine.
* MCBSP_CLKG_DELAY determines the amount of CPU cycles in the 2 clock
* generator (CLKG) cycles required for the Mcbsp initialization routine.
* For the functions defined in Mcbsp.c, MCBSP_INIT_DELAY and MCBSP_CLKG_DELAY
* are based off of either a 150 MHz SYSCLKOUT (default) or a 100 MHz SYSCLKOUT
*/

/*
* CPU_FRQ_100MHZ and CPU_FRQ_150MHZ are defined in DSP2833x_Examples.h
*/

/*
* For 150 MHz SYSCLKOUT(default)
*/
#if CPU_FRQ_150MHZ
    #define CPU_SPD              150000000UL

    /*
    * SRG input is LSPCLK (SYSCLKOUT/4) for examples
    */
    #define MCBSP_SRG_FREQ       (CPU_SPD/4)                    
#endif

/*
* For 100 MHz SYSCLKOUT
*/
#if CPU_FRQ_100MHZ
    #define CPU_SPD              100000000UL
    
    /*
    * SRG input is LSPCLK (SYSCLKOUT/4) for examples
    */
    #define MCBSP_SRG_FREQ       CPU_SPD/4
#endif

#define CLKGDV_VAL           1

/*
*  of CPU cycles in 2 SRG cycles-init delay
*/
#define MCBSP_INIT_DELAY     (2U*(CPU_SPD/MCBSP_SRG_FREQ))

/*
*  of CPU cycles in 2 CLKG cycles-init delay
*/
#define MCBSP_CLKG_DELAY     (2U*(CPU_SPD/(MCBSP_SRG_FREQ/(1U+CLKGDV_VAL))))

/*
* Function Prototypes
*/
void delay_loop(void);		/* Delay function used for SRG initialization*/
void clkg_delay_loop(void); /* Delay function used for CLKG initialization*/

/*
* InitMcbsp - This function initializes the McBSP to a known state.
*/
void InitMcbsp(void)
{
    InitMcbspa();
#if DSP28_MCBSPB
    InitMcbspb();
#endif /* end DSP28_MCBSPB*/
}

/*
* InitMcbspa - This function initializes McBSPa to a known state.
*/
void InitMcbspa(void)
{
    /*
    * McBSP-A register settings
    */
    
    /*
    * Reset FS generator, sample rate generator & transmitter
    */
    McbspaRegs.SPCR2.all=0x0000U;
    
    McbspaRegs.SPCR1.all=0x0000U;        /* Reset Receiver, Right justify word*/
    
    /*
    * Enable loopback mode for test. 
    * Comment out for normal McBSP transfer mode.
    */
    McbspaRegs.SPCR1.bit.DLB = 1U;

    McbspaRegs.MFFINT.all = 0x0U;          /* Disable all interrupts*/

    /*
    * Single-phase frame, 1 word/frame, No companding	(Receive)
    */
    McbspaRegs.RCR2.all = 0x0U;
    McbspaRegs.RCR1.all = 0x0U;
    
    /*
    * Single-phase frame, 1 word/frame, No companding	(Transmit)
    */
    McbspaRegs.XCR2.all = 0x0U;
    McbspaRegs.XCR1.all = 0x0U;

    /*
    * FSX generated internally, FSR derived from an external source
    */
    McbspaRegs.PCR.bit.FSXM = 1U;
    
    /*
    * CLKX generated internally, CLKR derived from an external source
    */
    McbspaRegs.PCR.bit.CLKXM = 1U;

    /*
    * CLKSM=1 (If SCLKME=0, i/p clock to SRG is LSPCLK)
    */
    McbspaRegs.SRGR2.bit.CLKSM = 1U;
    
    McbspaRegs.SRGR2.bit.FPER = 31U;     /* FPER = 32 CLKG periods*/

    McbspaRegs.SRGR1.bit.FWID = 0U;      /* Frame Width = 1 CLKG period*/
    
    /*
    * CLKG frequency = LSPCLK/(CLKGDV+1)
    */
    McbspaRegs.SRGR1.bit.CLKGDV = CLKGDV_VAL;

    delay_loop();                   /* Wait at least 2 SRG clock cycles*/

    McbspaRegs.SPCR2.bit.GRST = 1U;    /* Enable the sample rate generator*/
    clkg_delay_loop();              /* Wait at least 2 CLKG cycles*/
    McbspaRegs.SPCR2.bit.XRST = 1U;    /* Release TX from Reset*/
    McbspaRegs.SPCR1.bit.RRST = 1U;    /* Release RX from Reset*/
    McbspaRegs.SPCR2.bit.FRST = 1U;    /* Frame Sync Generator reset*/
}

/*
* InitMcbspb - This function initializes McBSPb to a known state.
*/
#if (DSP28_MCBSPB)
void InitMcbspb(void)
{
    /*
    * McBSP-B register settings
    */
    
    /*
    * Reset FS generator, sample rate generator & transmitter
    */
    McbspbRegs.SPCR2.all = 0x0000U;
    
    McbspbRegs.SPCR1.all = 0x0000U;		/* Reset Receiver, Right justify word*/
    
    /*
    * Enable loopback mode for test. 
    * Comment out for normal McBSP transfer mode.
    */
    McbspbRegs.SPCR1.bit.DLB = 1U;

    McbspbRegs.MFFINT.all = 0x0U;			/* Disable all interrupts*/

    /*
    * Single-phase frame, 1 word/frame, No companding	(Receive)
    */
    McbspbRegs.RCR2.all = 0x0U;
    McbspbRegs.RCR1.all = 0x0U;

    /*
    * Single-phase frame, 1 word/frame, No companding	(Transmit)
    */
    McbspbRegs.XCR2.all = 0x0U;
    McbspbRegs.XCR1.all = 0x0U;

    /*
    * CLKSM=1 (If SCLKME=0, i/p clock to SRG is LSPCLK)
    */
    McbspbRegs.SRGR2.bit.CLKSM = 1U;
    McbspbRegs.SRGR2.bit.FPER = 31U;		/* FPER = 32 CLKG periods*/

    McbspbRegs.SRGR1.bit.FWID = 0U;      /* Frame Width = 1 CLKG period*/
    
    /*
    * CLKG frequency = LSPCLK/(CLKGDV+1)
    */
    McbspbRegs.SRGR1.bit.CLKGDV = CLKGDV_VAL;

    /*
    * FSX generated internally, FSR derived from an external source
    */
    McbspbRegs.PCR.bit.FSXM = 1U;
    
    /*
    * CLKX generated internally, CLKR derived from an external source
    */
    McbspbRegs.PCR.bit.CLKXM = 1U;
    
    delay_loop();                   /* Wait at least 2 SRG clock cycles*/
    McbspbRegs.SPCR2.bit.GRST = 1U;    /* Enable the sample rate generator*/
    clkg_delay_loop();              /* Wait at least 2 CLKG cycles*/
    McbspbRegs.SPCR2.bit.XRST = 1U;    /* Release TX from Reset*/
    McbspbRegs.SPCR1.bit.RRST = 1U;    /* Release RX from Reset*/
    McbspbRegs.SPCR2.bit.FRST = 1U;    /* Frame Sync Generator reset*/
}
#endif /* end DSP28_MCBSPB*/

/*
* InitMcbspa8bit - McBSP-A 8-bit Length
*/
void InitMcbspa8bit(void)
{
    McbspaRegs.RCR1.bit.RWDLEN1 = 0U;     /* 8-bit word*/
    McbspaRegs.XCR1.bit.XWDLEN1 = 0U;     /* 8-bit word*/
}

/*
* InitMcbspa12bit - McBSP-A 12 bit Length
*/
void InitMcbspa12bit(void)
{
    McbspaRegs.RCR1.bit.RWDLEN1 = 1U;     /* 12-bit word*/
    McbspaRegs.XCR1.bit.XWDLEN1 = 1U;     /* 12-bit word*/
}

/*
* InitMcbspa16bit - McBSP-A 16 bit Length
*/
void InitMcbspa16bit(void)
{
    McbspaRegs.RCR1.bit.RWDLEN1 = 2U;      /* 16-bit word*/
    McbspaRegs.XCR1.bit.XWDLEN1 = 2U;      /* 16-bit word*/
}

/*
* InitMcbspa20bit - McBSP-A 20 bit Length
*/
void InitMcbspa20bit(void)
{
    McbspaRegs.RCR1.bit.RWDLEN1 = 3U;     /* 20-bit word*/
    McbspaRegs.XCR1.bit.XWDLEN1 = 3U;     /* 20-bit word*/
}

/*
* InitMcbspa24bit - McBSP-A 24 bit Length
*/
void InitMcbspa24bit(void)
{
    McbspaRegs.RCR1.bit.RWDLEN1 = 4U;     /* 24-bit word*/
    McbspaRegs.XCR1.bit.XWDLEN1 = 4U;     /* 24-bit word*/
}

/*
* InitMcbspa32bit - McBSP-A 32 bit Length
*/
void InitMcbspa32bit(void)
{
    McbspaRegs.RCR1.bit.RWDLEN1 = 5U;     /* 32-bit word*/
    McbspaRegs.XCR1.bit.XWDLEN1 = 5U;     /* 32-bit word*/
}

/*
* McBSP-B Data Lengths
*/
#if (DSP28_MCBSPB)
/*
* InitMcbspb8bit - McBSP-B 8-bit Length
*/
void InitMcbspb8bit(void)
{
    McbspbRegs.RCR1.bit.RWDLEN1 = 0U;     /* 8-bit word*/
    McbspbRegs.XCR1.bit.XWDLEN1 = 0U;     /* 8-bit word*/
}

/*
* InitMcbspb12bit - McBSP-B 12 bit Length
*/
void InitMcbspb12bit(void)
{
    McbspbRegs.RCR1.bit.RWDLEN1 = 1U;     /* 12-bit word*/
    McbspbRegs.XCR1.bit.XWDLEN1 = 1U;     /* 12-bit word*/
}

/*
* InitMcbspb16bit - McBSP-B 16 bit Length
*/
void InitMcbspb16bit(void)
{
    McbspbRegs.RCR1.bit.RWDLEN1 = 2U;     /* 16-bit word*/
    McbspbRegs.XCR1.bit.XWDLEN1 = 2U;     /* 16-bit word*/
}

/*
* InitMcbspb20bit - McBSP-B 20 bit Length
*/
void InitMcbspb20bit(void)
{
    McbspbRegs.RCR1.bit.RWDLEN1 = 3U;     /* 20-bit word*/
    McbspbRegs.XCR1.bit.XWDLEN1 = 3U;     /* 20-bit word*/
}

/*
* InitMcbspb24bit - McBSP-B 24 bit Length
*/
void InitMcbspb24bit(void)
{
    McbspbRegs.RCR1.bit.RWDLEN1 = 4U;     /* 24-bit word*/
    McbspbRegs.XCR1.bit.XWDLEN1 = 4U;     /* 24-bit word*/
}

/*
* InitMcbspb32bit - McBSP-B 32 bit Length
*/
void InitMcbspb32bit(void)
{
    McbspbRegs.RCR1.bit.RWDLEN1 = 5U;     /* 32-bit word*/
    McbspbRegs.XCR1.bit.XWDLEN1 = 5U;     /* 32-bit word*/
}

#endif /*end DSP28_MCBSPB*/

/*
* InitMcbspGpio - 
*/
void InitMcbspGpio(void)
{
    InitMcbspaGpio();
#if DSP28_MCBSPB
    InitMcbspbGpio();
#endif               /* end DSP28_MCBSPB*/
}

/*
* InitMcbspaGpio - This function initializes GPIO pins to function as McBSP-A
*/
void InitMcbspaGpio(void)
{
    EALLOW;

    /*
    * Configure McBSP-A pins using GPIO regs
    * This specifies which of the possible GPIO pins will be McBSP functional
    * pins.
    * Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 2U;	/* GPIO20 is MDXA pin*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 2U;	/* GPIO21 is MDRA pin*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 2U;	/* GPIO22 is MCLKXA pin*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 2U;	/* GPIO23 is MFSXA pin*/
#if defined(MCBSPA1)
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 2U;		/* GPIO7 is MCLKRA pin*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 2U;		/* GPIO5 is MFSRA pin*/
#else
    GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 1U;	/* GPIO58 is MCLKRA pin*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 1U;	/* GPIO59 is MFSRA pin*/
#endif

    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user.
    * This will enable the pullups for the specified pins.
    */
    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0U;   /* Enable pull-up on GPIO20 (MDXA)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0U;   /* Enable pull-up on GPIO21 (MDRA)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0U;   /* Enable pull-up on GPIO22 (MCLKXA)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0U;   /* Enable pull-up on GPIO23 (MFSXA)*/
#if defined(MCBSPA1)
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0U;    /* Enable pull-up on GPIO7 (MCLKRA)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0U;    /* Enable pull-up on GPIO5 (MFSRA) */
#else
    GpioCtrlRegs.GPBPUD.bit.GPIO58 = 0U;  /* Enable pull-up on GPIO58 (MCLKRA)*/
    GpioCtrlRegs.GPBPUD.bit.GPIO59 = 0U;  /* Enable pull-up on GPIO59 (MFSRA) */
#endif

    /*
    * Set qualification for selected input pins to asynch only
    * This will select asynch (no qualification) for the selected pins.
    * Comment out other unwanted lines.
    */
    GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 3U;   /* Asynch input GPIO21 (MDRA)*/
    GpioCtrlRegs.GPAQSEL2.bit.GPIO22 = 3U;   /* Asynch input GPIO22 (MCLKXA)*/
    GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 3U;   /* Asynch input GPIO23 (MFSXA)*/
#if defined(MCBSPA1)    
    GpioCtrlRegs.GPAQSEL1.bit.GPIO5 = 3U;    /* Asynch input GPIO5 (MFSRA)*/
    GpioCtrlRegs.GPAQSEL1.bit.GPIO7 = 3U;    /* Asynch input GPIO7 (MCLKRA)*/
#else
    GpioCtrlRegs.GPBQSEL2.bit.GPIO59 = 3U; /* Asynch input GPIO59 (MFSRA)*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO58 = 3U; /* Asynch input GPIO58(MCLKRA)*/
#endif
    EDIS;
}

/*
* InitMcbspbGpio - This function initializes GPIO pins to function as McBSP-B
*/
#if DSP28_MCBSPB
void InitMcbspbGpio(void)
{
    EALLOW;
    
    /*
    * Configure McBSP-A pins using GPIO regs
    * This specifies which of the possible GPIO pins will be McBSP functional
    * pins.
    * Comment out other unwanted lines.
    */
#if defined(MCBSPB1)
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 3U;	    /* GPIO12 is MDXB pin*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 3U;	    /* GPIO13 is MDRB pin*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 3U;	    /* GPIO14 is MCLKXB pin*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 3U;	    /* GPIO15 is MFSXB pin*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 1U;	    /* GPIO60 is MCLKRB pin*/
    GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 1U;	    /* GPIO61 is MFSRB pin*/
#else
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 3U;	    /* GPIO24 is MDXB pin*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 3U;	    /* GPIO25 is MDRB pin*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 3U;	    /* GPIO26 is MCLKXB pin*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 3U;	    /* GPIO27 is MFSXB pin*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO1  = 3U;		    /* GPIO1 is MFSRB pin*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO3  = 3U;		    /* GPIO3 is MCLKRB pin*/
#endif

    /*
    * Enable internal pull-up for the selected pins
    * Pull-ups can be enabled or disabled by the user.
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
#if defined(MCBSPB1)    
    GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0U;	/*Enable pull-up on GPIO12 (MDXB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0U;	/*Enable pull-up on GPIO13 (MDRB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0U;	/*Enable pull-up on GPIO14 (MCLKXB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0U;	/*Enable pull-up on GPIO15 (MFSXB)*/
    GpioCtrlRegs.GPBPUD.bit.GPIO60 = 0U;	/*Enable pull-up on GPIO60 (MCLKRB)*/
    GpioCtrlRegs.GPBPUD.bit.GPIO61 = 0U;	/*Enable pull-up on GPIO61 (MFSRB)*/
#else
    GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0U;    /*Enable pull-up on GPIO24 (MDXB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0U;    /*Enable pull-up on GPIO25 (MDRB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0U	    /*Enable pull-up on GPIO26 (MCLKXB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0U;    /*Enable pull-up on GPIO27 (MFSXB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO1  = 0U;	/*Enable pull-up on GPIO1 (MFSRB) */
    GpioCtrlRegs.GPAPUD.bit.GPIO3  = 0U;	/*Enable pull-up on GPIO3 (MCLKRB)*/
#endif

    /*
    * Set qualification for selected input pins to asynch only
    * This will select asynch (no qualification) for the selected pins.
    * Comment out other unwanted lines.
    */
#if defined(MCBSPB1)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 3U; /* Asynch input GPIO13 (MDRB)*/
    GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3U; /* Asynch input GPIO14 (MCLKXB)*/
    GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3U; /* Asynch input GPIO15 (MFSXB)*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO60 = 3U; /* Asynch input GPIO60 (MCLKRB)*/
    GpioCtrlRegs.GPBQSEL2.bit.GPIO61 = 3U; /* Asynch input GPIO61 (MFSRB)*/
#else
    GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 3U;   /* Asynch input GPIO25 (MDRB)*/
    GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 3U;   /* Asynch input GPIO26(MCLKXB)*/
    GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 3U;   /* Asynch input GPIO27 (MFSXB)*/
    GpioCtrlRegs.GPAQSEL1.bit.GPIO3  = 3U;   /* Asynch input GPIO3 (MCLKRB)*/
    GpioCtrlRegs.GPAQSEL1.bit.GPIO1  = 3U;   /* Asynch input GPIO1 (MFSRB)*/
#endif
    EDIS;
}
#endif /* end DSP28_MCBSPB*/

/*
* delay_loop - 
*/
void delay_loop(void)
{
    uint32_t      i;
    
    /*
    * delay in McBsp init. must be at least 2 SRG cycles
    */
    for (i = 0; i < MCBSP_INIT_DELAY; i++)
    {
      ;  
    }
}

/*
* clkg_delay_loop - 
*/
void clkg_delay_loop(void)
{
    uint32_t      i;
    
    /*
    * delay in McBsp init. must be at least 2 SRG cycles
    */
    for (i = 0; i < MCBSP_CLKG_DELAY; i++)
    {
      ;
    } 
}

/*
* End of File
*/

