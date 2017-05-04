/*
*###########################################################################
*
* FILE:   DSP2833x_Device.h
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
#ifndef DSP2833x_DEVICE_H
#define DSP2833x_DEVICE_H
#include <stdint.h>
/*
* Included Peripheral Header Files
*/
#include "DSP2833x_Adc.h"                /* ADC Registers*/
#include "DSP2833x_DevEmu.h"             /* Device Emulation Registers*/
#include "DSP2833x_CpuTimers.h"          /* 32-bit CPU Timers*/
#include "DSP2833x_ECan.h"               /* Enhanced eCAN Registers*/
#include "DSP2833x_ECap.h"               /* Enhanced Capture*/
#include "DSP2833x_DMA.h"                /* DMA Registers*/
#include "DSP2833x_EPwm.h"               /* Enhanced PWM*/
#include "DSP2833x_EQep.h"               /* Enhanced QEP*/
#include "DSP2833x_Gpio.h"               /* General Purpose I/O Registers*/
#include "DSP2833x_I2c.h"                /* I2C Registers*/
#include "DSP2833x_Mcbsp.h"              /* McBSP*/
#include "DSP2833x_PieCtrl.h"            /* PIE Control Registers*/
#include "DSP2833x_PieVect.h"            /* PIE Vector Table*/
#include "DSP2833x_Spi.h"                /* SPI Registers*/
#include "DSP2833x_Sci.h"                /* SCI Registers*/
#include "DSP2833x_SysCtrl.h"            /* System Control/Power Modes*/
#include "DSP2833x_XIntrupt.h"           /* External Interrupts*/
#include "DSP2833x_Xintf.h"              /* XINTF External Interface*/

#ifdef __cplusplus
extern "C" {
#endif

/*
* Defines
*/
#define   TARGET   1

/*
* User To Select Target Device
*/
#define   DSP28_28335   (TARGET)    /* Selects '28335/'28235*/
#define   DSP28_28334   0         /* Selects '28334/'28234*/
#define   DSP28_28333   0         /* Selects '28333/'*/
#define   DSP28_28332   0         /* Selects '28332/'28232*/

/*
* Common CPU Definitions
*/
extern cregister volatile uint16_t IFR;
extern cregister volatile uint16_t IER;

#define  EINT   do{asm(" clrc INTM");}while(0)
#define  DINT   do{asm(" setc INTM");}while(0)
#define  ERTM   do{asm(" clrc DBGM");}while(0)
#define  DRTM   do{asm(" setc DBGM");}while(0)
#define  EALLOW do{asm(" EALLOW");}while(0)
#define  EDIS   do{asm(" EDIS");}while(0)
#define  ESTOP0 do{asm(" ESTOP0");}while(0)
#define  RPTNOP do{asm(" RPT #7 || NOP");}while(0)
#define  NOP    do{asm(" NOP");}while(0)
#define M_INT1  (0x0001U)
#define M_INT2  (0x0002U)
#define M_INT3  (0x0004U)
#define M_INT4  (0x0008U)
#define M_INT5  (0x0010U)
#define M_INT6  (0x0020U)
#define M_INT7  (0x0040U)
#define M_INT8  (0x0080U)
#define M_INT9  (0x0100U)
#define M_INT10 (0x0200U)
#define M_INT11 (0x0400U)
#define M_INT12 (0x0800U)
#define M_INT13 (0x1000U)
#define M_INT14 (0x2000U)
#define M_DLOG  (0x4000U)
#define M_RTOS  (0x8000U)

#define BIT0    (0x0001U)
#define BIT1    (0x0002U)
#define BIT2    (0x0004U)
#define BIT3    (0x0008U)
#define BIT4    (0x0010U)
#define BIT5    (0x0020U)
#define BIT6    (0x0040U)
#define BIT7    (0x0080U)
#define BIT8    (0x0100U)
#define BIT9    (0x0200U)
#define BIT10   (0x0400U)
#define BIT11   (0x0800U)
#define BIT12   (0x1000U)
#define BIT13   (0x2000U)
#define BIT14   (0x4000U)
#define BIT15   (0x8000U)

/*
* For Portability, User Is Recommended To Use Following Data Type Size
* Definitions For 16-bit and 32-Bit Signed/Unsigned Integers:
*/
#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef float              float32_t;
typedef long double        float64_t;
#endif

#if DSP28_28335 || DSP28_28333
#define DSP28_EPWM1  1
#define DSP28_EPWM2  1
#define DSP28_EPWM3  1
#define DSP28_EPWM4  1
#define DSP28_EPWM5  1
#define DSP28_EPWM6  1
#define DSP28_ECAP1  1
#define DSP28_ECAP2  1
#define DSP28_ECAP3  1
#define DSP28_ECAP4  1
#define DSP28_ECAP5  1
#define DSP28_ECAP6  1
#define DSP28_EQEP1  1
#define DSP28_EQEP2  1
#define DSP28_ECANA  1
#define DSP28_ECANB  1
#define DSP28_MCBSPA 1
#define DSP28_MCBSPB 1
#define DSP28_SPIA   1
#define DSP28_SCIA   1
#define DSP28_SCIB   1
#define DSP28_SCIC   1
#define DSP28_I2CA   1
#endif  /* end DSP28_28335 || DSP28_28333*/

#if DSP28_28334
#define DSP28_EPWM1  1
#define DSP28_EPWM2  1
#define DSP28_EPWM3  1
#define DSP28_EPWM4  1
#define DSP28_EPWM5  1
#define DSP28_EPWM6  1
#define DSP28_ECAP1  1
#define DSP28_ECAP2  1
#define DSP28_ECAP3  1
#define DSP28_ECAP4  1
#define DSP28_ECAP5  0
#define DSP28_ECAP6  0
#define DSP28_EQEP1  1
#define DSP28_EQEP2  1
#define DSP28_ECANA  1
#define DSP28_ECANB  1
#define DSP28_MCBSPA 1
#define DSP28_MCBSPB 1
#define DSP28_SPIA   1
#define DSP28_SCIA   1
#define DSP28_SCIB   1
#define DSP28_SCIC   1
#define DSP28_I2CA   1
#endif  /* end DSP28_28334*/

#if DSP28_28332
#define DSP28_EPWM1  1
#define DSP28_EPWM2  1
#define DSP28_EPWM3  1
#define DSP28_EPWM4  1
#define DSP28_EPWM5  1
#define DSP28_EPWM6  1
#define DSP28_ECAP1  1
#define DSP28_ECAP2  1
#define DSP28_ECAP3  1
#define DSP28_ECAP4  1
#define DSP28_ECAP5  0
#define DSP28_ECAP6  0
#define DSP28_EQEP1  1
#define DSP28_EQEP2  1
#define DSP28_ECANA  1
#define DSP28_ECANB  1
#define DSP28_MCBSPA 1
#define DSP28_MCBSPB 0
#define DSP28_SPIA   1
#define DSP28_SCIA   1
#define DSP28_SCIB   1
#define DSP28_SCIC   0
#define DSP28_I2CA   1
#endif  /* end DSP28_28332*/

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  /* end of DSP2833x_DEVICE_H definition*/

/*
* End of file
*/

