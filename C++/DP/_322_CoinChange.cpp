#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int coinChange(vector<int>& coins, int amount){
        int n = coins.size();

        vector<int> prev(amount+1, 0);

        for(int j = 0; j <= amount; j++){
            if(j%coins[0] == 0) prev[j] = j / coins[0];
            else prev[j] = 1e6;
        }

        for(int i = 1; i < n; i++){
            vector<int> curr(amount+1, 0);
            for(int j = 0; j <= amount; j++){
                int nottake = prev[j];

                int take = INT_MAX;
                if(coins[i] <= j) take = 1 + curr[j - coins[i]];

                curr[j] = min(take, nottake);
            }
            prev = curr;
        }

        int ans = prev[amount];
        if(ans >= 1e6) return -1;

        return ans;
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << Solution::coinChange(coins, amount) << endl;
    return 0;
}

// Time Complexity: O(N * T)
// Space Complexity: O(T)