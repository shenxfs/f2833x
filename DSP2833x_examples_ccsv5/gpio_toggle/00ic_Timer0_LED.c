/* 
TI File $Revision: /main/1 $
Checkin $Date: September 21, 2007   08:58:44 $
###########################################################################

FILE:    Example_2833xLedBlink.c

TITLE:   DSP2833x eZdsp LED Blink Getting Started Program.

ASSUMPTION:S

   This program requires the DSP2833x header files.


   As supplied, this project is configured for "boot to SARAM"
   operation.  The 2833x Boot Mode table is shown below.
   For information on configuring the boot mode of an eZdsp,
   please refer to the documentation included with the eZdsp,

      $Boot_Table:

        GPIO87   GPIO86     GPIO85   GPIO84
         XA15     XA14       XA13     XA12
          PU       PU         PU       PU
       ==========================================
           1        1          1        1    Jump to Flash
           1        1          1        0    SCI-A boot
           1        1          0        1    SPI-A boot
           1        1          0        0    I2C-A boot
           1        0          1        1    eCAN-A boot
           1        0          1        0    McBSP-A boot
           1        0          0        1    Jump to XINTF x16
           1        0          0        0    Jump to XINTF x32
           0        1          1        1    Jump to OTP
           0        1          1        0    Parallel GPIO I/O boot
           0        1          0        1    Parallel XINTF boot
           0        1          0        0    Jump to SARAM	    <- "boot to SARAM"
           0        0          1        1    Branch to check boot mode
           0        0          1        0    Boot to flash, bypass ADC cal
           0        0          0        1    Boot to SARAM, bypass ADC cal
           0        0          0        0    Boot to SCI-A, bypass ADC cal
                                             Boot_Table_End$

DESCRIPTION:

   This example configures CPU Timer0 for a 500 msec period, and toggles the GPIO32
   LED on the 2833x eZdsp once per interrupt. For testing purposes, this example
   also increments a counter each time the timer asserts an interrupt.

      Watch Variables:
         CpuTimer0.InterruptCount

      Monitor the GPIO32 LED blink on (for 500 msec) and off (for 500 msec) on the 2833x eZdsp.

###########################################################################
$TI Release: DSP2833x Header Files V1.10 $
$Release Date: February 15, 2008 $
###########################################################################
 */


#include "DSP2833x_Device.h"     /* DSP2833x Headerfile Include File */
#include "DSP2833x_Examples.h"   /* DSP2833x Examples Include File */

/* Prototype statements for functions found within this file.*/
interrupt void cpu_timer0_isr(void);
uint32_t Count,Flag;
void main(void);

void main(void)
{

/* 
Step 1. Initialize System Control:
PLL, WatchDog, enable Peripheral Clocks
This example function is found in the DSP2833x_SysCtrl.c file.
 */
   InitSysCtrl();

/* 
Step 2. Initalize GPIO:
This example function is found in the DSP2833x_Gpio.c file and
illustrates how to set the GPIO to it's default state.
InitGpio();  // Skipped for this example
 */


/* 
Step 3. Clear all interrupts and initialize PIE vector table:
Disable CPU interrupts
 */
   DINT;

/* 
Initialize the PIE control registers to their default state.
The default state is all PIE interrupts disabled and flags
are cleared.
This function is found in the DSP2833x_PieCtrl.c file.
 */
   InitPieCtrl();

/* Disable CPU interrupts and clear all CPU interrupt flags: */
   IER = 0x0000U;
   IFR = 0x0000U;

/* 
Initialize the PIE vector table with pointers to the shell Interrupt
Service Routines (ISR).
This will populate the entire table, even if the interrupt
is not used in this example.  This is useful for debug purposes.
The shell ISR routines are found in DSP2833x_DefaultIsr.c.
This function is found in DSP2833x_PieVect.c.
 */
   InitPieVectTable();

/* 
Interrupts that are used in this example are re-mapped to
ISR functions found within this file.
 */
   EALLOW;  /* This is needed to write to EALLOW protected registers*/
   PieVectTable.TINT0 = &cpu_timer0_isr;

   Count = 0U;
   Flag = 0U;

   EDIS;    /* This is needed to disable write to EALLOW protected registers */

/* 
Step 4. Initialize the Device Peripheral. This function can be
        found in DSP2833x_CpuTimers.c
 */
   InitCpuTimers();   /* For this example, only initialize the Cpu Timers */
#if (CPU_FRQ_150MHZ)
/* 
Configure CPU-Timer 0 to interrupt every 500 milliseconds:
150MHz CPU Freq, 50 millisecond Period (in uSeconds)
 */
   ConfigCpuTimer(&CpuTimer0, 150U, 500000UL);
#endif
#if (CPU_FRQ_100MHZ)
/*
Configure CPU-Timer 0 to interrupt every 500 milliseconds:
 100MHz CPU Freq, 50 millisecond Period (in uSeconds)
 */
   ConfigCpuTimer(&CpuTimer0, 100U, 500000UL);
#endif

/* 
To ensure precise timing, use write-only instructions to write to the entire register. Therefore, if any
of the configuration bits are changed in ConfigCpuTimer and InitCpuTimers (in DSP2833x_CpuTimers.h), the
below settings must also be updated.
 */

   CpuTimer0Regs.TCR.all = 0x4001U; /* Use write-only instruction to set TSS bit = 0 */

/* Step 5. User specific code, enable interrupts: */

/* Configure GPIO0-3 as a GPIO output pin */
   EALLOW;
   GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0U;
   GpioCtrlRegs.GPADIR.bit.GPIO0 = 1U;
   GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0U;
   GpioCtrlRegs.GPADIR.bit.GPIO1 = 1U;
   GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0U;
   GpioCtrlRegs.GPADIR.bit.GPIO2 = 1U;
   GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0U;
   GpioCtrlRegs.GPADIR.bit.GPIO3 = 1U;
   EDIS;

/* Enable CPU INT1 which is connected to CPU-Timer 0: */
   IER |= M_INT1;

/* Enable TINT0 in the PIE: Group 1 interrupt 7 */
   PieCtrlRegs.PIEIER1.bit.INTx7 = 1U;

/* Enable global Interrupts and higher priority real-time debug events: */
   EINT;   /* Enable Global interrupt INTM */
   ERTM;   /* Enable Global realtime interrupt DBGM */

/* Step 6. IDLE loop. Just sit and loop forever (optional): */
   while(1)
   {
		;
   }
}


interrupt void cpu_timer0_isr(void)
{
   CpuTimer0.InterruptCount++;
   GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1U; /* Toggle GPIO0 once per 500 milliseconds */
   GpioDataRegs.GPATOGGLE.bit.GPIO1 = 1U; /* Toggle GPIO1 once per 500 milliseconds */
   GpioDataRegs.GPATOGGLE.bit.GPIO2 = 1U; /* Toggle GPIO2 once per 500 milliseconds */
   GpioDataRegs.GPATOGGLE.bit.GPIO3 = 1U; /* Toggle GPIO3 once per 500 milliseconds */
/*    Acknowledge this interrupt to receive more interrupts from group 1 */
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}


/* 
===========================================================================
No more.
===========================================================================
 */
