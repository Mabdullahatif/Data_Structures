/*
    Title: Balanced Parentheses Check using Stack
    Description: This C++ program implements a stack data structure to check whether a given string containing parentheses, curly braces, and square brackets has balanced parentheses. The program uses a stack to keep track of opening symbols and match them with their corresponding closing symbols. If the parentheses are balanced, it outputs "So It is balanced"; otherwise, it outputs "So It is not balanced".
    
    Implementation Details:
    - The program defines a class named "stack" to create a stack data structure using an array.
    - The stack supports basic operations like push, pop, top, and checks for full and empty conditions.
    - The class also includes a method "isbalanced" that takes a string as input and checks whether its parentheses are balanced or not.
    - The main function demonstrates the usage of the stack class.
    
    Steps in isbalanced Function:
    - Initialize an empty stack.
    - Traverse the given string character by character.
    - If the character is an opening symbol ('{', '[', or '('), push it onto the stack.
    - If the character is a closing symbol ('}', ']', or ')'), check if the top of the stack contains the corresponding opening symbol. If not, the parentheses are not balanced.
    - If the stack is empty or the top does not match, return false.
    - If the traversal is complete and the stack is empty, the parentheses are balanced; otherwise, they are not balanced.

    Usage:
    - The program creates a stack and pushes elements onto it.
    - It demonstrates popping elements, checking the top item, and checking balanced parentheses for two example strings.
*/
#include <iostream>
#include <string>
using namespace std;

class stack{
private:
	int maxsize;
	int currsize;
	int* arr;
	int top;
	
public:
	stack(int n=10){
		maxsize=n;
		currsize=0;
		top=-1;
		arr=new int[maxsize];
	}
	~stack(){
		if(arr!=0){
			delete[] arr;
		}
	}
	
	bool isfull(){
		if(currsize==maxsize){
			return 1;
		}
		return 0;
	}
	
	int size(){
		return currsize;
	}
	
	bool isempty(){
		if(currsize==0){
			return 1;
		}
		return 0;
	}
	
	bool Top(int& num){
		if(currsize==0){
			return false;
		}
		else{
			num=arr[top];
			return false;
		}
	}
	
    bool pop(){
        if(isempty()){
            return false;
        }
        else{
            top--;
            currsize--;
            return true;
        }
    }

    bool push(int n){
        if(isfull()){
            return false;
        }
        else{
            top++;
            arr[top]=n;
            currsize++;
            return true;
        }
    }
    
    bool isbalanced(string& element){
    	char cc='}';
    	char cs=']';
    	char cb=')';
    	stack s;
    	int c;
    	for(int i=0;element[i]!='\0';i++){
    		if(element[i]==cc || element[i]==cs || element[i]==cb){
    			s.Top(c);
    			s.pop();
    			if(c == '('){
    				c = cb;
				}
				else if(c == '['){
					c = cs;
				}
				else if(c == '{'){
					c = cc;
				}
				
				if(c != element[i])
    				return false;
			}
			
			else{
				s.push(element[i]);
			}
		}
		return true;
	}
    
    
};

int main(){
	cout<<"    IMPLEMENTING STACK    ";
	endl(cout);endl(cout);
	stack s;
	s.push(1);
	s.push(2);
    s.push(3);
	s.push(4);
	s.push(5);
	cout<<"Items entered in Stack as 1,2,3,4,5";endl(cout);endl(cout);
	
	int x;
	s.Top(x);
	cout<<"Top item will be : ";
	cout<<x;
	cout<<endl;endl(cout);
	s.pop();
	int y;
	cout<<"After popping one time top item will be : ";
	s.Top(y);
	cout<<y;endl(cout);endl(cout);
	cout<<"String Entered to check if balanced \"[{{}}] " ; endl(cout);
	string a="[{{}}]";
	cout<<s.isbalanced(a);
	if(s.isbalanced(a)){
		cout<<" : So It is balanced ";
	}
	else{
		cout<<" : So It is not balanced ";
	}
	
	
	endl(cout);endl(cout);
	cout<<"String Entered to check if balanced \"[{(}] " ; endl(cout);
	string b="[{(}]";
	cout<<s.isbalanced(b);
	if(s.isbalanced(b)){
		cout<<" : So It is balanced ";
	}
	else{
		cout<<" : So It is not balanced ";
	}
	endl(cout);
	return 0;
	
}

