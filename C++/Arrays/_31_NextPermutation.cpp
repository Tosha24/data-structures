// Problem: https://leetcode.com/problems/next-permutation/

/* Solution:
 * 1. Find the point where the increasing sequence is not followed. This is called break-point
 * 2. Swap the elements present at ind and the element slightly just greater than the ind element.
 * 3. Reverse the right half of the array to make it slightly greater than the previous permutation
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

void swap(vector<int> &nums, int i, int ind){
    int temp = nums[ind];
    nums[ind] = nums[i];
    nums[i] = temp;
}

void reverse(vector<int> &nums, int from, int to){
    for(int i = from; i <= to; i++){
        swap(nums, i, to);
        to--;
    }
}

void nextPermutation(vector<int> &nums){
    // Find the point where the increasing sequence is not followed. This is called break-point
    int n = nums.size();
    int ind = -1;
    for(int i = n-2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            ind = i;
            break;
        }
    }

    // Swap the elements present at ind and the element slightly just greater than the ind element.
    if(ind != -1){
        for(int i = n-1; i > ind; i--){
            if(nums[ind] < nums[i]){
                swap(nums, i, ind);
                break;
            }
        }
    }

    // Reverse the right half of the array to make it slightly greater than the previous permutation
    reverse(nums, ind+1, n-1);
}

int main(){
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    nextPermutation(nums);
    for(int item : nums){
        cout << item << " ";
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)