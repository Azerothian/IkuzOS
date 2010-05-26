# Detect the OS
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
# Compilers to Use for MacOS X using Macports gcc
CC=i386-elf-gcc-4.3.2
LD=i386-elf-ld
AS=nasm
endif

# Compilation Flags
CFLAGS=-c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -I includes
AFLAGS=-f elf

# Build the whole Kernel
all: kernel

kernel: main.o boot.o
	$(LD) -T link.ld -o kernel.bin boot.o main.o

main.o: main.c
	$(CC) $(CFLAGS) main.c

boot.o: boot.s
	$(AS) $(AFLAGS) boot.s -o boot.o

clean:
	rm -rf *.o

