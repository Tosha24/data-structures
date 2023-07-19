#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int frogJump(int ind, vector<int>& height, int k){
        if(ind == 0) return 0;
        int mini = INT_MAX;

        for(int j = 1; j <= k; j++){
            if(ind - j >= 0){
                int jumpK = frogJump(ind - j, height, k) + abs(height[ind] - height[ind - j]);
                mini = min(mini, jumpK);
            }
        }
        return mini;
    }
};

int main(){
    int n = 5;
    vector<int> height = {10, 40, 50, 20, 60};
    int k = 3;
    cout << Solution::frogJump(n-1, height, k) << endl;
    return 0;
}

// Time Complexity: O(kN)
// Space Complexity: O(N) --> recursion stack