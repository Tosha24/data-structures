// Problem: Given an integer x, return true if x is a palindrome, and false otherwise.
// For eg: Input: 1211  ==> Output: false

// Approach: Binary Search
/* Solution:
 * We will start from both the ends of the string. If the character at both ends are not same, we return false at any point of the iteration and not continue further.
 * If the character at both ends are same, we increase start pointer and decrease end pointer. and continue the same till we traverse whole string.
 */

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

bool isPalindrome(int number){
    string str = to_string(number);
    int i = 0;
    int j = str.length() - 1;
    while(i <= j){
        if(str[i] != str[j]){
            return false;
        }
        else{
            i = i + 1;
            j = j - 1;
        }
    }
    return true;
}

int main()
{
    int number = 1211;
    isPalindrome(number) ? cout << "true" : cout << "false";
    return 0;
}

// Time Complexity: O(logn)