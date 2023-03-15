// Problem: You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters. Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.
// For eg: Input: letters = ["c","f","j"], target = "a"   ==>   Output: "c"

// Approach: Binary Search
/* Solution:
 * Here we perform simple binary search, but instead of returning the mid element, we increment the start pointer (mid + 1 or start + 1). and then return the value at start index in either case.
 */

#include <iostream>
#include <vector>
using namespace std;

class _744_FindSmallestLetterGreaterThanTarget {
public:
    static char nextGreatestLetter(vector<char>& letters, char target) {
        if(target > letters[letters.size() - 1]){
            return letters[0];
        }
        int start = 0;
        int end = letters.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target > letters[mid]){
                start = mid + 1;
            }
            else if(target < letters[mid]){
                end = mid - 1;
            }
            else{
                start = start + 1;
                break;
            }
        }
        return letters[start];
    }
};

int main()
{
    vector<char> letters = {'x', 'x', 'y', 'y'};
    char target = 'w';
    cout << _744_FindSmallestLetterGreaterThanTarget::nextGreatestLetter(letters, target) << endl;
    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(n)