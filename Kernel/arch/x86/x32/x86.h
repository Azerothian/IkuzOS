/*
 *  x86.h
 *  Kernel
 *
 *  Created by Allen,Brendon on 2/06/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __ARCH__X86__X32__H__
#define __ARCH__X86__X32__H__

/*
 * A segment descriptor is an entry in the GDT or an LDT.
 */
struct x86_segment_descriptor {
	unsigned long words[2];
};

/*
 * An interrupt gate is an entry in the IDT.
 */
struct x86_interrupt_gate {
	unsigned short offset_low          ;
	unsigned short segment_selector    ;
	unsigned int reserved        : 5;
	unsigned int signature       : 8;
	unsigned int dpl             : 2;
	unsigned int present         : 1;
	unsigned short offset_high         ;
};


#endif
