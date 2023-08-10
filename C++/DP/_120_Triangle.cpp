#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution { 
public:
    static int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        
        vector<int> front(n, 0);
        for(int j = 0; j < n; j++){
            front[j] = triangle[n-1][j];
        }

        for(int i = n-2; i >= 0; i--){
            vector<int> curr(i+1, 0);
            for(int j = i; j >= 0; j--){
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j+1];

                curr[j] = min(down, diagonal);
            }
            front = curr;
        }

        return front[0];
    }
};

int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << Solution::minimumTotal(triangle) << endl;
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)