/*
 * gdt.h
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */

#ifndef GDT_H_
#define GDT_H_

#include <types.h>

#define CODE16_SEG 		0x8
#define DATA16_SEG 		0x10
#define CODE32_SEG 		0x18
#define DATA32_SEG 		0x20
#define USERCODE32_SEG	0x28
#define USERDATA32_SEG	0x30
#define TSS32_SEG		0x38

typedef struct _segmentDescEntry_t
{
   uint16_t limitLow;
   uint16_t baseLow;
   unsigned baseMid     : 8;
   unsigned type        : 5;
   unsigned privLevel   : 2;
   unsigned present     : 1;
   unsigned limitHi     : 4;
   unsigned available   : 1;
   unsigned reserved    : 1;
   unsigned defaultSize : 1;
   unsigned granularity : 1;
   unsigned baseHi      : 8;
} segmentDescEntry_t;

typedef struct _gateDescEntry_t
{
   uint16_t offsetLo;
   uint16_t segment;
   unsigned params    : 5;
   unsigned reserved  : 3;
   unsigned type      : 5;
   unsigned privLevel : 2;
   unsigned present   : 1;
   uint16_t offsetHi;
} gateDescEntry_t;

typedef union _descTableEntry_t
{
   segmentDescEntry_t seg;
   gateDescEntry_t    gate;
} descTableEntry_t;

#define SysReserved00 0x00
#define SysTSS16_Idle 0x01
#define SysLocDescTab 0x02
#define SysTSS16_Busy 0x03
#define SysCallGate16 0x04
#define Sys_Task_Gate 0x05
#define SysIntrGate16 0x06
#define SysTrapGate16 0x07
#define SysReserved08 0x08
#define SysTSS32_Idle 0x09
#define SysReserved0A 0x0A
#define SysTSS32_Busy 0x0B
#define SysCallGate32 0x0C
#define SysReserved0D 0x0D
#define SysIntrGate32 0x0E
#define SysTrapGate32 0x0F
#define SegDataXupRoN 0x10
#define SegDataXupRoA 0x11
#define SegDataXupRwN 0x12
#define SegDataXupRwA 0x13
#define SegDataXdnRoN 0x14
#define SegDataXdnRoA 0x15
#define SegDataXdnRwN 0x16
#define SegDataXdnRwA 0x17
#define SegCodeNonXoN 0x18
#define SegCodeNonXoA 0x19
#define SegCodeNonXrN 0x1A
#define SegCodeNonXrA 0x1B
#define SegCodeConXoN 0x1C
#define SegCodeConXoA 0x1D
#define SegCodeConXrN 0x1E
#define SegCodeConXrA 0x1F

void initGDT(void);
void gdtSetTSS(void *tss, uint32_t size);

#endif /* GDT_H_ */
