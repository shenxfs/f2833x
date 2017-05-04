/*
*###########################################################################
*
* FILE:   SFO.H
*
* TITLE:  Scale Factor Optimizer Library Interface Header
*
*
*###########################################################################
*
*  Ver | dd mmm yyyy | Who  | Description of changes
* =====|=============|======|===============================================
*  0.01| 09 Jan 2004 | TI   | New module
###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*
*
* Description:	This header provides the function call interface
* 			for the scale factor optimizer for the 'F2833x.
*/

/*
* Multiple include Guard
*/
#ifndef __4090522384024n8273240x3438jx43087401r34ru32r0___
#define __4090522384024n8273240x3438jx43087401r34ru32r0___

#include <stdint.h>

/*
* C++ namespace
*/
#ifdef __cplusplus
extern "C" {
#endif

/*
* Function prototypes for MEP SFO
*/
void SFO_MepEn(int16_t nEpwmModule);
void SFO_MepDis(int16_t nEpwmModule);

/*
* C++ namespace
*/
#ifdef __cplusplus
}
#endif /* extern "C" */


/*
* Multiple include Guard
*/
#endif  End: Multiple include Guard*/