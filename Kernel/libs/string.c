/* 
 * File:   string.c
 * Author: bdallen
 *
 * Created on May 27, 2010, 11:45 PM
 */
#include "string.h"
#include <k_types.h>

unsigned short strlen(const char *str)
{
    unsigned short len = 0;

      while(*str++ && len < MAXBUFFER)
        len++;

    return len;
}

void* memcpy(void *dest, const void *src, size_t n)
{
    //Function Tested @ 11:45 13/12/2003 - Got to Test a bit
    char *_dest = (char *)dest;
    const char *_src = (const char *)src;

    *_dest = *_src; //Just the first entry

    while(n)
    {
     *(_dest+n) = *(_src+n);
     n--;
    }

    return _dest;
}

