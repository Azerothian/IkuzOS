#include <types.h>
#include "gdt.h"
#include "cpu.h"

#define GDT_SIZE 256

descTableEntry_t globalDescTable[GDT_SIZE] =
{
		// reserved
		{{0x0000, 0x0000, 0x00, SysReserved00, 0, 0, 0x0, 0, 0, 0, 0, 0x00}},
		//code16 0x08
		{{0xffff, 0x0000, 0x00, SegCodeNonXrN, 0, 1, 0xf, 0, 0, 0, 0, 0x00}},
		//data16 0x10
		{{0xffff, 0x0000, 0x00, SegDataXupRwN, 0, 1, 0xf, 0, 0, 0, 0, 0x00}},
		//code32 0x18
		{{0xffff, 0x0000, 0x00, SegCodeNonXrN, 0, 1, 0xf, 0, 0, 1, 1, 0x00}},
		//date32 0x20
		{{0xffff, 0x0000, 0x00, SegDataXupRwN, 0, 1, 0xf, 0, 0, 1, 1, 0x00}},
		//code32 0x28 (Ring3 user)
		{{0xffff, 0x0000, 0x00, SegCodeNonXrN, 3, 1, 0xf, 0, 0, 1, 1, 0x00}},
		//data32 0x30 (Ring3 user)
		{{0xffff, 0x0000, 0x00, SegDataXupRwN, 3, 1, 0xf, 0, 0, 1, 1, 0x00}},
		// TSS selector 0x38
		{{0x0000, 0x0000, 0x00, SysTSS32_Idle, 0, 1, 0x0, 0, 0, 0, 0, 0x00}},
};

void initGDT(void)
{
		lgdt(globalDescTable, sizeof(globalDescTable) - 1);
}

void gdtSetTSS(void *tss, uint32_t size)
{
	uint32_t base = (uint32_t)tss;

	globalDescTable[7].seg.baseLow = base & 0xffff;
	globalDescTable[7].seg.baseMid = (base >> 16) & 0xff;
	globalDescTable[7].seg.baseHi  = (base >> 24) & 0xff;
	globalDescTable[7].seg.limitLow = size & 0xffff;
	globalDescTable[7].seg.limitHi  = size & 0xf;

}
