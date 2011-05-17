# Detect the OS
UNAME := $(shell uname -o)

# Architecture to Build For
IKUZOS_ARCH = x86
IKUZOS_SUBARCH = x32

ifeq ($(UNAME), Darwin)
# Compilers to Use for MacOS X using Macports gcc
CC = i386-elf-gcc-4.3.2
LD = i386-elf-ld
NASM = nasm
endif

ifeq ($(UNAME), Cygwin)
# Compilers to Use for Cygwin
CC = /i686-xcompiler/bin/i686-elf-gcc-4.2.2.exe
LD = /i686-xcompiler/bin/i686-elf-ld.exe
NASM = nasm
endif

MAKE = make
RM = rm
LD_KERNEL_FLAGS = -T arch/$(IKUZOS_ARCH)/link.ld

# Product Strings
IKUZOS_MAJOR = 0
IKUZOS_MINOR = 0
IKUZOS_REVISION = 1
IKUZOS_KERNELVER = $(IKUZOS_MAJOR).$(IKUZOS_MINOR).$(IKUZOS_REVISION)
IKUZOS_VER_STRING = IkuzOS
IKUZOS_CODENAME = Vash
IKUZOS_BUILD_DATE := $(shell date '+%Y-%m-%d %T %Z')
IKUZOS_COMPILER = $(shell $(CC) --version | head -n1 | cut -d " " -f 1,2,3)

# Build Directories
TOPDIR := $(shell pwd)
KERNEL = $(TOPDIR)/Kernel
SUBDIRS = Kernel