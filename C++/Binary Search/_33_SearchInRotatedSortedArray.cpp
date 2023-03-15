// Problem: We have been given a sorted array that is rotated k times. Also we are given an integer target, return the index of target if it is in nums, or -1 if it is not in nums. 
// For eg: nums = [4, 5, 6, 7, 0, 1, 2], target = 0  ==> Output: 4

// Approach: Binary Search
/* Solution:
 * We first find the pivot (the value of k (how many times the array is rotated/ the maximum number in the array)). After finding the pivot we perform binary search in either of the part (start to pivot || pivot+1 to end) depending on the value of target as compared to the start or end array value.
 */

#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>& nums, int start, int end){
    while(start < end){
        int mid = start + (end - start)/2;
        if(mid < end && nums[mid] > nums[mid + 1]){
            return mid;
        }
        else if(nums[mid] >= nums[start]){
            start = mid + 1;
        }
        else if(nums[mid] <= nums[end]){
            end = mid - 1;
        }
    }
    return start;
}

int binarySearch(vector<int>& nums, int target, int start, int end){
    while(start <= end){
        int mid = start + (end - start)/2;
        if(target > nums[mid]){
            start = mid + 1;
        }
        else if(target < nums[mid]){
            end = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int start = 0;
    int end = nums.size() - 1;
    int pivot = findPivot(nums, start, end);
    if(target >= nums[start]){
        int ans = binarySearch(nums, target, start, pivot);
        cout << ans << endl;
    }
    else if(target <= nums[end]){
        int ans = binarySearch(nums, target, pivot+1, end);
        cout << ans << endl;
    }
    else{
        cout << -1;
    }
    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(n)