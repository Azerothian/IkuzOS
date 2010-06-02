/*
 *  cpu.h
 *  Kernel
 *
 *  Created by Allen,Brendon on 2/06/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#include <types.h>

#define PRIV_KERN 0
#define PRIV_USER 3

#define SEL_GDT 0
#define SEL_LDT (1 << 2)

#define SELECTOR(index, table, rpl) \
((((index) & 0x1FFF) << 3) | (table) | ((rpl) & 3))

/* selectors for kernel code/data */
#define KERN_CS SELECTOR(1, SEL_GDT, 0)
#define KERN_DS SELECTOR(2, SEL_GDT, 0)

/* Get/Set EFLAGS */
u32_t get_eflags(void);
void set_eflags(u32_t eflags);

/* Get/Set CR0 */
u32_t get_cr0(void);
void set_cr0(u32_t cr0);

/* Get/Set CR3 */
u32_t get_cr3(void);
void set_cr3(u32_t cr3);

/* Get/Set CR4 */
u32_t get_cr4(void);
void set_cr4(u32_t cr4);