/*
    Description:
    This C++ program defines a templated matrix class that can allocate memory, input values, rotate elements, and output
    the contents of a matrix. It allows the user to input a matrix, rotate it in a circular manner, and then display the rotated matrix.

    What's happening in the code:
    1. The code includes the necessary header files.
    2. A templated class 'matrix' is defined:
       - It has private member variables 'rows' and 'cols' to store matrix dimensions.
       - Public methods include constructors, accessor and mutator methods for dimensions, memory allocation, input, 
       rotation, and output of a matrix.
    3. The 'main' function is defined:
       - It prompts the user to input the number of rows and columns for the matrix.
       - An instance of the 'matrix' class is created using integer type.
       - Memory is allocated for the matrix using the 'AllocateMemory' method.
       - User inputs values for the matrix using the 'input' method.
       - The matrix is rotated in a circular manner using the 'Rotate' method.
       - The rotated matrix is displayed using the 'output' method.

    Note: This code assumes valid inputs for matrix dimensions and doesn't handle exceptions.

*/

#include <iostream>
using namespace std;

template <typename T>
class matrix {
private:
    int rows, cols;
    
public:
    matrix() : rows(0), cols(0) {}
    matrix(int r, int c) : rows(r), cols(c) {}
    
    int getRow() const {
        return rows;
    }
    
    int getCol() const {
        return cols;
    }
    
    void setRow(int R) {
        rows = R;
    }
    
    void setCol(int C) {
        cols = C;
    }
    
    T** AllocateMemory(int R, int C) {
        T** mat = new T*[R];
        for (int i = 0; i < R; i++) {
            mat[i] = new T[C];
        }
        return mat;
    }
    
    void input(T** mat, int R, int C) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> mat[i][j];
            }
        }
    }
    
    T** Rotate(T** ptr, int size) {
        T p = ptr[0][0];
        T c;
        
        int i = 1;
        while (i < size) {
            c = ptr[i][0];
            ptr[i++][0] = p;
            p = c;
        }
        
        i = 1;
        while (i < size) {
            c = ptr[size - 1][i];
            ptr[size - 1][i++] = p;
            p = c;
        }
        
        i = size - 2;
        while (i >= 0) {
            c = ptr[i][size - 1];
            ptr[i--][size - 1] = p;
            p = c;
        }
        
        i = size - 2;
        while (i >= 0) {
            c = ptr[0][i];
            ptr[0][i--] = p;
            p = c;
        }
        return ptr;
    }
    
    void output(T** mat, int R, int C) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int r, c;
    cout << "Enter number of rows : ";
    cin >> r;
    cout << "Enter number of columns : ";
    cin >> c;

    matrix<int> mat(r, c);
    int** mat2 = mat.AllocateMemory(r, c);
    mat.input(mat2, r, c);
    mat.Rotate(mat2, r);
    mat.output(mat2, r, c);

    return 0;
}
