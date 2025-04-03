```markdown
# C++02: Ad-hoc Polymorphism, Operator Overloading, and Orthodox Canonical Class Form

This repository contains examples and explanations related to key C++ concepts: **Ad-hoc Polymorphism**, **Operator Overloading**, and the **Orthodox Canonical Class Form**. These concepts are important in mastering object-oriented programming and resource management in C++.

---

## Polymorphism: Pointers vs. References

Polymorphism in C++ allows objects of different types to be treated as objects of a common base type. In this section, we will explore the differences between using **pointers** and **references** to achieve polymorphism.

### Key Concepts:
- **Polymorphism**: The ability for a base class pointer or reference to call methods in derived class objects, allowing for different behaviors based on the actual type of the object.
- **Pointers**: A pointer is a variable that holds the memory address of an object. Pointers to base class objects can be used to call derived class methods, which is useful in dynamic polymorphism scenarios.
- **References**: A reference is an alias for an existing object. References to base class objects can also achieve polymorphism, but they cannot be null, unlike pointers.

### Pointers for Polymorphism

Pointers are commonly used for polymorphism because they allow dynamic memory allocation (`new`) and can point to objects of different types. You can also set a pointer to `nullptr` to represent no object.

```cpp
#include <iostream>

class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing a Shape" << std::endl;
    }
    virtual ~Shape() = default; // Virtual destructor for polymorphism
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

int main() {
    Shape* shape = new Circle(); // Base class pointer pointing to derived class object
    shape->draw();  // Calls Circle's draw() method
    delete shape;  // Free the dynamically allocated memory
    return 0;
}
```

### References for Polymorphism

References are safer and simpler to use than pointers. A reference cannot be null, and you don't need to explicitly dereference it. When using references, you also achieve polymorphism.

```cpp
#include <iostream>

class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing a Shape" << std::endl;
    }
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

int main() {
    Circle circle;
    Shape& shape = circle;  // Base class reference to derived class object
    shape.draw();  // Calls Circle's draw() method
    return 0;
}
```

### Comparison: Pointers vs. References

- **Pointers**:
  - Can be null (i.e., `nullptr`).
  - Can be reassigned to point to different objects.
  - Require explicit memory management (e.g., `new` and `delete`).

- **References**:
  - Cannot be null.
  - Cannot be reassigned once bound to an object.
  - Do not require explicit memory management.
  - Generally preferred for simpler and safer code.

### When to Use Pointers vs. References

- **Use Pointers** when:
  - You need dynamic memory allocation (`new` and `delete`).
  - You need to represent nullable objects (`nullptr`).
  - You need to reassign the object a pointer points to.

- **Use References** when:
  - You don't need dynamic memory allocation.
  - You want to avoid nullability and ensure the object is always valid.
  - You want to simplify your code by avoiding the need to dereference or check for null.

---

## Ad-hoc Polymorphism

**Ad-hoc Polymorphism** refers to the ability to use the same function or operator name with different types, achieved through **function overloading** and **operator overloading**. It enables a function or operator to behave differently depending on the types of the arguments passed to it.

### Key Concepts:
- **Function Overloading**: Defining multiple functions with the same name but different parameter types or numbers of parameters.
- **Operator Overloading**: Customizing the behavior of operators for user-defined types.

### Example: Function Overloading
```cpp
#include <iostream>

class Calculator {
public:
    // Function overloading for addition
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;
    std::cout << calc.add(1, 2) << std::endl;         // Calls int add(int, int)
    std::cout << calc.add(1.5, 2.3) << std::endl;     // Calls double add(double, double)
    return 0;
}
```

### Example: Operator Overloading
```cpp
#include <iostream>

class Point {
private:
    int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}

    // Overload the '+' operator to add two Point objects
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1(1, 2), p2(3, 4);
    Point p3 = p1 + p2;  // Uses overloaded '+' operator
    p3.display();
    return 0;
}
```

---

## Operator Overloading

Operator overloading allows us to define custom behavior for operators when they are applied to user-defined types. It provides a way to use the usual C++ operators (like `+`, `-`, `*`, etc.) with objects in a way that makes sense for that particular type.

### Guidelines for Operator Overloading:
- Only overload operators that make sense for your type (e.g., `+` for classes representing numeric values, `[]` for classes representing collections).
- Make sure to preserve the original semantics of the operator (e.g., `+` should generally result in addition).
- Operator overloading should be intuitive and consistent with the behavior of built-in types.

### Example: Overloading the `+` Operator for a `Complex` Number Class
```cpp
#include <iostream>

class Complex {
private:
    double real, imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload the '+' operator to add two Complex numbers
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(1.0, 2.0), c2(3.0, 4.0);
    Complex c3 = c1 + c2;  // Calls overloaded '+' operator
    c3.display();
    return 0;
}
```

---

## Orthodox Canonical Class Form

The **Orthodox Canonical Class Form (OCF)** is a set of guidelines for writing C++ classes that manage resources (such as dynamically allocated memory or file handles). It ensures that your class works correctly when objects are copied, assigned, and destroyed.

In the **Rule of Three** (pre-C++11), a class that manages resources should explicitly define three special member functions:
1. **Destructor**: Cleans up any allocated resources when the object is destroyed.
2. **Copy Constructor**: Initializes a new object as a copy of an existing one, ensuring proper resource management.
3. **Copy Assignment Operator**: Assigns one object to another, ensuring proper resource handling, especially when the objects are different.

With C++11 and later, the **Rule of Five** extends this idea to also include:
4. **Move Constructor**: Transfers ownership of resources from a temporary object to a new object.
5. **Move Assignment Operator**: Transfers ownership of resources from a temporary object to an existing object.

### Example: Implementing the Orthodox Canonical Form
```cpp
#include <iostream>
#include <cstring>

class MyClass {
private:
    char* data;
    
public:
    // Constructor
    MyClass(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Destructor
    ~MyClass() {
        delete[] data;
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other) return *this;  // Handle self-assignment

        delete[] data;  // Clean up existing resource

        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);

        return *this;
    }

    // Move Constructor (C++11)
    MyClass(MyClass&& other) noexcept {
        data = other.data;
        other.data = nullptr;
    }

    // Move Assignment Operator (C++11)
    MyClass& operator=(MyClass&& other) noexcept {
        if (this == &other) return *this;

        delete[] data;  // Clean up existing resource

        data = other.data;
        other.data = nullptr;

        return *this;
    }

    // Display data
    void display() const {
        std::cout << data << std::endl;
    }
};

int main() {
    MyClass a("Hello");
    MyClass

 b = a;    // Copy constructor
    MyClass c("World");
    c = a;             // Copy assignment operator

    a.display();
    b.display();
    c.display();
    
    MyClass d = std::move(a);  // Move constructor
    d.display();

    return 0;
}
```

### Key Points:
- **Destructor** ensures proper resource cleanup.
- **Copy Constructor** handles deep copies to avoid shallow copying issues.
- **Copy Assignment Operator** manages resource deallocation and copying of resources.
- **Move Constructor and Move Assignment** (C++11) help optimize resource management by transferring ownership of resources from temporary objects.

---

## Conclusion

This README covers essential C++ concepts such as **Polymorphism (Pointers vs. References)**, **Ad-hoc Polymorphism**, **Operator Overloading**, and the **Orthodox Canonical Class Form**, all of which are crucial for writing efficient, maintainable, and resource-safe C++ code. Understanding and applying these concepts will help you become proficient in managing objects and resources in C++ effectively.
