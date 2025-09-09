# Stack-Implementation-in-C
A complete stack data structure implementation in C with function pointers and advanced operations.

📋 Description

This C library provides a robust stack implementation featuring traditional stack operations along with advanced functionality like duplication and swapping. The implementation uses function pointers for a object-oriented style approach.
✨ Features

    Standard Stack Operations: Push, pop, and print

    Advanced Operations: Duplicate top element and swap top two elements

    Function Pointers: Object-oriented style method calls

    Memory Management: Proper allocation and deallocation

    Error Handling: Boundary checking and error messages

    Dynamic Capacity: Configurable stack size

📚 API Reference
Core Functions

    builder(int capacity) - Creates a new stack with specified capacity

    push(Stack stack, int x) - Adds element to top of stack

    pop(Stack stack) - Removes and returns top element

    print(Stack stack) - Displays stack contents

Advanced Operations

    dup(Stack stack) - Duplicates the top element

    swap(Stack stack) - Swaps the top two elements

    freeStack(Stack stack) - Releases stack memory

🛠️ Compilation
bash

gcc -Wall -Wextra -std=c99 -o stack stack.c main.c

⚠️ Important Notes

    Capacity Limits: Stack operations check bounds and report errors

    Memory Management: Always call freeStack() before freeing the stack structure

    Error Handling: Operations provide error messages for invalid conditions

    Function Pointers: Methods are called through function pointers for flexibility

📋 Requirements

    C99 compatible compiler

    Standard C library

🔄 Key Features

    Object-Oriented Style: Function pointers simulate methods

    Boundary Checking: Prevents stack overflow/underflow

    Visual Feedback: Clear printing of stack contents

    Advanced Operations: Beyond basic push/pop functionality

    Clean Memory Management: Proper allocation and deallocation
