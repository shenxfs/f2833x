/*
*###########################################################################
*
* FILE:   DSP2833x_Mcbsp.h
*
* TITLE:  DSP2833x Device McBSP Register Definitions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
#ifndef DSP2833x_MCBSP_H
#define DSP2833x_MCBSP_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/*
* McBSP Individual Register Bit Definitions
*/

/*
* McBSP DRR2 register bit definitions
*/
struct  DRR2_BITS
{        /* bit   description*/
    uint16_t     HWLB:8;     /* 16:23 High word low byte*/
    uint16_t     HWHB:8;     /* 24:31 High word high byte*/
};

union DRR2_REG
{
    uint16_t          all;
    struct DRR2_BITS  bit;
};

/*
* McBSP DRR1 register bit definitions
*/
struct  DRR1_BITS
{        /* bit   description*/
    uint16_t     LWLB:8;     /* 16:23 Low word low byte*/
    uint16_t     LWHB:8;     /* 24:31 low word high byte*/
};

union DRR1_REG
{
    uint16_t          all;
    struct DRR1_BITS  bit;
};

/*
* McBSP DXR2 register bit definitions
*/
struct  DXR2_BITS
{        /* bit   description*/
    uint16_t     HWLB:8;     /* 16:23 High word low byte*/
    uint16_t     HWHB:8;     /* 24:31 High word high byte*/
};

union DXR2_REG
{
    uint16_t          all;
    struct DXR2_BITS  bit;
};

/*
* McBSP DXR1 register bit definitions
*/
struct  DXR1_BITS
{        /* bit   description*/
    uint16_t     LWLB:8;     /* 16:23 Low word low byte*/
    uint16_t     LWHB:8;     /* 24:31 low word high byte*/
};

union DXR1_REG
{
    uint16_t          all;
    struct DXR1_BITS  bit;
};

/*
* SPCR2 control register bit definitions
*/
struct  SPCR2_BITS
{        /* bit   description*/
    uint16_t     XRST:1;      /* 0     transmit reset*/
    uint16_t     XRDY:1;      /* 1     transmit ready*/
    uint16_t     XEMPTY:1;    /* 2     Transmit empty*/
    uint16_t     XSYNCERR:1;  /* 3     Transmit syn errorINT flag*/
    uint16_t     XINTM:2;     /* 5:4   Transmit interrupt types*/
    uint16_t     GRST:1;      /* 6     CLKG reset*/
    uint16_t     FRST:1;      /* 7     Frame sync reset*/
    uint16_t     SOFT:1;      /* 8     SOFT bit*/
    uint16_t     FREE:1;      /* 9     FREE bit*/
    uint16_t     rsvd:6;      /* 15:10 reserved*/
};

union SPCR2_REG
{
    uint16_t           all;
    struct SPCR2_BITS  bit;
};

/*
* SPCR1 control register bit definitions
*/
struct  SPCR1_BITS
{        /* bit   description*/
    uint16_t     RRST:1;      /* 0     Receive reset*/
    uint16_t     RRDY:1;      /* 1     Receive  ready*/
    uint16_t     RFULL:1;     /* 2     Receive  full*/
    uint16_t     RSYNCERR:1;  /* 7     Receive  syn error*/
    uint16_t     RINTM:2;     /* 5:4   Receive  interrupt types*/
    uint16_t     rsvd1:1;     /* 6     reserved*/
    uint16_t     DXENA:1;     /* 7     DX hi-z enable*/
    uint16_t     rsvd2:3;     /* 10:8  reserved*/
    uint16_t     CLKSTP:2;    /* 12:11 CLKSTOP mode bit*/
    uint16_t     RJUST:2;     /* 13:14 Right justified*/
    uint16_t     DLB:1;       /* 15    Digital loop back*/
};

union SPCR1_REG
{
    uint16_t          all;
    struct SPCR1_BITS bit;
};

/*
* RCR2 control register bit definitions
*/
struct  RCR2_BITS
{             /* bit    description*/
    uint16_t     RDATDLY:2;       /* 1:0    Receive data delay*/
    uint16_t     RFIG:1;          /* 2      Receive  frame sync ignore*/
    uint16_t     RCOMPAND:2;      /* 4:3    Receive  Companding Mode selects*/
    uint16_t     RWDLEN2:3;       /* 7:5    Receive  word length*/
    uint16_t     RFRLEN2:7;       /* 14:8   Receive  Frame sync*/
    uint16_t     RPHASE:1;        /* 15     Receive Phase*/
};

union RCR2_REG
{
    uint16_t         all;
    struct RCR2_BITS bit;
};

/*
* RCR1 control register bit definitions
*/
struct  RCR1_BITS
{          /* bit   description*/
    uint16_t     rsvd1:5;      /* 4:0   reserved*/
    uint16_t     RWDLEN1:3;    /* 7:5   Receive word length*/
    uint16_t     RFRLEN1:7;    /* 14:8  Receive frame length*/
    uint16_t     rsvd2:1;      /* 15    reserved*/
};

union RCR1_REG {
    uint16_t         all;
    struct RCR1_BITS bit;
};

/*
* XCR2 control register bit definitions
*/
struct  XCR2_BITS
{          /* bit    description*/
    uint16_t     XDATDLY:2;    /* 1:0    Transmit data delay*/
    uint16_t     XFIG:1;       /* 2      Transmit frame sync ignore*/
    uint16_t     XCOMPAND:2;   /* 4:3    Transmit Companding Mode selects*/
    uint16_t     XWDLEN2:3;    /* 7:5    Transmit  word length*/
    uint16_t     XFRLEN2:7;    /* 14:8   Transmit  Frame sync*/
    uint16_t     XPHASE:1;     /* 15     Transmit Phase*/
};  

union XCR2_REG
{
    uint16_t         all;
    struct XCR2_BITS bit;
};

/*
* XCR1 control register bit definitions
*/
struct  XCR1_BITS
{             /* bit   description*/
    uint16_t     rsvd1:5;         /* 4:0   reserved*/
    uint16_t     XWDLEN1:3;       /* 7:5   Transmit word length*/
    uint16_t     XFRLEN1:7;       /* 14:8  Transmit frame length*/
    uint16_t     rsvd2:1;         /* 15    reserved*/
};

union XCR1_REG
{
    uint16_t         all;
    struct XCR1_BITS bit;
};

/*
* SRGR2 Sample rate generator control register bit definitions
*/
struct  SRGR2_BITS
{            /* bit  description*/
    uint16_t     FPER:12;         /* 11:0 Frame period*/
    uint16_t     FSGM:1;          /* 12   Frame sync generator mode*/
    uint16_t     CLKSM:1;         /* 13   Sample rate generator mode*/
    uint16_t     rsvd:1;          /* 14   reserved*/
    uint16_t     GSYNC:1;         /* 15   CLKG sync*/
};

union  SRGR2_REG
{
    uint16_t            all;
    struct  SRGR2_BITS  bit;
};

/*
* SRGR1 control register bit definitions
*/
struct  SRGR1_BITS
{         /* bit   description*/
    uint16_t     CLKGDV:8;     /* 7:0   CLKG divider*/
    uint16_t     FWID:8;       /* 15:8  Frame width*/
};

union  SRGR1_REG
{
    uint16_t            all;
    struct  SRGR1_BITS  bit;
};

/*
* MCR2 Multichannel control register bit definitions
*/
struct  MCR2_BITS
{             /* bit   description*/
    uint16_t     XMCM:2;          /* 1:0   Transmit multichannel mode*/
    uint16_t     XCBLK:3;         /* 2:4   Transmit current block*/
    uint16_t     XPABLK:2;        /* 5:6   Transmit partition A Block*/
    uint16_t     XPBBLK:2;        /* 7:8   Transmit partition B Block*/
    uint16_t     XMCME:1;         /* 9     Transmit multi-channel enhance mode*/
    uint16_t     rsvd:6;          /* 15:10 reserved*/
};

union  MCR2_REG
{
    uint16_t           all;
    struct  MCR2_BITS  bit;
};

/*
* MCR1 Multichannel control register bit definitions
*/
struct  MCR1_BITS
{          /* bit   description*/
    uint16_t     RMCM:1;       /* 0     Receive multichannel mode*/
    uint16_t     rsvd:1;       /* 1     reserved*/
    uint16_t     RCBLK:3;      /* 4:2   Receive current block*/
    uint16_t     RPABLK:2;     /* 6:5   Receive partition A Block*/
    uint16_t     RPBBLK:2;     /* 7:8   Receive partition B Block*/
    uint16_t     RMCME:1;      /* 9     Receive multi-channel enhance mode*/
    uint16_t     rsvd1:6;      /* 15:10 reserved*/
};

union  MCR1_REG
{
    uint16_t           all;
    struct  MCR1_BITS  bit;
};

/*
* RCERA control register bit definitions
*/
struct  RCERA_BITS
{          /* bit description*/
    uint16_t     RCEA0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     RCEA1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     RCEA2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     RCEA3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     RCEA4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     RCEA5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     RCEA6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     RCEA7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     RCEA8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     RCEA9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     RCEA10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     RCEA11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     RCEA12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     RCEA13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     RCEA14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     RCEA15:1;      /* 15  Receive Channel enable bit*/
};

union RCERA_REG
{
    uint16_t            all;
    struct  RCERA_BITS  bit;
};

/*
* RCERB control register bit definitions
*/
struct  RCERB_BITS
{          /* bit description*/
    uint16_t     RCEB0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     RCEB1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     RCEB2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     RCEB3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     RCEB4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     RCEB5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     RCEB6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     RCEB7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     RCEB8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     RCEB9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     RCEB10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     RCEB11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     RCEB12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     RCEB13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     RCEB14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     RCEB15:1;      /* 15  Receive Channel enable bit*/
}; 

union RCERB_REG
{
    uint16_t            all;
    struct  RCERB_BITS  bit;
};

/*
* XCERA control register bit definitions
*/
struct  XCERA_BITS
{            /* bit description*/
    uint16_t     XCERA0:1;        /* 0   Receive Channel enable bit*/
    uint16_t     XCERA1:1;        /* 1   Receive Channel enable bit*/
    uint16_t     XCERA2:1;        /* 2   Receive Channel enable bit*/
    uint16_t     XCERA3:1;        /* 3   Receive Channel enable bit*/
    uint16_t     XCERA4:1;        /* 4   Receive Channel enable bit*/
    uint16_t     XCERA5:1;        /* 5   Receive Channel enable bit*/
    uint16_t     XCERA6:1;        /* 6   Receive Channel enable bit*/
    uint16_t     XCERA7:1;        /* 7   Receive Channel enable bit*/
    uint16_t     XCERA8:1;        /* 8   Receive Channel enable bit*/
    uint16_t     XCERA9:1;        /* 9   Receive Channel enable bit*/
    uint16_t     XCERA10:1;       /* 10  Receive Channel enable bit*/
    uint16_t     XCERA11:1;       /* 11  Receive Channel enable bit*/
    uint16_t     XCERA12:1;       /* 12  Receive Channel enable bit*/
    uint16_t     XCERA13:1;       /* 13  Receive Channel enable bit*/
    uint16_t     XCERA14:1;       /* 14  Receive Channel enable bit*/
    uint16_t     XCERA15:1;       /* 15  Receive Channel enable bit*/
};

union XCERA_REG
{
    uint16_t            all;
    struct  XCERA_BITS  bit;
};  

/*
* XCERB control register bit definitions
*/
struct  XCERB_BITS
{           /* bit description*/
    uint16_t     XCERB0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     XCERB1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     XCERB2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     XCERB3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     XCERB4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     XCERB5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     XCERB6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     XCERB7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     XCERB8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     XCERB9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     XCERB10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     XCERB11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     XCERB12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     XCERB13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     XCERB14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     XCERB15:1;      /* 15  Receive Channel enable bit*/
};
    
union XCERB_REG
{
    uint16_t            all;
    struct  XCERB_BITS  bit;
};

/*
* PCR control register bit definitions
*/
struct  PCR_BITS
{            /* bit description*/
    uint16_t     CLKRP:1;       /* 0   Receive Clock polarity*/
    uint16_t     CLKXP:1;       /* 1   Transmit clock polarity*/
    uint16_t     FSRP:1;        /* 2   Receive Frame synchronization polarity*/
    uint16_t     FSXP:1;        /* 3   Transmit Frame synchronization polarity*/
    uint16_t     DR_STAT:1;     /* 4   DR pin status - reserved for this McBSP*/
    uint16_t     DX_STAT:1;     /* 5   DX pin status - reserved for this McBSP*/
    uint16_t     CLKS_STAT:1;   /* 6   CLKS pin status - reserved for 28x -McBSP*/
    uint16_t     SCLKME:1;      /* 7   Enhanced sample clock mode selection bit.*/
    uint16_t     CLKRM:1;       /* 8   Receiver Clock Mode*/
    uint16_t     CLKXM:1;       /* 9   Transmitter Clock Mode.*/
    uint16_t     FSRM:1;        /* 10  Receive Frame Synchronization Mode*/
    uint16_t     FSXM:1;        /* 11  Transmit Frame Synchronization Mode*/
    uint16_t     RIOEN:1;       /* 12  General Purpose I/O Mode - reserved in*/
                              /*     this 28x-McBSP*/
    uint16_t     XIOEN:1;       /* 13  General Purpose I/O Mode - reserved in */
                              /*     this 28x-McBSP*/
    uint16_t     IDEL_EN:1;     /* 14  reserved in this 28x-McBSP*/
    uint16_t     rsvd:1  ;      /* 15  reserved*/
};

union PCR_REG
{
    uint16_t          all;
    struct  PCR_BITS  bit;
};

/*
* RCERC control register bit definitions
*/
struct  RCERC_BITS
{          /* bit description*/
    uint16_t     RCEC0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     RCEC1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     RCEC2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     RCEC3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     RCEC4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     RCEC5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     RCEC6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     RCEC7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     RCEC8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     RCEC9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     RCEC10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     RCEC11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     RCEC12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     RCEC13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     RCEC14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     RCEC15:1;      /* 15  Receive Channel enable bit*/
};

union RCERC_REG
{
    uint16_t            all;
    struct  RCERC_BITS  bit;
};

/*
* RCERD control register bit definitions
*/
struct  RCERD_BITS
{          /* bit description*/
    uint16_t     RCED0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     RCED1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     RCED2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     RCED3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     RCED4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     RCED5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     RCED6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     RCED7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     RCED8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     RCED9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     RCED10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     RCED11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     RCED12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     RCED13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     RCED14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     RCED15:1;      /* 15  Receive Channel enable bit*/
};

union RCERD_REG
{
    uint16_t            all;
    struct  RCERD_BITS  bit;
};

/*
* XCERC control register bit definitions
*/
struct  XCERC_BITS
{           /* bit description*/
    uint16_t     XCERC0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     XCERC1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     XCERC2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     XCERC3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     XCERC4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     XCERC5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     XCERC6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     XCERC7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     XCERC8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     XCERC9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     XCERC10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     XCERC11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     XCERC12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     XCERC13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     XCERC14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     XCERC15:1;      /* 15  Receive Channel enable bit*/
};

union XCERC_REG
{
    uint16_t            all;
    struct  XCERC_BITS  bit;
};

/*
* XCERD control register bit definitions
*/
struct  XCERD_BITS
{           /* bit description*/
    uint16_t     XCERD0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     XCERD1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     XCERD2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     XCERD3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     XCERD4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     XCERD5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     XCERD6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     XCERD7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     XCERD8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     XCERD9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     XCERD10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     XCERD11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     XCERD12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     XCERD13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     XCERD14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     XCERD15:1;      /* 15  Receive Channel enable bit*/
}; 

union XCERD_REG
{
    uint16_t            all;
    struct  XCERD_BITS  bit;
};

/*
* RCERE control register bit definitions
*/
struct  RCERE_BITS
{          /* bit description*/
    uint16_t     RCEE0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     RCEE1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     RCEE2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     RCEE3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     RCEE4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     RCEE5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     RCEE6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     RCEE7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     RCEE8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     RCEE9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     RCEE10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     RCEE11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     RCEE12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     RCEE13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     RCEE14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     RCEE15:1;      /* 15  Receive Channel enable bit*/
};

union RCERE_REG
{
    uint16_t            all;
    struct  RCERE_BITS  bit;
};

/*
* RCERF control register bit definitions
*/
struct  RCERF_BITS
{          /* bit   description*/
    uint16_t     RCEF0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     RCEF1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     RCEF2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     RCEF3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     RCEF4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     RCEF5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     RCEF6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     RCEF7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     RCEF8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     RCEF9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     RCEF10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     RCEF11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     RCEF12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     RCEF13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     RCEF14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     RCEF15:1;      /* 15  Receive Channel enable bit*/
};

union RCERF_REG
{
   uint16_t            all;
   struct  RCERF_BITS  bit;
};

/* XCERE control register bit definitions:*/
struct  XCERE_BITS
{         /* bit description*/
   uint16_t     XCERE0:1;       /* 0   Receive Channel enable bit*/
   uint16_t     XCERE1:1;       /* 1   Receive Channel enable bit*/
   uint16_t     XCERE2:1;       /* 2   Receive Channel enable bit*/
   uint16_t     XCERE3:1;       /* 3   Receive Channel enable bit*/
   uint16_t     XCERE4:1;       /* 4   Receive Channel enable bit*/
   uint16_t     XCERE5:1;       /* 5   Receive Channel enable bit*/
   uint16_t     XCERE6:1;       /* 6   Receive Channel enable bit*/
   uint16_t     XCERE7:1;       /* 7   Receive Channel enable bit*/
   uint16_t     XCERE8:1;       /* 8   Receive Channel enable bit*/
   uint16_t     XCERE9:1;       /* 9   Receive Channel enable bit*/
   uint16_t     XCERE10:1;      /* 10  Receive Channel enable bit*/
   uint16_t     XCERE11:1;      /* 11  Receive Channel enable bit*/
   uint16_t     XCERE12:1;      /* 12  Receive Channel enable bit*/
   uint16_t     XCERE13:1;      /* 13  Receive Channel enable bit*/
   uint16_t     XCERE14:1;      /* 14  Receive Channel enable bit*/
   uint16_t     XCERE15:1;      /* 15  Receive Channel enable bit*/
};

union XCERE_REG
{
    uint16_t            all;
    struct  XCERE_BITS  bit;
};

/*
* XCERF control register bit definitions
*/
struct  XCERF_BITS
{            /* bit description*/
    uint16_t     XCERF0:1;        /* 0   Receive Channel enable bit*/
    uint16_t     XCERF1:1;        /* 1   Receive Channel enable bit*/
    uint16_t     XCERF2:1;        /* 2   Receive Channel enable bit*/
    uint16_t     XCERF3:1;        /* 3   Receive Channel enable bit*/
    uint16_t     XCERF4:1;        /* 4   Receive Channel enable bit*/
    uint16_t     XCERF5:1;        /* 5   Receive Channel enable bit*/
    uint16_t     XCERF6:1;        /* 6   Receive Channel enable bit*/
    uint16_t     XCERF7:1;        /* 7   Receive Channel enable bit*/
    uint16_t     XCERF8:1;        /* 8   Receive Channel enable bit*/
    uint16_t     XCERF9:1;        /* 9   Receive Channel enable bit*/
    uint16_t     XCERF10:1;       /* 10  Receive Channel enable bit*/
    uint16_t     XCERF11:1;       /* 11  Receive Channel enable bit*/
    uint16_t     XCERF12:1;       /* 12  Receive Channel enable bit*/
    uint16_t     XCERF13:1;       /* 13  Receive Channel enable bit*/
    uint16_t     XCERF14:1;       /* 14  Receive Channel enable bit*/
    uint16_t     XCERF15:1;       /* 15  Receive Channel enable bit*/
};

union XCERF_REG
{
    uint16_t            all;
    struct  XCERF_BITS  bit;
};

/*
* RCERG control register bit definitions
*/
struct  RCERG_BITS
{          /* bit description*/
    uint16_t     RCEG0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     RCEG1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     RCEG2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     RCEG3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     RCEG4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     RCEG5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     RCEG6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     RCEG7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     RCEG8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     RCEG9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     RCEG10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     RCEG11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     RCEG12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     RCEG13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     RCEG14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     RCEG15:1;      /* 15  Receive Channel enable bit*/
};

union RCERG_REG
{
   uint16_t            all;
   struct  RCERG_BITS  bit;
};

/* RCERH control register bit definitions:*/
struct  RCERH_BITS
{         /* bit description*/
   uint16_t     RCEH0:1;       /* 0   Receive Channel enable bit*/
   uint16_t     RCEH1:1;       /* 1   Receive Channel enable bit*/
   uint16_t     RCEH2:1;       /* 2   Receive Channel enable bit*/
   uint16_t     RCEH3:1;       /* 3   Receive Channel enable bit*/
   uint16_t     RCEH4:1;       /* 4   Receive Channel enable bit*/
   uint16_t     RCEH5:1;       /* 5   Receive Channel enable bit*/
   uint16_t     RCEH6:1;       /* 6   Receive Channel enable bit*/
   uint16_t     RCEH7:1;       /* 7   Receive Channel enable bit*/
   uint16_t     RCEH8:1;       /* 8   Receive Channel enable bit*/
   uint16_t     RCEH9:1;       /* 9   Receive Channel enable bit*/
   uint16_t     RCEH10:1;      /* 10  Receive Channel enable bit*/
   uint16_t     RCEH11:1;      /* 11  Receive Channel enable bit*/
   uint16_t     RCEH12:1;      /* 12  Receive Channel enable bit*/
   uint16_t     RCEH13:1;      /* 13  Receive Channel enable bit*/
   uint16_t     RCEH14:1;      /* 14  Receive Channel enable bit*/
   uint16_t     RCEH15:1;      /* 15  Receive Channel enable bit*/
};

union RCERH_REG
{
    uint16_t            all;
    struct  RCERH_BITS  bit;
};

/*
* XCERG control register bit definitions
*/
struct  XCERG_BITS
{           /* bit description*/
    uint16_t     XCERG0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     XCERG1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     XCERG2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     XCERG3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     XCERG4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     XCERG5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     XCERG6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     XCERG7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     XCERG8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     XCERG9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     XCERG10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     XCERG11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     XCERG12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     XCERG13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     XCERG14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     XCERG15:1;      /* 15  Receive Channel enable bit*/
};

union XCERG_REG
{
    uint16_t            all;
    struct  XCERG_BITS  bit;
};

/*
* XCERH control register bit definitions
*/
struct  XCERH_BITS
{          /* bit description*/
    uint16_t     XCEH0:1;       /* 0   Receive Channel enable bit*/
    uint16_t     XCEH1:1;       /* 1   Receive Channel enable bit*/
    uint16_t     XCEH2:1;       /* 2   Receive Channel enable bit*/
    uint16_t     XCEH3:1;       /* 3   Receive Channel enable bit*/
    uint16_t     XCEH4:1;       /* 4   Receive Channel enable bit*/
    uint16_t     XCEH5:1;       /* 5   Receive Channel enable bit*/
    uint16_t     XCEH6:1;       /* 6   Receive Channel enable bit*/
    uint16_t     XCEH7:1;       /* 7   Receive Channel enable bit*/
    uint16_t     XCEH8:1;       /* 8   Receive Channel enable bit*/
    uint16_t     XCEH9:1;       /* 9   Receive Channel enable bit*/
    uint16_t     XCEH10:1;      /* 10  Receive Channel enable bit*/
    uint16_t     XCEH11:1;      /* 11  Receive Channel enable bit*/
    uint16_t     XCEH12:1;      /* 12  Receive Channel enable bit*/
    uint16_t     XCEH13:1;      /* 13  Receive Channel enable bit*/
    uint16_t     XCEH14:1;      /* 14  Receive Channel enable bit*/
    uint16_t     XCEH15:1;      /* 15  Receive Channel enable bit*/
}; 

union XCERH_REG
{
    uint16_t            all;
    struct  XCERH_BITS  bit;
};

/*
* McBSP Interrupt enable register for RINT/XINT
*/
struct  MFFINT_BITS
{       /* bits description*/
    uint16_t     XINT:1;      /* 0    XINT  interrupt enable*/
    uint16_t     rsvd1:1;     /* 1    reserved*/
    uint16_t     RINT:1;      /* 2    RINT  interrupt enable*/
    uint16_t     rsvd2:13;    /* 15:3 reserved*/
};

union MFFINT_REG
{
    uint16_t            all;
    struct MFFINT_BITS  bit;
};

/*
* McBSP Register File
*/
struct  MCBSP_REGS
{
    union DRR2_REG    DRR2;       /* MCBSP Data receive register bits 31-16*/
    union DRR1_REG    DRR1;       /* MCBSP Data receive register bits 15-0*/
    union DXR2_REG    DXR2;       /* MCBSP Data transmit register bits 31-16*/
    union DXR1_REG    DXR1;       /* MCBSP Data transmit register bits 15-0*/
    union SPCR2_REG   SPCR2;      /* MCBSP control register bits 31-16*/
    union SPCR1_REG   SPCR1;      /* MCBSP control register bits 15-0*/
    union RCR2_REG    RCR2;       /* MCBSP receive control register bits 31-16*/
    union RCR1_REG    RCR1;       /* MCBSP receive control register bits 15-0*/
    union XCR2_REG    XCR2;       /* MCBSP transmit control register bits 31-16*/
    union XCR1_REG    XCR1;       /* MCBSP transmit control register bits 15-0*/
    union SRGR2_REG   SRGR2;      /* MCBSP sample rate gen register bits 31-16*/
    union SRGR1_REG   SRGR1;      /* MCBSP sample rate gen register bits 15-0*/
    union MCR2_REG    MCR2;       /* MCBSP multichannel register bits 31-16*/
    union MCR1_REG    MCR1;       /* MCBSP multichannel register bits 15-0*/
    union RCERA_REG   RCERA;      /* MCBSP Receive channel enable partition A*/
    union RCERB_REG   RCERB;      /* MCBSP Receive channel enable partition B*/
    union XCERA_REG   XCERA;      /* MCBSP Transmit channel enable partition A*/
    union XCERB_REG   XCERB;      /* MCBSP Transmit channel enable partition B*/
    union PCR_REG     PCR;        /* MCBSP Pin control register bits 15-0*/
    union RCERC_REG   RCERC;      /* MCBSP Receive channel enable partition C*/
    union RCERD_REG   RCERD;      /* MCBSP Receive channel enable partition D*/
    union XCERC_REG   XCERC;      /* MCBSP Transmit channel enable partition C*/
    union XCERD_REG   XCERD;      /* MCBSP Transmit channel enable partition D*/
    union RCERE_REG   RCERE;      /* MCBSP Receive channel enable partition E*/
    union RCERF_REG   RCERF;      /* MCBSP Receive channel enable partition F*/
    union XCERE_REG   XCERE;      /* MCBSP Transmit channel enable partition E*/
    union XCERF_REG   XCERF;      /* MCBSP Transmit channel enable partition F*/
    union RCERG_REG   RCERG;      /* MCBSP Receive channel enable partition G*/
    union RCERH_REG   RCERH;      /* MCBSP Receive channel enable partition H*/
    union XCERG_REG   XCERG;      /* MCBSP Transmit channel enable partition G*/
    union XCERH_REG   XCERH;      /* MCBSP Transmit channel enable partition H*/
    uint16_t          rsvd1[4];   /* reserved*/
    union MFFINT_REG  MFFINT;     /* MCBSP Interrupt enable register for 
                                  * RINT/XINT*/
    uint16_t          rsvd2;      /* reserved*/
};

/*
* McBSP External References & Function Declarations
*/
extern volatile struct MCBSP_REGS McbspaRegs;
extern volatile struct MCBSP_REGS McbspbRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  /* end of DSP2833x_MCBSP_H definition*/

/*
* No more
*/

