/* 
Description:
	This C++ program demonstrates the implementation of a singly linked list class called 'LinkedList'. It includes functions 
	for insertion at the start and displaying the list. The program also includes a function to check if the linked list is 
	a palindrome or not. The main function showcases the usage of these functions with a sample operation.

Details:
	- The program defines two classes: 'Node' and 'LinkedList'.
	- 'Node' represents a node in the singly linked list, with data and 'next' pointers.
	- 'LinkedList' encapsulates the singly linked list and provides functions for list operations.
	- The 'isPalindrome' function checks whether the linked list is a palindrome.
	- The main function demonstrates the insertion of a string into the linked list and checks whether it is a palindrome or not.

	Note: This program showcases a simple palindrome check for a linked list.
*/
#include <iostream>
using namespace std;
class LinkedList;
class Node {
	friend class LinkedList;
	string data;
	Node* next;//end of class
};
class LinkedList{
private:
	Node* head;
public:
	LinkedList() {
		head = 0;
	}

	bool insertAtStart(string val) {
		Node* temp = new Node;
		temp->data = val;
		temp->next = head;
		head = temp;
		return 1;
	}

	void Display() {
		Node* curr = head;
		while (curr != 0) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}

	~LinkedList() {
		while (head!=0) {
			Node* curr = head;
			head = curr->next;
			delete curr;
			curr = head;
		}
	}

    bool isPlalindrome(){
      Node* curr = head;
      string str = "";
      while(curr){
        str+=curr->data;
        curr = curr->next;
      }
      int n=str.size();
      for(int i=0;i<n/2;i++){
        if(str[i]!=str[n-i-1]){
          return false;
        }
      }
      return true;
    }
};
int main() {
    LinkedList l,l2;
    l.insertAtStart("madam");
    if(l.isPlalindrome()){
        cout<<"Node is palindrome";
    }
    else{
        cout<<"Node is not palindrome";
    }

    return 0;

}
