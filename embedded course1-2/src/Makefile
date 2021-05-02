#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk
 
TARGET = c1m4

ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = gcc 
	LDFLAGS = $(CFLAGS)
	PLATFORM_TARGET = -DHOST
	CFLAGS = -g -std=c99 -O0 -Wall -Werror 
endif

ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	CPU = -mcpu=cortex-m4
	PLATFORM_TARGET = -DMSP432
	LINKER_FILE = -T ./../msp432p401r.lds
	LD = arm-none-eabi-ld
	#LDFLAGS = $(LINKER_FILE) -Map=$(TARGET).map
	LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE)
	ARCH = -mthumb -march=armv7e-m \
			-mfloat-abi=hard \
			-mfpu=fpv4-sp-d16
	SPECS = --specs=nosys.specs
	CFLAGS = -g -std=c99 -O0 -Wall -Werror $(CPU) $(ARCH) $(SPECS)
endif


CPPFLAGS = -E 
OBJS = $(notdir $(SOURCES:.c=.o))
E_OBJS = $(SOURCES:.c=.i)
ASSM_OBJS = $(SOURCES:.c=.asm)

%.i : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(PLATFORM_TARGET) $(INCLUDES) $< -o $@

%.o : %.c
	$(CC) -c $(CFLAGS) $(PLATFORM_TARGET) $(INCLUDES) $< -o $@ -DCOURSE1

%.asm : %.c 
	$(CC) -S $(CFLAGS) $(PLATFORM_TARGET) $(INCLUDES) $< -o $@ 

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build 
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

.PHONY: clean
clean:
	rm -f *.o *.map *.out *.i *.asm *.s 