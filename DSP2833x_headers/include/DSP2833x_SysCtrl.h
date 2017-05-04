/*
*###########################################################################
*
* FILE:   DSP2833x_SysCtrl.h
*
* TITLE:  DSP2833x Device System Control Register Definitions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
#ifndef DSP2833x_SYS_CTRL_H
#define DSP2833x_SYS_CTRL_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/*
* System Control Individual Register Bit Definitions
*/

/*
* PLL Status Register
*/
struct PLLSTS_BITS
{     /* bits  description*/
    uint16_t PLLLOCKS:1;     /* 0     PLL lock status*/
    uint16_t rsvd1:1;        /* 1     reserved*/
    uint16_t PLLOFF:1;       /* 2     PLL off bit*/
    uint16_t MCLKSTS:1;      /* 3     Missing clock status bit*/
    uint16_t MCLKCLR:1;      /* 4     Missing clock clear bit*/
    uint16_t OSCOFF:1;       /* 5     Oscillator clock off*/
    uint16_t MCLKOFF:1;      /* 6     Missing clock detect*/
    uint16_t DIVSEL:2;       /* 7     Divide Select*/
    uint16_t rsvd2:7;        /* 15:7  reserved*/
};

union PLLSTS_REG
{
    uint16_t            all;
    struct PLLSTS_BITS  bit;
};

/*
* High speed peripheral clock register bit definitions
*/
struct HISPCP_BITS
{       /* bits  description*/
    uint16_t HSPCLK:3;        /* 2:0   Rate relative to SYSCLKOUT*/
    uint16_t rsvd1:13;        /* 15:3  reserved*/
};
    
union HISPCP_REG
{
    uint16_t            all;
    struct HISPCP_BITS  bit;
};

/*
* Low speed peripheral clock register bit definitions
*/
struct LOSPCP_BITS
{       /* bits  description*/
    uint16_t LSPCLK:3;        /* 2:0   Rate relative to SYSCLKOUT*/
    uint16_t rsvd1:13;        /* 15:3  reserved*/
};

union LOSPCP_REG
{
    uint16_t            all;
    struct LOSPCP_BITS  bit;
};

/*
* Peripheral clock control register 0 bit definitions
*/
struct PCLKCR0_BITS 
{    /* bits  description*/
    uint16_t rsvd1:2;       /* 1:0   reserved*/
    uint16_t TBCLKSYNC:1;   /* 2     EWPM Module TBCLK enable/sync*/
    uint16_t ADCENCLK:1;    /* 3     Enable high speed clk to ADC*/
    uint16_t I2CAENCLK:1;   /* 4     Enable SYSCLKOUT to I2C-A*/
    uint16_t SCICENCLK:1;   /* 5     Enalbe low speed clk to SCI-C*/
    uint16_t rsvd2:2;       /* 7:6   reserved*/
    uint16_t SPIAENCLK:1;   /* 8     Enable low speed clk to SPI-A*/
    uint16_t rsvd3:1;       /* 9     reserved*/
    uint16_t SCIAENCLK:1;   /* 10    Enable low speed clk to SCI-A*/
    uint16_t SCIBENCLK:1;   /* 11    Enable low speed clk to SCI-B*/
    uint16_t MCBSPAENCLK:1; /* 12    Enable low speed clk to McBSP-A*/
    uint16_t MCBSPBENCLK:1; /* 13    Enable low speed clk to McBSP-B*/
    uint16_t ECANAENCLK:1;  /* 14    Enable system clk to eCAN-A*/
    uint16_t ECANBENCLK:1;  /* 15    Enable system clk to eCAN-B*/
};

union PCLKCR0_REG
{
    uint16_t            all;
    struct PCLKCR0_BITS bit;
};

/*
* Peripheral clock control register 1 bit definitions
*/
struct PCLKCR1_BITS
{     /* bits  description*/
    uint16_t EPWM1ENCLK:1;   /* 0     Enable SYSCLKOUT to EPWM1*/
    uint16_t EPWM2ENCLK:1;   /* 1     Enable SYSCLKOUT to EPWM2*/
    uint16_t EPWM3ENCLK:1;   /* 2     Enable SYSCLKOUT to EPWM3*/
    uint16_t EPWM4ENCLK:1;   /* 3     Enable SYSCLKOUT to EPWM4*/
    uint16_t EPWM5ENCLK:1;   /* 4     Enable SYSCLKOUT to EPWM5*/
    uint16_t EPWM6ENCLK:1;   /* 5     Enable SYSCLKOUT to EPWM6*/
    uint16_t rsvd1:2;        /* 7:6   reserved*/
    uint16_t ECAP1ENCLK:1;   /* 8     Enable SYSCLKOUT to ECAP1*/
    uint16_t ECAP2ENCLK:1;   /* 9     Enable SYSCLKOUT to ECAP2*/
    uint16_t ECAP3ENCLK:1;   /* 10    Enable SYSCLKOUT to ECAP3*/
    uint16_t ECAP4ENCLK:1;   /* 11    Enable SYSCLKOUT to ECAP4*/
    uint16_t ECAP5ENCLK:1;   /* 12    Enable SYSCLKOUT to ECAP5*/
    uint16_t ECAP6ENCLK:1;   /* 13    Enable SYSCLKOUT to ECAP6*/
    uint16_t EQEP1ENCLK:1;   /* 14    Enable SYSCLKOUT to EQEP1*/
    uint16_t EQEP2ENCLK:1;   /* 15    Enable SYSCLKOUT to EQEP2*/
};

union PCLKCR1_REG
{
    uint16_t            all;
    struct PCLKCR1_BITS bit;
};

/*
* Peripheral clock control register 2 bit definitions
*/
struct PCLKCR3_BITS
{         /* bits  description*/
    uint16_t rsvd1:8;            /* 7:0   reserved*/
    uint16_t CPUTIMER0ENCLK:1;   /* 8     Enable SYSCLKOUT to CPU-Timer 0*/
    uint16_t CPUTIMER1ENCLK:1;   /* 9     Enable SYSCLKOUT to CPU-Timer 1*/
    uint16_t CPUTIMER2ENCLK:1;   /* 10    Enable SYSCLKOUT to CPU-Timer 2*/
    uint16_t DMAENCLK:1;         /* 11    Enable the DMA clock*/
    uint16_t XINTFENCLK:1;       /* 12    Enable SYSCLKOUT to XINTF*/
    uint16_t GPIOINENCLK:1;      /*     Enable GPIO input clock*/
    uint16_t rsvd2:2;            /* 15:14 reserved*/
};

union PCLKCR3_REG {
    uint16_t            all;
    struct PCLKCR3_BITS bit;
};

/*
* PLL control register bit definitions
*/
struct PLLCR_BITS
{       /* bits  description*/
    uint16_t DIV:4;         /* 3:0   Set clock ratio for the PLL*/
    uint16_t rsvd1:12;      /* 15:4  reserved*/
};

union PLLCR_REG
{
    uint16_t           all;
    struct PLLCR_BITS  bit;
};

/*
* Low Power Mode 0 control register bit definitions
*/
struct LPMCR0_BITS
{      /* bits  description*/
    uint16_t LPM:2;         /* 1:0   Set the low power mode*/
    uint16_t QUALSTDBY:6;   /* 7:2   Qualification*/
    uint16_t rsvd1:7;       /* 14:8  reserved*/
    uint16_t WDINTE:1;      /* 15    Enables WD to wake the device from STANDBY*/
};
    
union LPMCR0_REG
{
    uint16_t              all;
    struct LPMCR0_BITS  bit;
};

/*
* Dual-mapping configuration register bit definitions
*/
struct MAPCNF_BITS
{     /* bits  description*/
    uint16_t MAPEPWM:1;    /* 0     EPWM dual-map enable*/
    uint16_t rsvd1:15;     /* 15:1  reserved*/
};

union MAPCNF_REG
{
	uint16_t           all;
	struct MAPCNF_BITS bit;
};

/*
* System Control Register File
*/
struct SYS_CTRL_REGS
{
    uint16_t            rsvd1;     /* 0*/
    union   PLLSTS_REG  PLLSTS;    /* 1*/
    uint16_t            rsvd2[8];  /* 2-9*/
    
    /*
    * 10: High-speed peripheral clock pre-scaler
    */
    union   HISPCP_REG  HISPCP;
    
    union   LOSPCP_REG  LOSPCP;    /* 11: Low-speed peripheral clock pre-scaler*/
    union   PCLKCR0_REG PCLKCR0;   /* 12: Peripheral clock control register*/
    union   PCLKCR1_REG PCLKCR1;   /* 13: Peripheral clock control register*/
    union   LPMCR0_REG  LPMCR0;    /* 14: Low-power mode control register 0*/
    uint16_t            rsvd3;     /* 15: reserved*/
    union   PCLKCR3_REG PCLKCR3;   /* 16: Peripheral clock control register*/
    union   PLLCR_REG   PLLCR;     /* 17: PLL control register*/
    
    /*
    * No bit definitions are defined for SCSR because
    * a read-modify-write instruction can clear the WDOVERRIDE bit
    */
    uint16_t            SCSR;      /* 18: System control and status register*/
    
    uint16_t            WDCNTR;    /* 19: WD counter register*/
    uint16_t            rsvd4;     /* 20*/
    uint16_t            WDKEY;     /* 21: WD reset key register*/
    uint16_t            rsvd5[3];  /* 22-24*/
    
    /*
    * No bit definitions are defined for WDCR because
    * the proper value must be written to the WDCHK field
    * whenever writing to this register.
    */
    uint16_t            WDCR;      /* 25: WD timer control register*/
    
    uint16_t            rsvd6[4];  /* 26-29*/
    union   MAPCNF_REG  MAPCNF;    /* 30: Dual-mapping configuration register*/
    uint16_t            rsvd7[1];  /* 31*/
};

/*
* CSM Registers
*/

/*
* CSM Status & Control register bit definitions
*/
struct  CSMSCR_BITS
{       /* bit   description*/
    uint16_t     SECURE:1;    /* 0     Secure flag*/
    uint16_t     rsvd1:14;    /* 14-1  reserved*/
    uint16_t     FORCESEC:1;  /* 15    Force Secure control bit*/
};

/*
* Allow access to the bit fields or entire register
*/
union CSMSCR_REG
{
    uint16_t           all;
    struct CSMSCR_BITS bit;
};

/*
* CSM Register File
*/
struct  CSM_REGS
{
    uint16_t           KEY0;    /* KEY reg bits 15-0*/
    uint16_t           KEY1;    /* KEY reg bits 31-16*/
    uint16_t           KEY2;    /* KEY reg bits 47-32*/
    uint16_t           KEY3;    /* KEY reg bits 63-48*/
    uint16_t           KEY4;    /* KEY reg bits 79-64*/
    uint16_t           KEY5;    /* KEY reg bits 95-80*/
    uint16_t           KEY6;    /* KEY reg bits 111-96*/
    uint16_t           KEY7;    /* KEY reg bits 127-112*/
    uint16_t           rsvd1;   /* reserved*/
    uint16_t           rsvd2;   /* reserved*/
    uint16_t           rsvd3;   /* reserved*/
    uint16_t           rsvd4;   /* reserved*/
    uint16_t           rsvd5;   /* reserved*/
    uint16_t           rsvd6;   /* reserved*/
    uint16_t           rsvd7;   /* reserved*/
    union CSMSCR_REG CSMSCR;  /* CSM Status & Control register*/
};  

/*
* Password locations
*/
struct  CSM_PWL
{
    uint16_t   PSWD0;  /* PSWD bits 15-0*/
    uint16_t   PSWD1;  /* PSWD bits 31-16*/
    uint16_t   PSWD2;  /* PSWD bits 47-32*/
    uint16_t   PSWD3;  /* PSWD bits 63-48*/
    uint16_t   PSWD4;  /* PSWD bits 79-64*/
    uint16_t   PSWD5;  /* PSWD bits 95-80*/
    uint16_t   PSWD6;  /* PSWD bits 111-96*/
    uint16_t   PSWD7;  /* PSWD bits 127-112*/
};  
    
/*
* Defines for Flash Registers
*/
#define FLASH_SLEEP   (0x0000U)
#define FLASH_STANDBY (0x0001U)
#define FLASH_ACTIVE  (0x0003U)

/*
* Flash Option Register bit definitions
*/
struct  FOPT_BITS
{        /* bit   description*/
    uint16_t     ENPIPE:1;   /* 0     Enable Pipeline Mode*/
    uint16_t     rsvd:15;    /* 1-15  reserved*/
};

/*
* Allow access to the bit fields or entire register
*/
union FOPT_REG
{
    uint16_t         all;
    struct FOPT_BITS bit;
};

/*
* Flash Power Modes Register bit definitions
*/
struct  FPWR_BITS
{        /* bit   description*/
    uint16_t     PWR:2;      /* 0-1   Power Mode bits*/
    uint16_t     rsvd:14;    /* 2-15  reserved*/
};

/*
* Allow access to the bit fields or entire register
*/
union FPWR_REG
{
    uint16_t         all;
    struct FPWR_BITS bit;
};

/*
* Flash Status Register bit definitions
*/
struct  FSTATUS_BITS
{        /* bit   description*/
    uint16_t     PWRS:2;        /* 0-1   Power Mode Status bits*/
    uint16_t     STDBYWAITS:1;  /* 2     Bank/Pump Sleep to Standby Wait Counter Status bits*/
    uint16_t     ACTIVEWAITS:1; /* 3     Bank/Pump Standby to Active Wait Counter Status bits*/
    uint16_t     rsvd1:4;       /* 4-7   reserved*/
    uint16_t     V3STAT:1;      /* 8     VDD3V Status Latch bit*/
    uint16_t     rsvd2:7;       /* 9-15  reserved*/
};  

/*
* Allow access to the bit fields or entire register
*/
union FSTATUS_REG
{
    uint16_t            all;
    struct FSTATUS_BITS bit;
};  

/*
* Flash Sleep to Standby Wait Counter Register bit definitions
*/
struct  FSTDBYWAIT_BITS
{     /* bit   description*/
    /*
    * 0-8   Bank/Pump Sleep to Standby Wait Count bits
    */
    uint16_t     STDBYWAIT:9;
    
    uint16_t     rsvd:7;        /* 9-15  reserved*/
};

/*
* Allow access to the bit fields or entire register
*/
union FSTDBYWAIT_REG
{
    uint16_t               all;
    struct FSTDBYWAIT_BITS bit;
};

/*
* Flash Standby to Active Wait Counter Register bit definitions
*/
struct  FACTIVEWAIT_BITS
{    /* bit   description*/
    /*
    * 0-8   Bank/Pump Standby to Active Wait Count bits
    */
    uint16_t     ACTIVEWAIT:9;
    
    uint16_t     rsvd:7;        /* 9-15  reserved*/
};

/*
* Allow access to the bit fields or entire register
*/
union FACTIVEWAIT_REG
{
    uint16_t                all;
    struct FACTIVEWAIT_BITS bit;
};

/*
* Bank Read Access Wait State Register bit definitions
*/
struct  FBANKWAIT_BITS
{        /* bit   description*/
    uint16_t     RANDWAIT:4;      /* 0-3   Flash Random Read Wait State bits*/
    uint16_t     rsvd1:4;         /* 4-7   reserved*/
    uint16_t     PAGEWAIT:4;      /* 8-11  Flash Paged Read Wait State bits*/
    uint16_t     rsvd2:4;         /* 12-15 reserved*/
}; 

/*
* Allow access to the bit fields or entire register
*/
union FBANKWAIT_REG
{
    uint16_t              all;
    struct FBANKWAIT_BITS bit;
};

/*
* OTP Read Access Wait State Register bit definitions
*/
struct  FOTPWAIT_BITS
{       /* bit   description*/
    uint16_t     OTPWAIT:5;     /* 0-4   OTP Read Wait State bits*/
    uint16_t     rsvd:11;       /* 5-15  reserved*/
};

/*
* Allow access to the bit fields or entire register
*/
union FOTPWAIT_REG
{
    uint16_t             all;
    struct FOTPWAIT_BITS bit;
};  

struct FLASH_REGS
{
    union FOPT_REG        FOPT;        /* Option Register*/
    uint16_t              rsvd1;       /* reserved*/
    union FPWR_REG        FPWR;        /* Power Modes Register*/
    union FSTATUS_REG     FSTATUS;     /* Status Register*/
    
    /*
    * Pump/Bank Sleep to Standby Wait State Register
    */
    union FSTDBYWAIT_REG  FSTDBYWAIT;
    
    /*
    * Pump/Bank Standby to Active Wait State Register
    */
    union FACTIVEWAIT_REG FACTIVEWAIT;
    
    union FBANKWAIT_REG   FBANKWAIT;   /* Bank Read Access Wait State Register*/
    union FOTPWAIT_REG    FOTPWAIT;    /* OTP Read Access Wait State Register*/
};

/*
* System Control External References & Function Declarations
*/
extern volatile struct SYS_CTRL_REGS SysCtrlRegs;
extern volatile struct CSM_REGS CsmRegs;
extern volatile struct CSM_PWL CsmPwl;
extern volatile struct FLASH_REGS FlashRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  /* end of DSP2833x_SYS_CTRL_H definition*/

/*
* End of file
*/

