/*
*###########################################################################
*
* FILE:   DSP2833x_Examples.h
*
* TITLE:  DSP2833x Device Definitions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
#ifndef DSP2833x_EXAMPLES_H
#define DSP2833x_EXAMPLES_H

/*
* Include Example Header Files
*/

/*
* Prototypes for global functions within the .c files.
*/
#include "DSP2833x_GlobalPrototypes.h"
#include "DSP2833x_EPwm_defines.h"       /* Macros used for PWM examples.*/
#include "DSP2833x_Dma_defines.h"        /* Macros used for DMA examples.*/
#include "DSP2833x_I2c_defines.h"        /* Macros used for I2C examples.*/

/*
* Include files not used with DSP/BIOS
*/
#ifndef DSP28_BIOS
#include "DSP2833x_DefaultIsr.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
* Specify the PLL control register (PLLCR) and divide select (DIVSEL) value.
*0  Enable /4 for SYSCLKOUT
*1  Enable /4 for SYSCKOUT
*2  Enable /2 for SYSCLKOUT
*3  Enable /1 for SYSCLKOUT
*/
#define DSP28_DIVSEL   (2U)

/*
*
*/
#define DSP28_PLLCR   (10U)

/*
* Specify the clock rate of the CPU (SYSCLKOUT) in nS.
*
*  Take into account the input clock frequency and the PLL multiplier
*	      selected in step 1.
*
*      Use one of the values provided, or define your own.
*      The trailing L is required tells the compiler to treat
*      the number as a 64-bit value.
*
*      Only one statement should be uncommented.
*
*      Example 1:150 MHz devices:
*                CLKIN is a 30MHz crystal.
*
*                In step 1 the user specified PLLCR = 0xA for a
*                150Mhz CPU clock (SYSCLKOUT = 150MHz).
*
*                In this case, the CPU_RATE will be 6.667L
*                Uncomment the line:  #define CPU_RATE  6.667L
*
*      Example 2:  100 MHz devices:
*                  CLKIN is a 20MHz crystal.
*
*	              In step 1 the user specified PLLCR = 0xA for a
*	              100Mhz CPU clock (SYSCLKOUT = 100MHz).
*
*	              In this case, the CPU_RATE will be 10.000L
*                  Uncomment the line:  #define CPU_RATE  10.000L
*/
#define CPU_RATE    6.667L   /* for a 150MHz CPU clock speed (SYSCLKOUT)*/
#define CPU_FRQ		150UL    /* CPU clock Freq (MHz)*/
/*
* Target device (in DSP2833x_Device.h) determines CPU frequency
* (for examples) - either 150 MHz (for 28335 and 28334) or 100 MHz
* (for 28332 and 28333). User does not have to change anything here.
*/
#if DSP28_28332 || DSP28_28333  /* 28332 and 28333 devices only*/
  #define CPU_FRQ_100MHZ  1     /* 100 Mhz CPU Freq (20 MHz input freq)*/
  #define CPU_FRQ_150MHZ  0
#else
  #define CPU_FRQ_100MHZ  0  /* DSP28_28335||DSP28_28334*/
  #define CPU_FRQ_150MHZ  1  /* 150 MHz CPU Freq (30 MHz input freq) by DEFAULT*/
#endif

#define PARTNO_28335  0xEF
#define PARTNO_28334  0xEE
#define PARTNO_28333  0xEA
#define PARTNO_28332  0xED
#define PARTNO_28235  0xE8
#define PARTNO_28234  0xE7
#define PARTNO_28232  0xE6

/*
* DO NOT MODIFY THIS LINE.
*
#define DELAY_US(A)  do{DSP28x_usDelay(((((long double) A * 1000.0L) / \
        (long double)CPU_RATE) - 9.0L) / 5.0L);}while(0)
*/
#define DELAY_US(A)  do{DSP28x_usDelay(((A) * CPU_FRQ  - 9UL) / 5UL);}while(0)

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  /* end of DSP2833x_EXAMPLES_H definition*/

/*
* End of file
*/

