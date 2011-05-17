/*
 * toupper.c
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */
#include <types.h>
#include <ikzlib/string.h>

int toupper(int c)
{
	int ret = c;
	if((uint32_t)(c-'a') < 26)
			ret += 'A' - 'a';
	return ret;
}
