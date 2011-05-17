/*
 * stdarg.h
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */

#ifndef STDARG_H_
#define STDARG_H_

typedef char *va_list;

#define VA_SIZE( type ) \
	(( sizeof(type) + sizeof(int) - 1 ) & ~(sizeof(int)-1))

#define va_start(ap, v) \
	(ap = ((va_list) & (v) + VA_SIZE(v)))

#define va_arg(ap, type) \
	(ap += VA_SIZE(type), *((type *)(ap - VA_SIZE(type))))

#define va_end(ap) ( (void)(ap = 0) )

#endif /* STDARG_H_ */
