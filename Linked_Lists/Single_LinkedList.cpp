/* 
Description:
	This C++ program demonstrates the implementation of a singly linked list class called 'LinkedList'. It includes various 
	functions for operations on a singly linked list, such as insertion at the start and end, deletion from the start and 
	end, searching for an element, sorted insertion, checking if the list is empty, finding the Nth term, and performing 
	the union of two linked lists. The program showcases the usage of these functions with sample operations.

Details:
	- The program defines two classes: 'Node' and 'LinkedList'.
	- 'Node' represents a node in the singly linked list, with data and 'next' pointer.
	- 'LinkedList' encapsulates the singly linked list and provides functions for list operations.
	- The main function demonstrates various operations on different instances of the 'LinkedList' class.

Operations Demonstrated:
	1. Insertion at the start, end, and sorted insertion.
	2. Deletion from the start and end.
	3. Searching for an element in the list.
	4. Checking if the list is empty.
	5. Finding the Nth term of the list.
	6. Performing the union of two linked lists.

	Note: This program showcases the basic functionality of a singly linked list and its operations.
*/
#include <iostream>
using namespace std;
class LinkedList;
class Node {
	friend class LinkedList;
	int data;
	Node* next;//end of class
};
class LinkedList{
private:
	Node* head;
public:
	LinkedList() {
		head = 0;
	}

	bool insertAtStart(int val) {
		Node* temp = new Node;
		temp->data = val;
		temp->next = head;
		head = temp;
		return 1;
	}//end of insertAtStart

	bool deleteFromStart() {
		if (head == 0) {
			return 0;
		}
		else {
			Node* curr = head;
			head = curr->next;
			//head=head->next;
			delete curr;
			return 1;
		}
	}//end of deleteFromStart

	void Display() {
		Node* curr = head;
		while (curr != 0) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}//end of Display

	bool insertAtEnd(int val) {
		Node* temp = new Node;
		temp->data = val;
		temp->next = 0;
		Node* prev = 0, *curr = head;
		while (curr != 0) {
			prev = curr;
			curr = curr->next;
		}
		//if element is first in list
		if (prev == 0) {
			head = temp;
			return 1;
		}
		else {
			prev->next = temp;
			return 1;
		}

	}//end of insertAtEnd

	bool deleteFromEnd(){
		if (head == 0) {
			cout << "List is empty \n ";
			return 0;
		}
		else
		{
			Node* curr = head, * last = 0, * secondLast = 0;
			while (curr != 0) {
				secondLast = last;
				last=curr;
				last = curr->next;
			}
			if (secondLast == 0) {
				head = NULL;
				delete last;
				last = 0;
				cout << "Last Block deleted \n";
				return 1;
			}
			else
			{
				secondLast->next = 0;
				delete last;
				last = 0;
				cout << "Last Block deleted \n";
				return 1;
			}
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
	bool SearchAnElement(int val){
		Node* curr=head;
		while(curr!=0){
			if(curr->data==val){
				return true;
				curr=curr->next;
			}	
		}
		return false;
	}
	bool isEmpty(){
     	if(head==0){
		    return true;
	 	}
		return false;
	}
	
	LinkedList Union(LinkedList a,LinkedList b){
		LinkedList c;
		Node* temp=a.head;
		while(temp!=0){
			if(!c.SearchAnElement(temp->data)){
				c.insertAtEnd(temp->data);
			}
			temp=temp->next;
		}
		temp=b.head;
		while(temp!=0){
			if(!c.SearchAnElement(temp->data)){
				c.insertAtEnd(temp->data);
			}
			temp=temp->next;
		}
	return c;
	}
bool sortedInsert(int val)
    {
        Node* temp = new Node;
        temp->data = val;
        Node* curr = head, *prev = 0;
        while (curr != NULL && curr->data<val)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == 0)
        {
            head = temp;
        }
        else
        {
            prev->next = temp;
        }
        temp->next = curr;
        //cout << "Element is inserted in Sorted Linked List...!\n";
        return 1;
    }
    int printnth(int index){
        Node* curr=head;   
	    int count=0;  
	    while (curr!=0)  {  
	        if(count==index)  
	            return(curr->data);  
	        count++;  
	        curr=curr->next;  
	    }  	
		return 0;
	}
};
void line(){
	cout<<"--------------------------------------------";
	cout<<endl;
}
int main() {
    LinkedList d;
    LinkedList d1;
    LinkedList d2;
    LinkedList d3;
    LinkedList d4;
    LinkedList d5;
    cout<<"         WORKING WITH SINGLY LINKED LIST        ";endl(cout);
    cout<<"                   1,2,3,4,5                    ";endl(cout);endl(cout);
    
    cout<<"Inserted At Start !! ";
    d.insertAtStart(1);
    d.insertAtStart(2);
	d.insertAtStart(3);
	d.insertAtStart(4);
	d.insertAtStart(5);
	d.Display();
	endl(cout);
	line();
	
    cout<<"Deleted from Start !! ";
    d1.insertAtStart(1);
    d1.insertAtStart(2);
	d1.insertAtStart(3);
	d1.insertAtStart(4);
	d1.insertAtStart(5);
	d1.deleteFromStart();
	d1.Display();
	endl(cout);
	line();
	
    cout<<"Inserted At end !! ";
    d2.insertAtEnd(1);
    d2.insertAtEnd(2);
	d2.insertAtEnd(3);
	d2.insertAtEnd(4);
	d2.insertAtEnd(5);
	d2.Display();
	endl(cout);
	line();
	
    cout<<"Delete At end !! ";
    d3.insertAtEnd(1);
    d3.insertAtEnd(2);
	d3.insertAtEnd(3);
	d3.insertAtEnd(4);
	d3.insertAtEnd(5);
//	d3.deleteFromEnd();
	d3.Display();
	endl(cout);
	line();
	
	cout<<"Sorted Insert !! ";
	d4.sortedInsert(1);
	d4.sortedInsert(3);
	d4.sortedInsert(4);
	d4.sortedInsert(5);
	d4.sortedInsert(2);
	d4.Display();
	cout<<endl;
	line();
	
	cout<<"Print Nth Term !! ";
	d5.sortedInsert(1);
	d5.sortedInsert(3);
	d5.sortedInsert(4);
	d5.sortedInsert(5);
	d5.sortedInsert(2);
	cout<<d5.printnth(0);
    return 0;
    
}

