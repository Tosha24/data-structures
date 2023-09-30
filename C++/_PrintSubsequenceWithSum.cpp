// Problem: To print the subsequences whose sum is equal to the given sum.
// For eg: Input: [1, 2, 1], target = 2   ==>   Output: [1, 1], [2]

// Approach: Recursion
/* Solution:
 * Here we keep track of stack(that push the current index's element) and also the sum variable(that calculates the sum of elements present in the stack).
 * Here we either take the element or not take the element. By adding the element into the stack and adding all the elements in the stack, we consider that element. And by removing the element from the stack and then adding all the remaining elements in the stack, we do not consider that element. We reach end of the array length(for all possible iterations) and then we print the entire subsequence whose sum is equal to the required sum.
 */

#include <bits/stdc++.h>
using namespace std;

class _PrintSubsequenceWithSum {
public:
    static void printSubsequence(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int sum, int target) {
        if (index == nums.size()) {
            if (sum == target) {
                ans.push_back(ds);
            }
            return;
        }
        
        ds.push_back(nums[index]);
        sum = sum + nums[index];
        printSubsequence(index + 1, nums, ans, ds, sum, target);

        ds.pop_back();
        sum = sum - nums[index];
        printSubsequence(index + 1, nums, ans, ds, sum, target);
        return;
    }
};

int main(){
    vector<int> nums = {1, 2, 1};
    int target = 2;
    vector<vector<int>> ans;
    vector<int> ds;
    _PrintSubsequenceWithSum::printSubsequence(0, nums, ans, ds, 0, target);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << ", ";
        }
        cout << "], ";
    }
    cout << " ]";
    return 0;
}

// Time Complexity: O(2^N * N)
// Space Complexity: O(N)