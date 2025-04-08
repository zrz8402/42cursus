#include <iostream>

class Shape {
public:
    double area;
    double perimeter;

    Shape(double a, double p) : area(a), perimeter(p) {}
};

void printArea(Shape& shape, double Shape::*ptrToMember) {
    std::cout << "The value of the member variable is: " << shape.*ptrToMember << std::endl;
}

void printArea1(double value) {
    std::cout << "Directly received value: " << value << std::endl;
}

void printArea2(Shape& shape) {
    std::cout << "Accessing area using the object directly: Area = " << shape.area << std::endl;
}

void printPerimeter2(Shape& shape) {
    std::cout << "Accessing perimeter using the object directly: Perimeter = " << shape.perimeter << std::endl;
}

int main() {
    Shape triangle(10.0, 30.0);
    Shape rectangle(20.0, 40.0);

    double Shape::*ptrToArea = &Shape::area;
    double Shape::*ptrToPerimeter = &Shape::perimeter;

    std::cout << "Using pointers to member variables:" << std::endl;
    printArea(triangle, ptrToArea);
    printArea(triangle, ptrToPerimeter);
    printArea(rectangle, ptrToArea);
    printArea(rectangle, ptrToPerimeter);

    std::cout << "\nUsing direct member variable access:" << std::endl;
    printArea1(triangle.area);
    printArea1(triangle.perimeter);
    printArea1(rectangle.area);
    printArea1(rectangle.perimeter);

    std::cout << "\nUsing direct object access methods:" << std::endl;
    printArea2(triangle);
    printPerimeter2(triangle);
    printArea2(rectangle);
    printPerimeter2(rectangle);

    return 0;
}
