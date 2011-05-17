include ../makefile.inc

# Kernel Loader
KLDROBJ=arch/$(IKUZOS_ARCH)/boot.o

# NewLib
#NEWLIBOBJ=libs/$(ARCH)/$(SUBARCH)/libc.a

#Kernel CPU Specific
KCPUOBJ=arch/$(IKUZOS_ARCH)/$(IKUZOS_SUBARCH)/cpu.o

# Kernel Arch
KRNASRC := $(shell ls arch/$(IKUZOS_ARCH)/*.c)
KRNAOBJ=$(KRNASRC:.c=.o)

# Kernel Mode Drivers
KRNDSRC := $(shell find ./drivers -name "*.c")
KRNDOBJ := $(KRNDSRC:.c=.o)

# Textmode Video
TVIDOBJ=video/textmode.o

# Filesystem Objects
FSOBJ=fs/fat_12.o fs/fat_32.o

# Include Directories
INCLUDES = includes

# All Kernel Objects
KOBJ=$(KLDROBJ) main.o ikzlib/ikzlib.o $(KCPUOBJ) $(IKZLOBJ) $(KRNAOBJ) $(KRNDOBJ) $(IOOBJ) $(TVIDOBJ) $(FSOBJ) $(HWIOBJ) $(x86OBJ) $(NEWLIBOBJ)

# Build Flags
include buildflags.inc

# Build the whole Kernel
all: prep ikzlib kernel

kernel: $(KOBJ)
		$(LD) $(LD_KERNEL_FLAGS) -o ../build/$(IKUZOS_ARCH)_$(IKUZOS_SUBARCH)/IKZKERN $(KOBJ)
	
ikzlib/ikzlib.o: 
		@make -C ikzlib all
			
prep:
		@mkdir build
		@mkdir build/$(IKUZOS_ARCH)_$(IKUZOS_SUBARCH)

clean:
		rm -rf build
		rm -rf $(foreach OBJ,$(KOBJ),$(OBJ))
		@make -C ikzlib clean
	
include buildrules.inc