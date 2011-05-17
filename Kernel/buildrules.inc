#Rules
%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) $(CDEBUG) -c -o $@ $<

%.o:%.asm
	$(NASM) $(NASMFLAGS) $< -o $@