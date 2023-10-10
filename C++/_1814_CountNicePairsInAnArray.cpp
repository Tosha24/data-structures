// Arrays, HashMap

// Problem: https://leetcode.com/problems/count-nice-pairs-in-an-array/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int countNicePairs(vector<int>& nums){
        int n = nums.size();
        unordered_map<int, int> mp;
        long long ans = 0;
        for(int i=0; i<n; i++){
            int rev = 0;
            int temp = nums[i];
            while(temp > 0){
                rev = rev*10 + temp%10;
                temp /= 10;
            }
            int diff = nums[i] - rev;
            if(mp.find(diff) != mp.end()){
                ans += mp[diff];
            }
            mp[diff]++;
        }
        return ans%1000000007;
    }
};

int main(){
    vector<int> nums = {13, 10, 35, 24, 76};
    cout << Solution::countNicePairs(nums) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)