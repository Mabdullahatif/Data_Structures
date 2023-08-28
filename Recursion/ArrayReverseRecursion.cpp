/*
Description:
This program demonstrates the reversal of an array of floating-point numbers using a recursive approach. It defines a function named 'reverse' to reverse the elements of the array and a 'display' function to print the reversed array.

Working:
1. The function 'reverse' is defined to reverse the elements of the given array using recursion.
2. The function takes four parameters:
   - 'arr': The array to be reversed.
   - 'start': The index of the first element to start the reversal from.
   - 'end': The index of the last element to end the reversal at.
   - 'size': The size of the array.
3. The base case of the recursion is when 'start' becomes greater than or equal to 'end'. In this case, the function returns 0.
4. Otherwise, the function performs the following steps:
   - Swaps the elements at 'start' and 'end' indices.
   - Calls itself recursively with 'start' incremented and 'end' decremented.
   - This swapping and recursive call continue until 'start' becomes greater than or equal to 'end', effectively reversing the array.
5. The 'display' function is defined to print the elements of the array.
6. In the main function:
   - An array 'arr' containing floating-point numbers is defined.
   - The 'end', 'start', and 'size' variables are initialized.
   - The 'reverse' function is called with the array, start, end, and size as arguments to reverse the array.
   - The reversed array is displayed using the 'display' function.

Usage:
This code showcases the usage of recursion to reverse an array of floating-point numbers. It demonstrates how recursive algorithms can be used to modify and manipulate arrays effectively.

*/
#include <iostream>
using namespace std;

int reverse(float arr[],int start,int end,int size){
    float temp;
    if(start<end){
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        reverse(arr,start+1,end-1,size);  
    } 
    return 0;
}

void display(float arr[],float n){
    for (int i=0;i<n;i++){
    	cout<<arr[i]<<", ";
	}
}
int main() { 
   float arr[]={1.0, 5.4, 0.85, 91.2, 6.5};
   float end=5;
   float start=0;
   float size=end;
   reverse(arr,start,end-1,size);
   cout<<"Reversed Array is : ";
   display(arr,end);
   return 0;
}
