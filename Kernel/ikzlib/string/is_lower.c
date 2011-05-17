/*
 * is_lower.c
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */
#include <types.h>
#include <ikzlib/string.h>

char is_lower(unsigned char s)
{
    if(s >= 'a' && s <= 'z')
        return 1;
    return 0;
}
