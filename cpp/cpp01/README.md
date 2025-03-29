# Project: cpp01 - Memory Management and Control Structures in C++

## Overview

This project focuses on fundamental concepts in C++ programming, including memory allocation, pointers to members, references, and switch statements. Each section provides explanations and code examples to help solidify these concepts.

## Table of Contents

- [Introduction](#introduction)
- [Objectives](#objectives)
- [Memory Allocation](#memory-allocation)
  - [Stack Memory](#stack-memory)
  - [Heap Memory](#heap-memory)
- [Pointers to Members](#pointers-to-members)
- [References](#references)
- [Switch Statements](#switch-statements)

## Introduction

Understanding memory management and control structures is essential for effective programming in C++. This project explores these topics through practical examples and detailed explanations.

## Objectives

- Explain the concepts of memory allocation and management.
- Demonstrate the use of pointers to class members.
- Discuss references and their applications.
- Illustrate the use of switch statements for control flow.

## Memory Allocation

Memory in C++ can be allocated in two primary areas: the stack and the heap.

### Stack Memory

- **Definition**: Stack memory is a region of memory used for static memory allocation. It is managed automatically by the compiler.
- **Lifetime**: Variables allocated on the stack exist only within the scope of the function that created them. Once the function exits, the memory is automatically reclaimed.
- **Performance**: Stack allocation is generally faster because it involves simple pointer arithmetic. However, the size of stack memory is limited.

**Example:**

```cpp
#include <iostream>

void stackAllocation() {
    int stackVar = 10; // Allocated on the stack
    std::cout << "Stack Variable: " << stackVar << std::endl;
}

int main() {
    stackAllocation();
    // stackVar is not accessible here
    return 0;
}
```

### Heap Memory

- **Definition**: Heap memory is used for dynamic memory allocation, where variables are allocated and deallocated manually.
- **Lifetime**: Objects created on the heap remain in memory until they are explicitly deallocated using `delete`.
- **Performance**: Heap allocation is generally slower than stack allocation due to the overhead of managing memory. It also carries the risk of memory leaks if memory is not properly managed.

**Example:**

```cpp
#include <iostream>

void heapAllocation() {
    int* heapVar = new int(20); // Allocated on the heap
    std::cout << "Heap Variable: " << *heapVar << std::endl;
    delete heapVar; // Manual deallocation
}

int main() {
    heapAllocation();
    return 0;
}
```

## References

References provide an alias for variables, making them easier to work with without the overhead of pointers. They cannot be null and must be initialized upon declaration.

**Example:**

```cpp
#include <iostream>

void modifyValue(int& ref) {
    ref += 10; // Modifies the original variable
}

int main() {
    int number = 5;
    std::cout << "Original Value: " << number << std::endl;
    modifyValue(number);
    std::cout << "Modified Value: " << number << std::endl;
    return 0;
}
```

## Pointers to Members

Pointers to members allow access to class member variables and functions, facilitating dynamic access. For more information, refer to the [README](../note_directory/README.md) file.

**Example:**

```cpp
#include <iostream>

class MyClass {
public:
    int value;
    void display() {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    MyClass obj;
    obj.value = 42;

    // Pointer to member variable
    int MyClass::* ptrToValue = &MyClass::value;
    std::cout << "Value via Pointer: " << obj.*ptrToValue << std::endl;

    // Pointer to member function
    void (MyClass::*ptrToFunc)() = &MyClass::display;
    (obj.*ptrToFunc)(); // Call the member function
    return 0;
}
```

## Switch Statements

Switch statements allow for a clean and efficient way to execute different actions based on the value of a variable.

**Example:**

```cpp
#include <iostream>

void switchExample(int day) {
    switch (day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        default:
            std::cout << "Invalid day" << std::endl;
    }
}

int main() {
    int day = 2;
    switchExample(day);
    return 0;
}
```
