// Problem: https://leetcode.com/problems/kth-missing-positive-number/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution{
public:
    static int findKthPositive(vector<int>& arr, int k){
        int n = arr.size();

        for(int i = 0; i < n; i++){
            if(arr[i] <= k) k++;
            else break;
        }

        return k;
    }
};

int main(){
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    cout << Solution::findKthPositive(arr, k) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)