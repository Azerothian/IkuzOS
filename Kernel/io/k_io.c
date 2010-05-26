/* 
 * File:   io.c
 * Author: bdallen
 *
 * Created on May 26, 2010, 9:42 PM
 */
#include "k_io.h"

void outb(DW port, DB data)
{
    __asm__ ("outb %1, %0"::"d"(port),"a"(data));
}

void outw(DW port, DW data)
{
    __asm__ ("outw %1, %0"::"d"(port),"a"(data));
}

