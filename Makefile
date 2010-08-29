## Local builds with make ARCH_FLAGS=i686 to get the last inception thought of Fischer till
## the code buffer that morphs the thought is fixed for x86_64
## To cross-compile for eg: MIPS (32 bit)
## build with make CROSS_COMPILE=<everything-without-gcc-suffix> ARCH_FLAGS= 

CROSS_COMPILE :=
CC := $(CROSS_COMPILE)gcc
UNAME := $(shell uname)
ARCH := $(shell uname -m | sed -e 's,i.86,i386,')
ifeq ($(ARCH),i386)
	ARCH_FLAGS := -m32 
else 
	ifeq ($(ARCH), x86_64)
		ARCH_FLAGS := -m64
	else
		ARCH_FLAGS :=
	endif
endif

HFILES = SList.h DList.h 
CFILES = SList.c DList.c clib.c
CFLAGS := -g -Wall $(ARCH_FLAGS) 
SRC_FILES := $(HFILES)$(CFILES)
OBJ_FILES :=  clib.o SList.o DList.o

MY_DIRNAME = /usr/local/include/clib/

# Set up some sensible defaults
SRCROOT ?= .
SYMROOT ?= .
DSTROOT ?= /tmp/$(PROJECT_NAME).dst
ifeq "" "$(INSTALL_AS_USER)"
    INSTALL_AS_USER = $(USER)
endif
ifeq "" "$(INSTALL_AS_GROUP)"
    INSTALL_AS_GROUP = $(GROUP)
endif
ifeq "" "$(INSTALL_PERMISSIONS)"
    INSTALL_PERMISSIONS = o+rX
endif

TARGET = clib

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJ_FILES) 

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm -f $(OBJ_FILES) *~ $(TARGET)
