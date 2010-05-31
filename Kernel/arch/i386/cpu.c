/*
 *  cpu.c
 *  Kernel
 *
 *  Created by Brendon Allen on 31/05/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "cpu.h"

/* Get the current value of the eflags register */
__inline__ unsigned long get_eflags(void)
{
	unsigned long eflags;
	asm volatile("pushfl; popl %0":"=a" (eflags));
	return eflags;
}

/* Set the current value of the eflags register */
__inline__ void set_eflags(unsigned long eflags)
{
	asm volatile("pushl %0; popfl"::"a" (eflags));
}

/* Get the current value of the cr0 register */
__inline__ unsigned long get_cr0(void)
{
	unsigned long cr0;
	asm volatile("movl %%cr0, %0" : "=a" (cr0));
	return cr0;
}

/* Set the current value of the cr0 register */
__inline__ void set_cr0(unsigned long cr0)
{
	asm volatile("movl %0, %%cr0" :: "a" (cr0));
}

/* Get the current value of the cr3 register */
__inline__ unsigned long get_cr3(void)
{
	unsigned long cr3;
	asm volatile("movl %%cr3, %0" : "=a" (cr3));
	return cr3;
}

/* Set the current value of the cr3 register */
__inline__ void set_cr3(unsigned long cr3)
{
	asm volatile("movl %0, %%cr3" :: "a" (cr3));
}

/* Get the current value of the cr4 register */
__inline__ unsigned long get_cr4(void)
{
	unsigned long cr4;
	asm volatile("movl %%cr4, %0" : "=a" (cr4));
	return cr4;
}

/* Set the current value of the cr4 register */
__inline__ void set_cr4(unsigned long cr4)
{
	asm volatile("movl %0, %%cr4" :: "a" (cr4));
}


