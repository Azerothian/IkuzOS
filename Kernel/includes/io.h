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

    // Standard IO
    void outb(unsigned short port, unsigned char val);
    unsigned char inb(unsigned short port);
    void insl(unsigned short port, unsigned int buffer, unsigned long count);

    // PC Speaker
    void k_pcspk_play_sound(unsigned int nFrequence);
    void k_pcspk_nosound();
    void kbeep();

#endif
