// ✔️ Arrays [Hint: Sorting, Diff = sum - target, min distance]

// Problem: https://leetcode.com/problems/3sum-closest/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closestSum = INT_MAX, minDiff = INT_MAX;

        for(int i = 0; i < n; i++){
            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);

                if(diff < minDiff){
                    minDiff = diff;
                    closestSum = sum;
                }

                if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        return closestSum;
    }
};

int main(){
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << Solution::threeSumClosest(nums, target) << endl;
    return 0;
}

// Time Complexity: O(logn) + O(n)
// Space Complexity: O(1)