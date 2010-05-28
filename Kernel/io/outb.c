/* 
 * File:   outb.c
 * Author: bdallen
 *
 * Created on May 28, 2010, 11:23 AM
 */

#include <io.h>

/*
 * 
 */
__inline__ void outb(unsigned short port, unsigned char val)
{
   asm volatile("outb %0,%1"::"a"(val), "Nd" (port));
}

