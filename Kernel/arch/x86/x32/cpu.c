/*
 *  cpu.c
 *  Kernel
 *
 *  Created by Allen,Brendon on 2/06/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <cpu.h>

void outportb(uint32_t port, uint8_t outdata)
{
	__asm__ __volatile__("outb %b0, %w1" : : "a"(outdata), "d"(port));
}

uint8_t inportb(uint16_t port)
{
	uint8_t retVal;

	__asm__ __volatile__("inb %1, %0" : "=a"(retVal) : "d"(port));
	return retVal;
}

void outportw(uint16_t port, uint16_t data)
{
	__asm__ __volatile__("outw %1, %0" : : "dN"(port), "a"(data));
}

uint16_t inportw(uint16_t port)
{
	uint16_t retVal;
	__asm__ __volatile__("inw %1, %0" : "=a"(retVal) : "d"(port));
	return retVal;
}

void outportdw(uint16_t port, uint32_t data)
{
	__asm__ __volatile__("outl %1, %0" : : "dN"(port), "a"(data));
}

uint32_t inportdw(uint16_t port)
{
	uint32_t retVal;

	__asm__ __volatile__("inl %%dx, %%eax" : "=a"(retVal) : "d"(port));
	return retVal;
}

void hlt(void)
{
	__asm__ __volatile__("hlt" : : : "memory");
}

void invlpg(_dword_union address)
{
	__asm__ __volatile__("invlpg (%0)" : : "r"(address.u));
}

void disableInts(void)
{
	__asm__ __volatile__("cli");
}

void enableInts(void)
{
	__asm__ __volatile__("sti");
}

unsigned long get_cr2(void)
{
	unsigned long result;
	__asm__ __volatile__("mov %%cr2,%0" : "=r"(result));
	return result;
}

unsigned long get_cr3(void)
{
	unsigned long result;
	__asm__ __volatile__("mov %%cr3,%0" : "=r"(result));
	return result;
}

unsigned long get_cr4(void)
{
	unsigned long result;
	__asm__ __volatile__("mov %%cr4,%0" : "=r"(result));
	return result;
}

void set_cr0(unsigned long value)
{
	__asm__ __volatile__("mov %0,%%cr0" : : "r"(value));
}

void set_cr3(unsigned long value)
{
	__asm__ __volatile__("mov %0,%%cr3" : : "r"(value));
}

void set_cr4(unsigned long value)
{
	__asm__ __volatile__("mov %0,%%cr4" : : "r"(value));
}

void set_pdbr(_dword_union pdbr)
{
	__asm__ __volatile__("mov %0,%%cr3" : : "r"(pdbr.u));
}

void ltr(uint16_t selector)
{
	__asm__ __volatile__("ltr %0" : : "rm"(selector));
}

void lgdt(_dword_union base, uint16_t limit)
{
	struct
	{
		unsigned short limit __attribute__((__packed__));
		unsigned long base __attribute__((__packed__));
	} pack = {limit, base.u};
	__asm__ __volatile__("lgdt %0" : : "m"(pack));
}

void lidt(_dword_union base1, uint16_t limit1)
{
	struct
	{
		uint16_t limit __attribute__((__packed__));
		uint32_t base __attribute__((__packed__));
	} pack = {limit1, base1.u};
	__asm__ __volatile__("lidt (%0)" : : "p"(&pack));
}
