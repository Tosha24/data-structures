// Problem: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    static int getSum(vector<int>& nums, int div){
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
        int n = nums.size();
        if (n > threshold) return -1;
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = (low + high) / 2;
            if (getSum(nums, mid) <= threshold) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main(){
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    cout << Solution::smallestDivisor(nums, threshold);
    return 0;
}

// Time Complexity: O(nlog(maxi))
// Space Complexity: O(1)