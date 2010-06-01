/*
 *  types.h
 *  Kernel
 *
 *  Created by Allen,Brendon on 1/06/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#if !defined(X64_32BIT_CODE)
/*
 * long, pointers are 64bit on x86_64
 * int is 32Bit on x86-64
 */
typedef unsigned long		u64_t;
typedef unsigned int		u32_t;
typedef unsigned short		u16_t;
typedef unsigned char		u8_t;

typedef signed long	        s64_t;
typedef signed int		s32_t;
typedef signed short		s16_t;
typedef signed char		s8_t;

/**
 *	word_t - 64 Bit
 */
typedef u64_t            	word_t;

/**
 *	64 Bit Macros
 */
#define __X86_64BIT_TYPED(x)	(x##UL)
#define X86_64BIT_TYPED(x)	__X86_64BIT_TYPED(x)
#define X86_64BIT_ZERO		X86_64BIT_TYPED(0)
#define X86_64BIT_ONE		X86_64BIT_TYPED(1)

#else
/* This is for the few startup files which are compiled as 32 bit code */

typedef unsigned int __attribute__((__mode__(__DI__))) u64_t;
typedef unsigned int		u32_t;
typedef unsigned short		u16_t;
typedef unsigned char		u8_t;

typedef int __attribute__((__mode__(__DI__))) s64_t;
typedef int			s32_t;
typedef short			s16_t;
typedef char			s8_t;

/**
 *	word_t - 32 Bit
 */
typedef u32_t            	word_t;

/**
 *	64 Bit 0
 */

/**
 *	64 Bit Macros
 */
#define __X86_64BIT_TYPED(x)	(x##ULL)
#define X86_64BIT_TYPED(x)	__X86_64BIT_TYPED(x)
#define X86_64BIT_ZERO		X86_64BIT_TYPED(0)
#define X86_64BIT_ONE		X86_64BIT_TYPED(1)

#endif /* !defined(X64_32BIT_CODE) */

#endif /* !__ARCH__X86__X64__TYPES_H__ */

