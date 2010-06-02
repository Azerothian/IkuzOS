
#include "main.h"

/**
 * _kernel_main() - Main entry point for the IkuzOS Kernel
 */
void _kernel_main()
{
    clear_screen();
    printk("IkuzOS is Starting Up!\n");
	
	u32_t cr0;
	cr0 = get_cr0();
	
	printk(cr0);

    // Halt the System
    set_color(RED);
    printk("System Is Now Halting.....\n");
    //hlt();
}