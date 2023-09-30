// Arrays [Hint: Prev, Curr, Succ Pointers; Point to only not equal neighbours]

// Problem: https://www.geeksforgeeks.org/count-hills-and-valleys-in-an-array/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int countHillValley(vector<int>& nums){
        int n = nums.size();

        int count = 0;

        for(int i = 1; i < n - 1; i++){
            if(nums[i] == nums[i-1]) continue;

            int j = i - 1, k = i + 1;

            while(j >= 0 && nums[j] == nums[i]) j--;
            while(k < n && nums[i] == nums[k]) k++;

            if(k >= n || j < 0) continue;

            if(nums[i] < nums[j] && nums[i] < nums[k]) count += 1;  // i is a valley
            else if(nums[i] > nums[j] && nums[i] > nums[k]) count += 1;  // i is a hill
        }

        return count;
    }
};

int main(){
    vector<int> nums = {2, 4, 1, 1, 6, 5};
    cout << Solution::countHillValley(nums) << endl;
    return 0;
}

// Time Complexity: O(n) 
// Space Complexity: O(1)