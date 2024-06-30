# Compiler and linker
CC = gcc
LD = ld

# Compiler flags
# CFLAGS = -nostartfiles

# Linker flags, specify the linker script
LDFLAGS = -T linker.ld

# Target executable
TARGET = initcall_example

# Source files
SRCS = main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to link the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

