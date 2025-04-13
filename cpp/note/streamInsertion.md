### **Overloading the Stream Insertion Operator (`<<`) for Custom Output**

### Syntax Overview:
```cpp
std::ostream& operator<<(std::ostream& os, const YourClass &obj)
```

### Parameters:
- **`std::ostream& os`**: A reference to an output stream (e.g., `std::cout` or `std::ofstream`).
- **`const YourClass &obj`**: A constant reference to the object being output. It prevents modifying the original object.
