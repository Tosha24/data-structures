// ✔️ Arrays

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private: 
    static bool isPossible(vector<int>& nums, int p, int diff){
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] <= diff){
                p--;
                i++;
            }
        }
        return p<=0;
    }
public:
    static int minimizeMax(vector<int>& nums, int p){
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums[n - 1] - nums[0];
        int ans = right;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(isPossible(nums, p, mid)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {10, 1, 2, 7, 1, 3};
    int p = 2;
    cout << Solution::minimizeMax(nums, p) << endl;
    return 0;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(1)