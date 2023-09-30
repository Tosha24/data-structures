// ✔️ Array

// Problem: https://leetcode.com/problems/number-of-arithmetic-triplets/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int arithmeticTriplets(vector<int>& nums, int diff){
        int n = nums.size();

        unordered_map<int, int> mp;
        int count = 0;

        for(int i = n - 1; i >= 0; i--){
            int num = nums[i];
            int nextNum1 = num + diff;
            int nextNum2 = num + 2 * diff;

            if(mp.find(nextNum1) != mp.end() && mp.find(nextNum2) != mp.end()){
                count += 1;
            }

            mp[num] += 1;
        }
        return count;
    }
};

int main(){
    vector<int> nums = {0, 1, 4, 6, 7, 10};
    int diff = 3;
    cout << Solution::arithmeticTriplets(nums, diff) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(2*n) ~ O(n)