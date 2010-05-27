/* 
 * File:   string.h
 * Author: bdallen
 *
 * Created on May 27, 2010, 11:45 PM
 */

#ifndef _STRING_H
#define	_STRING_H

    #include <k_types.h>

    #define MAXBUFFER 0x2000

  unsigned short strlen(const char *);
  void* memcpy(void *dest, const void *src, size_t n);
  char isnum(unsigned char c);
  char is_lower(unsigned char s);
  char is_upper(unsigned char s);

#endif	/* _STRING_H */

