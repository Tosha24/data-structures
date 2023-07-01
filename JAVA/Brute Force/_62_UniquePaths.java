// Problem: https://leetcode.com/problems/unique-paths/

/* Solution (Brute Force): 
 * 1. We use recursion to solve this problem.
 * 2. We can move either right or down, so we can use recursion to solve this problem.
 */

public class _62_UniquePaths{
    private static int uniquePaths(int m, int n){
        return move_right_down(0, 0, m, n);
    }
    private static int move_right_down(int i, int j, int m, int n){
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }
        return move_right_down(i + 1, j, m, n) + move_right_down(i, j+1, m, n);
    }
    public static void main(String[] args) {
        int m = 5, n = 3;
        System.out.println(uniquePaths(m, n));
        _62_UniquePaths_DP obj = new _62_UniquePaths_DP();
        System.out.println(obj.better_solution(m, n));
    }
}

/* Solution (Better Approach):
 * 1. We use recursion to solve this problem.
 * 2. We can move either right or down, so we can use recursion to solve this problem.
 * 3. We use DP to store the result of each step.
 * 4. We use dp matrix because we want to avoid the same recursion again in other recursion tree. (which makes it more efficient)
 */

class _62_UniquePaths_DP{
    private static int uniquePaths(int m, int n){
        int[][] dp = new int[m][n];
        return move_right_down(0, 0, m, n, dp);
    }
    private static int move_right_down(int i, int j, int m, int n, int[][] dp){
        if(i == m - 1 && j == n - 1) return 1;
        if(i >= m || j >= n) return 0;

        if(dp[i][j] != 0) return dp[i][j];
        else return dp[i][j] = move_right_down(i+1, j, m, n, dp) + move_right_down(i, j+1, m, n, dp);
    }  
    int better_solution(int m, int n){
        return uniquePaths(m, n);
    }
}

// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)