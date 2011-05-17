/*
 *  cpu.h
 *  Kernel
 *
 *  Created by Allen,Brendon on 2/06/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#include <types.h>

typedef struct _regs_t
{
	uint32_t gs;
	uint32_t fs;
	uint32_t es;
	uint32_t ds;
	uint32_t edi;
	uint32_t esi;
	uint32_t ebp;
	uint32_t esp;
	uint32_t ebx;
	uint32_t edx;
	uint32_t ecx;
	uint32_t eax;
	uint32_t vec, err; // Interrupt vector, error code
	uint32_t eip, cs, eflags, useresp, ss;
} regs_t;

typedef struct _uregs_t
{
	uint32_t gs;
	uint32_t fs;
	uint32_t es;
	uint32_t ds;
	uint32_t edi;
	uint32_t esi;
	uint32_t ebp;
	uint32_t esp;
	uint32_t ebx;
	uint32_t edx;
	uint32_t ecx;
	uint32_t eax;
	uint32_t eip;
	uint32_t cs;
	uint32_t eflags;
	uint32_t useresp;
	uint32_t ss;
} uregs_t;

typedef union __dword_union
{
		void *p;
		unsigned long u;
		long s;
} _dword_union __attribute__((__transparent_union__));

#define CR0_PE         0x00000001u
#define CR0_MP         0x00000002u
#define CR0_EM         0x00000004u
#define CR0_TS         0x00000008u
#define CR0_ET         0x00000010u
#define CR0_NE         0x00000020u
#define CR0_WP         0x00010000u
#define CR0_AM         0x00040000u
#define CR0_NW         0x20000000u
#define CR0_CD         0x40000000u
#define CR0_PG         0x80000000u

#define CR4_VME        0x00000001u
#define CR4_PVI        0x00000002u
#define CR4_TSD        0x00000004u
#define CR4_DE         0x00000008u
#define CR4_PSE        0x00000010u
#define CR4_PAE        0x00000020u
#define CR4_MCE        0x00000040u
#define CR4_PGE        0x00000080u
#define CR4_PCE        0x00000100u
#define CR4_OSFXSR     0x00000200u
#define CR4_OSXMMEXCPT 0x00000400u

#define PDBR_PWT       0x00000008u
#define PDBR_PCD       0x00000010u

void outportb(uint32_t port, uint8_t outata);
uint8_t inportb(uint16_t port);
void outportw(uint16_t port, uint16_t data);
uint16_t inportw(uint16_t port);
void outportdw(uint16_t port, uint32_t data);
uint32_t inportdw(uint16_t port);

void hlt(void);
void invlpg(_dword_union address);
void disableInts(void);
void enableInts(void);

unsigned long get_cr0(void);
unsigned long get_cr2(void);
unsigned long get_cr3(void);
unsigned long get_cr4(void);

void set_cr0(unsigned long value);
void set_cr3(unsigned long value);
void set_cr4(unsigned long value);
void set_pdbr(_dword_union pdbr);

void ltr(uint16_t selector);
void lgdt(_dword_union base, uint16_t limit);
void lidt(_dword_union base, uint16_t limit);
int detectCpu(void);
