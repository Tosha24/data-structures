// Problem: To count all the subsequences whose sum is equal to the given sum.
// For eg: Input: arr = [1, 2, 1], target = 2    ==>  Output: 2

// Approach: Recursion
/* Solution:
* Here we keep track of stack(that push the current index's element) and also the sum variable(that calculates the sum of elements present in the stack).
* Here we either take the element or not take the element. By adding the element into the stack and adding all the elements in the stack, we consider that element. And by removing the element from the stack and then adding all the remaining elements in the stack, we do not consider that element. 
* We reach end of the array length(for all possible iterations) and then if the sum is equal to the required sum we return 1 to indicate 1 subsequence. and return 0 to indicate no subsequence with reqSum. At last after performing both the add and remove function we now add both the count of subsequences and return for the previous solution.
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class _CountSubsequencesWithSum {
public:
    static int printSubsequence(int index, vector<int>& nums, stack<int>& ds, int sum, int target) {
        if (index == nums.size()) {
            if (sum == target) {
                return 1;
            }
            else
                return 0;
        }
        ds.push(nums[index]);
        sum = sum + nums[index];
        int l = printSubsequence(index + 1, nums, ds, sum, target);

        ds.pop();
        sum = sum - nums[index];
        int r = printSubsequence(index + 1, nums, ds, sum, target);
        return l+r;
    }
};

int main(){
    vector<int> nums = {1, 2, 1};
    int target = 2;
    stack<int> ds;
    int count = _CountSubsequencesWithSum::printSubsequence(0, nums, ds, 0, target);
    cout << count << endl;
    return 0;
}

// Time Complexity: O(2^N * N)
// Space Complexity: O(N)
