// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/* Solution: (Brute Force)
 * 1. Iterate through the array
 * 2. Keep track of the minimum price
 * 3. Calculate the profit
 * 4. Update the maximum profit
 * 5. Return the maximum profit
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxProfit(vector<int> prices){
    int maxProfit = 0;
    for(int i = 0; i < prices.size(); i++){
        for(int j = i+1; j < prices.size(); j++){
            if(prices[j] > prices[i]){
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
    }
    return maxProfit;
} 

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)