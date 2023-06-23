// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/* Solution: (Brute Force)
 * 1. Iterate through the array
 * 2. Keep track of the minimum price
 * 3. Calculate the profit
 * 4. Update the maximum profit
 * 5. Return the maximum profit
 */

public class _121_BestTimeToBuyAndSellStock {
    private static int maxProfit(int[] prices){
        int maxProfit = 0;
        for(int i = 0; i < prices.length; i++){
            for(int j = i+1; j < prices.length; j++){
                if(prices[j] > prices[i]){
                    maxProfit = Math.max(maxProfit, prices[j] - prices[i]);
                }
            }
        }
        return maxProfit;
    }
    public static void main(String[] args) {
        int[] prices = {7,1,5,3,6,4};
        System.out.println(maxProfit(prices));
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)