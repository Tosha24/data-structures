// ✔️ Arrays, Bitwise Operator - XOR

// Problem: https://www.leetcode.com/problems/find-the-original-array-of-prefix-xor/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findArray(vector<int>& pref){
        int n = pref.size();

        for(int i = n - 1; i > 0; i--){
            pref[i] = pref[i] ^ pref[i - 1];
        }

        return pref;
    }
};


int main(){
    vector<int> pref = {5, 2, 0, 3, 1};
    vector<int> res = Solution().findArray(pref);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)