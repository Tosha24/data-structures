// ✔️ Arrays, HashMap

// Problem: https://leetcode.com/problems/number-of-good-pairs/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int numIdenticalPairs(vector<int>& nums){
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> hash;

        for(int i = 0; i < n; i++){
            if(hash.find(nums[i]) != hash.end()){
                count += hash.at(nums[i]);
                hash.at(nums[i]) += 1;
            }
            else{
                hash[nums[i]] = 1;
            }
        }
        return count;
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << Solution::numIdenticalPairs(nums) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)