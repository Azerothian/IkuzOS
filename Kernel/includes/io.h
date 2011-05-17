/* 
 * File:   io.h
 * Author: bdallen
 *
 * Created on May 26, 2010, 9:44 PM
 */
#ifndef _IO_H
#define	_IO_H

	#include<cpu.h>

    // CLear the Interrupt Flags
    void cli();

    // Set the Interrupt Flags
    void sti();

    // Halt the CPU
    void hlt();

    // PC Speaker
    void k_pcspk_play_sound(unsigned int nFrequence);
    void k_pcspk_nosound();
    void kbeep();

#endif
