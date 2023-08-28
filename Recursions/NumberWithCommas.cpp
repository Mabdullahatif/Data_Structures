/*
Description:
This program demonstrates the usage of recursion to insert commas in a large number for better readability. The goal is to format a given number by inserting commas every three digits, from right to left.

Working:
1. The 'putcommas' function is defined to insert commas in a large number using recursion.
2. It takes an integer 'num' as input and recursively processes the number by dividing it by 1000.
3. The modulo operation '% 1000' is used to extract the last three digits of the number, and they are printed followed by a comma.
4. The function then proceeds to process the remaining digits by making a recursive call.
5. The process continues until the remaining part of the number becomes zero or negative.
6. In the 'main' function:
   - An integer 'input' is defined with a large number.
   - The 'putcommas' function is called with the 'input' to insert commas.
   - The formatted number with commas is displayed.

Usage:
This code demonstrates how to format large numbers for better readability by inserting commas every three digits from right to left. This can make it easier to read and understand the magnitude of large numbers.

*/
#include <iostream>
using namespace std;
void putcommas(int num){
	if (num<= 0){
		return ;
	}

	putcommas(num/1000);
	cout<<(num%1000)<<",";
	return;
}

int main()
{
	int input = 1234567;
	putcommas(input);
	cout<<endl;
	return 0;
}
