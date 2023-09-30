// Problem: Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.
// For eg: Input: array = [1,2,3,4,5,3,1], target = 3   ==>  Output: 2

// Approach: Binary Search
/* Solution:
 * We first find the peak value's index in mountain array.
 * To find the peak value's index, we compare mid with mid+1 and then return start when start >= end.
 * Then we perform binary search in ascending part and if we don't find the target in it, we then search in descending part.
 */

#include <iostream>
#include <vector>
using namespace std;

class _1095_FindInMountainArray {
public:
    static int findMinIndex(vector<int> nums) {
        int start = 0;
        int end = nums.size() - 1;
        while(start < end){
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid + 1]){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
    static int binarySearch(vector<int> nums, int target, int start, int end){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[start] < nums[end]){
                if(nums[mid] > target){
                    end = mid - 1;
                }
                else if(nums[mid] < target){
                    start = mid + 1;
                }
                else{
                    return mid;
                }
            }
            else{
                if(nums[mid] > target){
                    start = mid + 1;
                }
                else if(nums[mid] < target){
                    end = mid - 1;
                }
                else{
                    return mid;
                }
            }
        }
        return INT32_MAX;
    }
};

int main(){
    vector<int> nums = {0, 1, 2, 4, 3, 2, 1};
    int target = 1;
    int peak = _1095_FindInMountainArray::findMinIndex(nums);
    int asc = _1095_FindInMountainArray::binarySearch(nums, target, 0, peak);
    int desc = _1095_FindInMountainArray::binarySearch(nums, target, peak+1, nums.size() - 1);
    if(asc < desc){
        cout << asc << endl;
    }
    else if(asc > desc){
        cout << desc << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(n)