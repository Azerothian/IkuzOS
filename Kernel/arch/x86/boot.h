/*
 *  boot.h
 *  Kernel
 *
 *  Created by Allen,Brendon on 31/05/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

/* The Multiboot information.  */
#ifndef __ARCHX86BOOT_H
#define __ARCHX86BOOT_H
	typedef struct _MultibootInfo_t
	{
	   uint32_t flags;

	   uint32_t mem_lower;
	   uint32_t mem_upper;

	   struct
	   {
		  uint8_t part3;
		  uint8_t part2;
		  uint8_t part1;
		  uint8_t drive;
	   } boot_device;

	   char *cmdline;

	   uint32_t mods_count;
	   struct
	   {
		  void  *mod_start;
		  void  *mod_end;
		  uint8_t *string;
		  uint32_t reserved;
	   } *mods_addr;

	   union
	   {
		  struct
		  {
			 uint32_t tabsize;
			 uint32_t strsize;
			 uint32_t addr;
			 uint32_t reserved;
		  } aout;
		  struct
		  {
			 uint32_t num;
			 uint32_t size;
			 uint32_t addr;
			 uint32_t shndx;
		  } elf;
		  struct
		  {
			uint32_t pages;
			uint32_t kpdir;
			uint32_t reserved2;
			uint32_t reserved3;
		  } ominos;
	   } syms;

	   uint32_t mmap_length;
	   struct
	   {
		  uint64_t base_addr;
		  uint64_t length;
		  uint32_t type;
	   } *mmap_addr;

	   uint32_t drives_length;
	   struct DrivesInfo
	   {
		  uint32_t size;
		  uint8_t  drive_number;
		  uint8_t  drive_mode;
		  uint16_t drive_cylinders;
		  uint8_t  drive_heads;
		  uint8_t  drive_sectors;
		  uint16_t drive_ports[1];
	   } *drives_addr;

	   uint32_t config_table;

	   char *boot_loader_name;

	   struct
	   {
		  uint16_t version;
		  uint16_t cseg;
		  uint32_t offset;
		  uint16_t cseg_16;
		  uint16_t dseg;
		  uint16_t flags;
		  uint16_t cseg_len;
		  uint16_t cseg_16_len;
		  uint16_t dseg_len;
	   } *apm_table;

	   uint32_t vbe_control_info;
	   uint32_t vbe_mode_info;
	   uint16_t vbe_mode;
	   uint16_t vbe_interface_seg;
	   uint16_t vbe_interface_off;
	   uint16_t vbe_interface_len;
	} MultibootInfo_t;

	#define MEM_INFO         0x0001
	#define BOOT_DEVICE      0x0002
	#define CMDLINE          0x0004
	#define MODS_INFO        0x0008
	#define AOUT_SYMS        0x0010
	#define ELF_SYMS         0x0020
	#define MMAP_INFO        0x0040
	#define DRIVES_INFO      0x0080
	#define CONFIG_TABLE     0x0100
	#define BOOT_LOADER_NAME 0x0200
	#define APM_TABLE        0x0400
	#define VBE_INFO         0x0800

#endif
