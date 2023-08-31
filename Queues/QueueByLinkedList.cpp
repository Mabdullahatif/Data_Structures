/*
    Simple Queue Implementation
    
    This program demonstrates a basic implementation of a queue using C++ classes.
    
    The class "Queue" represents a simple queue data structure. It consists of nodes linked
    together to form a queue. The nodes are defined by the "Node" class, which contains an
    integer data and a pointer to the next node.
    
    The "Queue" class provides basic queue operations such as enqueue (insertion at the rear)
    and dequeue (removal from the front). It maintains pointers to the front and rear nodes
    of the queue.
    
    The "main" function does not exist in this code as it only provides the class definitions
    and member function implementations for the "Node" and "Queue" classes.
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
public:
    Queue(){
        front=0;
        rear=0;
    }
    ~Queue();
    bool isEmpty();
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


};

int main() {
    Queue myQueue;

    // Enqueue some values
    myQueue.Enqueue(10);
    myQueue.Enqueue(20);
    myQueue.Enqueue(30);

    // Dequeue and display the dequeued values
    while (!myQueue.isEmpty()) {
        cout << "Dequeued: " << myQueue.Dequeue() << endl;
    }

    return 0;
}
