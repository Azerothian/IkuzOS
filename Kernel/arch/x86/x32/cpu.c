/*
 *  cpu.c
 *  Kernel
 *
 *  Created by Allen,Brendon on 2/06/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "cpu.h"
#include "../x86.h"

/* segment descriptor constants (upper word) */
#define SEG_PAGE_GRANULARITY (1 << 23)
#define SEG_PRESENT          (1 << 15)
#define SEG_CODE_OR_DATA     (1 << 12) /* system bit = 1 */
#define SEG_DB               (1 << 22)
#define SEG_TYPE_CODE        (0xA << 8) /* code, !conforming, readable, !accessed */
#define SEG_TYPE_DATA        (0x2 << 8) /* data, expand-up, writable, !accessed */
#define SEG_TYPE_TSS         (0x9 << 8) /* 32 bit, !busy */

/* Get the current value of the eflags register */
__inline__ u32_t get_eflags(void)
{
	u32_t eflags;
	asm volatile("pushfl; popl %0":"=a" (eflags));
	return eflags;
}

/* Set the current value of the eflags register */
__inline__ void set_eflags(u32_t eflags)
{
	asm volatile("pushl %0; popfl"::"a" (eflags));
}

/* Get the current value of the cr0 register */
__inline__ u32_t get_cr0(void)
{
	u32_t cr0;
	asm volatile("movl %%cr0, %0" : "=a" (cr0));
	return cr0;
}

/* Set the current value of the cr0 register */
__inline__ void set_cr0(u32_t cr0)
{
	asm volatile("movl %0, %%cr0" :: "a" (cr0));
}

/* Get the current value of the cr3 register */
__inline__ u32_t get_cr3(void)
{
	u32_t cr3;
	asm volatile("movl %%cr3, %0" : "=a" (cr3));
	return cr3;
}

/* Set the current value of the cr3 register */
__inline__ void set_cr3(u32_t cr3)
{
	asm volatile("movl %0, %%cr3" :: "a" (cr3));
}

/* Get the current value of the cr4 register */
__inline__ u32_t get_cr4(void)
{
	u32_t cr4;
	asm volatile("movl %%cr4, %0" : "=a" (cr4));
	return cr4;
}

/* Set the current value of the cr4 register */
__inline__ void set_cr4(u32_t cr4)
{
	asm volatile("movl %0, %%cr4" :: "a" (cr4));
}

/* Init the Interrupt Gate */
void x86_init_int_gate(struct x86_interrupt_gate *gate, u32_t addr, int dpl)
{
	gate->offset_low = addr & 0xffff;
	gate->segment_selector = KERN_CS;
	gate->reserved = 0;
	gate->signature = 0x70;  /* == 01110000b */
	gate->dpl = dpl;
	gate->present = 1;
	gate->offset_high = addr >> 16;
}


