# Compiler settings
CC = gcc
BASE_CFLAGS = -Wall -Werror -g
CFLAGS += $(BASE_CFLAGS)

# Object files variable that contains a list of 
# the object files that will be built
# Add necessary objects for all .h files
# add songs.o below delimited by a space
OBJS = main.o songs.o utils.o stack.o

# Default target all runs the compilation for main and test
# by default it will create both files
all: main.bin

# Main program target
main.bin: $(OBJS)
	$(CC) $(CFLAGS) -o main.bin $(OBJS)

# Generic rule for building object files
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Dependencies
# format > target: dependency
# example> utils.o: utils.h
main.o: main.c songs.h utils.h stack.h
# ADD target and dependency for songs.o, not sure try running gcc -MM songs.c 
songs.o: songs.h
utils.o: utils.h
stack.o: stack.h
# Clean target
clean:
	rm -f main.bin *.o

# .PHONY will cause the Makefile to the target
# all and then the target clean by default
.PHONY: all clean

