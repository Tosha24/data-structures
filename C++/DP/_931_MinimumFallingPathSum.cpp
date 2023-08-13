#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int minFallingPathSum(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> prev(n, 0);

        for(int j = 0; j < n; j++){
            prev[j] = matrix[0][j];
        }

        for(int i = 1; i < m; i++){
            vector<int> curr(n,0);
            for(int j = 0; j < n; j++){
                int up = matrix[i][j] + prev[j];
                int left = 1e6;
                if(j > 0){
                    left = matrix[i][j] + prev[j-1];
                }

                int right = 1e6;
                if(j < n-1){
                    right = matrix[i][j] + prev[j+1];
                }

                curr[j] = min(up, min(left, right));
            }
            prev = curr;
        }

        int mini = INT_MAX;
        for(int j = 0; j < n; j++){
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};

int main(){
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << Solution::minFallingPathSum(matrix) << endl;
    return 0;
}