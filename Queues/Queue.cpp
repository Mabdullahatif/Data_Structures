/*
    Queue Operations
    
    This program demonstrates the implementation of a basic queue data structure with various operations.
    
    The code defines a class named "Node" that represents a node in the queue. The class "Queue" contains
    methods to perform queue operations such as enqueue, dequeue, check if the queue is empty, and display
    the front and rear elements of the queue.
    
    The "Enqueue" operation adds an element to the rear of the queue. The "Dequeue" operation removes an
    element from the front of the queue. The "Front" operation retrieves the element at the front of the
    queue, and the "Rear" operation retrieves the element at the rear of the queue. Additionally, there's
    an "alterqueue" method that modifies the queue by interleaving its elements with another queue's
    elements.
    
    The "alterqueue" method takes another queue as an argument, and it interleaves the elements from both
    queues in an alternating fashion. It uses a temporary queue to hold half of the elements and then
    reorganizes them to create the interleaved effect.
    
    The "main" function initializes a queue, enqueues several elements, and demonstrates the "Front," "Rear,"
    and "alterqueue" operations. It displays the front and rear elements of the queue and the modified
    queue after applying the "alterqueue" method.
*/
#include <iostream>
using namespace std;
class Queue;
class Node{
    friend class Queue;
    int data;
    Node* next;

};
class Queue{
private:
    Node* front;
    Node* rear;
    int count;
public:
    Queue(){
        front=0;
        rear=0;
        count=1;
    }
    int counter(){ //used in enqueue function 
    	return count++;
	}
    
    ~Queue(){
    	while(front!=0){
    		Node* ptr=front;
    		front=front->next;
    		delete ptr;
		}
	}
    
    bool isEmpty(){
        if(front==0){
            return true;
        }
        return false;
    }
    int Front(){
    	Node *f =front;
    	//cout<< f->data;
    	return f->data;
	}
	
	int Rear(){
		Node *r = rear;
		//cout<< r->data;
		return r->data;
	}
    
    bool Enqueue(int val){ //insert at end
        Node* temp=new Node;
        temp->data=val;
        temp->next=0;
        if(rear==0){
            front=temp;
            rear=temp;
            return true;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
        counter();
    }

    bool Dequeue(){ // delete from end 
        if(isEmpty()){
            return false;
        }
        if(front==rear){
            delete rear;
            front=0;
            rear=0;
            return true;
        }
        else{
            Node* temp =front;
            front =front->next;
            delete temp;
            temp=0;
            return true;
        }
    }
    
    void alterqueue(Queue q){
    	Queue q1;
    	int size=counter();
    	int middle=q.counter()/2;
    	
    	for(int i=0;i<middle;i++){
    		q1.Enqueue(q.Front());
    		q.Dequeue();
		}
		
		for(int i=0;i<middle;i++){
			q.Enqueue(q1.Front());
			q.Enqueue(q.Front());
			q.Dequeue();
			q1.Dequeue();
		}
		
		
		for(int i=0;i<size;i++){
			cout<<q.Front()<<" ";
			q.Dequeue();
		}
	}

};

int main(){
	cout<<" IMPLEMENTING QUEUE  ";endl(cout);endl(cout);
	Queue q;
	q.Enqueue(3);
	q.Enqueue(2);
    q.Enqueue(5);
	q.Enqueue(6);
	q.Enqueue(7);
	q.Enqueue(9);
    q.Enqueue(8);
	q.Enqueue(4);
	cout<<"Displaying front of the queue : ";cout<<q.Front();
	endl(cout);endl(cout);
	cout<<"Displaying rear of the queue : ";cout<<q.Rear();
	//cout<<q.counter();
	endl(cout);endl(cout);
	cout<<"Displaying Alter of the queue : ";q.alterqueue(q);
	
	return 0;
}

