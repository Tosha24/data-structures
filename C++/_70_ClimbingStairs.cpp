// ✔️

// Problem: https://leetcode.com/problems/climbing-stairs/

/* Intuition: 
    - We can reach ith step in two ways:
        - Taking a single step from (i-1)th step
        - Taking a step of 2 from (i-2)th step
    - So, dp[i] = dp[i-1] + dp[i-2]
    - Base cases: dp[0] = 1, dp[1] = 1 (same like Fibonacci)
    - We can solve this problem using tabulation method or space optimization
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    // Tabulation method -> TC = O(n) , SC = O(n)
    static int climbStairs2(int n){
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2 ; i <= n ; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    // Space Optimization -> TC = O(n) , SC = O(1) 
    static int climbStairs(int n){
        int prev = 1, prev2 = 1;

        for(int i =2 ; i <=n; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

int main() {
    int n = 3;
    cout << Solution::climbStairs(n) << endl;
    return 0;
}