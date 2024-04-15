# Compiler to use
CC=gcc

# Compiler flags
CFLAGS=-Wall -g

# Name of the executable to create
TARGET=life

# Default target
all: $(TARGET)

# Link the object files into a binary
$(TARGET): main.o life.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o life.o

# Compile the main.c to main.o
main.o: main.c life.h
	$(CC) $(CFLAGS) -c main.c

# Compile the life.c to life.o
life.o: life.c life.h
	$(CC) $(CFLAGS) -c life.c

# Clean up
clean:
	rm -f $(TARGET) *.o

# Phony targets
.PHONY: clean
