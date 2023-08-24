/*
    Description:
    This C++ program demonstrates the use of templated classes to create a generic Rectangle class that can calculate the area and perimeter of rectangles using different numeric types.

    What's happening in the code:
    1. The code includes the necessary header file.
    2. A templated class 'Shape' is defined:
       - It has private member variables 'length' and 'width' of type 'T'.
       - Public methods include constructors, accessor and mutator methods for length and width.
    3. Another templated class 'Rectangle' is defined:
       - It has private member variables 'Length', 'Width', 'Area', and 'Perimeter' of type 'T', and an instance of the 'Shape' class.
       - Public methods include constructors, mutator methods for length and width, methods to calculate area and perimeter.
    4. The 'main' function is defined:
       - Two instances of the 'Rectangle' class are created using double type.
       - The 'calculateArea' method is called on one instance to calculate and display the area.
       - The 'calculatePerimeter' method is called on the other instance to calculate and display the perimeter.

    Note: This code showcases the use of templated classes for generic functionality.
*/
#include<iostream>
using namespace std;

template <typename T>
class Shape {
private:
    T length;
    T width;
public:
    Shape(T l, T w) : length(l), width(w) {}
    
    T getLength() const {
        return length;
    }
    
    T getWidth() const {
        return width;
    }
    
    void setLength(T l) {
        length = l;
    }
    
    void setWidth(T w) {
        width = w;
    }
};

template <typename T>
class Rectangle {
private:
    T Length;
    T Width;
    T Area;
    T Perimeter;
    Shape<T> s;
public:
    Rectangle(T a, T p) : s(a, p), Length(a), Width(p) {}
    
    void setLength(T l) {
        Length = l;
    }
    
    void setWidth(T w) {
        Width = w;
    }
    
    void calculateArea() {
        Area = Length * Width;
        cout << "Area is: " << Area;
    }
    
    void calculatePerimeter() {
        Perimeter = 2 * (Length + Width);
        cout << "Perimeter is: " << Perimeter;
    }
};

int main() {
    Rectangle<double> rect(4.5, 5.2);
    Rectangle<double> rect2(4.5, 5.2);

    rect.calculateArea();
    cout << endl;

    rect2.calculatePerimeter();
    cout << endl;

    return 0;
}
