/*
    Description:
    This C++ program showcases the use of templated classes and file input/output to manage student data. It defines a 
    'Student' class that holds information about a student's roll number, name, and CGPA. The program then writes a 
    student's data to a file, reads it back, and displays the contents.

    What's happening in the code:
    1. The code includes necessary header files.
    2. A templated class 'Student' is defined:
       - It has private member variables 'rollno', 'name', and 'cgpa'.
       - Public methods include constructors, setter and getter methods, and a friend '<<' operator to output student data.
    3. The 'main' function is defined:
       - An instance of 'Student' class is created using a float type.
       - The program writes the student data to a file named "students.txt" using the 'ofstream' class.
       - If the write operation is successful, a success message is displayed; otherwise, an error message is shown.
       - The program then reads and displays the contents of the "students.txt" file using the 'ifstream' class.
       - If the read operation is successful, the contents are displayed; otherwise, an error message is shown.

    Note: This code demonstrates the use of templated classes, file I/O, and operator overloading for output.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
class Student {
private:
    int rollno;
    string name;
    T cgpa;

public:
    Student() : rollno(0), name(""), cgpa(0) {}
    Student(int r, string n, T c) : rollno(r), name(n), cgpa(c) {}

    void setrollno(int r) {
        rollno = r;
    }
    void setname(string n) {
        name = n;
    }
    void setcgpa(T c) {
        cgpa = c;
    }

    int getrollno() const {
        return rollno;
    }

    string getname() const {
        return name;
    }

    T getcgpa() const {
        return cgpa;
    }

    friend ostream& operator<<(ostream& out, const Student<T>& s) {
        out << "Roll-No of the Student is: " << s.rollno << endl;
        out << "Name of the Student is: " << s.name << endl;
        out << "Cgpa of the Student is: " << s.cgpa << endl;
        return out;
    }
};

int main() {
    Student<float> s(1, "ali", 3.3);

    ofstream outfile("students.txt");
    if (outfile.is_open()) {
        outfile << s;  // Write student data to the file
        outfile.close();
        cout << "File written successfully!" << endl;
    } else {
        cout << "Couldn't open file for writing" << endl;
    }

    ifstream myfile("students.txt");
    if (myfile.is_open()) {
        cout << "File opened successfully!" << endl;
        string myline;
        while (getline(myfile, myline)) {
            cout << myline << '\n';
        }
        myfile.close();
    } else {
        cout << "Couldn't open file for reading" << endl;
    }

    return 0;
}
