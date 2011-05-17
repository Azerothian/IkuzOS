/*
 * doprint.c
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */
#include <ikzlib/string.h>
#include <ikzlib/stdio.h>
#include <ikzlib/stdarg.h>

int doPrint(const char *fmt, va_list args, fnptr_t fn, void *ptr)
{
	int argument = 0;
	unsigned int flags, count, radix, actual_wd, given_wd;
	char *where;

	flags = count = radix = given_wd = 0;

	while(*fmt != 0)
	{
		//possible format string
		if(*fmt == '%')
		{
			fmt++;
			count++;
			if(*fmt >= '0' && *fmt <= '9')
			{
				// Allows user to either specific %08x or %8x. both will work now
				if(*fmt == '0' && *(fmt+1) >='0' && *(fmt+1) <= '9')
					*fmt++;
				flags = ( flags | PR_LZ);
				given_wd = (*fmt - '0');
				fmt++;
			}
			if(*fmt == 'X')
			{
				flags |= PR_CX;
				radix = 16;
				argument = va_arg(args, int);
				emit_str(argument, flags, fn, actual_wd, given_wd, radix, &ptr);
			}
			else if(*fmt == '%'){
				fn(*fmt, &ptr);
				flags = given_wd = 0;
			}
			else if(*fmt== 'x'){ /* hex value */
				radix = 16;
				argument = va_arg(args, int);
				emit_str(argument, flags, fn, actual_wd, given_wd, radix, &ptr);
			}
			else if(*fmt == 'o'){
				radix = 8;
				argument = va_arg(args, int);
				emit_str(argument, flags, fn, actual_wd, given_wd, radix, &ptr);
			}
			else if(*fmt == 'b'){
				radix = 2;
				argument = va_arg(args, int);
				emit_str(argument, flags, fn, actual_wd, given_wd, radix, &ptr);
			}
			else if(*fmt == 'd'){
				radix = 10;
				argument = va_arg(args, int);
				emit_str(argument, flags, fn, actual_wd, given_wd, radix, &ptr);
			}
			else if(*fmt == 's'){
				where = va_arg(args, char *);
				actual_wd = strlen(where);
				while(*where != '\0')
					fn(*where++, &ptr);
			}
			else if(*fmt == 'c'){
				argument = va_arg(args, char);
				fn(argument, &ptr);
			}

		}
		else
			fn(*fmt, &ptr);

		*fmt++;
		count++;
	}
	return(count);
}
