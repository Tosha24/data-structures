// Dynamic Programming

// Problem: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int dp[51][51][101];
    int N, M, K;
    int solve(int idx, int lenLis, int lar){
        if(idx == N){
            if(lenLis == K){
                return 1;
            }
            return 0;
        }
        if(dp[idx][lenLis][lar] != -1)
            return dp[idx][lenLis][lar];
        int ans = 0;
        for(int i = 1; i <= M; i++){
            if(i > lar){
                ans += solve(idx+1, lenLis+1, i);
            }
            else{
                ans += solve(idx+1, lenLis, lar);
            }
            ans = ans % 1000000007;
        }
        return dp[idx][lenLis][lar] = ans;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};

int main(){
    Solution s;
    int n = 2, m = 3, k = 1;
    cout << s.numOfArrays(n, m, k) << endl;
    return 0;
}