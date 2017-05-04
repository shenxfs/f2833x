/*
*###########################################################################
*
* FILE:   DSP2833x_Xintf.h
*
* TITLE:  DSP2833x Device External Interface Register Definitions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
#ifndef DSP2833x_XINTF_H
#define DSP2833x_XINTF_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/*
* XINTF timing register bit definitions
*/
struct XTIMING_BITS
{     /* bits  description*/
    uint16_t XWRTRAIL:2;    /* 1:0   Write access trail timing*/
    uint16_t XWRACTIVE:3;   /* 4:2   Write access active timing*/
    uint16_t XWRLEAD:2;     /* 6:5   Write access lead timing*/
    uint16_t XRDTRAIL:2;    /* 8:7   Read access trail timing*/
    uint16_t XRDACTIVE:3;   /* 11:9  Read access active timing*/
    uint16_t XRDLEAD:2;     /* 13:12 Read access lead timing*/
    uint16_t USEREADY:1;    /* 14    Extend access using HW waitstates*/
    uint16_t READYMODE:1;   /* 15    Ready mode*/
    uint16_t XSIZE:2;       /* 17:16 XINTF bus width - must be written as 11b*/
    uint16_t rsvd1:4;       /* 21:18 reserved*/
    uint16_t X2TIMING:1;    /* 22    Double lead/active/trail timing*/
    uint16_t rsvd3:9;       /* 31:23 reserved*/
};

union XTIMING_REG
{
    uint32_t             all;
    struct XTIMING_BITS  bit;
};

/*
* XINTF control register bit definitions
*/
struct XINTCNF2_BITS
{     /* bits  description*/
    uint16_t WRBUFF:2;       /* 1:0   Write buffer depth*/
    uint16_t CLKMODE:1;      /* 2     Ratio for XCLKOUT with respect to XTIMCLK*/
    uint16_t CLKOFF:1;       /* 3     Disable XCLKOUT*/
    uint16_t rsvd1:2;        /* 5:4   reserved*/
    uint16_t WLEVEL:2;       /* 7:6   Current level of the write buffer*/
    uint16_t rsvd2:1;        /* 8     reserved*/
    uint16_t HOLD:1;         /* 9     Hold enable/disable*/
    uint16_t HOLDS:1;        /* 10    Current state of HOLDn input*/
    uint16_t HOLDAS:1;       /* 11    Current state of HOLDAn output*/
    uint16_t rsvd3:4;        /* 15:12 reserved*/
    uint16_t XTIMCLK:3;      /* 18:16 Ratio for XTIMCLK*/
    uint16_t rsvd4:13;       /* 31:19 reserved*/
};

union XINTCNF2_REG
{
    uint32_t              all;
    struct XINTCNF2_BITS  bit;
};

/*
* XINTF bank switching register bit definitions
*/
struct XBANK_BITS
{       /* bits  description*/
    uint16_t  BANK:3;       /* 2:0   Zone for which banking is enabled*/
    uint16_t  BCYC:3;       /* 5:3   XTIMCLK cycles to add*/
    uint16_t  rsvd:10;      /* 15:6  reserved*/
};  
    
union XBANK_REG
{
    uint16_t           all;
    struct XBANK_BITS  bit;
};

struct XRESET_BITS
{
    uint16_t  XHARDRESET:1;
    uint16_t  rsvd1:15;
};

union XRESET_REG
{
    uint16_t           all;
    struct XRESET_BITS bit;
};

/*
* XINTF Register File
*/
struct XINTF_REGS
{
    union XTIMING_REG 	XTIMING0;
    uint32_t  			rsvd1[5];
    union XTIMING_REG 	XTIMING6;
    union XTIMING_REG 	XTIMING7;
    uint32_t  			rsvd2[2];
    union XINTCNF2_REG 	XINTCNF2;
    uint32_t  			rsvd3;
    union XBANK_REG    	XBANK;
    uint16_t  			rsvd4;
    uint16_t  			XREVISION;
    uint16_t  			rsvd5[2];
    union XRESET_REG   	XRESET;
};

/*
* XINTF External References & Function Declarations
*/
extern volatile struct XINTF_REGS XintfRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  /* end of DSP2833x_XINTF_H definition*/

/*
* End of File
*/

