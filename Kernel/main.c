
#include "main.h"

/* -- Include the main kernel libraries for base functionality */
#include <types.h>
#include <io.h>
#include <textmode.h>
#include <fat.h>
#include "drivers/ata/ata.h"
#include "arch/i386/boot.h"

/**
 * _kernel_main() - Main entry point for the IkuzOS Kernel
 */
void _kernel_main()
{
    clear_screen();
    printk("IkuzOS is Starting Up!\n");

    // Halt the System
    set_color(RED);
    printk("System Is Now Halting.....\n");
    //hlt();
}