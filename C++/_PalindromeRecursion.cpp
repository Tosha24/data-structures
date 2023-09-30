// Problem: Check if the number is palindrome
// For eg: 121 is a palindrome

// Approach: Recursion

#include <bits/stdc++.h>
using namespace std;

class _PalindromeRecursion {
public:
    static bool isPalindrome(vector<int>& nums, int low){
        int n = nums.size();
        if(low >= n/2){
            return true;
        }
        if(nums[low] != nums[n - low - 1]){
            return false;
        }
        return isPalindrome(nums, low + 1);
    }
};

int main(){
    vector<int> nums = {1, 1, 2, 2, 1};
    _PalindromeRecursion::isPalindrome(nums, 0) ? cout << "true" : cout << "false";
    return 0;
}

// Time Complexity: O(logN)
// Space Complexity: O(N) + O(logN)
