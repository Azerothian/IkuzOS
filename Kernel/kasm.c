/* 
 * File:   kasm.c
 * Author: bdallen
 *
 * Created on May 27, 2010, 11:28 PM
 */
#include "kasm.h"

void lidt(IDT *idt)
{
	__asm__ __volatile__ ("lidt (%0)"::"p"(idt));
}


void sidt(IDT *idt)
{
	__asm__ __volatile__ ("sidt %0"::"m"(*idt));
}

void lgdt(GDT *gdt)
{
	__asm__ __volatile__ ("lgdt (%0)"::"p"(gdt));
}

void sgdt(GDT *gdt)
{
	__asm__ __volatile__ ("sgdt %0"::"m"(*gdt));
}


