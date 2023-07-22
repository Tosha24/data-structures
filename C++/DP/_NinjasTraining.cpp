#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution_Memoization {
public:
    // Memoization: TC - O(n*4*3), SC - O(n) + O(n*4)
    static int ninjaTraining(int n, vector<vector<int>> &points) {
        int last = 3;
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(points, n - 1, last, dp);
    }
    static int solve(vector<vector<int>>& points, int day, int last, vector<vector<int>>& dp) {
        if(dp[day][last] != -1) return dp[day][last];

        if(day == 0) {
            int maxi = 0;
            for(int a = 0; a < 3; a++){
                if(a != last) {
                    maxi = max(maxi, points[0][a]);
                }
            }
            return dp[day][last] = maxi;
        }
        else{
            int maxi = 0;
            for(int a = 0; a < 3; a++){
                if(a != last){
                    int activity_points = points[day][a] + solve(points, day - 1, a, dp);
                    maxi = max(maxi, activity_points);
                }
            }
            return dp[day][last] = maxi;
        }
    }
};

class Solution_Tabulation {
public:
    // Tabulation: TC - O(n*4*3), SC - O(n*4)
    static int ninjaTraining(int n, vector<vector<int>>& points){
        vector<vector<int>> dp(n, vector<int>(4));

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        for(int day = 1; day < n; day++){
            for(int last = 0; last < 4; last++){
                dp[day][last] = 0;
                for(int a = 0; a < 3; a++){
                    if(a != last){
                        int activity_points = points[day][a] + dp[day - 1][a];
                        dp[day][last] = max(dp[day][last], activity_points);
                    }
                }
            }
        }

        return dp[n-1][3];
    }
};

class Solution_SpaceOptimization {
public:
    // Space Optimization: TC - O(n*4*3), SC - O(4)
    static int ninjaTraining(int n, vector<vector<int>>& points) {
        vector<int> prev(4,0);

        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

        for(int day = 1; day < n; day++){
            vector<int> curr(4, 0);
            for(int last = 0; last < 4; last++){
                for(int a = 0; a < 3; a++){
                    if(a != last){
                        int activity_points = points[day][a] + prev[a];
                        curr[last] = max(curr[last], activity_points);
                    }
                }
            }
            prev = curr;
        }
        return prev[3];
    }
};

int main(){
    vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    int n = points.size();

    cout << Solution_Memoization::ninjaTraining(n, points) << endl;
    cout << Solution_Tabulation::ninjaTraining(n, points) << endl;
    cout << Solution_SpaceOptimization::ninjaTraining(n, points) << endl;
    return 0;
}