// ✔️ Arrays

// Problem: https://leetcode.com/problems/move-zeroes/

/* Solution:
 * We use two pointers, i and j. i is the slow-runner while j is the fast-runner.
 * We first find the first zero element in the array and store its index in k.
 * Then we initialize the pointer i to k and pointer j to k + 1.
 * We iteratively try to point j to the non-zero element in the array.
 * If we find a non-zero element, we swap the elements at i and j and increment i.
 * We increment j in each iteration (even though no swapping is done).  
 */

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class _283_MoveZeroes{
public:
    static void moveZeroes(vector<int>& nums){
        int n = nums.size();
        int k = 0;
        while(k < n){
            if(nums[k] == 0){
                break;
            }
            else{
                k = k + 1;
            }
        }

        int i = k, j = k + 1;
        while(i < n && j < n){
            if(nums[j] != 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i = i + 1;
            }
            j = j + 1;
        }
    }
};

int main(){
    vector<int> nums = {0, 1, 0, 3, 14};
    _283_MoveZeroes::moveZeroes(nums);
    for(int i : nums){
        cout << i << ", ";
    }
    return 0;
}   

// Time Complexity: O(n)
// Space Complexity: O(1)