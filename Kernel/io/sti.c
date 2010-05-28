/* 
 * File:   sti.c
 * Author: bdallen
 *
 * Created on May 28, 2010, 11:19 AM
 */

#include <io.h>

/*
 * Set the Interrupt Flag
 */
void sti()
{
    asm volatile("sti");
}
