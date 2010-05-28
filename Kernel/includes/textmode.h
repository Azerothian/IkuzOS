/* 
 * File:   textmode.h
 * Author: bdallen
 *
 * Created on May 28, 2010, 12:07 PM
 */

#ifndef _TEXTMODE_H
#define	_TEXTMODE_H

// Colours for Text
#define WHITE 0x0F
#define GREEN 0x0A
#define BLUE  0x01
#define RED   0x0C
#define YELLOW 0x0E

void newline();//go to the next line
void kputc(char c);//put a character on the screen
void kprint(char *s);//put a string on the screen
void print_hex(unsigned int hex);
void print_int( unsigned int c);//print and integer
void set_color(unsigned char c);
void clear_screen();
void scroll();
void print_bin( unsigned int c);


#endif	/* _TEXTMODE_H */

