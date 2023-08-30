/*
    Template Queue Implementation
    
    This program demonstrates the implementation of a templated queue class using C++ templates.
    
    The class "Queue" is implemented using templates, allowing the user to create queues of various
    data types. The queue class provides basic queue operations such as enqueue, dequeue, checking
    if the queue is empty or full, getting the size of the queue, and retrieving the front element.
    
    The queue is implemented using an array-based circular buffer to efficiently manage the elements.
    The capacity of the queue is specified during instantiation.
    
    The "main" function demonstrates the usage of the templated queue class. It creates a queue of
    integers, enqueues elements, retrieves the front element, dequeues an element, and displays the
    size of the queue.
*/
#include <iostream>
using namespace std;
template <typename T>
class Queue {
private:
    T* arr;
    size_t frontIndex;
    size_t rearIndex;
    size_t capacity;
    size_t size;

public:
    Queue(size_t maxCapacity) : capacity(maxCapacity), frontIndex(0), rearIndex(0), size(0) {
        arr = new T[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    size_t getSize() const {
        return size;
    }

    void enqueue(const T& value) {
        if (isFull()) {
            cerr << "Queue is full. Cannot enqueue.\n";
            return;
        }
        arr[rearIndex] = value;
        rearIndex = (rearIndex + 1) % capacity;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    T front() const {
        if (isEmpty()) {
            cerr << "Queue is empty. No front element.\n";
            return T(); // Assuming T is a default-constructible type
        }
        return arr[frontIndex];
    }
};

int main() {
    Queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << "\n";
    cout << "Queue size: " << q.getSize() << "\n";

    q.dequeue();
    cout << "Front element after dequeue: " << q.front() << "\n";
    cout << "Queue size after dequeue: " << q.getSize() << "\n";

    return 0;
}
