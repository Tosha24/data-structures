// Problem: https://leetcode.com/problems/sort-colors/

/* Solution:
 * 1. Use three pointers to keep track of the position of 0, 1, 2.
 * 2. We use Dutch National Flag Algorithm to solve this problem.
 * 3. We use low to keep track of the position of 0, mid to keep track of the position of 1, high to keep track of the position of 2.
 * 4. We use mid to traverse the array.
 * 5. From 0 to low-1, we have all sorted 0's.
 * 6. From low to mid-1, we have all sorted 1's.
 * 7. From mid to high, we have all unsorted elements.
 * 8. From high+1 to the end, we have all sorted 2's.
 * 9. If nums[mid] == 0, we swap nums[mid] and nums[low], and we increment both low and mid.
 * 10. If nums[mid] == 1, we increment mid.
 * 11. If nums[mid] == 2, we swap nums[mid] and nums[high], and we decrement high.
 * 12. We keep doing this until mid <= high.
 */

#include <iostream>
using namespace std;

class _75_SortColors{
public: 
    static void sortColors(int nums[], int n){
        int low = 0, mid = 0, high = n - 1;
        int temp;
        while(mid <= high){
            if(nums[mid] == 0){
                temp = nums[mid];
                nums[mid] = nums[low];
                nums[low] = temp;
                mid = mid + 1;
                low = low + 1;
            }
            else if(nums[mid] == 1){
                mid = mid + 1;
            }
            else if(nums[mid] == 2){
                temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;
                high = high - 1;
            }
        }
    }
};

int main(){
    int nums[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);
    _75_SortColors::sortColors(nums, n);
    for(int i : nums){
        cout << i + " ";
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)