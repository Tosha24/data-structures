// Problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice.
// For eg: arr = [2, 7, 11, 15], target = 9   ==>  Output: [0, 1]

// Approach: Brute force

#include <bits/stdc++.h>
using namespace std;

class _1_TwoSum {
public:
    static vector<int> twoSum(vector<int>& nums, int target){
        vector<int> ans = {-1, -1};
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = _1_TwoSum::twoSum(nums, target);
    cout << "[ ";
    for(int i : ans){
        cout << i << ", ";
    }
    cout << "]" << endl;
    return 0;
}
