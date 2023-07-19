#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    // Memoization: TC - O(kN),  SC - O(N)
    static int frogJump(int n, vector<int> &height, int k)
    {
        vector<int> dp(n, -1);

        return jump(n-1, height, dp, k);
    }
    static int jump(int ind, vector<int> &height, vector<int> &dp, int k)
    {
        if (ind == 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        int mmSteps = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (ind - j >= 0)
            {
                int jumpK = jump(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
                mmSteps = min(jumpK, mmSteps);
            }
        }
        return dp[ind] = mmSteps;
    }
};

class Solution2_Tabulation
{
public:
    // Tabulation: TC - O(kN),   SC - O(N)
    static int frogJump(int n, vector<int> &height, int k)
    {
        vector<int> dp(n);

        dp[0] = 0;
        for (int ind = 1; ind < n; ind++)
        {
            int mini = INT_MAX;
            for(int j = 1; j < k; j++){
                if(ind - j >= 0){
                    int jumpK = dp[ind - j] + abs(height[ind] - height[ind - j]);
                    mini = min(jumpK, mini);
                }
            }
            dp[ind] = mini;
        }

        return dp[n - 1];
    }
};

int main()
{
    vector<int> height = {10, 40, 50, 20, 60};
    int n = 5;
    int k = 3;
    cout << Solution::frogJump(n, height, k) << endl;
    cout << Solution2_Tabulation::frogJump(n - 1, height, k) << endl;
    return 0;
}