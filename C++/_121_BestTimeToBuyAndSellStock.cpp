// ✔️ Arrays

// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/* Solution: (Optimal Solution)
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
    int minPrice = prices[0];
    for(int i = 1; i < prices.size(); i++){
        int cost = prices[i] - minPrice;
        maxProfit = max(maxProfit, cost);
        minPrice = min(minPrice, prices[i]);
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)