// Problem: https://leetcode.com/problems/kth-missing-positive-number/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 0, end = n - 1;
        while(start <= end){
            int mid = start + (end - start)/2;

            int missing = arr[mid] - (mid + 1);

            if(missing < k) start = mid + 1;
            else end = mid - 1;
        }
        return k + end + 1;
    }
};

int main(){
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    cout << Solution::findKthPositive(arr, k) << endl;
    return 0;
}

// Time Complexity: O(log(n))
// Space Complexity: O(1)