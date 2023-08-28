/*
Description:
This program calculates the sum of the digits of a given number using a recursive approach. It defines a function named sum_digit to calculate the sum of digits recursively.

Working:
1. The function sum_digit is defined to calculate the sum of digits for a given number 'n'.
2. The function takes a single parameter, 'n', which represents the number whose digits' sum needs to be calculated.
3. The base case of the recursion is when 'n' becomes 0. In this case, the function returns 0, as there are no digits to add.
4. Otherwise, the function performs the following steps:
   - It calculates the last digit of the number using 'n % 10'.
   - It recursively calls the sum_digit function with the remaining digits obtained by 'n / 10'.
   - The sum of the last digit and the result of the recursive call is calculated and returned.
   - This step effectively adds up all the digits in the number.
5. In the main function:
   - An integer 'num' (in this case, 795) is chosen for which the sum of digits needs to be calculated.
   - The function sum_digit is called with 'num' as an argument, and the result is stored in the 'result' variable.
   - The calculated sum of digits is displayed as output.

Usage:
This code demonstrates a recursive approach to calculate the sum of digits in a given number. It showcases how recursion can be used to solve problems that involve repetitive calculations or operations.

*/
#include <iostream>
using namespace std;
int sum_digit(int n){
    if (n == 0){
        return 0;
	}
    int first=(n % 10 + sum_digit(n / 10));
    return (first % 10 + sum_digit(first / 10));
}

int main()
{
    int num = 795;
    int result = sum_digit(num);
    cout << "Sum of digits in "<<result << endl;
    return 0;
}
