/*
 * emit_str.c
 *
 *  Created on: 17/05/2011
 *      Author: admin
 */

#include <ikzlib/stdio.h>
#include <types.h>

void emit_str(uint32_t i, uint32_t flags, fnptr_t fn,
              uint32_t actual_wd, uint32_t given_wd,
              uint32_t radix, void *ptr){
	char temp[32];
	char string[255];
	int counter = 0, length = 0, tmp_count = 0;

	if(i == 0){
		string[0] = '0';
//		string[1] = 0;
		fn(string[0], &ptr);
//		fn(string[1], &ptr);
		return;
	}

	while(i > 0){
		temp[counter] = i % radix + '0';
		i /= radix;
		if(temp[counter] > '9')
		{
			if( flags & PR_CX )
				temp[counter] += 7;
			else
				temp[counter] += 39;
		}
		counter++;
	}
	counter--;


    actual_wd = counter;
//	k_printf("actual_wd = %d\n", actual_wd);
//	k_printf("given_wd  = %d\n", given_wd);
    if(flags & PR_LZ){
		given_wd--;
        while(given_wd > actual_wd){
            fn('0', &ptr);
			given_wd--;
        }
    }

	while(counter >= 0)
		string[length++] = temp[counter--];

	string[length] = 0;

	for(;tmp_count < length; tmp_count++)
	  fn(string[tmp_count], &ptr);
}
