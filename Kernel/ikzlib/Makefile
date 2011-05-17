include ../../makefile.inc

# LIB
LIBSRC := $(shell ls *.c)
LIBOBJ=$(LIBSRC:.c=.o)

# CTYPE
CTPLSRC := $(shell ls ctype/*.c)
CTPOBJ=$(CTPLSRC:.c=.o)

# STRING
STRLSRC := $(shell ls string/*.c)
STROBJ=$(STRLSRC:.c=.o)

# STDIO
SIOLSRC := $(shell ls stdio/*.c)
SIOOBJ=$(SIOLSRC:.c=.o)

# Full Library
IKZLIB = $(LIBOBJ) $(CTPOBJ) $(SIOOBJ) $(STROBJ)

# Include Directories
INCLUDES = ../includes

include ../buildflags.inc

all: ikzlib
	
ikzlib: $(IKZLIB)
		$(LD) -o ikzlib.o $(IKZLIB)
		
clean:
		rm -rf $(foreach OBJ,$(IKZLIB),$(OBJ))

include ../buildrules.inc

