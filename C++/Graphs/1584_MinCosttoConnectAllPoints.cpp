// Problem: https://leetcode.com/problems/min-cost-to-connect-all-points/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int minCostConnectPoints(vector<vector<int>>& points){
        int n = points.size();

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[0] = 0;
        int res = 0;

        for(int i = 0; i < n; i++){
            int u = -1;
            for(int j = 0; j < n; j++){
                if(!visited[j] && (u == -1 || dist[j] < dist[u])){
                    u = j;
                }
            }
            visited[u] = true;
            res += dist[u];

            for(int v = 0; v < n; v++){
                int d = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if(!visited[v] && d < dist[v]){
                    dist[v] = d;
                }
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << Solution::minCostConnectPoints(points) << endl;
    return 0;
}