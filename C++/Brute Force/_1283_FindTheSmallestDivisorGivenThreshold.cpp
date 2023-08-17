// Problem: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    static int getSum(vector<int>& nums, int div, int threshold){
        int n = nums.size();

        double sum = 0;
        for(int i = 0; i < n; i++){
            double quotient = ceil((double)nums[i]/(double)div);
            sum += quotient; 
        }   
        return (int)sum;
    }
public:
    static int smallestDivisor(vector<int>& nums, int threshold) {
        int mini = INT_MAX;
        int maxi = *max_element(nums.begin(), nums.end());
        for(int div = 1; div <= maxi; div++){
            int sum = getSum(nums, div, threshold);
            if(sum <= threshold) return div;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    cout << Solution::smallestDivisor(nums, threshold);
    return 0;
}

// Time Complexity: O(maxi * N)
// Space Complexity: O(1)