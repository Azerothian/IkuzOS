/* 
 * File:   textmode.c
 * Author: bdallen
 *
 * Created on May 28, 2010, 12:03 PM
 */
#include <textmode.h>
#include <types.h>


/*
 * 
 */
char *texmem = cast_charp(0xB8000);
char *cline = cast_charp(0xB8000);
unsigned char color = 0x07; //white

void kprint(char *s)
{
    while(*s != '\0')
    {
        if(*s == '\n') newline();
        if(texmem>= cast_charp(0xB8FFF))clear_screen();
        kputc(*s);
        s++;
    }
}

void kputc(char c)
{
    *texmem = c;
    texmem++;
    *texmem = color;
    texmem++;
}

void newline()
{
    cline += 0xA0;
    texmem = cline;
}


void print_hex(unsigned int i)
{

    kprint("0x");

    int counter = 8;
    unsigned char cur;

    while(counter-- > 0){
            cur = (i & 0xf0000000) >> 28;

            i <<= 4;

            if (cur >= 0xA)
                    cur += 0x07;

            cur += 0x30;

            kputc(cur);
    }
}

void set_color(unsigned char c)
{
    color = c;
}

void clear_screen()
{
    texmem = cast_charp(0xB8000);
    int i;
    int screensz;
    screensz = 80 * 25;
    for(i = 1; i < screensz; i++)
    {
    kputc(' ');

    }
    texmem = cast_charp(0xB8000);
}

static void printInt_internal( unsigned int c, int base )
{
    static char const * const digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if ( c > 0 )
    {
        printInt_internal( c / base, base );
        kputc( digits[c % base] );
    }
}


void print_int( unsigned int c)
{
    if ( c == 0 )
    {
        kprint( "0" );
    }
    else
    {
        printInt_internal( c, 10);
        kprint( "" );
    }
}

void print_bin( unsigned int c)
{
    if ( c == 0 )
    {
        kprint( "0" );
    }
    else
    {
        printInt_internal( c, 2);
        kprint( "" );
    }
}

void scroll()
{

}
