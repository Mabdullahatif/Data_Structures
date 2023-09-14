/**
 * This C++ program demonstrates the implementation of a MaxHeap data structure.
 * 
 * A MaxHeap is a binary heap data structure in which the parent node always has a greater or equal value
 * compared to its children. This property allows for efficient retrieval of the maximum element from the heap.
 * 
 * In this code:
 * - A MaxHeap class is defined, which stores HeapItem objects containing a key and a value.
 * - The class provides methods for insertion, retrieval, and deletion of the maximum element.
 * - Heapify operations (heapifyUp and heapifyDown) are used to maintain the heap property.
 * - The program showcases the usage of the MaxHeap class, including merging two heaps.
 */
#include <iostream>
using namespace std;

class MaxHeap;

class HeapItem {
public:
    friend class MaxHeap;
    int key;
    int value;

public:
    HeapItem(int _key, int _value) : key(_key), value(_value) {}
};

class MaxHeap {
private:
    HeapItem** arr;
    int capacity;
    int total_items;

public:
    MaxHeap(int _capacity) {
        capacity = _capacity;
        total_items = 0;
        arr = new HeapItem*[_capacity];
    }

    void InternalMergeHeap(HeapItem* merged[], HeapItem* a[], HeapItem* b[], int s1, int s2) {
        for (int i = 0; i < s1; i++)
            merged[i] = a[i];
        for (int i = 0; i < s2; i++)
            merged[s1 + i] = b[i];
        bmh(merged, s1 + s2);
    }

    bool isEmpty() {
        return total_items == 0;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int right(int i) {
        return (2 * i + 2);
    }

    int left(int i) {
        return (2 * i + 1);
    }

    void Heapify(HeapItem* arr[], int total_items, int index) {
        int largest = index;
        int left_child = left(index);
        int right_child = right(index);

        if (left_child < total_items && arr[left_child]->key > arr[largest]->key)
            largest = left_child;

        if (right_child < total_items && arr[right_child]->key > arr[largest]->key)
            largest = right_child;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            Heapify(arr, total_items, largest);
        }
    }

    void heapsort(HeapItem* arr[], int t) {
        for (int i = t / 2 - 1; i >= 0; i--) {
            Heapify(arr, t, i);
        }
        for (int i = t - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            Heapify(arr, i, 0);
        }
    }

    void InsertKey(int k, int v) {
        if (total_items == capacity)
            return;
        total_items++;
        int i = total_items - 1;
        arr[i] = new HeapItem(k, v);
        while (i != 0 && (arr[parent(i)]->key < arr[i]->key)) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    HeapItem* Get_Max_Heap() {
        if (isEmpty())
            return nullptr;
        return arr[0];
    }

    void DeleteMaxHeap() {
        if (isEmpty())
            return;
        delete arr[0];
        arr[0] = arr[total_items - 1];
        total_items--;
        Heapify(arr, total_items, 0);
    }

    void display() {
        cout << "Array used to enter in Heap: ";
        for (int i = 0; i < total_items; i++) {
            cout << arr[i]->key << " ";
        }
    }

    void getkthMax(int k) {
        HeapItem** sortedArr = new HeapItem*[total_items];
        for (int i = 0; i < total_items; i++) {
            sortedArr[i] = arr[i];
        }
        heapsort(sortedArr, total_items);
        cout << endl;
        cout << "Kth Max Element of the heap is : " << sortedArr[total_items - k]->key << " ";
        delete[] sortedArr;
    }

    void bmh(HeapItem* arr[], int N) {
        for (int i = N / 2 - 1; i >= 0; i--)
            Heapify(arr, N, i);
    }

    void MergeHeap(HeapItem* merged[], HeapItem* a[], HeapItem* b[], int s1, int s2) {
        InternalMergeHeap(merged, a, b, s1, s2);
    }

    ~MaxHeap() {
        cout << "\n\nDestructor for MaxHeap is called !!";
        for (int i = 0; i < total_items; i++) {
            delete arr[i];
        }
        delete[] arr;
    }
};

int main() {
    MaxHeap m(6), m1(5), m3(8);

    m.InsertKey(3, 30);
    m.InsertKey(2, 20);
    m.InsertKey(5, 50);
    m.InsertKey(4, 40);
    m.InsertKey(7, 70);
    m.InsertKey(6, 60);
    m.display();
    cout << endl;
    HeapItem* maxItem = m.Get_Max_Heap();
    if (maxItem)
        cout << maxItem->key << " " << maxItem->value << endl;
    m.getkthMax(1);
    cout << endl << endl;

    m1.InsertKey(9, 90);
    m1.InsertKey(8, 80);
    m1.InsertKey(11, 110);
    m1.InsertKey(10, 100);
    m1.InsertKey(13, 130);

    HeapItem* array1[] = { m1.Get_Max_Heap(), m1.Get_Max_Heap(), m1.Get_Max_Heap(), m1.Get_Max_Heap(), m1.Get_Max_Heap() };
    HeapItem* array2[] = { m.Get_Max_Heap(), m.Get_Max_Heap(), m.Get_Max_Heap() };
    const int s1 = sizeof(array1) / sizeof(array1[0]);
    const int s2 = sizeof(array2) / sizeof(array2[0]);
    HeapItem* merged[s1 + s2];

    m3.MergeHeap(merged, array1, array2, s1, s2);
    cout << "Heap After Merging is: ";
    for (int i = 0; i < s1 + s2; i++)
        cout << merged[i]->key << " ";
    cout << endl;

    return 0;
}
