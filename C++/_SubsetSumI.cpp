// Solved in GFG
// Problem: Given a list arr of N integers, print sums of all subsets in it.
// For eg: Input: arr = [2, 3]   ==>  Output: [0, 2, 3, 5]

// Approach: Recursion and backtracking

#include <bits/stdc++.h>
using namespace std;

class _SubsetSumI{
public:
    static vector<int> subsetSums(vector<int>& nums, int N){
        vector<int> ans;
        findSubsets(0, nums, N, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
    static void findSubsets(int index, vector<int>& nums, int N, int sum, vector<int>& ans){
        if(index == N){
            ans.push_back(sum);
            return;
        }
        
        sum = sum + nums[index];
        findSubsets(index + 1, nums, N, sum, ans);
        
        sum = sum - nums[index];
        findSubsets(index + 1, nums, N, sum, ans);
        return;
    }
};

int main(){
    vector<int> nums = {2, 3};
    int N = nums.size();
    vector<int> ans = _SubsetSumI::subsetSums(nums, N);
    cout << "[ ";
    for(int i : ans){
        cout << i << ", ";
    }
    cout << "]" << endl;
    return 0;
}

// Time Complexity: O(2^N + 2^N*log(2^N)) 
// Space Complexity: O(2^N)