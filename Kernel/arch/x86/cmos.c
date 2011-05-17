#include <types.h>

// get_cmos_mem()
// --------------
// Description : Gets the memory amount of a machine from the CMOS value
// Returns : Unsigned Short of memory Value in KB
unsigned short get_cmos_mem()
{
    unsigned short total;
    unsigned char lowmem, highmem;

    outportb(0x70, 0x30);
    lowmem = inportb(0x71);
    outportb(0x70, 0x31);
    highmem = inportb(0x71);

    total = lowmem | highmem << 8;
    return total;
}
