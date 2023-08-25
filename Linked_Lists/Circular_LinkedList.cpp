/* 
Description:
  This C++ program demonstrates the implementation of a circular doubly linked list class called 'circularlinklist'. 
  It includes functions for insertion at the start and end, and deletion from the start and end of the circular linked 
  list. The program also showcases the usage of these functions with sample operations.

Details:
  - The program defines two classes: 'Node' and 'circularlinklist'.
  - 'Node' represents a node in the circular doubly linked list, with data, 'next', and 'prev' pointers.
  - 'circularlinklist' encapsulates the circular doubly linked list and provides functions for list operations.
  - The main function demonstrates various operations on an instance of the 'circularlinklist' class.

Operations Demonstrated:
  1. Insertion at the start and end of the circular doubly linked list.
  2. Deletion from the start and end of the circular doubly linked list.

  Note: This program showcases basic functionality of a circular doubly linked list and its operations.
*/
#include <iostream>
using namespace std;
//template<class T>// in case have to implement
class circularlinklist;//doubly class definition
class Node{// node class implementation
    friend circularlinklist;
    int data;
    Node* next,*prev;
};// end of node class


class circularlinklist{//doubly class implementation
private:
    Node* head;
public:
    circularlinklist(){//default constructor
		head = 0;
	}// end of constructor
	
    void insertatstart(int value) {
      Node* temp=new Node;
      temp->data=value;
      temp->next=temp->prev=0; 
      if(head==0) {
        head=temp;
        temp->next=temp->prev=head;
      }else{
        Node* curr=head;
        while(curr->next!=head){
          curr=curr->next;
		}
        curr->next=temp;
        temp->prev=curr;
        temp->next=head;
        head->prev=temp;
        head=temp;
      }    
    }

    void PrintList() {
      Node* curr=head;
      bool check=true;
      if(curr!=0) {
      	cout<<endl;
        cout<<"The list has these to display : ";
        while(check){
          cout<<curr->data<<" ";
          curr=curr->next;
          if(curr==head) 
            break;
        }
        cout<<endl;
      } 
	  else{
        cout<<"The list has nothing to display !";
      }
    }  
    
 void insertatend(int value){
      Node* temp=new Node;
      temp->data=value;
      temp->next=temp->prev=0; 
      if(head==NULL) {
        head=temp;
        temp->next=temp->prev=head;
      }else{
        Node* curr=head;
        while(curr->next!=head){
        	curr=curr->next;
		}
        curr->next=temp;
        temp->next=head;
        temp->prev=curr;
        head->prev=temp;
      }    
    }
	
void deletefromstart() {
    if (head != 0) {
        if (head->next == head) {
            head = 0;
        } else {
            Node* curr = head;
            Node* temp = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            head = head->next;
            head->prev = curr;
            curr->next = head;
            delete temp;
            temp = nullptr; // Set temp to nullptr after deletion
        }
    }
}

void deletefromend() {
    if (head != 0) {
        if (head->next == head) {
            head = 0;
        } else {
            Node* curr = head;
            while (curr->next->next != head) {
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = head;
            head->prev = curr;
            delete temp;
            temp = nullptr; // Set temp to nullptr after deletion
        }
    }
}
};
void line(){
	cout<<"--------------------------------------------";
	cout<<endl;
}
//what if we want to make a circular singly or circular doubly linked list?
// curr->prev->head;
int main(){
	circularlinklist c;
    circularlinklist c1;
    circularlinklist c2;
    circularlinklist c3;
    circularlinklist c4;
    circularlinklist c5;
    cout<<"        WORKING WITH CIRCULAR LINKED LIST       ";endl(cout);
    cout<<"                   1,2,3,4,5                    ";endl(cout);endl(cout);
    
    cout<<"Inserted At Start !! ";
    c.insertatstart(1);
    c.insertatstart(2);
	c.insertatstart(3);
	c.insertatstart(4);
	c.insertatstart(5);
	c.PrintList();
	endl(cout);
	line();
	
    cout<<"Deleted from Start !! ";
    c1.insertatstart(1);
    c1.insertatstart(2);
	c1.insertatstart(3);
	c1.insertatstart(4);
	c1.insertatstart(5);
	c1.deletefromstart();
	c1.PrintList();
	endl(cout);
	line();
	
    cout<<"Inserted At end !! ";
    c2.insertatend(1);
    c2.insertatend(2);
	c2.insertatend(3);
	c2.insertatend(4);
	c2.insertatend(5);
	c2.PrintList();
	endl(cout);
	line();
	
    cout<<"Deleted from End !! ";
    c3.insertatend(1);
    c3.insertatend(2);
	c3.insertatend(3);
	c3.insertatend(4);
	c3.insertatend(5);
	c3.deletefromend();
	c3.PrintList();
	endl(cout);
	
    return 0;
}
