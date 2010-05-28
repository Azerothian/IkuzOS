
#include "main.h"

/* -- Include the main kernel libraries for base functionality */
#include <io.h>
#include <textmode.h>

/**
 * _kernel_main() - Main entry point for the IkuzOS Kernel
 */
void _kernel_main()
{
    clear_screen();
    kprint("IkuzOS is Starting Up!!!!");
    hlt();
}