// DP

// Problem: https://leetcode.com/problems/integer-break/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution{
public:
    static int integerBreak(int n){
        if(n == 2) return 1;
        if(n == 3) return 2;
        int res = 1;
        while(n > 4){
            res *= 3;
            n -= 3;
        }
        res *= n;
        return res;
    }
};

int main(){
    int n = 10;
    cout << Solution::integerBreak(n) << endl; // 36  
    return 0;
}