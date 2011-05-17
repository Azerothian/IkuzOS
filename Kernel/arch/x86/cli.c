/* 
 * File:   clr.c
 * Author: bdallen
 *
 * Created on May 28, 2010, 11:15 AM
 */

#include <io.h>

/*
 * Clear the Interrupt Flag
 */
void cli()
{
    asm volatile("cli");
}

