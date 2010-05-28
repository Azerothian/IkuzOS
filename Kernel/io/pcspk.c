/* 
 * File:   pcspk.c
 * Author: bdallen
 *
 * Created on May 28, 2010, 4:23 PM
 */
#include <io.h>
#include <types.h>


 //Play sound using built in speaker
 void k_pcspk_play_sound(unsigned int nFrequence) {
 	int Div;
 	int tmp;

        //Set the PIT to the desired frequency
 	Div = 1193180 / nFrequence;
 	outb(0x43, 0xb6);
 	outb(0x42, (unsigned int) (Div) );
 	outb(0x42, (unsigned int) (Div >> 8));

        //And play the sound using the PC speaker
 	tmp = inb(0x61);
  	if (tmp != (tmp | 3)) {
 		outb(0x61, tmp | 3);
 	}
 }

 //make it shutup
 void k_pcspk_nosound() {
 	unsigned int tmp = (inb(0x61) & 0xFC);
 	outb(0x61, tmp);
 }

 //Make a beep
 void kbeep() {
 	 k_pcspk_play_sound(1000);
 	 //timer_wait(10);
 	 //nosound();
          //set_PIT_2(old_frequency);
 }

