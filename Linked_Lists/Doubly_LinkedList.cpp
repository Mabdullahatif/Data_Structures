/* 
Description:
	This C++ program demonstrates the implementation of a doubly linked list class called 'doublylinklist'. It includes 
	functions for various operations on the doubly linked list, such as insertion at the start and end, deletion from the 
	start and end, searching for an element, sorted insertion, and deletion of a specific value. The program also showcases 
	the usage of the 'doublylinklist' class with sample operations.

Details:
	- The program defines three classes: 'Node', 'doublylinklist', and the 'main' function.
	- 'Node' represents a node in the doubly linked list, with data, 'next', and 'prev' pointers.
	- 'doublylinklist' encapsulates the doubly linked list and provides functions for list operations.
	- The main function demonstrates various operations on different instances of the 'doublylinklist' class.

Operations Demonstrated:
	1. Insertion at the start and end of the list.
	2. Deletion from the start and end of the list.
	3. Searching for an element in the list.
	4. Sorted insertion of elements.
	5. Deletion of a specific value.
	6. Reversed display of the list.

	Note: This program showcases the basic functionality of a doubly linked list and its operations.
*/
#include <iostream>
using namespace std;
//template<class T>// in case have to implement
class doublylinklist;//doubly class definition
class Node{// node class implementation
    friend doublylinklist;
    int data;
    Node* next,*prev;
};// end of node class


class doublylinklist{//doubly class implementation
private:
    Node* head;
public:
    doublylinklist(){//default constructor
		head = 0;
	}// end of constructor
	
	
    bool insertatstart(int val){//insert at start function
      Node* temp=new Node;//new node for storing
      temp->data=val;
      temp->next=0;
      temp->prev=0; 
      if(head==0) {// condition check
        head=temp;
        return 1;
      } 
	  else{//implementation
        head->prev=temp;
        temp->next=head;
        head=temp;
        head->prev=0;
        return 1;
      }    
    }// end of insert at end function
    
    
    bool insertatend(int val){// insert at end fucntion
      Node* temp=new Node;// new node for storing
      temp->data=val;
      temp->next=0;
      temp->prev=0; 
      if(head==0) {//condition check
        head=temp;
        return 1;
      }
	  else{//implementation
        Node* curr=head;
        while(curr->next!=0)
          curr=curr->next;
        curr->next =temp;
        temp->prev =curr;
        return 1;
      }    
    }// end of insert at end fucntion
    
    
	bool deletefromstart(){//delete from start fucntion
		if(head==0){//condition check
			cout << "The list has nothing to delete ! \n";
			return 0;
		}
		else{//implementation
			Node* curr = head;
			head=curr->next;
			//head=head->next;
			//cout<<"Deleted from Start ! \n";
			delete curr;
			curr=0;
			return 1;
		}
	}//end of deleteFromStart
	
	
    bool deletefromend(){// delete from end function
		if(head==0) {//condition check
			cout<<"The list has nothing to delete ! \n";
			return 0;
		}
		else{//implementation
		Node* temp=head;
          while(temp->next->next!=0){
            temp=temp->next;
		  }
          Node* temp2=temp->next;
          temp->next=0;
          //cout<<"Deleted from Start ! \n";
          delete temp2;
		  temp2=0;
		  return 1; 
		}	
    }//end of delete from end function
    
    
    void display(){//display fucntion
      Node* curr = head;
      if(curr!=0) {//condtion check
      cout<<endl;
        cout<<"The list has these to display : ";
        //cout<<endl;
        while(curr!=0) {//implementation
          cout<<curr->data<<", ";// same like singly link list
          curr = curr->next;
        }
        cout<<endl;
      } else {//implementation
        cout<<"The list has nothing to display !";
      }
    }
    Node* search(int val){//search function
		Node* curr=head;
		if(head==0){//condition check
		//	cout<<"List is empty nothing to search !\n";
		}
		else{//implementation
		  while(curr!=0){
			if(curr->data==val){//true/yes/exists check
			//cout<<"\nYes, it Exists ! ";
				break;
			}	
			curr=curr->next;
	      }//false/no/don't exists check
		}
		return curr;
	}//end of search fucntion
	
	
    ~doublylinklist(){//destructor
		while(head!=0) {//implementation same like singly link list 
			Node* curr = head;
			head = curr->next;
			delete curr;
			curr = head;
		}
	}//end of destructor
	
	
    bool sortedinsert(int val){//sorted insert fucntion
    	Node* temp= new Node;// new node for storing
    	temp->data=val;
    	temp->next=0;
    	temp->prev=0;
    	if(head==0){//condition check
    		head=temp;
    		temp->prev=0;
    		temp->next=0;
    		return true;
		}
		Node* prev=0;
		Node* curr=head;
		while(curr!=0 && curr->data<val){//implementation if going at end
			prev=curr;
			curr=curr->next;
		}
		if(prev==0){//implementation if going at start
			temp->next=curr;
			curr->prev=temp;
			head=temp;
			temp->prev=0;
		}
		else{//implementation if going at Middle
			temp->next=curr;
			temp->prev=prev;
			prev->next=temp;
			if(curr!=0){
				curr->prev=temp;
			}
		}
		return true;
	}//end of sorted insert function
	
	
    bool deletespecifivalue(int val){//delete specific value fucntion
    	if(head==0){//condition check
    		return false;
		}
		Node* temp=search(val);
		if(temp!=0){
			if(temp->next==0){//implementation if deleting from end
				temp->prev->next=0;
			}
			else if(temp->prev==0){//implementation if deleting from start
				temp->next->prev=0;
				head=temp->next;
			}
			else{//implementation if deleting from middle
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
			}
			delete temp;
			temp=0;
			return true;
		}	
	}

    void reversedisplay(){//display fucntion
      Node* curr = head;
      if(curr!=0) {//condtion check
      cout<<endl;
        cout<<"The list has these to display : ";
        //cout<<endl;
        while(curr->next!=0) {//implementation
          //cout<<curr->data<<", ";// same like singly link list
          curr = curr->next;
        }
        while(curr!=0){
        	cout<<curr->data<<", ";
        	curr=curr->prev;
			
		}
        cout<<endl;
      } 
	  else {//implementation
        cout<<"The list has nothing to display !";
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
    doublylinklist d;
    doublylinklist d1;
    doublylinklist d2;
    doublylinklist d3;
    doublylinklist d4;
    doublylinklist d5;
    cout<<"         WORKING WITH DOUBLY LINKED LIST        ";endl(cout);
    cout<<"                   1,2,3,4,5                    ";endl(cout);endl(cout);
    
    cout<<"Inserted At Start !! ";
    d.insertatstart(1);
    d.insertatstart(2);
	d.insertatstart(3);
	d.insertatstart(4);
	d.insertatstart(5);
	d.display();
	endl(cout);
	line();
	
    cout<<"Deleted from Start !! ";
    d1.insertatstart(1);
    d1.insertatstart(2);
	d1.insertatstart(3);
	d1.insertatstart(4);
	d1.insertatstart(5);
	d1.deletefromstart();
	d1.display();
	endl(cout);
	line();
	
    cout<<"Inserted At end !! ";
    d2.insertatend(1);
    d2.insertatend(2);
	d2.insertatend(3);
	d2.insertatend(4);
	d2.insertatend(5);
	d2.display();
	endl(cout);
	line();
	
    cout<<"Deleted from End !! ";
    d3.insertatend(1);
    d3.insertatend(2);
	d3.insertatend(3);
	d3.insertatend(4);
	d3.insertatend(5);
	d3.deletefromend();
	d3.display();
	endl(cout);
	line();

	cout<<"Searching and Insert Sorting !! ";
    d4.sortedinsert(2);
    d4.sortedinsert(5);
	d4.sortedinsert(3);
	d4.sortedinsert(1);
	d4.sortedinsert(4);
	cout<<endl;
	cout<<"                                -Searched (1)  ";
	if(d4.search(1)){
		endl(cout);
		cout<<"Searched Element Exists in this list !!";
	}
	else{
		endl(cout);
		cout<<"Searched Element Doesn't Exists in this list !!";
	}
	d4.display();
	cout<<endl;
	cout<<"                                -Searched (7)  ";
	if(d4.search(7)){
		endl(cout);
		cout<<"Searched Element Exists in this list !!";
	}
	else{
		endl(cout);
		cout<<"Searched Element Doesn't Exists in this list !!";
	}
	d4.display();
	endl(cout);
	line();
	
	cout<<"Deleting Specific Value !!      -Deleted (5)";
    d5.sortedinsert(2);
    d5.sortedinsert(5);
	d5.sortedinsert(3);
	d5.sortedinsert(1);
	d5.sortedinsert(4);
	d5.deletespecifivalue(5);
	d5.display();
	endl(cout);
	line();
	cout<<"Reverse Display !! -Entered 5,4,3,2,1";
	doublylinklist d6;
	d6.insertatstart(1);
	d6.insertatstart(2);
	d6.insertatstart(3);
	d6.insertatstart(4);
	d6.insertatstart(5);
	d6.reversedisplay();
	
	
    return 0;
}


