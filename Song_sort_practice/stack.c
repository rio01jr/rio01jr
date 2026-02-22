#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int *stack = NULL;
int top_index = -1;
int capacity = 0;

/*
Stack Representation:

Initially:
Capacity = 2
  +---+---+
  |   |   |
  +---+---+
   0   1

After pushing 10:
Capacity = 2
  +----+---+
  | 10 |   |
  +----+---+
   0    1

After pushing 20:
Capacity = 2
  +----+----+
  | 10 | 20 |
  +----+----+
   0    1

After pushing 30 (resize):
Capacity = 4
  +----+----+----+----+
  | 10 | 20 | 30 |    |
  +----+----+----+----+
   0    1    2    3

After popping (30 is removed):
Capacity = 4
  +----+----+----+----+
  | 10 | 20 |    |    |
  +----+----+----+----+
   0    1    2    3
*/

// Function to initialize the stack
void initialize_stack(int initialCapacity) {
    stack = (int *)malloc(initialCapacity * sizeof(int));
    capacity = initialCapacity;
}

// Function to resize the stack
void resize_stack() {
    capacity *= 2;
    stack = (int *)realloc(stack, capacity * sizeof(int));
    // printf("Stack resized to capacity: %d\n", capacity);
}

// Function to push an element onto the stack
void push(int value) {
    if (top_index == capacity - 1) {
        resize_stack();
    }
    stack[++top_index] = value;
}

// Function to pop an element from the stack
int pop() {
    if (top_index == -1) {
        return -1;
    }
    return stack[top_index--];
}

// Function to peek at the top element of the stack
int top() {
    if (top_index == -1) {
        return -1;
    }
    return stack[top_index];
}

// Function to check if the stack is empty
int isEmpty() {
    return top_index == -1;
}

// Function to free the stack
void freeStack() {
    free(stack);
}
