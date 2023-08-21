// Problem: https://leetcode.com/problems/maximal-network-rank/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> count(n);
        vector<vector<int>> direct(n, vector<int>(n));

        for(vector<int> road: roads){
            count[road[0]]++;
            count[road[1]]++;
            direct[road[0]][road[1]] = 1;
            direct[road[1]][road[0]] = 1;
        }

        int rank = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                rank = max(rank, count[i] + count[j] - direct[i][j]);
            }
        }
        return rank;
    }
};

int main(){
    vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    int n = 6;
    cout << Solution::maximalNetworkRank(n, roads) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n*n)