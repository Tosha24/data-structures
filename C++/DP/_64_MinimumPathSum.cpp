#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);
        
        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    curr[j] = grid[i][j];
                    continue;
                }

                int up = grid[i][j];
                if(i > 0) up += prev[j];
                else up += 1e6;

                int left = grid[i][j];
                if(j > 0) left += curr[j-1];
                else left += 1e6;

                curr[j] = min(up, left);
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << Solution::minPathSum(grid) << endl;
    return 0;
}

// Time Complexity: O(N*M)
// Space Complexity: O(N)