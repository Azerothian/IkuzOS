#include <types.h>
#include <ikzlib/string.h>

char *strrchr(char *s, int c)
{
	char *last = c?0:s;
	while(*s)
	{
		if(*s == c)
			last = s;
		s+=1;
	}
	return last;
}
