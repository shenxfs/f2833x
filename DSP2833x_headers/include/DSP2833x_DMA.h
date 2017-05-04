/*
*###########################################################################
*
* FILE:   DSP2833x_DMA.h
*
* TITLE:  DSP2833x DMA Module Register Bit Definitions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
#ifndef DSP2833x_DMA_H
#define DSP2833x_DMA_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
* Channel MODE register bit definitions
*/
struct MODE_BITS
{      /* bits   description*/
    uint16_t PERINTSEL:5; /* 4:0 Peripheral Interrupt and Sync Select Bits (R/W):
                        *        0     no interrupt
                        *        1     SEQ1INT & ADCSYNC
                        *        2     SEQ2INT
                        *        3     XINT1
                        *        4     XINT2
                        *        5     XINT3
                        *        6     XINT4
                        *        7     XINT5
                        *        8     XINT6
                        *        9     XINT7
                        *        10    XINT13
                        *        11    TINT0
                        *        12    TINT1
                        *        13    TINT2
                        *        14    MXEVTA & MXSYNCA
                        *        15    MREVTA & MRSYNCA
                        *        16    MXEVTB & MXSYNCB
                        *        17    MREVTB & MRSYNCB
                        *        18    ePWM1SOCA
                        *        19    ePWM1SOCB
                        *        20    ePWM2SOCA
                        *        21    ePWM2SOCB
                        *        22    ePWM3SOCA
                        *        23    ePWM3SOCB
                        *        24    ePWM4SOCA
                        *        25    ePWM4SOCB
                        *        26    ePWM5SOCA
                        *        27    ePWM5SOCB
                        *        28    ePWM6SOCA
                        *        29    ePWM6SOCB
                        *        30:31 no interrupt*/
    uint16_t rsvd1:2;     /* 6:5    (R=0:0)*/
    uint16_t OVRINTE:1;   /* 7      Overflow Interrupt Enable (R/W):
                        *        0     overflow interrupt disabled
                        *        1     overflow interrupt enabled*/
    uint16_t PERINTE:1;   /* 8      Peripheral Interrupt Enable Bit (R/W):
                        *        0     peripheral interrupt disabled
                        *        1     peripheral interrupt enabled*/
    uint16_t CHINTMODE:1; /* 9      Channel Interrupt Mode Bit (R/W):
                        *        0     generate interrupt at beginning of new 
                        *              transfer
                        *        1     generate interrupt at end of transfer*/
    uint16_t ONESHOT:1;   /* 10     One Shot Mode Bit (R/W):
                        *        0     only interrupt event triggers single 
                        *              burst transfer
                        *        1     first interrupt triggers burst, 
                        *              continue until transfer count is zero*/
    uint16_t CONTINUOUS:1;/* 11     Continous Mode Bit (R/W):
                        *        0     stop when transfer count is zero
                        *        1     re-initialize when transfer count is 
                        *              zero*/
    uint16_t SYNCE:1;     /* 12     Sync Enable Bit (R/W):
                        *        0     ignore selected interrupt sync signal
                        *        1     enable selected interrupt sync signal*/
    uint16_t SYNCSEL:1;   /* 13     Sync Select Bit (R/W):
                        *        0     sync signal controls source wrap 
                        *              counter
                        *        1     sync signal controls destination wrap 
                        *              counter*/
    uint16_t DATASIZE:1;  /* 14     Data Size Mode Bit (R/W):
                        *        0     16-bit data transfer size
                        *        1     32-bit data transfer size*/
    uint16_t CHINTE:1;    /* 15     Channel Interrupt Enable Bit (R/W):
                        *        0     channel interrupt disabled
                        *        1     channel interrupt enabled*/
};

union MODE_REG
{
    uint16_t              all;
    struct MODE_BITS      bit;
};

/*
* Channel CONTROL register bit definitions
*/
struct CONTROL_BITS
{       /* bits   description*/
    uint16_t RUN:1;           /* 0      Run Bit (R=0/W=1)*/
    uint16_t HALT:1;          /* 1      Halt Bit (R=0/W=1)*/
    uint16_t SOFTRESET:1;     /* 2      Soft Reset Bit (R=0/W=1)*/
    uint16_t PERINTFRC:1;     /* 3      Interrupt Force Bit (R=0/W=1)*/
    uint16_t PERINTCLR:1;     /* 4      Interrupt Clear Bit (R=0/W=1)*/
    uint16_t SYNCFRC:1;       /* 5      Sync Force Bit (R=0/W=1)*/
    uint16_t SYNCCLR:1;       /* 6      Sync Clear Bit (R=0/W=1)*/
    uint16_t ERRCLR:1;        /* 7      Error Clear Bit (R=0/W=1)*/
    uint16_t PERINTFLG:1;     /* 8      Interrupt Flag Bit (R):
                            *        0     no interrupt pending
                            *        1     interrupt pending*/
    uint16_t SYNCFLG:1;       /* 9      Sync Flag Bit (R):
                            *        0     no sync pending
                            *        1     sync pending*/
    uint16_t SYNCERR:1;       /* 10     Sync Error Flag Bit (R):
                            *        0     no sync error
                            *        1     sync error detected*/
    uint16_t TRANSFERSTS:1;   /* 11     Transfer Status Bit (R):
                            *        0     no transfer in progress or pending
                            *        1     transfer in progress or pending*/
    uint16_t BURSTSTS:1;      /* 12     Burst Status Bit (R):
                            *        0     no burst in progress or pending
                            *        1     burst in progress or pending*/
    uint16_t RUNSTS:1;        /* 13     Run Status Bit (R):
                            *        0     channel not running or halted
                            *        1     channel running*/
    uint16_t OVRFLG:1;        /* 14     Overflow Flag Bit(R)
                            *        0     no overflow event
                            *        1     overflow event*/
    uint16_t rsvd1:1;         /* 15     (R=0)*/
};

union CONTROL_REG
{
    uint16_t               all;
    struct CONTROL_BITS    bit;
};

/*
* DMACTRL register bit definitions
*/
struct DMACTRL_BITS
{         /* bits   description*/
    uint16_t HARDRESET:1;       /* 0      Hard Reset Bit (R=0/W=1)*/
    uint16_t PRIORITYRESET:1;   /* 1      Priority Reset Bit (R=0/W=1)*/
    uint16_t rsvd1:14;          /* 15:2   (R=0:0)*/
};

union DMACTRL_REG
{
    uint16_t               all;
    struct DMACTRL_BITS    bit;
};

/*
* DEBUGCTRL register bit definitions
*/
struct DEBUGCTRL_BITS
{     /* bits   description*/
    uint16_t rsvd1:15;        /* 14:0   (R=0:0)*/
    uint16_t FREE:1;          /* 15     Debug Mode Bit (R/W):
                            *    0   halt after current read-write operation
                            *    1   continue running*/
};

union DEBUGCTRL_REG
{
    uint16_t               all;
    struct DEBUGCTRL_BITS  bit;
};

/*
* PRIORITYCTRL1 register bit definitions
*/
struct PRIORITYCTRL1_BITS
{ /* bits   description*/
   uint16_t CH1PRIORITY:1;    /*     0      Ch1 Priority Bit (R/W):
                            *     0     same priority as all other channels
                            *     1     highest priority channel*/
   uint16_t rsvd1:15;         /* 15:1   (R=0:0)*/
};

union PRIORITYCTRL1_REG
{
    uint16_t                   all;
    struct PRIORITYCTRL1_BITS  bit;
};

/*
* PRIORITYSTAT register bit definitions:
*/
struct PRIORITYSTAT_BITS
{     /* bits   description*/
    uint16_t ACTIVESTS:3;        /* 2:0    Active Channel Status Bits (R):
                               *        0,0,0  no channel active
                               *        0,0,1  Ch1 channel active
                               *        0,1,0  Ch2 channel active
                               *        0,1,1  Ch3 channel active
                               *        1,0,0  Ch4 channel active
                               *        1,0,1  Ch5 channel active
                               *        1,1,0  Ch6 channel active*/
    uint16_t rsvd1:1;            /* 3      (R=0)*/
    uint16_t ACTIVESTS_SHADOW:3; /* 6:4   Active Channel Status Shadow Bits (R):
                               * 0,0,0 no channel active & interrupted by Ch1
                               * 0,0,1 cannot occur
                               * 0,1,0 Ch2 was active and interrupted by Ch1
                               * 0,1,1 Ch3 was active and interrupted by Ch1
                               * 1,0,0 Ch4 was active and interrupted by Ch1
                               * 1,0,1 Ch5 was active and interrupted by Ch1
                               * 1,1,0 Ch6 was active and interrupted by Ch1*/
    uint16_t rsvd2:9;            /* 15:7   (R=0:0)*/
};

union PRIORITYSTAT_REG
{
    uint16_t                   all;
    struct PRIORITYSTAT_BITS   bit;
};

/*
* Burst Size
*/
struct BURST_SIZE_BITS
{   /* bits  description*/
    uint16_t BURSTSIZE:5;    /* 4:0   Burst transfer size*/
    uint16_t rsvd1:11;       /* 15:5  reserved*/
};

union BURST_SIZE_REG
{
    uint16_t                all;
    struct BURST_SIZE_BITS  bit;
};

/*
* Burst Count
*/
struct BURST_COUNT_BITS
{ /* bits  description*/
    uint16_t BURSTCOUNT:5;   /* 4:0   Burst transfer size*/
    uint16_t rsvd1:11;       /* 15:5  reserved*/
};

union BURST_COUNT_REG
{
    uint16_t                 all;
    struct BURST_COUNT_BITS  bit;
};

/*
* DMA Channel Registers:
*/
struct CH_REGS
{
    union  MODE_REG            MODE;                 /* Mode Register*/
    union  CONTROL_REG         CONTROL;              /* Control Register*/

    union  BURST_SIZE_REG      BURST_SIZE;           /* Burst Size Register*/
    union  BURST_COUNT_REG     BURST_COUNT;          /* Burst Count Register*/
    
    /*
    * Source Burst Step Register
    */
    int16_t                    SRC_BURST_STEP;       
    
    /*
    * Destination Burst Step Register
    */
    int16_t                    DST_BURST_STEP;

    uint16_t                   TRANSFER_SIZE;        /* Transfer Size Register*/
    uint16_t                   TRANSFER_COUNT;       /* Transfer Count Register*/
    
    /*
    * Source Transfer Step Register
    */
    int16_t                    SRC_TRANSFER_STEP;
    
    /*
    * Destination Transfer Step Register
    */
    int16_t                    DST_TRANSFER_STEP;

    uint16_t                   SRC_WRAP_SIZE;      /* Source Wrap Size Register*/
    uint16_t                   SRC_WRAP_COUNT;     /* Source Wrap Count Register*/
    int16_t                    SRC_WRAP_STEP;      /* Source Wrap Step Register*/

    /*
    * Destination Wrap Size Register
    */
    uint16_t                   DST_WRAP_SIZE;        
    
    /*
    * Destination Wrap Count Register
    */
    uint16_t                   DST_WRAP_COUNT;
    
    /*
    * Destination Wrap Step Register
    */
    int16_t                    DST_WRAP_STEP;

    /*
    * Source Begin Address Shadow Register
    */
    uint32_t                   SRC_BEG_ADDR_SHADOW;
    
    /*
    * Source Address Shadow Register
    */
    uint32_t                   SRC_ADDR_SHADOW;
    
    /*
    * Source Begin Address Active Register
    */
    uint32_t                   SRC_BEG_ADDR_ACTIVE;
    
    /*
    * Source Address Active Register
    */
    uint32_t                   SRC_ADDR_ACTIVE;

    /*
    * Destination Begin Address Shadow Register
    */
    uint32_t                   DST_BEG_ADDR_SHADOW;
    
    /*
    * Destination Address Shadow Register
    */
    uint32_t                   DST_ADDR_SHADOW;
    
    /*
    * Destination Begin Address Active Register
    */
    uint32_t                   DST_BEG_ADDR_ACTIVE;
    
    /*
    * Destination Address Active Register
    */
    uint32_t                   DST_ADDR_ACTIVE;
};

/*
* DMA Registers
*/
struct DMA_REGS
{
    union  DMACTRL_REG         DMACTRL;          /* DMA Control Register*/
    union  DEBUGCTRL_REG       DEBUGCTRL;        /* Debug Control Register*/
    uint16_t                   rsvd0;            /* reserved*/
    uint16_t                   rsvd1;            /**/
    union  PRIORITYCTRL1_REG   PRIORITYCTRL1;    /* Priority Control 1 Register*/
    uint16_t                   rsvd2;            /**/
    union  PRIORITYSTAT_REG    PRIORITYSTAT;     /* Priority Status Register*/
    uint16_t                   rsvd3[25];        /**/
    struct CH_REGS             CH1;              /* DMA Channel 1 Registers*/
    struct CH_REGS             CH2;              /* DMA Channel 2 Registers*/
    struct CH_REGS             CH3;              /* DMA Channel 3 Registers*/
    struct CH_REGS             CH4;              /* DMA Channel 4 Registers*/
    struct CH_REGS             CH5;              /* DMA Channel 5 Registers*/
    struct CH_REGS             CH6;              /* DMA Channel 6 Registers*/
};

/*
* External References & Function Declarations
*/
extern volatile struct DMA_REGS DmaRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  /* end of DSP2833x_DMA_H definition*/

/*
* End of file 
*/

