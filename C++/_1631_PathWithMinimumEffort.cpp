// Problem: https://leetcode.com/problems/path-with-minimum-effort/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int minimumEffortPath(vector<vector<int>>& heights) {
        // Creating a min heap priority queue that arranges elements in ascending order of the pair : Syntax: priority_queue<type, vector<type>, greater<type>> pq;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n,1e9));    // It will store the min distance 
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        // To interate over all the four directions from the current cell
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Base case: if the row and col is the destination
            if(row == m - 1 && col == n - 1) return diff;

            for(int i = 0; i < 4; i++){
                int newR = row + dr[i];
                int newC = col + dc[i];

                if(newR >= 0 && newC >= 0 && newR < m && newC < n){
                    // Finding the max of all differences
                    int newEffort = max(abs(heights[row][col] - heights[newR][newC]), diff);

                    // changing the cell value only if the dist in min than already present element 
                    if(newEffort < dist[newR][newC]){
                        dist[newR][newC] = newEffort;
                        pq.push({newEffort, {newR, newC}});
                    }
                }
            }
        }
        return 0;   // unreachable
    }
};

int main(){
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    cout << Solution::minimumEffortPath(heights) << endl;
    return 0;
}

// Time Complexity: O(4*N*M * log(N*M)) where N*M are the total cells, log(N*M) for insertion-deletion operations in priority_queue
// Space Complexity: O(N*M) for the dist matrix and priority_queue