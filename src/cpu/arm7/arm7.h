/*****************************************************************************
 *
 *   arm7.h
 *   Portable ARM7TDMI CPU Emulator
 *
 *   Copyright Steve Ellenoff, all rights reserved.
 *
 *   - This source code is released as freeware for non-commercial purposes.
 *   - You are free to use and redistribute this code in modified or
 *     unmodified form, provided you list me in the credits.
 *   - If you modify this source code, you must add a notice to each modified
 *     source file that it has been changed.  If you're a nice person, you
 *     will clearly mark each change too.  :)
 *   - If you wish to use this for commercial purposes, please contact me at
 *     sellenoff@hotmail.com
 *   - The author of this copywritten work reserves the right to change the
 *     terms of its usage and license at any time, including retroactively
 *   - This entire notice must remain in the source code.
 *
 *  This work is based on:
 *  #1) 'Atmel Corporation ARM7TDMI (Thumb) Datasheet - January 1999'
 *  #2) Arm 2/3/6 emulator By Bryan McPhail (bmcphail@tendril.co.uk) and Phil Stroffolino (MAME CORE 0.76)
 *
 *****************************************************************************

 This file contains everything related to the arm7 cpu specific implementation.
 Anything related to the arm7 core itself is defined in arm7core.h instead.

 ******************************************************************************/

#pragma once

#ifndef __ARM7_H__
#define __ARM7_H__
#define ARM7_MEM_SHIFT	24
#define ARM7_MEM_MASK	((1 << ARM7_MEM_SHIFT) - 1)
//#include "cpuintrf.h"

#include "arm7core.h"   //include arm7 core
/****************************************************************************************************
 *  PUBLIC FUNCTIONS
 ***************************************************************************************************/
//extern void arm7_get_info(UINT32 state, cpuinfo *info);
#ifdef __cplusplus
extern "C" {
#endif
void arm7_reset(void);
int arm7_execute(int cycles);
void arm7_set_irq_line(int irqline, int state);
int arm7MapArea(unsigned int nStart, unsigned int nEnd, int nMode, unsigned char *Mem);
int ArmScan(int nAction);

void arm7SetReadHandler(unsigned int (*)(unsigned int));
void arm7SetWriteHandler(void (*)(unsigned int, unsigned int));
#ifdef __cplusplus
}
#endif
#endif /* __ARM7_H__ */
