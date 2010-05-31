# Detect the OS
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
# Compilers to Use for MacOS X using Macports gcc
CC=i386-elf-gcc-4.3.2
LD=i386-elf-ld
NASM=nasm
endif

# Architecture to Build For
ARCH=i386

# Include Directories
INCLUDES=includes

# Compilation Flags
CFLAGS=-Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -fno-omit-frame-pointer -fno-builtin -ffreestanding
CDEBUG=-D__DEBUG__
NASMFLAGS=-f elf

# Kernel Loader
KLDROBJ=arch/$(ARCH)/boot.o

#Kernel x86 Code
x86OBJ=arch/i386/cpu.o

# Kernel IO
IOOBJ=io/cli.o io/sti.o io/hlt.o io/outb.o io/inb.o io/insl.o io/pcspk.o

# Hardware Drivers
HWIOBJ=drivers/ata/ata.o

# Textmode Video
TVIDOBJ=video/textmode.o

# Filesystem Objects
FSOBJ=fs/fat_12.o fs/fat_32.o

# All Kernel Objects
KOBJ=$(KLDROBJ) main.o $(IOOBJ) $(TVIDOBJ) $(FSOBJ) $(HWIOBJ) $(x86OBJ)

#Rules
%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) $(CDEBUG) -c -o $@ $<

%.o:%.asm
	$(NASM) $(NASMFLAGS) $< -o $@

# Build the whole Kernel
all: kernel

kernel: $(KOBJ)
	$(LD) -T arch/$(ARCH)/link.ld -o IKZKERN $(KOBJ)

clean:
	rm -rf $(foreach OBJ,$(KOBJ),$(OBJ))
	rm -rf IKZKERN