/*
    Description:
    This C++ program performs basic arithmetic operations on two operands based on user input. It provides a template 
	function to perform operations like addition, subtraction, multiplication, and division.

    What's happening in the code:
    1. The code includes the necessary header files and declares the namespace std for standard C++ functionality.
    2. A template function named 'performOperation' is defined, which takes two operands of a generic type 'Variable', 
	along with an operation character 'op'.
    3. Inside the 'performOperation' function:
       - The switch statement is used to evaluate the operation character 'op'.
       - Depending on the operation, the code performs the appropriate arithmetic operation on the operands and displays 
	   the result.
    4. The 'main' function is defined:
       - It declares variables 'a' and 'b' of type double to store the operands and a variable 'op' of type char to store 
	   the operation character.
       - The user is prompted to input the values of 'a', 'b', and 'op'.
       - An if statement checks whether 'op' corresponds to a valid arithmetic operation ('*', '+', '-', or '/').
       - If the operation is valid, the 'performOperation' function is called with 'a', 'b', and 'op' as arguments.
       - If the operation is not valid, the code outputs an error message.
    5. The 'main' function returns 0 to indicate successful program execution.

    Note: This code assumes that the user will enter valid inputs and doesn't handle division by zero.

*/
using namespace std;
#include <iostream>

template<class Variable> 
 void performOperation(Variable a,Variable b,char op){
	switch(op){
		case '*':
			cout<<"answer is : "<<a*b;
			break;
		case '+':
			cout<<"answer is : "<<a+b;
			break;
		case '-':
			cout<<"answer is : "<<a-b;
			break;
		case '/':
			cout<<"answer is : "<<a/b;
			break;
	}		
}

int main( ){
	double a,b;char op;
	cout <<"Enter first operand : ";cin>>a;
	cout<<"Enter second operand : ";cin>>b;
	cout<<"Enter operation : ";cin>>op;
	if (op == '*' || op == '+' || op == '-' || op == '/'){
		performOperation(a, b, op);
	}
	else{
		cout<<"Wrong operation";
	}
	return 0;
}



