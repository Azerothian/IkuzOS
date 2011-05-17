#ifndef _STRING_H
#define	_STRING_H

#include <types.h>

void* memcpy(void *dest, const void *src, size_t n);
void *memset(void *dest, int value, unsigned count);
int strncmp(char *s1, char *s2, unsigned int len);
int strncpy(char *dest, char *src, int count);
uint32_t strlen(const char *str);
char *strrchr(char *s, int c);

char is_lower(unsigned char s);
char is_upper(unsigned char s);
int toupper(int c);
int tolower(int c);

#endif	/* _STRING_H */

