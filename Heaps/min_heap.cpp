/**
 * This C++ program demonstrates the implementation of a MinHeap data structure.
 * 
 * A MinHeap is a binary heap data structure in which the parent node always has a smaller or equal value
 * compared to its children. This property allows for efficient retrieval of the minimum element from the heap.
 * 
 * In this code:
 * - A MinHeap class is defined, which stores integer elements.
 * - The class provides methods for insertion, retrieval, and deletion of the minimum element.
 * - Heapify operations are used to maintain the heap property.
 * - The program showcases the usage of the MinHeap class.
 */
#include <iostream>
using namespace std;

class MinHeap;
class HeapItem{
	friend class MinHeap;
	int key;
	int value;
};

class MinHeap{
private:
	int* arr;
	int capacity;
	int total_items;
public:
	int MinHeap::Minheap(){
		arr=0;
		capacity=0;
		total_items=0;
	}
	
	MinHeap(int _capacity){
		capacity=_capacity;
		total_items=0;
		arr= new int[_capacity];
	}
	
    bool isEmpty(){
        if(total_items == 0)
            return true;
        else
            return false;
    }
	
	int parent(int i){
		return (i-2)/2;
	}
	
	int right(int i){
		return (2*i +2);
	}
	
	int left(int i){
		return (2*i +1);
	}
	
	
	int SortHeap(int index,int *arr){
        if(total_items <= 1)
            return *arr;
        int leftchild = left(index);
        int rightchild = right(index);
        int minimum = index;
        if(leftchild < total_items && arr[leftchild] < arr[index])
            minimum = leftchild;
        if(rightchild < total_items && arr[rightchild] < arr[minimum])
            minimum = rightchild;
        if(minimum != index){
            int temp = arr[index];
            arr[index] = arr[minimum];
            arr[minimum] = temp;
        }
        return *arr;
    }
    
	int InsertKey(int k){
		if(total_items==capacity)
			return 0;
		total_items++;
		int i=total_items-1;
		arr[i]=k;
		while(i!=0 && (arr[parent(i)]>arr[i])){
            int temp = arr[parent(i)];
            arr[parent(i)] = arr[i];
            arr[i] = temp;
            i = parent(i);
		}
		return *arr;
	}
	
	
    int Get_Min_Heap(){
        int min = arr[0];
        cout<<"\nMin Element of the Heap is : ";
        return arr[0];
    }

    void DeleteMinHeap(){
        int size = total_items;
        int last_element = arr[size - 1];
        arr[0] = last_element;
        total_items--;
        size--;
        SortHeap(0,arr);
    }
    void display(){
    	cout<<"Array used to Enter in Heap displayed : \n";
    	for(int i=0;i<capacity;i++){
    		cout<<arr[i]<<" ";
		}
	}

    ~MinHeap(){
    	cout<<"\n\nDestructor for MinHeap is called !!";
        for(int i = 0 ; i < capacity ; i++){
            delete [] arr;
            arr = 0;
        }
    }
	
	
};

int main()
{
    MinHeap m(12);
    m.InsertKey(3);
    m.InsertKey(2);
    m.InsertKey(5);
    m.InsertKey(4);
    m.InsertKey(7);
    m.InsertKey(6);
    m.InsertKey(9);
    m.InsertKey(8);
    m.InsertKey(11);
    m.InsertKey(10);
    m.InsertKey(13);
    m.InsertKey(12);
    m.display();endl(cout);
	cout<<m.Get_Min_Heap();
	cout<<"\n\nAfter deleting Minimum element of the heap !!\n ";
    m.DeleteMinHeap();
	cout<<m.Get_Min_Heap();
    return 0;
}










