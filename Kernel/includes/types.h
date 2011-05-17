/* 
 * File:   k_types.h
 * Author: bdallen
 *
 * Created on May 26, 2010, 9:46 PM
 */
#ifndef _K_TYPES_H
    #define _K_TYPES_H

	#if (ARCH==X86)
		#include "../arch/x86/types.h"
	#endif

    #define cast_uchar(x) ((unsigned char) (x))
    #define cast_ucharp(x) ((unsigned char*) (x))
    #define cast_char(x) ((char) (x))
    #define cast_charp(x) ((char*) (x))
    #define cast_ushort(x) ((unsigned short) (x))
    #define cast_ushortp(x) ((unsigned short*) (x))
    #define cast_short(x) ((short) (x))
    #define cast_shortp(x) ((short*) (x))
    #define cast_uint(x) ((unsigned int) (x))
    #define cast_uintp(x) ((unsigned int*) (x))
    #define cast_int(x) ((int) (x))
    #define cast_intp(x) ((int*) (x))
    #define cast_voidp(x) ((void*) (x))

	typedef unsigned char 	uint8_t;
	typedef unsigned short 	uint16_t;
	typedef unsigned long	uint32_t;
	typedef unsigned long long uint64_t;

	typedef signed char		int8_t;
	typedef signed short	int16_t;
	typedef signed long		int32_t;
	typedef signed long long int64_t;

	typedef uint32_t size_t;

	#define TRUE 1
	#define FALSE 0

	#define true TRUE
	#define false FALSE

	#ifndef NULL
	#define NULL ((void *)0)
	#endif

	typedef uint16_t mode_t;
	typedef uint16_t ino_t;
	typedef uint16_t dev_t;
	typedef uint16_t nlink_t;
	typedef uint16_t uid_t;
	typedef uint16_t gid_t;
	typedef long off_t;
	typedef long time_t;
	typedef int pid_t;

    // Date Type
    typedef struct
    {
        char mm,dd;
        int yy;
    }DATE;

    // Time Type
    typedef struct
    {
        int hour,min,sec;
    }TIME;


#endif
