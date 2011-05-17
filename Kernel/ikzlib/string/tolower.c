/*
 * tolower.c
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */
#include <types.h>
//#include <ikzlib/string.h>

int tolower(int c)
{
	int ret = c;
	if((uint32_t)c >= 0x41 && (uint32_t)c <= 0x5a)
		ret += 'a' - 'A';
	return ret;
}
