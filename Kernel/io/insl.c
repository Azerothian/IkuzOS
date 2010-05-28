
#include <io.h>

void insl(unsigned short port, unsigned int buffer, unsigned long count)
{
    asm("cld; rep; insl" :: "D" (buffer), "d" (port), "c" (count));
}
