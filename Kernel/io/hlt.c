/* 
 * File:   hlt.c
 * Author: bdallen
 *
 * Created on May 28, 2010, 11:20 AM
 */

#include <io.h>

/*
 * Halt the CPU
 */
void hlt()
{
    asm volatile ("hlt");
}
