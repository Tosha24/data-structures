// Problem: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. The solution set must not contain duplicate combinations.
// For eg: Input: candidates = [10,1,2,7,6,1,5], target = 8   ==>   Output: [[1,1,6], [1,2,5], [1,7], [2,6]]

// Approach: Recursion

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class _40_CombinationSumII
{
public:
    static void findCombinations(int index, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            ds.push_back(candidates[i]);
            findCombinations(i + 1, candidates, target - candidates[i], ans, ds);
            ds.pop_back();
        }
    }
    static vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, candidates, target, ans, ds);
        return ans;
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = _40_CombinationSumII::combinationSum(candidates, target);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]";
}

// Time Complexity: O(2^n * k)
// Space Complexity: O(n*k)