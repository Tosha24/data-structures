// Problem: https://leetcode.com/problems/merge-sorted-array/

/* Solution (Optimal Solution):
 * 1. Start from the end of the array
 * 2. Compare the last elements of both the arrays
 * 3. Whichever is greater, put it at the end of the first array
 * 4. Decrement the index of the array from which the element was picked
 * 5. Decrement the index of the first array
 * 6. Repeat steps 2-5 until one of the arrays is empty
 * 7. If the second array is empty, then the first array is already sorted
 * 8. If the first array is empty, then copy the remaining elements of the second array to the first array
 */

#include <bits/stdc++.h>
#include <vector>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while(i >= 0 && j >= 0){
        if(nums1[i] >= nums2[j]){
            nums1[k] = nums1[i];
            i--;
        }
        else{
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    while(j >= 0){
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    for(int i = 0; i < m + n; i++){
        cout << nums1[i] << " ";
    }
}

// Time Complexity: O(m+n)
// Space Complexity: O(1)