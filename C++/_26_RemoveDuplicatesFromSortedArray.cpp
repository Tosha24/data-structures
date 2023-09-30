// ✔️ Arrays [Hint: Two pointers, slow runner, fast runner]

// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

/* Solution:
 * We use two pointers, i and j. i is the slow-runner while j is the fast-runner.
 * As long as nums[i] == nums[j], we increment j to skip the duplicate.
 * When we encounter nums[j] != nums[i], the duplicate run has ended so we must copy its value to nums[i + 1].
 * i is then incremented and we repeat the same process again until j reaches the end of array.
 */

#include <iostream>
using namespace std;

class _26_RemoveDuplicatesFromSortedArray{
public:
    static int removeDuplicates(int nums[], int n){
        int i = 0;
        for(int j = 1; j < n; j++){
            if(nums[i] != nums[j]){
                i = i + 1;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main(){
    int nums[] = {1, 1};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << _26_RemoveDuplicatesFromSortedArray::removeDuplicates(nums, n) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)