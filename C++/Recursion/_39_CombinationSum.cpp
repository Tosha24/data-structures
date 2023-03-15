// Problem: Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. The same number may be chosen from candidates an unlimited number of times.
// For eg: Input: candidates = [2,3,6,7], target = 7   ==>   Output: [[2,2,3],[7]]

// Approach: Recursion
/* Solution: 
 * We continue choosing the same index, until we find that either the target gets zero(means our solution is inside data structure) or the current element is greater than the target we need to find (means we cannot choose that element because it will get bigger than the target). 
 * On each function call (for the same index), we keep decreasing the target variable until the target is zero or is less than the current element in the array. After finding for the same index, we find for the next index. We continue finding for the next index, until our index reaches the maximum of the array size.
 */

#include <iostream>
#include <vector>
using namespace std;

class _39_CombinationSum {
public:
    static void findCombination(int index, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ds){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            findCombination(index, candidates, target - candidates[index], ans, ds);
            ds.pop_back();
        }
        findCombination(index + 1, candidates, target, ans, ds);
        return;
    }
    static vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, candidates, target, ans, ds);
        return ans;
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> finalList = _39_CombinationSum::combinationSum(candidates, target);
    for(int i = 0; i < finalList.size(); i++){
        for(int j = 0; j < finalList[i].size(); j++){
            cout << finalList[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(2^n * k)
// Space Complexity: O(k*n)