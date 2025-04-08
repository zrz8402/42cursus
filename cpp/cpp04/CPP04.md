# C++ Polymorphism, Abstract Class, and Interface (C++04)

## 1. **Polymorphism**

Polymorphism in C++ allows objects of different derived classes to be treated as objects of a common base class. It enables one interface to be used for different underlying forms (data types). Polymorphism can be achieved through **inheritance** and **virtual functions**.

### Types of Polymorphism in C++04

1. **Compile-time Polymorphism (Static Polymorphism)**:
   - **Function Overloading**: Multiple functions with the same name but different parameter types or numbers.
   - **Operator Overloading**: Custom behavior for operators like `+`, `-`, etc., for user-defined types.
   - Both of these are resolved by the compiler at compile-time.

2. **Runtime Polymorphism (Dynamic Polymorphism)**:
   - Achieved through **virtual functions** and **method overriding**.
   - The correct function is chosen at runtime based on the actual object type, even when accessed through a base class pointer or reference.

### Example of Runtime Polymorphism:

```cpp
#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual void draw() {  // Virtual function for runtime polymorphism
        cout << "Drawing a shape" << endl;
    }
};

// Derived class 1
class Circle : public Shape {
public:
    void draw() override {  // Overriding the base class method
        cout << "Drawing a circle" << endl;
    }
};

// Derived class 2
class Square : public Shape {
public:
    void draw() override {  // Overriding the base class method
        cout << "Drawing a square" << endl;
    }
};

int main() {
    Shape* shape;  // Base class pointer

    Circle circle;
    Square square;

    shape = &circle;
    shape->draw();  // Calls Circle's draw() method at runtime

    shape = &square;
    shape->draw();  // Calls Square's draw() method at runtime

    return 0;
}
```

In this example, we see **runtime polymorphism** in action. The `draw()` function is **virtual** in the base class `Shape`. When called through the base class pointer, the appropriate method (`Circle::draw()` or `Square::draw()`) is called based on the actual object type.

---

## 2. **Abstract Classes**

An **abstract class** is a class that contains at least one pure virtual function and cannot be instantiated. It is meant to be used as a base class for other classes that implement the pure virtual function.

### Characteristics:
- **Pure Virtual Function**: A function declared in the base class with `= 0` at the end of its declaration.
- Abstract classes provide a common interface for derived classes, which must implement the pure virtual functions.

### Example:

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;  // Makes Shape an abstract class
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square" << endl;
    }
};

int main() {
    // Shape shape; // Error: cannot instantiate an abstract class

    Shape* shape1 = new Circle();  // Valid: Circle is a concrete class
    Shape* shape2 = new Square();  // Valid: Square is a concrete class

    shape1->draw();  // Output: Drawing a circle
    shape2->draw();  // Output: Drawing a square

    delete shape1;
    delete shape2;

    return 0;
}
```

In this example, the class `Shape` has a pure virtual function `draw()`, which makes it **abstract**. We cannot create an instance of `Shape`, but we can create instances of its derived classes (`Circle` and `Square`), which implement the `draw()` method.

---

## 3. **Interfaces in C++04**

In C++, an **interface** is usually implemented as a class that contains only pure virtual functions. C++ doesn't have a specific keyword for "interface" like some other languages (e.g., Java). Instead, an interface is a class with only pure virtual functions and no data members or non-pure virtual functions.

### Characteristics:
- An **interface** in C++ is a class where all member functions are pure virtual functions.
- It defines a contract that derived classes must implement.
- It does not provide any implementation, only function signatures.

### Example:

```cpp
#include <iostream>
using namespace std;

// Interface for drawing
class Drawable {
public:
    virtual void draw() = 0;  // Pure virtual function
};

// Concrete class that implements the interface
class Circle : public Drawable {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Drawable {
public:
    void draw() override {
        cout << "Drawing a square" << endl;
    }
};

int main() {
    Drawable* shape1 = new Circle();
    Drawable* shape2 = new Square();

    shape1->draw();  // Output: Drawing a circle
    shape2->draw();  // Output: Drawing a square

    delete shape1;
    delete shape2;

    return 0;
}
```

In this example, `Drawable` acts as an **interface** in C++. It has a pure virtual method `draw()`, which must be implemented by any class that inherits from it (like `Circle` and `Square`).

### Key Differences Between Abstract Class and Interface:
- An **abstract class** can have both pure virtual functions and implemented methods, while an **interface** only contains pure virtual functions.
- An **abstract class** can have data members, but an **interface** does not typically contain data members or any implementation code.

---

## Conclusion

- **Polymorphism** allows for flexibility in how objects of different types can be treated via common base class references or pointers.
- **Abstract classes** allow you to define a common interface for derived classes while leaving some implementation details up to the derived classes.
- **Interfaces** in C++ are implemented as classes with only pure virtual functions, defining a contract that concrete classes must adhere to.

These concepts form the core of object-oriented design, enabling more flexible, maintainable, and scalable systems.
