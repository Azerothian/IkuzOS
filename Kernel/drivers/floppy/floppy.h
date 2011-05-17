/*
 * floppy.h
 *
 *  Created on: 16/05/2011
 *      Author: admin
 */

#ifndef FLOPPY_H_
#define FLOPPY_H_

#define FLOPPY_DRIVE0		0
#define FLOPPY_DRIVE1		1

#define FLOPPY_READBLOCK	1
#define FLOPPY_WRITEBLOCK	2

#define FLOPPY_TIMEOUT 		128
#define FLOPPY_RWTRIES 		3
#define FLOPPY_DMA_CHANNEL	2

// base addresses
#define FLOPPY_PRIMARY		0x3f0
#define FLOPPY_SECONDARY	0x370

// registers
#define FLOPPY_DOR		0x02 // digital output register
#define FLOPPY_MSR		0x04 // main status register, input reg
#define FLOPPY_DRS		0x04 // data rate selector, output reg
#define FLOPPY_DATA		0x05 // data register
#define FLOPPY_CCR		0x07 // config control register

// commands
#define FLOPPY_RECALIBRATE	0x07
#define FLOPPY_SIS			0x08 //sense interrupt status
#define FLOPPY_SEEK			0x0f
#define FLOPPY_WRITE		0xc5
#define FLOPPY_READ			0xe6

#ifndef SEEK_START
#define SEEK_START   0
#define SEEK_CURRENT 1
#endif

typedef struct _floppyGeometry_t
{
	uint32_t sectors;
	uint32_t heads;
	uint32_t cylinders;
	uint32_t blocksize;
} floppyGeometry_t;

struct digitalOutputRegisterBits
{
	uint32_t drive:2;
	uint32_t reset:1;
	uint32_t dma:1;
	uint32_t mota:1;
	uint32_t motb:1;
	uint32_t motc:1;
	uint32_t motd:1;
} __attribute__((packed));

struct digitalOutputRegister
{
	union
	{
		struct digitalOutputRegisterBits bits;
		uint8_t data;
	};
};

struct mainStatusRegisterBits
{
	uint32_t mota:1;
	uint32_t motb:1;
	uint32_t motc:1;
	uint32_t motd:1;
	uint32_t busy:1;
	uint32_t nondma:1;
	uint32_t dio:1;
	uint32_t mrq:1;
} __attribute__((packed));

struct mainStatusRegister
{
	union
	{
		struct mainStatusRegisterBits bits;
		uint8_t data;
	};
};

struct status0Bits
{
	uint32_t us0:1;
	uint32_t us1:1;
	uint32_t hd:1;
	uint32_t nr:1;
	uint32_t uc:1;
	uint32_t se:1;
	uint32_t intCode:2;
} __attribute__((packed));

struct status0
{
	union
	{
		struct status0Bits bits;
		uint8_t data;
	};
};

typedef struct _floppyDrive_t
{
	int type;
	int locked;
	uint16_t base;
	uint32_t currentBlock;
	uint32_t currentCylinder;
	struct status0 st0;
	floppyGeometry_t *geometry;
} floppyDrive_t;

int initFloppy(void);

#endif /* FLOPPY_H_ */
