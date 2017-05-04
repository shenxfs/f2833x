/*
*###########################################################################
*
* FILE:   DSP2833x_GlobalPrototypes.h
*
* TITLE:  Global prototypes for DSP2833x Examples
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
#ifndef DSP2833x_GLOBALPROTOTYPES_H
#define DSP2833x_GLOBALPROTOTYPES_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/*
* shared global function prototypes
*/
extern void InitAdc(void);
extern void DMAInitialize(void);

/*
* DMA Channel 1
*/
extern void DMACH1AddrConfig(volatile uint16_t *DMA_Dest,
                             volatile uint16_t *DMA_Source);
extern void DMACH1BurstConfig(uint16_t bsize, int16_t srcbstep, int16_t desbstep);
extern void DMACH1TransferConfig(uint16_t tsize, int16_t srctstep, int16_t deststep);
extern void DMACH1WrapConfig(uint16_t srcwsize, int16_t srcwstep, uint16_t deswsize,
                             int16_t deswstep);
extern void DMACH1ModeConfig(uint16_t persel, uint16_t perinte, uint16_t oneshot, 
                             uint16_t cont, uint16_t synce, uint16_t syncsel, 
                             uint16_t ovrinte, uint16_t datasize, uint16_t chintmode,
                             uint16_t chinte);
extern void StartDMACH1(void);

/*
* DMA Channel 2
*/
extern void DMACH2AddrConfig(volatile uint16_t *DMA_Dest,
                             volatile uint16_t *DMA_Source);
extern void DMACH2BurstConfig(uint16_t bsize, int16_t srcbstep, int16_t desbstep);
extern void DMACH2TransferConfig(uint16_t tsize, int16_t srctstep, int16_t deststep);
extern void DMACH2WrapConfig(uint16_t srcwsize, int16_t srcwstep, uint16_t deswsize, 
                             int16_t deswstep);
extern void DMACH2ModeConfig(uint16_t persel, uint16_t perinte, uint16_t oneshot, 
                             uint16_t cont, uint16_t synce, uint16_t syncsel,
                             uint16_t ovrinte, uint16_t datasize, uint16_t chintmode,
                             uint16_t chinte);
extern void StartDMACH2(void);

/*
* DMA Channel 3
*/
extern void DMACH3AddrConfig(volatile uint16_t *DMA_Dest,
                             volatile uint16_t *DMA_Source);
extern void DMACH3BurstConfig(uint16_t bsize, int16_t srcbstep, int16_t desbstep);
extern void DMACH3TransferConfig(uint16_t tsize, int16_t srctstep, int16_t deststep);
extern void DMACH3WrapConfig(uint16_t srcwsize, int16_t srcwstep, uint16_t deswsize, 
                             int16_t deswstep);
extern void DMACH3ModeConfig(uint16_t persel, uint16_t perinte, uint16_t oneshot, 
                             uint16_t cont, uint16_t synce, uint16_t syncsel, 
                             uint16_t ovrinte, uint16_t datasize, uint16_t chintmode,
                             uint16_t chinte);
extern void StartDMACH3(void);

/*
* DMA Channel 4
*/
extern void DMACH4AddrConfig(volatile uint16_t *DMA_Dest,
                             volatile uint16_t *DMA_Source);
extern void DMACH4BurstConfig(uint16_t bsize, int16_t srcbstep, int16_t desbstep);
extern void DMACH4TransferConfig(uint16_t tsize, int16_t srctstep, int16_t deststep);
extern void DMACH4WrapConfig(uint16_t srcwsize, int16_t srcwstep, uint16_t deswsize, 
                             int16_t deswstep);
extern void DMACH4ModeConfig(uint16_t persel, uint16_t perinte, uint16_t oneshot, 
                             uint16_t cont, uint16_t synce, uint16_t syncsel,
                             uint16_t ovrinte, uint16_t datasize, uint16_t chintmode,
                             uint16_t chinte);
extern void StartDMACH4(void);

/*
* DMA Channel 5
*/
extern void DMACH5AddrConfig(volatile uint16_t *DMA_Dest,
                             volatile uint16_t *DMA_Source);
extern void DMACH5BurstConfig(uint16_t bsize, int16_t srcbstep, int16_t desbstep);
extern void DMACH5TransferConfig(uint16_t tsize, int16_t srctstep, int16_t deststep);
extern void DMACH5WrapConfig(uint16_t srcwsize, int16_t srcwstep, uint16_t deswsize, 
                             int16_t deswstep);
extern void DMACH5ModeConfig(uint16_t persel, uint16_t perinte, uint16_t oneshot, 
                             uint16_t cont, uint16_t synce, uint16_t syncsel,
                             uint16_t ovrinte, uint16_t datasize, uint16_t chintmode,
                             uint16_t chinte);
extern void StartDMACH5(void);

/*
* DMA Channel 6
*/
extern void DMACH6AddrConfig(volatile uint16_t *DMA_Dest,
                             volatile uint16_t *DMA_Source);
extern void DMACH6BurstConfig(uint16_t bsize, int16_t srcbstep, int16_t desbstep);
extern void DMACH6TransferConfig(uint16_t tsize, int16_t srctstep, int16_t deststep);
extern void DMACH6WrapConfig(uint16_t srcwsize, int16_t srcwstep, uint16_t deswsize, 
                             int16_t deswstep);
extern void DMACH6ModeConfig(uint16_t persel, uint16_t perinte, uint16_t oneshot, 
                             uint16_t cont, uint16_t synce, uint16_t syncsel,
                             uint16_t ovrinte, uint16_t datasize, uint16_t chintmode,
                             uint16_t chinte);
extern void StartDMACH6(void);

extern void InitPeripherals(void);
#if DSP28_ECANA
extern void InitECan(void);
extern void InitECana(void);
extern void InitECanGpio(void);
extern void InitECanaGpio(void);
#endif /* endif DSP28_ECANA*/
#if DSP28_ECANB
extern void InitECanb(void);
extern void InitECanbGpio(void);
#endif /* endif DSP28_ECANB*/
extern void InitECap(void);
extern void InitECapGpio(void);
extern void InitECap1Gpio(void);
extern void InitECap2Gpio(void);
#if DSP28_ECAP3
extern void InitECap3Gpio(void);
#endif /* endif DSP28_ECAP3*/
#if DSP28_ECAP4
extern void InitECap4Gpio(void);
#endif /* endif DSP28_ECAP4*/
#if DSP28_ECAP5
extern void InitECap5Gpio(void);
#endif /* endif DSP28_ECAP5*/
#if DSP28_ECAP6
extern void InitECap6Gpio(void);
#endif /* endif DSP28_ECAP6*/
extern void InitEPwm(void);
extern void InitEPwmGpio(void);
extern void InitEPwm1Gpio(void);
extern void InitEPwm2Gpio(void);
extern void InitEPwm3Gpio(void);
#if DSP28_EPWM4
extern void InitEPwm4Gpio(void);
#endif /* endif DSP28_EPWM4*/
#if DSP28_EPWM5
extern void InitEPwm5Gpio(void);
#endif /* endif DSP28_EPWM5*/
#if DSP28_EPWM6
extern void InitEPwm6Gpio(void);
#endif /* endif DSP28_EPWM6*/
#if DSP28_EQEP1
extern void InitEQep(void);
extern void InitEQepGpio(void);
extern void InitEQep1Gpio(void);
#endif /* if DSP28_EQEP1*/
#if DSP28_EQEP2
extern void InitEQep2Gpio(void);
#endif /* endif DSP28_EQEP2*/
extern void InitGpio(void);
extern void InitI2CGpio(void);

extern void InitMcbsp(void);
extern void InitMcbspa(void);
extern void delay_loop(void);
extern void InitMcbspaGpio(void);
extern void InitMcbspa8bit(void);
extern void InitMcbspa12bit(void);
extern void InitMcbspa16bit(void);
extern void InitMcbspa20bit(void);
extern void InitMcbspa24bit(void);
extern void InitMcbspa32bit(void);
#if DSP28_MCBSPB
extern void InitMcbspb(void);
extern void InitMcbspbGpio(void);
extern void InitMcbspb8bit(void);
extern void InitMcbspb12bit(void);
extern void InitMcbspb16bit(void);
extern void InitMcbspb20bit(void);
extern void InitMcbspb24bit(void);
extern void InitMcbspb32bit(void);
#endif /* endif DSP28_MCBSPB*/

extern void InitPieCtrl(void);
extern void InitPieVectTable(void);

extern void InitSci(void);
extern void InitSciGpio(void);
extern void InitSciaGpio(void);
#if DSP28_SCIB
extern void InitScibGpio(void);
#endif /* endif DSP28_SCIB*/
#if DSP28_SCIC
extern void InitScicGpio(void);
#endif
extern void InitSpi(void);
extern void InitSpiGpio(void);
extern void InitSpiaGpio(void);
extern void InitSysCtrl(void);
extern void InitTzGpio(void);
extern void InitXIntrupt(void);
extern void XintfInit(void);
extern void InitXintf16Gpio(void);
extern void InitXintf32Gpio(void);
extern void InitPll(uint16_t pllcr, uint16_t clkindiv);
extern void InitPeripheralClocks(void);
extern void EnableInterrupts(void);
extern void DSP28x_usDelay(uint32_t Count);
extern void ADC_cal (void);
extern void ServiceDog(void);
extern void DisableDog(void);
extern uint16_t CsmUnlock(void);

/*
* DSP28_DBGIER.asm
*/
extern void SetDBGIER(uint16_t dbgier);

/*
*                 CAUTION
* This function MUST be executed out of RAM. Executing it
* out of OTP/Flash will yield unpredictable results
*/
extern void InitFlash(void);

void MemCopy(uint16_t *SourceAddr, uint16_t *SourceEndAddr, uint16_t *DestAddr);

/*
* External symbols created by the linker cmd file
* DSP28 examples will use these to relocate code from one LOAD location
* in either Flash or XINTF to a different RUN location in internal
* RAM
*/
extern uint16_t RamfuncsLoadStart;
extern uint16_t RamfuncsLoadEnd;
extern uint16_t RamfuncsRunStart;
extern uint16_t RamfuncsLoadSize;

extern uint16_t XintffuncsLoadStart;
extern uint16_t XintffuncsLoadEnd;
extern uint16_t XintffuncsRunStart;
extern uint16_t XintffuncsLoadSize;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   /* - end of DSP2833x_GLOBALPROTOTYPES_H*/

/*
* End of file
*/

