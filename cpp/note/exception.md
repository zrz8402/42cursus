We'll explore **3 methods** to define and implement the two exceptions:

---

## 🔷 Method 1: Inherit from `std::exception` (Basic, Hardcoded Messages)  
## 🔶 Method 2: Inherit from `std::exception`, Custom Message via Constructor  
## 🔸 Method 3: Inherit from `std::runtime_error` (Preferred)

---

## ✅ **Method 1: Basic - `std::exception`, Hardcoded Message**

### 📄 `GradeException.hpp`
```cpp
#ifndef GRADE_EXCEPTION_HPP
#define GRADE_EXCEPTION_HPP

#include <exception>

class GradeTooHighException : public std::exception {
public:
    const char* what() const noexcept override;
};

class GradeTooLowException : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif
```

### 📄 `GradeException.cpp`
```cpp
#include "GradeException.hpp"

const char* GradeTooHighException::what() const noexcept {
    return "Grade too high";
}

const char* GradeTooLowException::what() const noexcept {
    return "Grade too low";
}
```

---

## ✅ **Method 2: Custom Message - `std::exception` with std::string**

### 📄 `GradeException.hpp`
```cpp
#ifndef GRADE_EXCEPTION_HPP
#define GRADE_EXCEPTION_HPP

#include <exception>
#include <string>

class GradeTooHighException : public std::exception {
private:
    std::string message;
public:
    GradeTooHighException(const std::string& msg);
    const char* what() const noexcept override;
};

class GradeTooLowException : public std::exception {
private:
    std::string message;
public:
    GradeTooLowException(const std::string& msg);
    const char* what() const noexcept override;
};

#endif
```

### 📄 `GradeException.cpp`
```cpp
#include "GradeException.hpp"

GradeTooHighException::GradeTooHighException(const std::string& msg)
    : message(msg) {}

const char* GradeTooHighException::what() const noexcept {
    return message.c_str();
}

GradeTooLowException::GradeTooLowException(const std::string& msg)
    : message(msg) {}

const char* GradeTooLowException::what() const noexcept {
    return message.c_str();
}
```

---

## ✅ **Method 3: Use `std::runtime_error` (Most Clean & STL-Friendly)**

### 📄 `GradeException.hpp`
```cpp
#ifndef GRADE_EXCEPTION_HPP
#define GRADE_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class GradeTooHighException : public std::runtime_error {
public:
    explicit GradeTooHighException(const std::string& msg = "Grade too high");
};

class GradeTooLowException : public std::runtime_error {
public:
    explicit GradeTooLowException(const std::string& msg = "Grade too low");
};

#endif
```

### 📄 `GradeException.cpp`
```cpp
#include "GradeException.hpp"

GradeTooHighException::GradeTooHighException(const std::string& msg)
    : std::runtime_error(msg) {}

GradeTooLowException::GradeTooLowException(const std::string& msg)
    : std::runtime_error(msg) {}
```

---

## 🧪 Usage Example (`main.cpp`)
```cpp
#include <iostream>
#include "GradeException.hpp"

void checkGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException("Grade is too high (must be >= 1)");
    else if (grade > 100)
        throw GradeTooLowException("Grade is too low (must be <= 100)");
    else
        std::cout << "Grade is valid: " << grade << std::endl;
}

int main() {
    try {
        checkGrade(120);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
```

---

## ✅ Summary Table

| Method | Custom Message? | STL-based? | Clean Separation | Suggested |
|--------|-----------------|------------|------------------|-----------|
| 1. Basic `std::exception` | ❌ No       | ✅ Yes         | ✅ Yes           | 👌 OK for static errors |
| 2. Manual `std::exception` | ✅ Yes     | ✅ Yes         | ✅ Yes           | 👍 Good if you need full control |
| 3. `std::runtime_error` | ✅ Yes       | ✅ Yes         | ✅ Yes           | 🏆 Best choice for your case |

---


Of course! Here's a clear and concise **note** you can use in your study materials or classwork:

---

### 📌 **Note: Understanding `catch (const std::exception& e)` in C++**

```cpp
try {
    // Code that might throw an exception
}
catch (/* exception type */ /* variable name */) {
    // Code to handle the exception
}
```


- The `catch` block is used to handle exceptions that are thrown inside a preceding `try` block.
  
- `std::exception` is the **base class** for all standard exceptions in C++. By catching this type, you can handle many kinds of standard exceptions (e.g., `runtime_error`, `invalid_argument`, etc.).

- `const` means the exception object should **not be modified** inside the catch block — it’s read-only.

- The `&` symbol indicates that the exception is caught **by reference**, which:
  - Avoids copying the exception object.
  - Preserves the **polymorphic behavior**, so calling `e.what()` will return the correct message for derived exception types.

- `e` is simply the **name of the exception variable**. You use it to refer to the caught exception inside the block. It could be named anything (like `ex`, `err`, or `banana`), but `e` is a common convention.

- You can access the error message using `e.what()`.

---

### ✅ Example:

```cpp
try {
    throw std::runtime_error("Invalid operation!");
}
catch (const std::exception& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
}
```

**Output:**
```
Exception caught: Invalid operation!
```

---