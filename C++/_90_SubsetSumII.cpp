// Problem: Given an integer array nums that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.
// For eg: Input: nums = [1,2,2]   ==>   Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Approach: Recursion
/* Solution:
 * To avoid duplicates of subsets, we select only those elements in which the current element is not equal to the previous one.
 * To do so, we iterate the loop from current index to the array length, and if the current element is equal to the prev element, we skip considering that element.
 * And we take those elements which are not equal to the prev one.
 * Another Approach: we can also create a set and store all the possible subsets in it. Automatically all the duplicate subsets will be removed from the result. But doing so, it will increase the time complexity as for every element, it has to check the whole set.
 */

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class _90_SubsetSumII {
public:
    static vector<vector<int>> subsetWithDups(vector<int>& nums) {
        vector<vector<int>> nodups;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, nodups, ds);
        return nodups;
    }

    static void findSubsets(int index, vector<int>& nums, vector<vector<int>>& nodups, vector<int>& ds){
        nodups.push_back(ds);

        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, nodups, ds);
            ds.pop_back();
        }
        return;
    }
};

int main(){
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = _90_SubsetSumII::subsetWithDups(nums);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << ", ";
        }
        cout << "]";
    }
    cout << " ]";
    return 0;
}

// Time Complexity: O(n*2^n)
// Space Complexity: O(2^n)*O(k)
