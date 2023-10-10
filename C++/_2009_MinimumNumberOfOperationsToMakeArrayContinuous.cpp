// Arrays, HashSet, Sorting, Sliding Window

// Problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution{
public:
    static int minOperations(vector<int>& nums){
        int n = nums.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
        }
        vector<int> a;
        for(auto i : s){
            a.push_back(i);
        }
        sort(a.begin(), a.end());
        int res = n;
        int r = 0;

        for(int l = 0; l < a.size(); l++){
            while(r < a.size() && a[r] < a[l] + n){
                r += 1;
            }
            int window = r - l;
            res = min(res, n - window);
        }

        return res;
    }
};

int main(){
    vector<int> nums = {4, 2, 5, 3};
    cout << Solution::minOperations(nums) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)