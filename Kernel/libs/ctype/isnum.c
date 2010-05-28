/* 
 * File:   isnum.c
 * Author: bdallen
 *
 * Created on May 28, 2010, 10:17 AM
 */
#include <ctype.h>

char isnum(unsigned char c)
{
     if(c >= '0' && c <= '9')
             return 1;
     else
            return 0;
}

