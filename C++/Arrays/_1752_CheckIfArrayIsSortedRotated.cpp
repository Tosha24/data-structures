// Problem: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

/* Solution:
 * We traverse through the array and check if nums[i] > nums[(i+1) % nums.length].
 * If yes, we increment count by 1.
 * Finally, we check if count <= 1.
 */

#include <bits/stdc++.h>
using namespace std;

class _1752_CheckIfArrayIsSortedRotated{
public:
    static bool check(int nums[], int n){
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i+1) % n]){
                count = count + 1;
            }
        }
        return count <= 1;
    }
};

int main(){
    int nums[] = {3, 4, 4, 1, 1};
    int n = sizeof(nums)/sizeof(nums[0]);
    _1752_CheckIfArrayIsSortedRotated::check(nums, n) ? cout << "True" << endl : cout << "False" << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)