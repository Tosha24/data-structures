// Problem: https://leetcode.com/problems/trapping-rain-water/

/* Intuition (Optimal Solution):
 * 1. Use two pointers, one from left and one from right.
 * 2. Keep track of the leftmax and rightmax.
 * 3. If height[l] <= height[r], then if height[l] >= leftmax, update leftmax, else add leftmax - height[l] to waterTrapped.
 * 4. If height[l] > height[r], then if height[r] >= rightmax, update rightmax, else add rightmax - height[r] to waterTrapped.
 * 5. Return waterTrapped.
 */

package Arrays;
public class _42_TrappingRainWater {
    private static int trap(int[] height){
        int waterTrapped = 0;
        int n = height.length;  
        int leftmax = 0;
        int rightmax = 0;

        int l = 0, r = n - 1;

        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] >= leftmax) leftmax = height[l];
                else waterTrapped += leftmax - height[l];
                l++;
            }
            else{
                if(height[r] >= rightmax) rightmax = height[r];
                else waterTrapped += rightmax - height[r];
                r--;
            }
        }

        return waterTrapped;
    }
    public static void main(String[] args) {
        int[] height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        System.out.println(trap(height));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)