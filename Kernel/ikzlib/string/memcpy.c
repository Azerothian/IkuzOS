/*
 * memcpy.c
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */
#include <types.h>
#include <ikzlib/string.h>

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
