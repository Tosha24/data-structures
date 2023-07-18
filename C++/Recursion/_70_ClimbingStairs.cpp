#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public: 
    static int climbStairs(int n){
        if(n == 0) return 1;
        if(n == 1) return 1;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main(){
    int n = 3;
    cout << Solution::climbStairs(n) << endl;
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N) -> recursion stack 