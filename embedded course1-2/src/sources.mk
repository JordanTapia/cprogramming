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

# Add your Source files to this variable

# Add your include paths to this variabl
ifeq ($(PLATFORM), HOST)
	SOURCES=-I../src/main.c \
		-I../src/memory.c \
		-I../src/course1.c \
		-I../src/stats.c\
		-I../src/data.c

	INCLUDES = -I../src \
		-I../include/common/
endif
ifeq ($(PLATFORM), MSP432)
	SOURCES = -I../src/main.c \
		-I../src/memory.c \
		-I../src/course1.c \
		-I../src/stats.c \
		-I../src/interrupts_msp432p401r_gcc.c \
		-I../src/startup_msp432p401r_gcc.c \
		-I../src/system_msp432p401r.c \
		-I../src/data.c
	INCLUDES = -I../src \
		-I../include/common/ \
		-I../include/CMSIS/ \
		-I../ \
		-I../include/msp432/ 
endif

