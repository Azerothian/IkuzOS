/*
 *  cpu.h
 *  Kernel
 *
 *  Created by Allen,Brendon on 2/06/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __ARCH__X86__CPU_H__
#define __ARCH__X86__CPU_H__

	#if SUBARCH==x32
		#include<arch/x86/x32/cpu.h>
	#endif

#endif
