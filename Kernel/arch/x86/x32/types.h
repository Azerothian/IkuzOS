#ifndef __ARCH__X86__X32__TYPES_H__
#define __ARCH__X86__X32__TYPES_H__


#define IKZ_32BIT
#undef  IKZ_64BIT


typedef unsigned int __attribute__((__mode__(__DI__))) u64_t;
typedef unsigned int		u32_t;
typedef unsigned short		u16_t;
typedef unsigned char		u8_t;

typedef signed int __attribute__((__mode__(__DI__))) s64_t;
typedef signed int		s32_t;
typedef signed short	s16_t;
typedef signed char		s8_t;

/**
 *	word_t - machine word wide unsigned int
 */
typedef u32_t			word_t;

#endif /* !__ARCH__X86__X32__TYPES_H__ */
