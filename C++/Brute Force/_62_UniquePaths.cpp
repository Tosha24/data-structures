// Problem: https://leetcode.com/problems/unique-paths/

/* Solution (Brute Force):
 * 1. We use recursion to solve this problem.
 * 2. We can move either right or down, so we can use recursion to solve this problem.
 */

/* Solution (Better Approach):
 * 1. We use recursion to solve this problem.
 * 2. We can move either right or down, so we can use recursion to solve this problem.
 * 3. We use DP to store the result of each step.
 * 4. We use dp matrix because we want to avoid the same recursion again in other recursion tree. (which makes it more efficient)
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Better Approach: Using DP
class _62_UniquePaths_DP {
public:
    static int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        return move_right_down(0, 0, m, n, dp);
    }
    static int move_right_down(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;

        if (dp[i][j] != 0)
            return dp[i][j];
        else
            return dp[i][j] = move_right_down(i + 1, j, m, n, dp) + move_right_down(i, j + 1, m, n, dp);
    }
};

// Brute Force Approach: Using recursion
class _62_UniquePaths {
public:
    static int move_right_down(int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) return 1;
        if (i >= m || j >= n) return 0;
        return move_right_down(i + 1, j, m, n) + move_right_down(i, j + 1, m, n);
    }

    static int uniquePaths(int m, int n) {
        return move_right_down(0, 0, m, n);
    }
};

int main()
{
    int m = 3, n = 7;
    cout << _62_UniquePaths::uniquePaths(m, n) << endl;
    cout << _62_UniquePaths_DP::uniquePaths(m, n) << endl;
}

// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)