/*
Description:
This program generates all possible binary combinations of a given length using recursion. The program prompts the user to enter a number 'num', and then it prints all the binary combinations of 'num' digits.

Working:
1. The 'print01' function is defined to generate binary combinations using recursion.
2. It takes two parameters: 'num' (remaining number of digits) and 'str' (current binary combination).
3. If 'num' becomes zero, the current binary combination 'str' is printed.
4. Otherwise, two recursive calls are made:
   - One call adds a '0' to the 'str' and decreases 'num' by 1.
   - The other call adds a '1' to the 'str', subtracts 2 from 'num', and then makes the recursive call.
5. The process continues until 'num' becomes zero, and all possible binary combinations are printed.

6. In the 'main' function:
   - A string 'str' is defined to store binary combinations.
   - An integer 'num' is obtained from the user, representing the desired binary string length.
   - The 'print01' function is called with 'num' and 'str' to generate and print binary combinations.

Usage:
This code generates and prints all possible binary combinations of a given length using recursion. It prompts the user to enter the length of the binary strings and then displays the binary combinations.
*/

#include <iostream>
using namespace std;

void print01(int num, string str) {
    if (num == 0) {
        cout << str << endl;
    } else {
        int iteration = 1;
        print01(num - iteration, str + "0");

        int iteration2 = 2;
        print01(num + (1 - iteration2), str + "1");
    }
}

int main() {
    string str = "";
    int num;
    cout << "Enter number for binary combinations: ";
    cin >> num;
    cout << "Your binary combinations are given below:" << endl;
    print01(num, str);

    return 0;
}
