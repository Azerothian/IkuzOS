/* 
 * File:   stdlib.c
 * Author: bdallen
 *
 * Created on May 27, 2010, 11:33 PM
 */
#include "stdlib.h"
 int atoi(char *num)
  {
    int no;
    unsigned short i;
    no = 0;
    i = 0;
    if(num[0] == '-')
     {
      i++;
     }
    for(;i<strlen(num);i++)
     {
      if(!isnum(num[i]))
        return 0;
      no = no * 10 + num[i] - '0';
     }
     if(num[0] == '-')
     {
      no = no * -1;
     }
    return no;
  }

