/*
*###########################################################################
*
* FILE:   DSP2833x_EQep.h
*
* TITLE:  DSP2833x Enhanced Quadrature Encoder Pulse Module 
*         Register Bit Definitions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
#ifndef DSP2833x_EQEP_H
#define DSP2833x_EQEP_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
* Capture decoder control register bit definitions
*/
struct QDECCTL_BITS
{       /* bits  description*/
    uint16_t rsvd1:5;         /* 4:0   reserved*/
    uint16_t QSP:1;           /* 5     QEPS input polarity*/
    uint16_t QIP:1;           /* 6     QEPI input polarity*/
    uint16_t QBP:1;           /* 7     QEPB input polarity*/
    uint16_t QAP:1;           /* 8     QEPA input polarity*/
    uint16_t IGATE:1;         /* 9     Index pulse gating option*/
    uint16_t SWAP:1;          /* 10    CLK/DIR signal source for Position Counter*/
    uint16_t XCR:1;           /* 11    External clock rate*/
    uint16_t SPSEL:1;         /* 12    Sync output pin select*/
    uint16_t SOEN:1;          /* 13    Enable position compare sync*/
    uint16_t QSRC:2;          /* 15:14 Position counter source*/
};

union QDECCTL_REG
{
    uint16_t              all;
    struct QDECCTL_BITS   bit;
};

/*
* QEP control register bit definitions
*/
struct QEPCTL_BITS
{            /* bits   description*/
    uint16_t WDE:1;               /* 0      QEP watchdog enable*/
    uint16_t UTE:1;               /* 1      QEP unit timer enable*/
    uint16_t QCLM:1;              /* 2      QEP capture latch mode*/
    uint16_t QPEN:1;              /* 3      Quadrature position counter enable*/
    uint16_t IEL:2;               /* 5:4    Index event latch*/
    uint16_t SEL:1;               /* 6      Strobe event latch*/
    uint16_t SWI:1;               /* 7      Software init position counter*/
    uint16_t IEI:2;               /* 9:8    Index event init of position count*/
    uint16_t SEI:2;               /* 11:10  Strobe event init*/
    uint16_t PCRM:2;              /* 13:12  Position counter reset*/
    uint16_t FREE_SOFT:2;         /* 15:14  Emulation mode*/
};

union QEPCTL_REG
{
    uint16_t             all;
    struct QEPCTL_BITS   bit;
};         

/*
* Quadrature capture control register bit definitions
*/
struct QCAPCTL_BITS
{          /* bits   description*/
    uint16_t UPPS:4;              /* 3:0    Unit position pre-scale */
    uint16_t CCPS:3;              /* 6:4    QEP capture timer pre-scale*/
    uint16_t rsvd1:8;             /* 14:7   reserved*/
    uint16_t CEN:1;               /* 15     Enable QEP capture*/
};

union QCAPCTL_REG
{
    uint16_t             all;
    struct QCAPCTL_BITS  bit;
}; 

/*
* Position compare control register bit definitions
*/
struct QPOSCTL_BITS
{           /* bits   description*/
    uint16_t PCSPW:12;            /* 11:0   Position compare sync pulse width*/
    uint16_t PCE:1;               /* 12     Position compare enable/disable*/
    uint16_t PCPOL:1;             /* 13     Polarity of sync output*/
    uint16_t PCLOAD:1;            /* 14     Position compare of shadow load*/
    uint16_t PCSHDW:1;            /* 15     Position compare shadow enable*/
};

union QPOSCTL_REG
{
    uint16_t             all;
    struct QPOSCTL_BITS  bit;
};         

/*
* QEP interrupt control register bit definitions
*/
struct QEINT_BITS
{           /* bits   description*/
    uint16_t rsvd1:1;           /* 0      reserved*/
    uint16_t PCE:1;             /* 1      Position counter error*/
    uint16_t QPE:1;             /* 2      Quadrature phase error*/
    uint16_t QDC:1;             /* 3      Quadrature dir change*/
    uint16_t WTO:1;             /* 4      Watchdog timeout*/
    uint16_t PCU:1;             /* 5      Position counter underflow*/
    uint16_t PCO:1;             /* 6      Position counter overflow*/
    uint16_t PCR:1;             /* 7      Position compare ready*/
    uint16_t PCM:1;             /* 8      Position compare match*/
    uint16_t SEL:1;             /* 9      Strobe event latch*/
    uint16_t IEL:1;             /* 10     Event latch*/
    uint16_t UTO:1;             /* 11     Unit timeout*/
    uint16_t rsvd2:4;           /* 15:12  reserved*/
};

union QEINT_REG
{
    uint16_t             all;
    struct QEINT_BITS    bit;
};

/*
* QEP interrupt status register bit definitions
*/
struct QFLG_BITS
{           /* bits   description*/
    uint16_t INT:1;            /* 0      Global interrupt */
    uint16_t PCE:1;            /* 1      Position counter error*/
    uint16_t PHE:1;            /* 2      Quadrature phase error*/
    uint16_t QDC:1;            /* 3      Quadrature dir change*/
    uint16_t WTO:1;            /* 4      Watchdog timeout*/
    uint16_t PCU:1;            /* 5      Position counter underflow*/
    uint16_t PCO:1;            /* 6      Position counter overflow*/
    uint16_t PCR:1;            /* 7      Position compare ready*/
    uint16_t PCM:1;            /* 8      Position compare match*/
    uint16_t SEL:1;            /* 9      Strobe event latch*/
    uint16_t IEL:1;            /* 10     Event latch*/
    uint16_t UTO:1;            /* 11     Unit timeout*/
    uint16_t rsvd2:4;          /* 15:12  reserved*/
};

union QFLG_REG
{
    uint16_t             all;
    struct QFLG_BITS     bit;
};

/*
* QEP interrupt force register bit definitions
*/
struct QFRC_BITS
{           /* bits   description*/
    uint16_t reserved:1;       /* 0      Reserved*/
    uint16_t PCE:1;            /* 1      Position counter error*/
    uint16_t PHE:1;            /* 2      Quadrature phase error*/
    uint16_t QDC:1;            /* 3      Quadrature dir change*/
    uint16_t WTO:1;            /* 4      Watchdog timeout*/
    uint16_t PCU:1;            /* 5      Position counter underflow*/
    uint16_t PCO:1;            /* 6      Position counter overflow*/
    uint16_t PCR:1;            /* 7      Position compare ready*/
    uint16_t PCM:1;            /* 8      Position compare match*/
    uint16_t SEL:1;            /* 9      Strobe event latch*/
    uint16_t IEL:1;            /* 10     Event latch*/
    uint16_t UTO:1;            /* 11     Unit timeout*/
    uint16_t rsvd2:4;          /* 15:12  reserved*/
};


union QFRC_REG
{
    uint16_t             all;
    struct QFRC_BITS     bit;
};

/*
* V1.1 Added UPEVNT (bit 7) This reflects changes 
* made as of F2833x Rev A devices
*/

/*
* QEP status register bit definitions
*/
struct QEPSTS_BITS
{           /* bits   description*/
    uint16_t PCEF:1;             /* 0      Position counter error*/
    uint16_t FIMF:1;             /* 1      First index marker*/
    uint16_t CDEF:1;             /* 2      Capture direction error*/
    uint16_t COEF:1;             /* 3      Capture overflow error*/
    uint16_t QDLF:1;             /* 4      QEP direction latch*/
    uint16_t QDF:1;              /* 5      Quadrature direction*/
    uint16_t FIDF:1;             /* 6      Direction on first index marker*/
    uint16_t UPEVNT:1;           /* 7      Unit position event flag*/
    uint16_t rsvd1:8;            /* 15:8   reserved*/
};

union QEPSTS_REG
{
    uint16_t             all;
    struct QEPSTS_BITS   bit;
};

struct EQEP_REGS
{
    uint32_t            QPOSCNT;   /* Position counter */
    uint32_t            QPOSINIT;  /* Position counter init*/
    uint32_t            QPOSMAX;   /* Maximum position count*/
    uint32_t            QPOSCMP;   /* Position compare*/
    uint32_t            QPOSILAT;  /* Index position latch*/
    uint32_t            QPOSSLAT;  /* Strobe position latch*/
    uint32_t            QPOSLAT;   /* Position latch*/
    uint32_t            QUTMR;     /* Unit timer*/
    uint32_t            QUPRD;     /* Unit period*/
    uint16_t            QWDTMR;    /* QEP watchdog timer*/
    uint16_t            QWDPRD;    /* QEP watchdog period*/
    union  QDECCTL_REG  QDECCTL;   /* Quadrature decoder control*/
    union  QEPCTL_REG   QEPCTL;    /* QEP control */
    union  QCAPCTL_REG  QCAPCTL;   /* Quadrature capture control */
    union  QPOSCTL_REG  QPOSCTL;   /* Position compare control*/
    union  QEINT_REG    QEINT;     /* QEP interrupt control*/   
    union  QFLG_REG     QFLG;      /* QEP interrupt flag*/
    union  QFLG_REG     QCLR;      /* QEP interrupt clear*/                  
    union  QFRC_REG     QFRC;      /* QEP interrupt force*/                 
    union  QEPSTS_REG   QEPSTS;    /* QEP status*/
    uint16_t            QCTMR;     /* QEP capture timer*/
    uint16_t            QCPRD;     /* QEP capture period*/
    uint16_t            QCTMRLAT;  /* QEP capture latch*/
    uint16_t            QCPRDLAT;  /* QEP capture period latch*/
    uint16_t            rsvd1[30]; /* reserved*/
};

/*
* GPI/O External References & Function Declarations
*/
extern volatile struct EQEP_REGS EQep1Regs;
extern volatile struct EQEP_REGS EQep2Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  /* end of DSP2833x_EQEP_H definition*/

/*
* End of file
*/

