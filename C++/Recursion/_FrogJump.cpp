#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int frogJump(int ind, vector<int>& height){
        if(ind == 0) return 0;

        int jumpTwo = INT_MAX;
        int jumpOne = frogJump(ind - 1, height) + abs(height[ind] - height[ind-1]);
        if(ind > 1) jumpTwo = frogJump(ind - 2, height) + abs(height[ind] - height[ind - 2]);

        return min(jumpOne, jumpTwo);
    }
};

int main(){
    int n = 4;
    vector<int> height = {10, 20, 30, 10};
    cout << Solution::frogJump(n-1, height) << endl;
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N) --> recursion stack