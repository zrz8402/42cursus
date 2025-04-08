# README: Deep Copy vs. Shallow Copy in C++

## Table of Contents
1. [Shallow Copy](#shallow-copy)
2. [Deep Copy](#deep-copy)
3. [When to Use Shallow or Deep Copy](#when-to-use-shallow-or-deep-copy)
4. [Example Code](#example-code)
5. [Conclusion](#conclusion)

---

### Shallow Copy
A **shallow copy** of an object creates a new object but does not duplicate the data contained in the original object. Instead, it copies the **pointers** or **references** to the original data. This means that both the original and the copied object will point to the same memory location for dynamic resources (e.g., dynamically allocated arrays, pointers).

#### Key Characteristics:
- Only the values of the object are copied, not the data they point to.
- Both the original and copied objects refer to the same memory location.
- It is faster than deep copy because it doesn't involve copying the data itself, just the references or pointers.

#### When Shallow Copy Can Be Problematic:
- If either the original or the copied object is modified, the changes will affect both.
- If one of the objects is destroyed, the other may become a "dangling pointer," leading to undefined behavior or memory corruption.

---

### Deep Copy
A **deep copy** involves creating a new object and copying both the values and the data pointed to by pointers in the original object. In other words, a deep copy duplicates the entire object, including dynamically allocated memory, ensuring that the original and the copied object are entirely independent of each other.

#### Key Characteristics:
- The object and all dynamically allocated memory or resources are fully copied.
- The original and copied objects do not share any data or memory locations.
- It ensures that changes to one object do not affect the other.

#### When to Use Deep Copy:
- When you need independent copies of objects that may contain dynamic memory or complex resources (e.g., arrays, file handles).
- When objects are copied and manipulated after the copy operation.

---

### When to Use Shallow or Deep Copy

- **Shallow Copy**:
  - Use shallow copy when you do not need the objects to be independent of each other.
  - Ideal for lightweight objects that do not hold resources like dynamic memory.
  - Common when copying small, stateless objects or when objects do not own resources.

- **Deep Copy**:
  - Use deep copy when the object owns dynamic resources that need to be preserved independently after copying.
  - Essential when dealing with objects that manage dynamic memory, file handles, or other resources.
  - Useful when you want to ensure changes to one object do not affect the other.

---

### Example Code

#### Shallow Copy Example
```cpp
#include <iostream>

class ShallowCopyExample {
public:
    int* data;

    ShallowCopyExample(int value) {
        data = new int(value);
    }

    // Shallow copy constructor (copies pointer only)
    ShallowCopyExample(const ShallowCopyExample& other) {
        data = other.data;
    }

    ~ShallowCopyExample() {
        delete data;
    }
};

int main() {
    ShallowCopyExample obj1(10);
    ShallowCopyExample obj2 = obj1; // Shallow copy

    // Modify the data of obj2
    *obj2.data = 20;

    std::cout << "obj1 data: " << *obj1.data << std::endl; // Prints 20
    std::cout << "obj2 data: " << *obj2.data << std::endl; // Prints 20

    // Both objects share the same memory, so modifying one affects the other
    return 0;
}
```

#### Deep Copy Example
```cpp
#include <iostream>

class DeepCopyExample {
public:
    int* data;

    DeepCopyExample(int value) {
        data = new int(value);
    }

    // Deep copy constructor (creates a new copy of the data)
    DeepCopyExample(const DeepCopyExample& other) {
        data = new int(*other.data); // Create a new copy of the data
    }

    ~DeepCopyExample() {
        delete data;
    }
};

int main() {
    DeepCopyExample obj1(10);
    DeepCopyExample obj2 = obj1; // Deep copy

    // Modify the data of obj2
    *obj2.data = 20;

    std::cout << "obj1 data: " << *obj1.data << std::endl; // Prints 10
    std::cout << "obj2 data: " << *obj2.data << std::endl; // Prints 20

    // The objects are independent, so modifying one does not affect the other
    return 0;
}
```

---

### Conclusion

In C++, **shallow copy** and **deep copy** are two different approaches to copying objects. A shallow copy is more efficient but can lead to issues when dealing with dynamically allocated resources. A deep copy, on the other hand, ensures that each object is fully independent, making it safer when dealing with complex data or dynamic memory.

Be mindful of which type of copy is appropriate for your use case to avoid potential memory management issues such as dangling pointers or unintended side effects.
