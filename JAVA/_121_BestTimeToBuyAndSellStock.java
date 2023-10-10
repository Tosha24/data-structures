// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/* Solution: (Optimal Solution)
 * 1. Iterate through the array
 * 2. Keep track of the minimum price
 * 3. Calculate the profit
 * 4. Update the maximum profit
 * 5. Return the maximum profit
 */

public class _121_BestTimeToBuyAndSellStock {
    private static int maxProfit(int[] prices){
        int maxProfit = 0;
        int mini = prices[0];
        for(int i = 1; i < prices.length; i++){
            int cost = prices[i] - mini;
            maxProfit = Math.max(maxProfit, cost);
            mini = Math.min(mini, prices[i]);
        }
        return maxProfit;
    }
    public static void main(String[] args) {
        int[] prices = {7, 1, 5, 3, 6, 4};
        System.out.print(maxProfit(prices));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)