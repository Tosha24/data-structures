// Problem: Given an array nums of distinct integers, return all the possible permutations.
// For eg: Input: nums = [1,2,3]   ==>  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Approach: Recursion
/* Solution:
 * Here, we consider all the indices one by one which are not considered in any function call.
 */

#include <iostream>
#include <vector>
using namespace std;

class _46_Permutations
{
public:
    static vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        bool mark[nums.size()];
        findPermutations(nums, ans, ds, mark);
        return ans;
    }
    static void findPermutations(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, bool* mark){
        // Base condition: if the size(ans array) and size(original array) means that is the required ans
        if (ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        // Consider all (0 to n) the non considered indices at every function call
        for (int i = 0; i < nums.size(); i++){
            // If the particular value of i is not consider then do consider it
            if (!mark[i])
            {
                mark[i] = true;
                ds.push_back(nums[i]);
                findPermutations(nums, ans, ds, mark);
                ds.pop_back();
                mark[i] = false;
            }
        }
        return;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = _46_Permutations::permute(nums);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++){
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << " ]";
    return 0;
}

// Time Complexity: O(n! * n)
// Space Complexity: O(n) + O(n)