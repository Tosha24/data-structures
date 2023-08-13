#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int minFallingPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);
        
        for(int j = 0; j < n; j++){
            prev[j] = grid[0][j];
        }

        for(int i = 1; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
                int ans = 1e6;

                for(int k = 0; k < n; k++){
                    if(k == j) continue;
                    ans = min(ans, grid[i][j] + prev[k]);
                }

                curr[j] = ans;
            }
            prev = curr;
        }

        int mini = INT_MAX;
        for(int j = 0; j < n; j++){
            mini = min(prev[j], mini);
        }

        return mini;
    }
};

int main(){
    vector<vector<int>> grid = {{-73,61,43,-48,-36},{3,30,27,57,10},{96,-76,84,59,-15},{5,-49,76,31,-7},{97,91,61,-46,67}};
    cout << Solution::minFallingPathSum(grid) << endl;
    return 0;
}

// Time Complexity: O(N) + O(N) + O(M*N*N) ==> O(M*N*N)
// Space Complexity: O(N) + O(N) ==> O(N)