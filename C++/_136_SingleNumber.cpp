// Problem: https://leetcode.com/problems/single-number/

/* Solution:
 * We use bitwise XOR to solve this problem:
 Rule 1. If we take XOR of zero and some bit, it will return that bit
 Rule 2. If we take XOR of two same bits, it will return 0
 * Hence, keeping above two rules in consideration, we can XOR all the elements of the given array together to find the unique non-repeating number.
 */

#include <iostream>
using namespace std;

class _136_SingleNumber{
public:
    static int singleNumber(int nums[], int n){
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

int main(){
    int nums[] = {4, 1, 2, 1, 2};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << _136_SingleNumber::singleNumber(nums, n) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)