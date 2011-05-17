
#include "main.h"

/**
 * _kernel_main() - Main entry point for the IkuzOS Kernel
 */
void _kernel_main()
{
	time_t startTime;

	// Disable Interrupts
	disableInts();

	// If we are running on x86 then load in the Global Descriptor Table
	#if ARCH==x86
		initGDT();
	#endif

	// Set the OS Startup Time
	startTime = rtcGetTime();
	setStartupTime(startTime);

	// Clear the Screen
    clear_screen();
    printk("IkuzOS is Starting Up!\n");
    unsigned short total;
    total = get_cmos_mem();
    printk("Total System Memory : ");
    print_int(total);
    printk(" Kb \n");
	
    // Halt the System
    set_color(RED);
    printk("System Is Now Halting.....\n");
    //hlt();
}
