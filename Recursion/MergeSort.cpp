/*
Description:
This program demonstrates the implementation of the merge sort algorithm to sort an array of integers in ascending order. Merge sort is a popular comparison-based sorting algorithm known for its efficiency and stability.

Working:
1. The function 'merge' is defined to merge two subarrays of the given array.
2. It takes four parameters:
   - 'array': The array to be merged.
   - 'left': The starting index of the first subarray.
   - 'mid': The ending index of the first subarray.
   - 'right': The ending index of the second subarray.
3. The function creates two temporary arrays 'l' and 'r' to hold the elements of the two subarrays.
4. It then compares the elements of 'l' and 'r' and merges them in ascending order into the original array.
5. The 'mergesort' function recursively divides the array into smaller subarrays until each subarray has a single element.
6. The 'merge' function is then called to merge these sorted subarrays back together in ascending order.
7. The 'display' function is defined to print the elements of an array.
8. In the main function:
   - An integer array 'arr' is defined with unsorted elements.
   - The 'size' variable is calculated to represent the size of the array.
   - The unsorted array is displayed.
   - The 'mergesort' function is called with the array, start index 0, and end index 'size - 1' to sort the array.
   - The sorted array is displayed.

Usage:
This code demonstrates the implementation of the merge sort algorithm, which divides the array into smaller subarrays, sorts them individually, and then merges them back together. Merge sort is an efficient sorting algorithm that guarantees stable and reliable sorting.

*/

#include <iostream>
using namespace std;

void merge(int array[], int left, int mid,int right){
    int  array1=mid-left+1;
    int const array2=right-mid;
    int *l = new int[array1];
    int *r = new int[array2];
    int indexOfarray1= 0; 
    int indexOfarray2= 0;
    int indexOfMergedArray= left;
    for (int i = 0; i < array1; i++){
    	l[i]=array[left+ i];
	}
    for (int j = 0; j < array2; j++){
    	r[j] = array[mid + 1 + j];
	} 

    while (indexOfarray1 < array1 && indexOfarray2 < array2) {
        if (l[indexOfarray1]<= r[indexOfarray2]) {
            array[indexOfMergedArray]= l[indexOfarray1];
            indexOfarray1++;
        }
        else {
            array[indexOfMergedArray]= r[indexOfarray2];
            indexOfarray2++;
        }
        indexOfMergedArray++;
    }
    while (indexOfarray1 < array1) {
        array[indexOfMergedArray]= l[indexOfarray1];
        indexOfarray1++;
        indexOfMergedArray++;
    }
    while (indexOfarray2 < array2) {
        array[indexOfMergedArray]= r[indexOfarray2];
        indexOfarray2++;
        indexOfMergedArray++;
    }
    delete[] l;
    delete[] r;
}
 
void mergesort(int arr[],int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    } 
}
 
void display(int arr[],int n){
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
 
int main()
{
    int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array to be be Merged is : ";display(arr,size);endl(cout);
    mergesort(arr,0,size-1);
    cout << "Array After Merging is :   ";display(arr,size);
    return 0;
}
