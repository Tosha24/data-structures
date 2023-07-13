// Problem: https://leetcode.com/problems/trapping-rain-water/

/* Intuition (Brute Force Approach):
 * For each element in the array, we find the maximum level of water it can trap after the rain,
 * which is equal to the minimum of maximum height of bars on both the sides minus its own height.
 */

/* Intuition (Better Approach):
 * In brute force, we iterate over the left and right parts again and again just to find the highest bar size upto that index.
 * But, this could be stored if we just traverse the array twice from both the ends and store these values in two arrays.
 */

class BruteForce {
    static int trap(int[] height){
        int n = height.length;

        int waterTrapped = 0;
        
        for(int i = 0; i < n; i++){
            int left = maximum(height, 0, i);
            int right = maximum(height, i, n-1);

            int minimum = Math.min(left, right);

            waterTrapped += minimum - height[i];
        }
        return waterTrapped;
    }
    private static int maximum(int[] height, int start, int end){
        int max = 0;
        for(int i = start; i <= end; i++){
            max = Math.max(max, height[i]);
        }
        return max;
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)


public class _42_TrappingRainWater{
    private static int trap(int[] height){
        int n = height.length;
        int waterTrapped = 0;

        int[] prefix = new int[n];
        int[] suffix = new int[n];

        // creating prefix array
        for(int i = 0; i < n; i++){
            prefix[i] = Math.max(height[i], (i == 0) ? 0 : prefix[i - 1]);
        }

        // Creating suffix array
        for(int i = n-1; i >= 0; i--){
            suffix[i] = Math.max(height[i], (i == n - 1) ? 0: suffix[i + 1]);
        }

        // Calculating water trapped
        for(int i = 0; i < n; i++){
            waterTrapped += Math.min(prefix[i], suffix[i]) - height[i];
        }
        return waterTrapped;
    }
       public static void main(String[] args) {
        int[] height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        System.out.println(trap(height));
        System.out.println(BruteForce.trap(height));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(2n) ---> for prefix and suffix arrays