/*
 * strncpy.c
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */
#include <types.h>
#include <ikzlib/string.h>

int strncpy(char *dest, char *src, int count)
{
	char *d, *s;
	int ret = 0;

	d = dest;
	s = src;

	while(*s != '\0' && count != 0)
	{
		*d++ = *s++;
		count--;
		ret++;
	}
	return ret;
}
