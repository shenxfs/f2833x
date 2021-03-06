/*
*###########################################################################
*
* FILE:	DSP2833x_I2cExample.h
*
* TITLE:	2833x I2C Example Code Definitions.
*
*###########################################################################
* $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
* $Release Date: November  1, 2016 $
* $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
*             http://www.ti.com/ ALL RIGHTS RESERVED $
*###########################################################################
*/
#ifndef DSP2833x_I2C_DEFINES_H
#define DSP2833x_I2C_DEFINES_H
#include <stdint.h>
/*
* Defines
*/

/*
* Error Messages
*/
#define I2C_ERROR               (0xFFFFU)
#define I2C_ARB_LOST_ERROR      (0x0001U)
#define I2C_NACK_ERROR          (0x0002U)
#define I2C_BUS_BUSY_ERROR      (0x1000U)
#define I2C_STP_NOT_READY_ERROR (0x5555U)
#define I2C_NO_FLAGS            (0xAAAAU)
#define I2C_SUCCESS             (0x0000U)

/*
* Clear Status Flags
*/
#define I2C_CLR_AL_BIT          (0x0001U)
#define I2C_CLR_NACK_BIT        (0x0002U)
#define I2C_CLR_ARDY_BIT        (0x0004U)
#define I2C_CLR_RRDY_BIT        (0x0008U)
#define I2C_CLR_SCD_BIT         (0x0020U)

/*
* Interrupt Source Messages
*/
#define I2C_NO_ISRC             (0x0000U)
#define I2C_ARB_ISRC            (0x0001U)
#define I2C_NACK_ISRC           (0x0002U)
#define I2C_ARDY_ISRC           (0x0003U)
#define I2C_RX_ISRC             (0x0004U)
#define I2C_TX_ISRC             (0x0005U)
#define I2C_SCD_ISRC            (0x0006U)
#define I2C_AAS_ISRC            (0x0007U)

/*
* I2CMSG structure defines
*/
#define I2C_NO_STOP  (0U)
#define I2C_YES_STOP (1U)
#define I2C_RECEIVE  (0U)
#define I2C_TRANSMIT (1U)
#define I2C_MAX_BUFFER_SIZE (16U)

/*
* I2C Slave State defines
*/
#define I2C_NOTSLAVE      (0U)
#define I2C_ADDR_AS_SLAVE (1U)
#define I2C_ST_MSG_READY  (2U)

/*
* I2C Slave Receiver messages defines
*/
#define I2C_SND_MSG1 (1U)
#define I2C_SND_MSG2 (2U)

/*
* I2C State defines
*/
#define I2C_IDLE               (0U)
#define I2C_SLAVE_RECEIVER     (1U)
#define I2C_SLAVE_TRANSMITTER  (2U)
#define I2C_MASTER_RECEIVER    (3U)
#define I2C_MASTER_TRANSMITTER (4U)

/*
* I2C  Message Commands for I2CMSG struct
*/
#define I2C_MSGSTAT_INACTIVE          (0x0000U)
#define I2C_MSGSTAT_SEND_WITHSTOP     (0x0010U)
#define I2C_MSGSTAT_WRITE_BUSY        (0x0011U)
#define I2C_MSGSTAT_SEND_NOSTOP       (0x0020U)
#define I2C_MSGSTAT_SEND_NOSTOP_BUSY  (0x0021U)
#define I2C_MSGSTAT_RESTART           (0x0022U)
#define I2C_MSGSTAT_READ_BUSY         (0x0023U)

/*
* Generic defines
*/
#define I2C_TRUE  		(1U)
#define I2C_FALSE 		(0U)
#define I2C_YES   		(1U)
#define I2C_NO    		(0U)
#define I2C_DUMMY_BYTE 	(0U)

/*
* Structures
*/

/*
* I2C Message Structure
*/
struct I2CMSG 
{
    uint16_t MsgStatus;	/* Word stating what state msg is in:
                        *   I2C_MSGCMD_INACTIVE = do not send msg
                        *   I2C_MSGCMD_BUSY = msg start has been sent,
                        *                     awaiting stop
                        *   I2C_MSGCMD_SEND_WITHSTOP = command to send
                        *       master trans msg complete with a stop bit
                        *   I2C_MSGCMD_SEND_NOSTOP = command to send
                        *       master trans msg without the stop bit
                        *   I2C_MSGCMD_RESTART = command to send a restart
                        *       as a master receiver with a stop bit*/
    uint16_t SlaveAddress; /* I2C address of slave msg is intended for*/
    uint16_t NumOfBytes;	 /* Num of valid bytes in (or to be put in MsgBuffer)*/
    
    /*
    * EEPROM address of data associated with msg (high byte)
    */
    uint16_t MemoryHighAddr;  
    
    /*
    * EEPROM address of data associated with msg (low byte)
    */
    uint16_t MemoryLowAddr;   
    
    /*
    * Array holding msg data - max that MAX_BUFFER_SIZE can be is 16 due to
    * the FIFO's*/
    uint16_t MsgBuffer[I2C_MAX_BUFFER_SIZE];	
};


#endif  /* end of DSP2833x_I2C_DEFINES_H definition*/

/*
* End of file
*/

