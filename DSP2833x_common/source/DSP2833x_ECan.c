/*
*###########################################################################
*
* FILE:	DSP2833x_ECan.c
*
* TITLE:	DSP2833x Enhanced CAN Initialization & Support Functions.
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
* InitECan - This function initializes the eCAN module to a known state.
*/
void InitECan(void)
{
    InitECana();
#if DSP28_ECANB
    InitECanb();
#endif /* if DSP28_ECANB*/
}

/*
* InitECana - Initialize eCAN-A module
*/
void InitECana(void)
{
    /*
    * Create a shadow register structure for the CAN control registers. This 
    * is needed, since only 32-bit access is allowed to these registers. 
    * 16-bit access to these registers could potentially corrupt the register
    * contents or return false data. This is especially true while writing 
    * to/reading from a bit (or group of bits) among bits 16 - 31
    */
    struct ECAN_REGS ECanaShadow;

    EALLOW;		/* EALLOW enables access to protected bits*/

    /*
    * Configure eCAN RX and TX pins for CAN operation using eCAN regs
    */
    ECanaShadow.CANTIOC.all = ECanaRegs.CANTIOC.all;
    ECanaShadow.CANTIOC.bit.TXFUNC = 1U;
    ECanaRegs.CANTIOC.all = ECanaShadow.CANTIOC.all;

    ECanaShadow.CANRIOC.all = ECanaRegs.CANRIOC.all;
    ECanaShadow.CANRIOC.bit.RXFUNC = 1U;
    ECanaRegs.CANRIOC.all = ECanaShadow.CANRIOC.all;

    /*
    * Configure eCAN for HECC mode - (reqd to access mailboxes 16 thru 31)
    * HECC mode also enables time-stamping feature
    */
    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.SCB = 1U;
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

    /*
    * Initialize all bits of 'Master Control Field' to zero
    * Some bits of MSGCTRL register come up in an unknown state. For proper 
    * operation, all bits (including reserved bits) of MSGCTRL must be 
    * initialized to zero
    */
    ECanaMboxes.MBOX0.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX1.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX2.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX3.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX4.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX5.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX6.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX7.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX8.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX9.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX10.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX11.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX12.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX13.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX14.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX15.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX16.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX17.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX18.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX19.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX20.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX21.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX22.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX23.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX24.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX25.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX26.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX27.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX28.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX29.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX30.MSGCTRL.all = 0x00000000U;
    ECanaMboxes.MBOX31.MSGCTRL.all = 0x00000000U;

    /*
    * TAn, RMPn, GIFn bits are all zero upon reset and are cleared again
    * as a matter of precaution.
    */
    ECanaRegs.CANTA.all	= 0xFFFFFFFFU;       /* Clear all TAn bits*/

    ECanaRegs.CANRMP.all = 0xFFFFFFFFU;      /* Clear all RMPn bits*/

    ECanaRegs.CANGIF0.all = 0xFFFFFFFFU;     /* Clear all interrupt flag bits*/
    ECanaRegs.CANGIF1.all = 0xFFFFFFFFU;

    /*
    * Configure bit timing parameters for eCANA
    */
    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.CCR = 1U ;            /* Set CCR = 1*/
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

    ECanaShadow.CANES.all = ECanaRegs.CANES.all;

    do
    {
        ECanaShadow.CANES.all = ECanaRegs.CANES.all;
    } while(ECanaShadow.CANES.bit.CCE != 1U );  	/* Wait for CCE bit to be set*/

    ECanaShadow.CANBTC.all = 0U;

    /*
    * CPU_FRQ_150MHz is defined in DSP2833x_Examples.h
    */
    #if (CPU_FRQ_150MHZ)
    /*
    * The following block for all 150 MHz SYSCLKOUT 
    * (75 MHz CAN clock) - default. Bit rate = 1 Mbps See Note at End of File
    */
    ECanaShadow.CANBTC.bit.BRPREG = 4U;
    ECanaShadow.CANBTC.bit.TSEG2REG = 2U;
    ECanaShadow.CANBTC.bit.TSEG1REG = 10U;
    #endif
    
    /*
    * CPU_FRQ_100MHz is defined in DSP2833x_Examples.h
    */
    #if (CPU_FRQ_100MHZ)
    /*
    * The following block is only for 100 MHz SYSCLKOUT (50 MHz CAN clock). 
    * Bit rate = 1 Mbps See Note at End of File
    */
    ECanaShadow.CANBTC.bit.BRPREG = 4U;
    ECanaShadow.CANBTC.bit.TSEG2REG = 1U;
    ECanaShadow.CANBTC.bit.TSEG1REG = 6U;
    #endif

    ECanaShadow.CANBTC.bit.SAM = 1U;
    ECanaRegs.CANBTC.all = ECanaShadow.CANBTC.all;

    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.CCR = 0U ;            /* Set CCR = 0*/
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

    ECanaShadow.CANES.all = ECanaRegs.CANES.all;

    do
    {
        ECanaShadow.CANES.all = ECanaRegs.CANES.all;
    } while(ECanaShadow.CANES.bit.CCE != 0U );/* Wait for CCE bit to be  cleared

    /*
    * Disable all Mailboxes
    */
    ECanaRegs.CANME.all = 0U;		/* Required before writing the MSGIDs*/

    EDIS;
}

#if (DSP28_ECANB)
/*
* Initialize eCAN-B module
*/
void InitECanb(void)
{
    /*
    * Create a shadow register structure for the CAN control registers. This 
    * is needed, since only 32-bit access is allowed to these registers. 
    * 16-bit access to these registers could potentially corrupt the register 
    * contents or return false data. This is especially true while writing 
    * to/reading from a bit (or group of bits) among bits 16 - 31
    */
    struct ECAN_REGS ECanbShadow;

    EALLOW;		/* EALLOW enables access to protected bits*/

    /*
    * Configure eCAN RX and TX pins for CAN operation using eCAN regs
    */
    ECanbShadow.CANTIOC.all = ECanbRegs.CANTIOC.all;
    ECanbShadow.CANTIOC.bit.TXFUNC = 1U;
    ECanbRegs.CANTIOC.all = ECanbShadow.CANTIOC.all;

    ECanbShadow.CANRIOC.all = ECanbRegs.CANRIOC.all;
    ECanbShadow.CANRIOC.bit.RXFUNC = 1U;
    ECanbRegs.CANRIOC.all = ECanbShadow.CANRIOC.all;

    /*
    * Configure eCAN for HECC mode - (read to access mailboxes 16 thru 31)
    */
    ECanbShadow.CANMC.all = ECanbRegs.CANMC.all;
    ECanbShadow.CANMC.bit.SCB = 1U;
    ECanbRegs.CANMC.all = ECanbShadow.CANMC.all;

    /*
    * Initialize all bits of 'Master Control Field' to zero
    * Some bits of MSGCTRL register come up in an unknown state. For proper 
    * operation, all bits (including reserved bits) of MSGCTRL must be 
    * initialized to zero
    */
    ECanbMboxes.MBOX0.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX1.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX2.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX3.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX4.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX5.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX6.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX7.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX8.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX9.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX10.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX11.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX12.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX13.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX14.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX15.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX16.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX17.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX18.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX19.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX20.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX21.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX22.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX23.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX24.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX25.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX26.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX27.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX28.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX29.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX30.MSGCTRL.all = 0x00000000U;
    ECanbMboxes.MBOX31.MSGCTRL.all = 0x00000000U;

    /*
    * TAn, RMPn, GIFn bits are all zero upon reset and are cleared again
    * as a matter of precaution.
    */
    ECanbRegs.CANTA.all	= 0xFFFFFFFFU;	/* Clear all TAn bits*/

    ECanbRegs.CANRMP.all = 0xFFFFFFFFU;	/* Clear all RMPn bits*/

    ECanbRegs.CANGIF0.all = 0xFFFFFFFFU;	/* Clear all interrupt flag bits*/
    ECanbRegs.CANGIF1.all = 0xFFFFFFFFU;

    /*
    * Configure bit timing parameters for eCANB
    */
    ECanbShadow.CANMC.all = ECanbRegs.CANMC.all;
    ECanbShadow.CANMC.bit.CCR = 1U ;            /* Set CCR = 1*/
    ECanbRegs.CANMC.all = ECanbShadow.CANMC.all;

    ECanbShadow.CANES.all = ECanbRegs.CANES.all;

    do
    {
        ECanbShadow.CANES.all = ECanbRegs.CANES.all;
    } while(ECanbShadow.CANES.bit.CCE != 1U); /* Wait for CCE bit to be  cleared*/

    ECanbShadow.CANBTC.all = 0U;

    /*
    * CPU_FRQ_150MHz is defined in DSP2833x_Examples.h
    */
    #if (CPU_FRQ_150MHZ)
    /*
    * The following block for all 150 MHz SYSCLKOUT 
    * (75 MHz CAN clock) - default. Bit rate = 1 Mbps See Note at end of file
    */
    ECanbShadow.CANBTC.bit.BRPREG = 4U;
    ECanbShadow.CANBTC.bit.TSEG2REG = 2U;
    ECanbShadow.CANBTC.bit.TSEG1REG = 10U;
    #endif
    
    /*
    * CPU_FRQ_100MHz is defined in DSP2833x_Examples.h
    */
    #if (CPU_FRQ_100MHZ)
    /*
    * The following block is only for 100 MHz SYSCLKOUT (50 MHz CAN clock).
    * Bit rate = 1 Mbps  See Note at end of file
    */
    ECanbShadow.CANBTC.bit.BRPREG = 4U;
    ECanbShadow.CANBTC.bit.TSEG2REG = 1U;
    ECanbShadow.CANBTC.bit.TSEG1REG = 6U;
    #endif

    ECanbShadow.CANBTC.bit.SAM = 1U;
    ECanbRegs.CANBTC.all = ECanbShadow.CANBTC.all;

    ECanbShadow.CANMC.all = ECanbRegs.CANMC.all;
    ECanbShadow.CANMC.bit.CCR = 0U ;            /* Set CCR = 0*/
    ECanbRegs.CANMC.all = ECanbShadow.CANMC.all;

    ECanbShadow.CANES.all = ECanbRegs.CANES.all;

    do
    {
        ECanbShadow.CANES.all = ECanbRegs.CANES.all;
    } while(ECanbShadow.CANES.bit.CCE != 0U );/* Wait for CCE bit to be  cleared*/

    /*
    * Disable all Mailboxes
    */
    ECanbRegs.CANME.all = 0U;		/* Required before writing the MSGIDs*/

    EDIS;
}
#endif /* if DSP28_ECANB*/

/*
* InitECanGpio - This function initializes GPIO pins to function as eCAN pins
*
* Each GPIO pin can be configured as a GPIO pin or up to 3 different
* peripheral functional pins. By default all pins come up as GPIO
* inputs after reset.
*
* Caution:
* Only one GPIO pin should be enabled for CANTXA/B operation.
* Only one GPIO pin shoudl be enabled for CANRXA/B operation.
* Comment out other unwanted lines.
*/
void InitECanGpio(void)
{
    InitECanaGpio();
#if (DSP28_ECANB)
    InitECanbGpio();
#endif /* if DSP28_ECANB*/
}

/*
* InitECanaGpio - This function initializes GPIO pins to function as eCAN- A
*/
void InitECanaGpio(void)
{
    EALLOW;

    /*
    * Enable internal pull-up for the selected CAN pins
    * Pull-ups can be enabled or disabled by the user.
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
#if defined(CANA1)    
    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0U; /* Enable pull-up for GPIO18 (CANRXA)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0U;  /*Enable pull-up for GPIO19 (CANTXA)*/
#else    
    GpioCtrlRegs.GPAPUD.bit.GPIO30 = 0U;	  /* Enable pull-up for GPIO30 (CANRXA)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0U;	 /*Enable pull-up for GPIO31 (CANTXA)*/
#endif

    /*
    * Set qualification for selected CAN pins to asynch only
    * Inputs are synchronized to SYSCLKOUT by default.
    * This will select asynch (no qualification) for the selected pins.
    */
#if defined(CAPA1)    
    GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 3U;  /* Asynch qual for GPIO18 (CANRXA)*/
#else
    GpioCtrlRegs.GPAQSEL2.bit.GPIO30 = 3U;   /* Asynch qual for GPIO30 (CANRXA)*/
#endif

    /*
    * Configure eCAN-A pins using GPIO regs
    * This specifies which of the possible GPIO pins will be eCAN functional 
    * pins.
    */
#if defined(CAPA1)    
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 3U;	/* Configure GPIO18 for CANRXA*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 3U;	/* Configure GPIO19 for CANTXA*/
#else    
    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 1U;	/* Configure GPIO30 for CANRXA*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 1U;	/* Configure GPIO31 for CANTXA*/

    EDIS;
}

#if (DSP28_ECANB)
/*
* InitECanbGpio - This function initializes GPIO pins to function as eCAN-B
*/
void InitECanbGpio(void)
{
    EALLOW;

    /*
    * Enable internal pull-up for the selected CAN pins
    * Pull-ups can be enabled or disabled by the user.
    * This will enable the pullups for the specified pins.
    * Comment out other unwanted lines.
    */
#if defined(CANB1)    
    GpioCtrlRegs.GPAPUD.bit.GPIO8 =  0U;	  /*Enable pull-up for GPIO8 (CANTXB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0U;	  /* Enable pull-up for GPIO10(CANRXB)*/
#elif defined(CANB2)
    GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0U;   /*Enable pull-up for GPIO12(CANTXB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0U;  /* Enable pull-up for GPIO13(CANRXB)*/
#elif defined(CANB3)
    GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0U;   /*Enable pull-up for GPIO16(CANTXB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0U;  /* Enable pull-up for GPIO17(CANRXB)*/
#else
    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0U;   /*Enable pull-up for GPIO20(CANTXB)*/
    GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0U;  /* Enable pull-up for GPIO21(CANRXB)*/
#endif

    /*
    * Set qualification for selected CAN pins to asynch only
    * Inputs are synchronized to SYSCLKOUT by default.
    * This will select asynch (no qualification) for the selected pins.
    * Comment out other unwanted lines.
    */
#if defined(CANB1)    
    GpioCtrlRegs.GPAQSEL1.bit.GPIO10 = 3U; /* Asynch qual for GPIO10 (CANRXB)*/
#elif defined(CANB2)    
    GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 3U; /* Asynch qual for GPIO13 (CANRXB)*/
#elif defined(CANB3)    
    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3U; /* Asynch qual for GPIO17 (CANRXB)*/
#else    
    GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 3U; /* Asynch qual for GPIO21 (CANRXB)*/
#endif

    /*
    * Configure eCAN-B pins using GPIO regs
    * This specifies which of the possible GPIO pins will be eCAN functional 
    * pins.
    */
#if defined(CANB1)    
    GpioCtrlRegs.GPAMUX1.bit.GPIO8  = 2U;   /* Configure GPIO8 for CANTXB */
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 2U;  /* Configure GPIO10 for CANRXB*/
#elif defined(CANB2)
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 2U;  /* Configure GPIO12 for CANTXB*/ 
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 2U;  /* Configure GPIO13 for CANRXB*/
#elif defined(CANB3)
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 2U;  /* Configure GPIO16 for CANTXB */
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 2U;  /* Configure GPIO17 for CANRXB*/
#else
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 3U;  /* Configure GPIO21 for CANRXB*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 3U;  /* Configure GPIO20 for CANTXB */
#endif
    EDIS;
}
#endif /* if DSP28_ECANB*/

/*
* Note: Bit timing parameters must be chosen based on the network parameters 
* such as the sampling point desired and the propagation delay of the network.
* The propagation delay is a function of length of the cable, delay introduced
* by the transceivers and opto/galvanic-isolators (if any).
*
* The parameters used in this file must be changed taking into account the 
* above mentioned factors in order to arrive at the bit-timing parameters 
* suitable for a network.
*/

/*
* End of File
*/

