// Problem: https://leetcode.com/problems/reverse-pairs/

/* Solution (Optimal Solution):
 * 1. We use Count Inversion algorithm along with merge sorting technique to solve this problem.
 * 2. We use merge sort to sort the array and count the number of inversions.
 * 3. We use the countPairs function to count the number of pairs that satisfy the condition.
 * 4. We use the merge function to merge the sorted arrays.
 */

#include <iostream>
#include <vector>
using namespace std;

class _493_ReversePairs {
public:
    static int reversePairs(vector<int>& nums){
        return mergeSort(nums, 0, nums.size() - 1);
    }   
    static int mergeSort(vector<int>& nums, int low, int high){
        int count = 0;
        if(low >= high) return count;
        int mid = (low + high)/2;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);
        merge(low, mid, high, nums);
        return count;
    }
    static void merge(int low, int mid, int high, vector<int>& nums){
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        int index = 0;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low; i <= high; i++){
            nums[i] = temp.at(i - low);
        }
    }
    static int countPairs(vector<int>& nums, int low, int mid, int high){
        int count = 0;
        int right = mid + 1;
        for(int i = low; i <= mid; i++){
            while(right <= high && nums[i] > (long) 2 * nums[right]){
                right++;
            }
            count += (right - mid - 1);
        }
        return count;
    }
};

int main(){
    vector<int> nums = {2, 4, 5, 3, 1};
    cout << _493_ReversePairs::reversePairs(nums) << endl;
    return 0;
}

// Time Complexity: O(nlogn) + O(n) = O(2nlogn)
// Space Complexity: O(n)