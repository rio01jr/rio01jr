#ifndef STACK_H
#define STACK_H

// Function declarations
void initialize_stack(int initialCapacity);
void resize_stack();
void push(int value);
int pop();
int top();
int isEmpty();
void freeStack();

#endif // STACK_H
