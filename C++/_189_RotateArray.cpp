// Problem: https://leetcode.com/problems/rotate-array/

/* Solution:
 * We use three reverse operations to solve this problem:
 * 1. Reverse the first k elements
 * 2. Reverse the rest n - k elements
 * 3. Reverse the whole array
 */

#include <iostream>
using namespace std;

class _189_RotateArray{
public: 
    static void reverse(int nums[], int start, int end){
        int i = start;
        int j = end;
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i = i + 1;
            j = j - 1;
        }
    }
    static void rotate(int nums[], int k, int n){
        k = k % n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};

int main(){
    int nums[] = {17};
    int k = 6;
    int n = sizeof(nums)/sizeof(nums[0]);
    _189_RotateArray::rotate(nums, k, n);
    for(int i : nums){
        cout << i << " ";
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)