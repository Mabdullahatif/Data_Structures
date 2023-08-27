/*
    Title: Stack Implementation using Linked List
    Description: This C++ program demonstrates the implementation of a stack data structure using linked list. It defines a class named "Stack" with methods for push, pop, and display operations. The stack is implemented as a singly linked list where each node holds an integer value and a pointer to the next node.

    Implementation Details:
    - The program defines a struct named "Node" to represent a node in the linked list. The Node struct has two members: 'data' to store the value and 'next' to store the pointer to the next node.
    - The class "Stack" has a private member 'top' which points to the top of the stack.
    - The class provides methods:
        - push(int val): Pushes a new element onto the stack by creating a new node and updating the 'top' pointer.
        - pop(): Pops an element from the top of the stack by removing the top node and updating the 'top' pointer.
        - display(): Displays the elements of the stack from top to bottom.
    - The destructor of the class is responsible for deallocating memory used by the linked list nodes.

    Usage:
    - The main function demonstrates the usage of the Stack class by pushing elements onto the stack, displaying the stack contents, and popping an element.

    Note:
    - The push operation is O(1) since it involves inserting a node at the beginning of the linked list.
    - The pop operation is also O(1) as it involves removing the first node from the linked list.
*/
#include <iostream>
using namespace std;

class Stack;
struct Node {
   friend class Stack;
   int data;
   Node *next;
};

class Stack {
private:
    Node* top = 0;
public:
    void push(int val) {
       Node* newnode = new Node;
       newnode->data = val;
       newnode->next = top;
       top = newnode;
    }

    bool pop() {
       if (top == 0) {
            return false;
       } else {
          Node* temp = top;
          top = top->next;
          delete temp;
          return true;
       }
    }

    bool display() {
        Node* ptr;
       if (top == 0) {
        return false;
       } else {
          ptr = top;
          cout << "Stack elements are: ";
          while (ptr != 0) {
             cout << ptr->data << " ";
             ptr = ptr->next;
          }
       }
       cout << endl;
       return true;
    }

    ~Stack() {
        while (top != 0) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack after pushing elements:" << endl;
    stack.display();

    stack.pop();

    cout << "Stack after popping an element:" << endl;
    stack.display();

    return 0;
}
