// Problem: https://leetcode.com/problems/merge-sorted-array/

/* Solution (Brute Force):
 * 1. Create a new array of size m+n
 * 2. Start from the beginning of both the arrays
 * 3. Compare the each elements of both the arrays one by one
 * 4. Whichever is smaller, put it in the new array
 * 5. Increment the index of the array from which the element was picked
 * 6. Increment the index of the new array
 * 7. Repeat steps 3-6 until one of the arrays is empty
 * 8. If the second array is empty, then copy the remaining elements of the first array to the new array
 * 9. If the first array is empty, then copy the remaining elements of the second array to the new array
 * 10. Copy the elements of the new array to the first array 
 */

#include <bits/stdc++.h>
#include <vector>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
    vector<int> merged_array(m+n);
    int i = 0, j = 0, k = 0;
    while(i < m && j < n){
        if(nums1[i] < nums2[j]){
            merged_array[k] = nums1[i];
            i++;
        }
        else{
            merged_array[k] = nums2[j];
            j++;
        }
        k++;
    }

    while(i < m){
        merged_array[k] = nums1[i];
        i++;
        k++;
    }

    while(j < n){
        merged_array[k] = nums2[j];
        j++;
        k++;
    }

    for(int p = 0; p < m+n; p++){
        nums1[p] = merged_array[p];
    }
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    for(int i = 0; i < m + n; i++){
        cout << nums1[i] << " ";
    }
}

// Time Complexity: O(m+n)
// Space Complexity: O(m+n)