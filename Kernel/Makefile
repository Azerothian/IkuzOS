# Detect the OS
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
# Compilers to Use for MacOS X using Macports gcc
CC=i386-elf-gcc-4.3.2
LD=i386-elf-ld
AS=nasm
endif

# Include Directories
INCLUDES=includes

# Compilation Flags
CFLAGS=-Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -fno-omit-frame-pointer -fno-builtin -ffreestanding
AFLAGS=-f elf

# Kernel IO
IOOBJ=io/cli.o io/sti.o io/hlt.o io/outb.o io/inb.o

# All Kernel Objects
KOBJ=main.o $(IOOBJ)

#Rules
%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c -o $@ $<

# Build the whole Kernel
all: kernel

kernel: $(KOBJ) boot.o
	$(LD) -T link.ld -o IKZKERN boot.o $(KOBJ)

boot.o: boot.s
	$(AS) $(AFLAGS) boot.s -o boot.o

clean:
	rm -rf $(foreach OBJ,$(KOBJ),$(OBJ))