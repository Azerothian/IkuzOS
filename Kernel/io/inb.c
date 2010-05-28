/* 
 * File:   inb.c
 * Author: bdallen
 *
 * Created on May 28, 2010, 11:25 AM
 */

#include <io.h>

/*
 * 
 */
__inline__ unsigned char inb(unsigned short port)
{
   unsigned char ret;
   asm volatile ("inb %1,%0":"=a"(ret):"Nd"(port));
   return ret;
}

