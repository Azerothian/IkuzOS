/*
 *  cpu.h
 *  Kernel
 *
 *  Created by Brendon Allen on 31/05/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

/*
* CPUID information.
*/
struct x86_cpuid_info {
	/* function 0: vendor id string */
	char vendor_id[12];
	
	/* function 1: processor signature in eax register */
	struct {
		unsigned stepping_id     : 4;
		unsigned model_number    : 4;
		unsigned family_code     : 4;
		unsigned type            : 2;
		unsigned unused1         : 2;
		unsigned extended_model  : 4;
		unsigned extended_family : 8;
		unsigned unused2         : 4;
	} proc_sig;
	
	/* function 1: feature flags in edx register */
	struct {
		unsigned fpu : 1;
		unsigned vme : 1;
		unsigned de : 1;
		unsigned pse : 1;
		unsigned tsc : 1;
		unsigned msr : 1;
		unsigned pae : 1;
		unsigned mce : 1;
		unsigned cx8 : 1;
		unsigned apic : 1;
		unsigned reserved1 : 1;
		unsigned sep : 1;
		unsigned mtrr : 1;
		unsigned pge : 1;
		unsigned mca : 1;
		unsigned cmov : 1;
		unsigned pat : 1;
		unsigned pse36 : 1;
		unsigned psn : 1;
		unsigned clfsh : 1;
		unsigned reserved2 : 1;
		unsigned ds : 1;
		unsigned acpi : 1;
		unsigned mmx : 1;
		unsigned fxsr : 1;
		unsigned sse : 1;
		unsigned sse2 : 1;
		unsigned ss : 1;
		unsigned htt : 1;
		unsigned tm : 1;
		unsigned ia64 : 1;
		unsigned pbe : 1;
	} feature_info_edx;
	
	/* function 1: feature flags in ecx register */
	struct {
		unsigned sse3 : 1;
		unsigned reserved1 : 1;
		unsigned dtes64 : 1;
		unsigned monitor : 1;
		unsigned ds_cpl : 1;
		unsigned vmx : 1;
		unsigned smx : 1;
		unsigned est : 1;
		unsigned tm2 : 1;
		unsigned ssse3 : 1;
		unsigned cnxt_id : 1;
		unsigned reserved2 : 2;
		unsigned cx16 : 1;
		unsigned xtpr : 1;
		unsigned pdcm : 1;
		unsigned reserved3 : 2;
		unsigned dca : 1;
		unsigned sse4_1 : 1;
		unsigned sse4_2 : 1;
		unsigned reserved4 : 11;
	} feature_info_ecx;
};


unsigned long get_eflags(void);
void set_eflags(unsigned long eflags);
unsigned long get_cr0(void);
void set_cr0(unsigned long cr0);
unsigned long get_cr3(void);
void set_cr3(unsigned long cr3);
unsigned long get_cr4(void);
void set_cr4(unsigned long cr4);

