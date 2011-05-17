/*
 * stdio.h
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */

#ifndef STDIO_H_
#define STDIO_H_

#include <types.h>
#include <ikzlib/stdarg.h>

#define PR_LJ	0x01 	// Left justify
#define PR_CX	0x02 	// use A-F for hex instead of a-f
#define PR_SC	0x04 	// signed numeric conversion (%d vs. %u)
#define PR_32	0x08 	// long 32bit numeric ocnversion
#define PR_16   0x10    /* short (16-bit) numeric conversion */
#define PR_WS   0x20    /* PR_SC set and num was < 0 */
#define PR_LZ   0x40    /* pad left with '0' instead of ' ' */
#define PR_FP   0x80    /* pointers are far */

typedef int (*fnptr_t)(uint8_t c, void **helper);
int doPrint(const char *fmt, va_list args, fnptr_t fn, void *ptr);
void emit_str(uint32_t i, uint32_t flags, fnptr_t fn, uint32_t actual_wd,
	      uint32_t given_wd, uint32_t radix, void *ptr);

#endif /* STDIO_H_ */
