include makefile.inc

ikzkrn:
		@make -C Kernel all
		
clean:
		@make -C Kernel clean
		
include buildrules.inc