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
SOURCES =   -I./main.c \
			-I./misc.c 
 
TARGET = c1m3

ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = gcc 
	LDFLAGS = $(CFLAGS)
	PLATFORM_TARGET = -DHOST
endif

ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	CPU = -mcpu=cortex-m4
	PLATFORM_TARGET = -DMSP432
	LINKER_FILE = -T ./msp432p401r.lds
	LD = arm-none-eabi-ld
	LDFLAGS = $(LINKER_FILE) -Map=$(TARGET).map
	ARCH = -mthumb -march=armv7e-m \
			-mfloat-abi=hard \
			-mfpu=fpv4-sp-d16
	SPECS = --specs=nosys.specs
endif

CFLAGS = -g -std=c99 -O0 -Wall -Werror 
CPPFLAGS = -E 
OBJS = $(notdir $(SOURCES:.c=.o))
E_OBJS = $(SOURCES:.c=.i)
ASSM_OBJS = $(SOURCES:.c=.asm)

%.i : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(PLATFORM_TARGET) $(INCLUDES) $< -o $@

%.o : %.c
	$(CC) -c $(CFLAGS) $(CPU) $(ARCH) $(SPECS) $(PLATFORM_TARGET) $(INCLUDES) $< -o $@

%.asm : %.c 
	$(CC) -S $(CFLAGS) $(PLATFORM_TARGET) $(INCLUDES) $< -o $@ 

.PHONY: build 
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	arm-none-eabi-gcc -Wl,-T msp432p401r.lds -Wl,-M=$(TARGET).map \
	--specs=nosys.specs -mfloat-abi=hard -o $(TARGET).out $(OBJS)


.PHONY: clean
clean:
	rm -f *.o *.map *.out *.i *.asm *.s