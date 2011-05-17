/*
 * is_upper.c
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */
#include <types.h>
#include <ikzlib/string.h>

char is_upper(unsigned char s)
{
    if(s >= 'A' && s <= 'Z')
        return 1;
    return 0;
}
