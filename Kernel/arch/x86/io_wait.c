
#include <io.h>

static inline
void io_wait( void )
{
    // port 0x80 is used for 'checkpoints' during POST.
    // The Linux kernel seems to think it is free for use :-/
    asm volatile( "outb %%al, $0x80"
                  : : "a"(0) );
}
