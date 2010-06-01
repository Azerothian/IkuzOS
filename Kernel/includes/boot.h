/*
 *  boot.h
 *  Kernel
 *
 *  Created by Allen,Brendon on 31/05/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _BOOT_H

	#define _BOOT_H

	/* Flags in multiboot_information struct */
	#define MB_INFO_FLAG_MEM         (1 << 0)
	#define MB_INFO_FLAG_BOOTDEV     (1 << 1)
	#define MB_INFO_FLAG_CMDLINE     (1 << 2)
	#define MB_INFO_FLAG_MODS        (1 << 3)
	#define MB_INFO_FLAG_AOUT        (1 << 4)
	#define MB_INFO_FLAG_ELF         (1 << 5)
	#define MB_INFO_FLAG_MMAP        (1 << 6)
	#if 0
		#define MB_INFO_FLAG_DRIVES      (1 << 7)
		#define MB_INFO_FLAGS_CFGTAB     (1 << 8)
		#define MB_INFO_FLAGS_BTLDR_NAME (1 << 9)
		#define MB_INFO_FLAGS_APMTAB     (1 << 10)
		#define MB_INFO_FLAGS_VBETAB     (1 << 11)
	#endif
#endif