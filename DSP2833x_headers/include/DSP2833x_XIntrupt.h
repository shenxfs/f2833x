/*
*###########################################################################
*
* FILE:  DSP2833x_XIntrupt.h
*
* TITLE: DSP2833x Device External Interrupt Register Definitions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
#ifndef DSP2833x_XINTRUPT_H
#define DSP2833x_XINTRUPT_H
#include <stdint.h>
#ifdef __cplusplus
esxtern "C" {
#endif

struct XINTCR_BITS
{
    uint16_t   ENABLE:1;    /* 0      enable/disable*/
    uint16_t   rsvd1:1;     /* 1      reserved*/
    uint16_t   POLARITY:2;  /* 3:2    pos/neg, both triggered*/
    uint16_t   rsvd2:12;    /*15:4    reserved*/
};

union XINTCR_REG
{
    uint16_t             all;
    struct XINTCR_BITS   bit;
};  

struct XNMICR_BITS
{
    uint16_t   ENABLE:1;    /* 0      enable/disable*/
    uint16_t   SELECT:1;    /* 1      Timer 1 or XNMI connected to int13*/
    uint16_t   POLARITY:2;  /* 3:2    pos/neg, or both triggered*/
    uint16_t   rsvd2:12;    /* 15:4   reserved*/
};

union XNMICR_REG
{
    uint16_t             all;
    struct XNMICR_BITS   bit;
};  

/*
* External Interrupt Register File
*/
struct XINTRUPT_REGS
{
    union XINTCR_REG XINT1CR;
    union XINTCR_REG XINT2CR;
    union XINTCR_REG XINT3CR;
    union XINTCR_REG XINT4CR;
    union XINTCR_REG XINT5CR;
    union XINTCR_REG XINT6CR;
    union XINTCR_REG XINT7CR;
    union XNMICR_REG XNMICR;
    uint16_t         XINT1CTR;
    uint16_t         XINT2CTR;
    uint16_t         rsvd[5];
    uint16_t         XNMICTR;
};

/*
* External Interrupt References & Function Declarations
*/
extern volatile struct XINTRUPT_REGS XIntruptRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  /* end of DSP2833x_XINTF_H definition*/

/*
* End of file
*/

