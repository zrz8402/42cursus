#include <iostream>
#include <string>

class MyClass {
public:
    void greet() {
        std::cout << "Hello from MyClass!" << std::endl;
    }

    int getValue() {
        return 42; // Returns an integer
    }

    void display(int value) {
        std::cout << "Value: " << value << std::endl;
    }

    void farewell() {
        std::cout << "Goodbye from MyClass!" << std::endl;
    }
};

int main() {
    MyClass obj;

	std::cout << "Calling functions using array of pointers to member functions:" << std::endl;
    // Case 1: Pointer to member function with no parameters and void return type
    void (MyClass::*ptrToGreet)() = &MyClass::greet;
    (obj.*ptrToGreet)();

    // Case 2: Pointer to member function with no parameters and int return type
    int (MyClass::*ptrToGetValue)() = &MyClass::getValue;
    int value = (obj.*ptrToGetValue)();
    std::cout << "Returned value: " << value << std::endl;

    // Case 3: Pointer to member function with one parameter
    void (MyClass::*ptrToDisplay)(int) = &MyClass::display;
    (obj.*ptrToDisplay)(10);

    // Case 4: Array of pointers to member functions (different functions)
    void (MyClass::*funcArray[])() = { &MyClass::greet, &MyClass::farewell };
    for (auto func : funcArray) {
        (obj.*func)();
    }
	// auto: introduced in C++11


	std::cout << "\nCalling functions directly:" << std::endl;
    // Case 1: Direct call to member function with no parameters and void return type
    obj.greet();

    // Case 2: Direct call to member function with no parameters and int return type
    value = obj.getValue();
    std::cout << "Returned value: " << value << std::endl; // Output: 42

    // Case 3: Direct call to member function with one parameter
    obj.display(10);

    // Case 4: Direct calls to different functions
    obj.greet();
    obj.farewell();

    return 0;
}
