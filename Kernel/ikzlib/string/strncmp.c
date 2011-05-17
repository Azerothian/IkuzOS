/*
 * strncmp.c
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */
#include <types.h>
#include <ikzlib/string.h>

int strncmp(char *s1, char *s2, unsigned int len)
{
	char res = 0;
	while(len > 0)
	{
		if((res = *s1 - *s2++) != 0 || !*s1++)
			break;
		len--;
	}
	return res;
}
