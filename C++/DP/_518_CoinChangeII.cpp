#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    static int change(int amount, vector<int>& coins){
        int n = coins.size();
        
        vector<int> prev(amount + 1, 0);

        for(int j = 0; j <= amount; j++){
            if(j % coins[0] == 0) prev[j] = 1;
        }

        for(int i = 1; i < n; i++){
            vector<int> curr(amount+1, 0);
            for(int j = 0; j <= amount; j++){
                int nottake = prev[j];

                int take = 0;
                if(coins[i] <= j) take = curr[j - coins[i]];

                curr[j] = nottake + take;
            }
            prev = curr;
        }

        return prev[amount];
    }
};

int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << Solution::change(amount, coins) << endl;
    return 0;
}

// Time Complexity: O(N * T)
// Space Complexity: O(T)