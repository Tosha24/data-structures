#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class _MinimumNumberOfCoins {
public: 
    static vector<int> minCoins(int coins[], int V, int n){
        sort(coins, coins + n);

        int min_coin = 0;
        vector<int> denominations;

        for(int i = n - 1; i >= 0; i--){
            while(coins[i] <= V){
                V -= coins[i];
                denominations.push_back(coins[i]);
                min_coin++;
            }
        }
        return denominations;
    }
};

int main(){
    int V = 49;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    vector<int> result =  _MinimumNumberOfCoins::minCoins(coins, V, n);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}

// Time Complexity: O(NlogN) + O(N^2)
// Space Complexity: O(N)