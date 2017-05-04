/*
*###########################################################################
*
* FILE:	DSP2833x_MemCopy.c
*
* TITLE:	Memory Copy Utility
*
* ASSUMPTIONS:          
*
* DESCRIPTION:
*
*          This function will copy the specified memory contents from
*          one location to another. 
* 
*          uint16_t *SourceAddr        Pointer to the first word to be moved
*                                    SourceAddr < SourceEndAddr
*          uint16_t* SourceEndAddr     Pointer to the last word to be moved
*          uint16_t* DestAddr          Pointer to the first destination word
*
*          No checks are made for invalid memory locations or that the
*          end address is > then the first start address.
*          
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
/*
* Included Files
*/
#include "DSP2833x_Device.h"

#pragma CHECK_MISRA("-16.7")
#pragma CHECK_MISRA("-12.13")
#pragma CHECK_MISRA("-17.4")
#pragma CHECK_MISRA("-8.1")

/*
* MemCopy -
*/
void MemCopy(uint16_t *SourceAddr, uint16_t *SourceEndAddr, uint16_t *DestAddr)
{
	while(SourceAddr < SourceEndAddr)
    { 
        *DestAddr++= *SourceAddr++;
    }
}

/*
* End of file
*/

