/*
*###########################################################################
*
* FILE:   DSP2833x_Adc.h
*
* TITLE:  DSP2833x Device ADC Register Definitions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
#ifndef DSP2833x_ADC_H
#define DSP2833x_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/*
* ADC Individual Register Bit Definitions:
*/
struct ADCTRL1_BITS
{     /* bits  description*/
    uint16_t  rsvd1:4;      /* 3:0   reserved*/
    uint16_t  SEQ_CASC:1;   /* 4     Cascaded sequencer mode*/
    uint16_t  SEQ_OVRD:1;   /* 5     Sequencer override */
    uint16_t  CONT_RUN:1;   /* 6     Continuous run*/
    uint16_t  CPS:1;        /* 7     ADC core clock pre-scalar*/
    uint16_t  ACQ_PS:4;     /* 11:8  Acquisition window size*/
    uint16_t  SUSMOD:2;     /* 13:12 Emulation suspend mode*/
    uint16_t  RESET:1;      /* 14    ADC reset*/
    uint16_t  rsvd2:1;      /* 15    reserved*/
};

union ADCTRL1_REG
{
   uint16_t              all;
   struct ADCTRL1_BITS   bit;
};

struct ADCTRL2_BITS
{         /* bits  description*/
    uint16_t  EPWM_SOCB_SEQ2:1; /* 0     EPWM compare B SOC mask for SEQ2*/
    uint16_t  rsvd1:1;          /* 1     reserved*/
    uint16_t  INT_MOD_SEQ2:1;   /* 2     SEQ2 Interrupt mode*/
    uint16_t  INT_ENA_SEQ2:1;   /* 3     SEQ2 Interrupt enable*/
    uint16_t  rsvd2:1;          /* 4     reserved*/
    uint16_t  SOC_SEQ2:1;       /* 5     Start of conversion for SEQ2*/
    uint16_t  RST_SEQ2:1;       /* 6     Reset SEQ2*/
    uint16_t  EXT_SOC_SEQ1:1;   /* 7     External start of conversion for SEQ1*/
    uint16_t  EPWM_SOCA_SEQ1:1; /* 8     EPWM compare B SOC mask for SEQ1*/
    uint16_t  rsvd3:1;          /* 9     reserved*/
    uint16_t  INT_MOD_SEQ1:1;   /* 10    SEQ1 Interrupt mode*/
    uint16_t  INT_ENA_SEQ1:1;   /* 11    SEQ1 Interrupt enable*/
    uint16_t  rsvd4:1;          /* 12    reserved*/
    uint16_t  SOC_SEQ1:1;       /* 13    Start of conversion trigger for SEQ1*/
    uint16_t  RST_SEQ1:1;       /* 14    Restart sequencer 1 */
    uint16_t  EPWM_SOCB_SEQ:1;  /* 15    EPWM compare B SOC enable*/
};

union ADCTRL2_REG
{
   uint16_t              all;
   struct ADCTRL2_BITS   bit;
};

struct ADCASEQSR_BITS
{       /* bits   description*/
    uint16_t  SEQ1_STATE:4;     /* 3:0    SEQ1 state*/
    uint16_t  SEQ2_STATE:3;     /* 6:4    SEQ2 state*/
    uint16_t  rsvd1:1;          /* 7      reserved*/
    uint16_t  SEQ_CNTR:4;       /* 11:8   Sequencing counter status */
    uint16_t  rsvd2:4;          /* 15:12  reserved */
};

union ADCASEQSR_REG
{
    uint16_t               all;
    struct ADCASEQSR_BITS  bit;
};

struct ADCMAXCONV_BITS
{      /* bits  description*/
    uint16_t  MAX_CONV1:4;      /* 3:0   Max number of conversions*/
    uint16_t  MAX_CONV2:3;      /* 6:4   Max number of conversions*/  
    uint16_t  rsvd1:9;          /* 15:7  reserved */
};

union ADCMAXCONV_REG
{
    uint16_t                all;
    struct ADCMAXCONV_BITS  bit;
};

struct ADCCHSELSEQ1_BITS
{    /* bits   description*/
    uint16_t  CONV00:4;         /* 3:0    Conversion selection 00*/
    uint16_t  CONV01:4;         /* 7:4    Conversion selection 01*/
    uint16_t  CONV02:4;         /* 11:8   Conversion selection 02*/
    uint16_t  CONV03:4;         /* 15:12  Conversion selection 03*/
};

union  ADCCHSELSEQ1_REG
{
    uint16_t                  all;
    struct ADCCHSELSEQ1_BITS  bit;
};

struct ADCCHSELSEQ2_BITS
{    /* bits   description*/
    uint16_t  CONV04:4;         /* 3:0    Conversion selection 04*/
    uint16_t  CONV05:4;         /* 7:4    Conversion selection 05*/
    uint16_t  CONV06:4;         /* 11:8   Conversion selection 06*/
    uint16_t  CONV07:4;         /* 15:12  Conversion selection 07*/
};

union  ADCCHSELSEQ2_REG
{
    uint16_t                  all;
    struct ADCCHSELSEQ2_BITS  bit;
};

struct ADCCHSELSEQ3_BITS
{    /* bits   description*/
    uint16_t  CONV08:4;         /* 3:0    Conversion selection 08*/
    uint16_t  CONV09:4;         /* 7:4    Conversion selection 09*/
    uint16_t  CONV10:4;         /* 11:8   Conversion selection 10*/
    uint16_t  CONV11:4;         /* 15:12  Conversion selection 11*/
};

union  ADCCHSELSEQ3_REG
{
    uint16_t                  all;
    struct ADCCHSELSEQ3_BITS  bit;
};

struct ADCCHSELSEQ4_BITS
{    /* bits   description*/
    uint16_t  CONV12:4;         /* 3:0    Conversion selection 12*/
    uint16_t  CONV13:4;         /* 7:4    Conversion selection 13*/
    uint16_t  CONV14:4;         /* 11:8   Conversion selection 14*/
    uint16_t  CONV15:4;         /* 15:12  Conversion selection 15*/
};

union  ADCCHSELSEQ4_REG
{
    uint16_t                  all;
    struct ADCCHSELSEQ4_BITS  bit;
};

struct ADCTRL3_BITS
{         /* bits   description*/
    uint16_t   SMODE_SEL:1;     /* 0      Sampling mode select*/
    uint16_t   ADCCLKPS:4;      /* 4:1    ADC core clock divider*/
    uint16_t   ADCPWDN:1;       /* 5      ADC powerdown*/
    uint16_t   ADCBGRFDN:2;     /* 7:6    ADC bandgap/ref power down*/
    uint16_t   rsvd1:8;         /* 15:8   reserved*/
}; 

union  ADCTRL3_REG
{
    uint16_t              all;
    struct ADCTRL3_BITS   bit;
};

struct ADCST_BITS
{           /* bits   description*/
    uint16_t   INT_SEQ1:1;      /* 0      SEQ1 Interrupt flag */
    uint16_t   INT_SEQ2:1;      /* 1      SEQ2 Interrupt flag*/
    uint16_t   SEQ1_BSY:1;      /* 2      SEQ1 busy status*/
    uint16_t   SEQ2_BSY:1;      /* 3      SEQ2 busy status*/
    uint16_t   INT_SEQ1_CLR:1;  /* 4      SEQ1 Interrupt clear*/
    uint16_t   INT_SEQ2_CLR:1;  /* 5      SEQ2 Interrupt clear*/
    uint16_t   EOS_BUF1:1;      /* 6      End of sequence buffer1*/
    uint16_t   EOS_BUF2:1;      /* 7      End of sequence buffer2*/
    uint16_t   rsvd1:8;         /* 15:8   reserved*/
};

union  ADCST_REG
{            
    uint16_t           all;    
    struct ADCST_BITS  bit;    
};                           

struct ADCREFSEL_BITS
{       /* bits   description*/
	uint16_t   rsvd1:14;        /* 13:0   reserved */
	uint16_t   REF_SEL:2;       /* 15:14  Reference select*/
};
union ADCREFSEL_REG
{
	uint16_t				all;
	struct ADCREFSEL_BITS 	bit;
};

struct ADCOFFTRIM_BITS
{       /* bits   description*/
	int16_t	    OFFSET_TRIM:9;    /* 8:0    Offset Trim */
	uint16_t	rsvd1:7;          /* 15:9   reserved*/
};

union ADCOFFTRIM_REG
{
	uint16_t				all;
	struct ADCOFFTRIM_BITS 	bit;
};

struct ADC_REGS
{
    union ADCTRL1_REG      ADCTRL1;       /*ADC Control 1*/
    union ADCTRL2_REG      ADCTRL2;       /*ADC Control 2*/
    union ADCMAXCONV_REG   ADCMAXCONV;    /*Max conversions*/
    union ADCCHSELSEQ1_REG ADCCHSELSEQ1;  /*Channel select sequencing control 1*/
    union ADCCHSELSEQ2_REG ADCCHSELSEQ2;  /*Channel select sequencing control 2*/
    union ADCCHSELSEQ3_REG ADCCHSELSEQ3;  /*Channel select sequencing control 3*/
    union ADCCHSELSEQ4_REG ADCCHSELSEQ4;  /*Channel select sequencing control 4*/
    union ADCASEQSR_REG    ADCASEQSR;     /*Autosequence status register*/
    uint16_t               ADCRESULT0;    /*Conversion Result Buffer 0*/
    uint16_t               ADCRESULT1;    /*Conversion Result Buffer 1*/
    uint16_t               ADCRESULT2;    /*Conversion Result Buffer 2*/
    uint16_t               ADCRESULT3;    /*Conversion Result Buffer 3*/
    uint16_t               ADCRESULT4;    /*Conversion Result Buffer 4*/
    uint16_t               ADCRESULT5;    /*Conversion Result Buffer 5*/
    uint16_t               ADCRESULT6;    /*Conversion Result Buffer 6*/
    uint16_t               ADCRESULT7;    /*Conversion Result Buffer 7*/
    uint16_t               ADCRESULT8;    /*Conversion Result Buffer 8*/
    uint16_t               ADCRESULT9;    /*Conversion Result Buffer 9*/
    uint16_t               ADCRESULT10;   /*Conversion Result Buffer 10*/
    uint16_t               ADCRESULT11;   /*Conversion Result Buffer 11*/
    uint16_t               ADCRESULT12;   /*Conversion Result Buffer 12*/
    uint16_t               ADCRESULT13;   /*Conversion Result Buffer 13*/
    uint16_t               ADCRESULT14;   /*Conversion Result Buffer 14*/
    uint16_t               ADCRESULT15;   /*Conversion Result Buffer 15*/
    union ADCTRL3_REG      ADCTRL3;       /*ADC Control 3*/
    union ADCST_REG        ADCST;         /*ADC Status Register*/
    uint16_t			   rsvd1;
    uint16_t               rsvd2;
    union ADCREFSEL_REG    ADCREFSEL;     /*Reference Select Register*/
    union ADCOFFTRIM_REG   ADCOFFTRIM;    /*Offset Trim Register*/
};

struct ADC_RESULT_MIRROR_REGS
{
    uint16_t                 ADCRESULT0;    /* Conversion Result Buffer 0*/
    uint16_t                 ADCRESULT1;    /* Conversion Result Buffer 1*/
    uint16_t                 ADCRESULT2;    /* Conversion Result Buffer 2*/
    uint16_t                 ADCRESULT3;    /* Conversion Result Buffer 3*/
    uint16_t                 ADCRESULT4;    /* Conversion Result Buffer 4*/
    uint16_t                 ADCRESULT5;    /* Conversion Result Buffer 5*/
    uint16_t                 ADCRESULT6;    /* Conversion Result Buffer 6*/
    uint16_t                 ADCRESULT7;    /* Conversion Result Buffer 7*/
    uint16_t                 ADCRESULT8;    /* Conversion Result Buffer 8*/
    uint16_t                 ADCRESULT9;    /* Conversion Result Buffer 9*/
    uint16_t                 ADCRESULT10;   /* Conversion Result Buffer 10*/
    uint16_t                 ADCRESULT11;   /* Conversion Result Buffer 11*/
    uint16_t                 ADCRESULT12;   /* Conversion Result Buffer 12*/
    uint16_t                 ADCRESULT13;   /* Conversion Result Buffer 13*/
    uint16_t                 ADCRESULT14;   /* Conversion Result Buffer 14*/
    uint16_t                 ADCRESULT15;   /* Conversion Result Buffer 15*/
};

/*
* ADC External References & Function Declarations:
*/
extern volatile struct ADC_REGS AdcRegs;
extern volatile struct ADC_RESULT_MIRROR_REGS AdcMirror;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  /* end of DSP2833x_ADC_H definition*/

/*
* End of file
*/

