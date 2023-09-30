// ✔️ Arrays

// Problem: Find all the unique permutations from a given nums array. Permutations can be in any order.
// For eg: Input: nums = [2, 2, 1, 1]   ==>  Output: [[2, 2, 1, 1], [2, 1, 2, 1], [2, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 1], [1, 2, 1, 2]]

// Approach: Recursion
/* Solution:
 *
 */

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class _47_PermutationII
{
public:
    static vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        bool mark[nums.size()] = {false};
        findPermutations(nums, ans, ds, mark);
        return ans;
    }
    static void findPermutations(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, bool* mark) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        int step = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (step > 0 && nums[i] == nums[i - 1])
                continue;
            if (!mark[i]) {
                mark[i] = true;
                ds.push_back(nums[i]);
                findPermutations(nums, ans, ds, mark);
                step = step + 1;
                ds.pop_back();
                mark[i] = false;
            }
        }
        return;
    }
};

int main() {
    vector<int> nums = {2, 2, 1, 1};
    vector<vector<int>> ans = _47_PermutationII::permuteUnique(nums);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << " ]";
    return 0;
}