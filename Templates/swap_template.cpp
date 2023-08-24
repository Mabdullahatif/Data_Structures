/*
    swap_template.cpp

    Description:
    This C++ program demonstrates the use of a templated swap function to interchange the values of different types of 
    variables. It swaps integer, float, and character variables and displays their values before and after swapping.

    What's happening in the code:
    1. The code includes the necessary header file.
    2. A template function 'swapit' is defined, which takes two references of a generic type 's'.
       - Inside the function, the values of 'a' and 'b' are swapped using a temporary variable 'temp'.
    3. The 'main' function is defined:
       - Integer 'i1' and 'i2', float 'f1' and 'f2', and character 'c1' and 'c2' variables are declared and initialized.
       - The values of these variables are displayed before swapping.
       - The 'swapit' function is called to swap the values of 'i1' and 'i2', 'f1' and 'f2', and 'c1' and 'c2'.
       - The values of the variables are displayed again after swapping.

    Note: The code uses the 'endl' manipulator to end lines, but the correct syntax should be '<< endl' instead of 
    'endl(cout)'.

*/

#include <iostream>
using namespace std;

template<class s>
void swapit(s &a, s &b) {
    s temp = a;
    a = b;
    b = temp;
}

int main() {
    int i1 = 6;
    int i2 = 3;
    float f1 = 7.2;
    float f2 = 4.5;
    char c1 = 'p';
    char c2 = 'x';
    
    cout << "before swapping" << endl;
    cout << "i1 : " << i1 << endl;
    cout << "i2 : " << i2 << endl;
    cout << endl;

    cout << "f1 : " << f1 << endl;
    cout << "f2 : " << f2 << endl;
    cout << endl;

    cout << "c1 : " << c1 << endl;
    cout << "c2 : " << c2 << endl;
    cout << endl;

    swapit(i1, i2);
    swapit(f1, f2);
    swapit(c1, c2);

    cout << "after swapping" << endl;
    cout << "i1 : " << i1 << endl;
    cout << "i2 : " << i2 << endl;
    cout << endl;

    cout << "f1 : " << f1 << endl;
    cout << "f2 : " << f2 << endl;
    cout << endl;

    cout << "c1 : " << c1 << endl;
    cout << "c2 : " << c2 << endl;
    cout << endl;

    return 0;
}
