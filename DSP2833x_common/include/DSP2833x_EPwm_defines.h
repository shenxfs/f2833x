/*
*###########################################################################
*
* FILE:   DSP2833x_EPwm_defines.h
*
* TITLE:  #defines used in ePWM examples examples
* 
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
#ifndef DSP2833x_EPWM_DEFINES_H
#define DSP2833x_EPWM_DEFINES_H


#ifdef __cplusplus
extern "C" {
#endif

/*
* TBCTL (Time-Base Control)
*
* CTRMODE bits
*/
#define	TB_COUNT_UP		(0x0U)
#define	TB_COUNT_DOWN	(0x1U)
#define	TB_COUNT_UPDOWN	(0x2U)
#define	TB_FREEZE		(0x3U)

/*
* PHSEN bit
*/
#define	TB_DISABLE		(0x0U)
#define	TB_ENABLE		(0x1U)

/*
* PRDLD bit
*/
#define	TB_SHADOW		(0x0U)
#define	TB_IMMEDIATE	(0x1U)

/*
* SYNCOSEL bits
*/
#define	TB_SYNC_IN		(0x0U)
#define	TB_CTR_ZERO		(0x1U)
#define	TB_CTR_CMPB		(0x2U)
#define	TB_SYNC_DISABLE	(0x3U)

/*
* HSPCLKDIV and CLKDIV bits
*/
#define	TB_DIV1			(0x0U)
#define	TB_DIV2			(0x1U)
#define	TB_DIV4			(0x2U)

/*
* PHSDIR bit
*/
#define	TB_DOWN			(0x0U)
#define	TB_UP			(0x1U)

/*
* CMPCTL (Compare Control)
*
* LOADAMODE and LOADBMODE bits
*/
#define	CC_CTR_ZERO		(0x0U)
#define	CC_CTR_PRD		(0x1U)
#define	CC_CTR_ZERO_PRD	(0x2U)
#define	CC_LD_DISABLE	(0x3U)

/*
* SHDWAMODE and SHDWBMODE bits
*/
#define	CC_SHADOW		(0x0U)
#define	CC_IMMEDIATE	(0x1U)

/*
* AQCTLA and AQCTLB (Action Qualifier Control)
*
* ZRO, PRD, CAU, CAD, CBU, CBD bits
*/
#define	AQ_NO_ACTION	(0x0U)
#define	AQ_CLEAR		(0x1U)
#define	AQ_SET			(0x2U)
#define	AQ_TOGGLE		(0x3U)

/*
* DBCTL (Dead-Band Control)
*
* OUT MODE bits
*/
#define	DB_DISABLE		(0x0U)
#define	DBB_ENABLE		(0x1U)
#define	DBA_ENABLE		(0x2U)
#define	DB_FULL_ENABLE	(0x3U)

/*
* POLSEL bits
*/
#define	DB_ACTV_HI		(0x0U)
#define	DB_ACTV_LOC		(0x1U)
#define	DB_ACTV_HIC		(0x2U)
#define	DB_ACTV_LO		(0x3U)

/*
* IN MODE
*/
#define DBA_ALL         (0x0U)
#define DBB_RED_DBA_FED (0x1U)
#define DBA_RED_DBB_FED (0x2U)
#define DBB_ALL         (0x3U)

/*
* CHPCTL (chopper control)
*
* CHPEN bit
*/
#define	CHP_DISABLE		(0x0U)
#define	CHP_ENABLE		(0x1U)

/*
* CHPFREQ bits
*/
#define	CHP_DIV1		(0x0U)
#define	CHP_DIV2		(0x1U)
#define	CHP_DIV3		(0x2U)
#define	CHP_DIV4		(0x3U)
#define	CHP_DIV5		(0x4U)
#define	CHP_DIV6		(0x5U)
#define	CHP_DIV7		(0x6U)
#define	CHP_DIV8		(0x7U)

/*
* CHPDUTY bits
*/
#define	CHP1_8TH		(0x0U)
#define	CHP2_8TH		(0x1U)
#define	CHP3_8TH		(0x2U)
#define	CHP4_8TH		(0x3U)
#define	CHP5_8TH		(0x4U)
#define	CHP6_8TH		(0x5U)
#define	CHP7_8TH		(0x6U)

/*
* TZSEL (Trip Zone Select)
*
* CBCn and OSHTn bits
*/
#define	TZ_DISABLE		(0x0U)
#define	TZ_ENABLE		(0x1U)

/*
* TZCTL (Trip Zone Control)
*
* TZA and TZB bits
*/
#define	TZ_HIZ			(0x0U)
#define	TZ_FORCE_HI		(0x1U)
#define	TZ_FORCE_LO		(0x2U)
#define	TZ_NO_CHANGE	(0x3U)

/*
* ETSEL (Event Trigger Select)
*/
#define	ET_CTR_ZERO		(0x1U)
#define	ET_CTR_PRD		(0x2U)
#define	ET_CTRU_CMPA	(0x4U)
#define	ET_CTRD_CMPA	(0x5U)
#define	ET_CTRU_CMPB	(0x6U)
#define	ET_CTRD_CMPB	(0x7U)

/*
* ETPS (Event Trigger Pre-scale)
*
* INTPRD, SOCAPRD, SOCBPRD bits
*/
#define	ET_DISABLE		(0x0U)
#define	ET_1ST			(0x1U)
#define	ET_2ND			(0x2U)
#define	ET_3RD			(0x3U)

/*
* HRPWM (High Resolution PWM)
*
* HRCNFG
*/
#define	HR_Disable		(0x0U)
#define	HR_REP			(0x1U)
#define	HR_FEP			(0x2U)
#define	HR_BEP			(0x3U)

#define	HR_CMP			(0x0U)
#define	HR_PHS			(0x1U)

#define	HR_CTR_ZERO		(0x0U)
#define	HR_CTR_PRD		(0x1U)


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   /* - end of DSP2833x_EPWM_DEFINES_H*/

/*
* End of file
*/

