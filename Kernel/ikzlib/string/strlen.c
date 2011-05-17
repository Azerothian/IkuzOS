/*
 * strlen.c
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */
#include <types.h>
#include <ikzlib/string.h>

uint32_t strlen(const char *str)
{
	int count=0;
	while(*str++ != '\0')
		count++;
	return count;
}
