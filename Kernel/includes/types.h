/* 
 * File:   k_types.h
 * Author: bdallen
 *
 * Created on May 26, 2010, 9:46 PM
 */
#ifndef __K_TYPES_H
    #define __K_TYPES_H

    #ifndef __SIZE_T
        #define size_t unsigned int
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
