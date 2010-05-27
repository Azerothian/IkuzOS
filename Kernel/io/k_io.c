/* 
 * File:   io.c
 * Author: bdallen
 *
 * Created on May 26, 2010, 9:42 PM
 */
#include "k_io.h"

/* Sends a byte (or word or dword) on a I/O location.
 * Traditionnal names are outb, outw and outl respectively.
 */
void outb(unsigned short port, unsigned char data)
{
    __asm__ ("outb %1, %0"::"d"(port),"a"(data));
}

/* Sends a byte (or word or dword) on a I/O location.
 * Traditionnal names are outb, outw and outl respectively.
 */
void outw(unsigned short port, unsigned char data)
{
    __asm__ ("outw %1, %0"::"d"(port),"a"(data));
}

/*
 * Receives a byte (or word or dword) from an I/O location.
 * Traditionnal names are inb, inw and inl respectively
 */
unsigned char inb(unsigned short port)
{
   unsigned char ret;
   __asm__ volatile ("inb %1,%0":"=a"(ret):"Nd"(port));
   return ret;
}

/*
 * Receives a byte (or word or dword) from an I/O location.
 * Traditionnal names are inb, inw and inl respectively
 */
unsigned char inw(unsigned short port)
{
   unsigned char ret;
   __asm__ volatile ("inw %1,%0":"=a"(ret):"Nd"(port));
   return ret;
}



