/* 
 * File:   main.h
 * Author: bdallen
 *
 * Created on May 26, 2010, 8:44 PM
 */

#define WHITE_SPACE 0x07
#define VIDEO_MEMORY 0xb8000

char *videoMemory = (char*) VIDEO_MEMORY;

void _kernel_main();
void clrscr();
void printxy(char *message, unsigned int x, unsigned int y);

