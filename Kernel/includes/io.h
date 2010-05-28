/* 
 * File:   io.h
 * Author: bdallen
 *
 * Created on May 26, 2010, 9:44 PM
 */
#ifndef _IO_H
#define	_IO_H

    // CLear the Interrupt Flags
    void cli();

    // Set the Interrupt Flags
    void sti();

    // Halt the CPU
    void hlt();


    __inline__ void outb(unsigned short port, unsigned char val);

    
    __inline__ unsigned char inb(unsigned short port);

#endif