/*
Description:
This program demonstrates a recursive approach to search for an element in an array. It uses a function named isMember to check whether a given element is present in the array or not. If the element is found, the function returns the index at which the element is located; otherwise, it returns -1.

Working:
1. The function isMember is defined to search for an element 'x' in an integer array 'arr' of a given size.
2. The function takes three parameters: the element to be searched ('x'), the size of the array ('size'), and the array itself ('arr').
3. Initially, the function decrements the 'size' to get the index of the last element.
4. It checks whether 'size' is negative. If true, it means the entire array has been searched, and the element was not found. In this case, the function returns -1.
5. If the element at the current index (arr[size]) matches the element 'x', the function returns the original size (n) of the array as the index where the element was found.
6. If the element at the current index does not match 'x', the function calls itself recursively with 'size' decremented, continuing the search from the next index.
7. In the main function:
   - An integer array 'arr' is initialized with some values.
   - The size of the array is set to 6.
   - An element 'x' (in this case, 12) is chosen for the search.
   - The function isMember is called to search for 'x' in the array.
   - If the returned index is not -1, the element is found, and "Element is present" is printed.
   - If the returned index is -1, the element is not found, and "Element is not present" is printed.

Usage:
This code showcases a recursive approach to searching for an element in an array. It highlights the concept of recursive function calls and how they can be used to solve repetitive problems like searching.

*/
#include <iostream>
using namespace std;
  
int isMember(int x, int size, int arr[]) {
      
    int n=size--;
    if (size<0) {
        return -1;
    }
    if (arr[size] == x) {
        return n;
    }
    return isMember(x, size, arr);
}
  
int main() {
    int arr[] = {10, 11, 12, 13, 14, 15};
    int size = 6;
    int x = 12;
    int n=isMember(x, size, arr);
    if (isMember(x, size, arr)!= -1) {
    	cout<<"Element is persent ";
	}
    else {
    	cout<<"Element is not present ";
	}
    return 0;
}
