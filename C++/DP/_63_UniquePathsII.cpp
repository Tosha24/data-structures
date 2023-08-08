#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// DP: Space Optimization --> TC = O(N * M) , SC = O(N)
class Solution_SO {
public:
    static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    curr[j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    curr[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = curr[j-1];

                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

int main(){
    vector<vector<int>> obstacleGrid = {{0,0,1},{0,1,0},{0,0,0}};
    cout << Solution_SO::uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}