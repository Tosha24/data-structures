// Problem: Print all the subsequences(continous/non-continous which are in order) of an array. 
// For eg: [3, 1, 2] have total 8 subsequences like [], [3], [1], [2], [3, 1], [3, 2], [1, 2], [3, 1, 2]

// Approach: Recursion

#include <iostream>
#include <vector>
using namespace std;

class _78_PrintSubsequence {
public:
    static void findSubset(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& seq) {
        if (index >= nums.size()) {  // termination condition: print the sequence when it reaches the end of the numsay.
            ans.push_back(seq);
            return;
        }
        seq.push_back(nums[index]);    // add the element at index to the sequence (to consider the element)
        findSubset(index + 1, nums, ans, seq);
        seq.pop_back();     // remove the element that was just added (to not consider the element)
        findSubset(index + 1, nums, ans, seq);
        return;
    }
    static vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> seq;
        findSubset(0, nums, ans, seq);
        return ans;
    }
};

int main() {
    vector<int> nums = { 8, 3, 6 };
    vector<vector<int>> ans = _78_PrintSubsequence::subsets(nums);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]";
    return 0;
}

// Time Complexity: O(2^N * N)
// Space Complexity: O(N)