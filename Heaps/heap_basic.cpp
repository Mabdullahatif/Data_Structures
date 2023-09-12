/**
 * This C++ program demonstrates the implementation of a MinHeap data structure.
 * 
 * MinHeap is a binary heap data structure in which the parent node always has a smaller or equal value
 * compared to its children. This property allows for efficient retrieval of the minimum element from the heap.
 * 
 * In this code:
 * - A MinHeap class template is defined, which can store elements of any comparable data type.
 * - The class provides methods for insertion, retrieval, and deletion of the smallest element.
 * - Heapify operations (heapifyUp and heapifyDown) are used to maintain the heap property.
 * - The main function demonstrates the usage of the MinHeap class by inserting elements and
 *   retrieving the smallest elements.
 * 
 * Note: Doubling of capacity is not implemented in this basic MinHeap.
 */


#include <iostream>

using namespace std;

template <class var>
class MinHeap{
	int capacity, currSize;
	var* arr;
	
	/* Heapify Up is needed when we insert a new element in an already heapified
	array. In this case we move from child to parent anc compare.*/
	void heapifyUp(int i){
		if(i != 1 && arr[i] < arr[i/2]){
			swap(arr[i], arr[i/2]);
			heapifyUp(i/2);
		}
	}
	
	/* We need heapify down when we want to restore the heap property
	in an existing array. In this case we move from parent to childs. */
	void heapifyDown(int i){
		int smallest = i;
		
		if(i * 2 <= currSize && arr[i * 2] < arr[smallest])
			smallest = i * 2;
		if(i * 2 + 1 <= currSize && arr[i * 2 + 1] < arr[smallest])
			smallest = i * 2 + 1;
		
		if(i != smallest){
			swap(arr[i], arr[smallest]);
			heapifyDown(smallest);
		}
	}
	
public:
	MinHeap(int cap): capacity(cap), currSize(0){
		arr = new var[capacity];
	}
	
	// Doubling of Capacity is not implemented
	void insert(var val){
		if(currSize + 1 >= capacity)
			return;
		
		arr[++currSize] = val;
		heapifyUp(currSize);
	}
	
	void print(){
		for(int i=1; i<=currSize; i++)
			cout << arr[i] << " ";
	}
	
	var getdeleteSmallest(){
		var val = arr[1];
		arr[1] = arr[currSize--];
		heapifyDown(1);
		return val;
	}
	
};

int main(){
	MinHeap<int> Heap(10);
	
	Heap.insert(5);
	Heap.insert(7);
	Heap.insert(3);
	Heap.insert(1);
	
	cout << Heap.getdeleteSmallest() << endl;
	cout << Heap.getdeleteSmallest() << endl;
	cout << Heap.getdeleteSmallest() << endl;
	cout << Heap.getdeleteSmallest() << endl;
	
	return 0;
}