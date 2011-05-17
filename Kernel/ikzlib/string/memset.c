/*
 * memset.c
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */
#include <types.h>
#include <ikzlib/string.h>

void *memset(void *dest, int value, unsigned count)
{
	void *destPtr = dest;
	while(count)
	{
		*(unsigned char *)dest = value;
		dest = (unsigned char *)dest + 1;
		--count;
	}
	return destPtr;
}
