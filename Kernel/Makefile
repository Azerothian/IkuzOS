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
CDEBUG=-D__DEBUG__

# Kernel IO
IOOBJ=io/cli.o io/sti.o io/hlt.o io/outb.o io/inb.o io/insl.o io/pcspk.o

# Hardware Drivers
HWIOBJ=drivers/ata/ata.o

# Textmode Video
TVIDOBJ=video/textmode.o

# Filesystem Objects
FSOBJ=fs/fat_12.o fs/fat_32.o

# All Kernel Objects
KOBJ=main.o $(IOOBJ) $(TVIDOBJ) $(FSOBJ) $(HWIOBJ)

#Rules
%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) $(CDEBUG) -c -o $@ $<

# Build the whole Kernel
all: kernel

kernel: $(KOBJ) boot.o
	$(LD) -T link.ld -o IKZKERN boot.o $(KOBJ)

boot.o: boot.s
	$(AS) $(AFLAGS) boot.s -o boot.o

clean:
	rm -rf $(foreach OBJ,$(KOBJ),$(OBJ))
	rm -rf boot.o
	rm -rf IKZKERN