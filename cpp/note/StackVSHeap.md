# Memory Management

## Table of Contents
- [Memory Allocation](#memory-allocation)
  - [Stack Memory](#stack-memory)
  - [Heap Memory](#heap-memory)
- [References](#references)

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