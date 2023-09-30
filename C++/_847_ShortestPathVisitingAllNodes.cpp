// Problem: https://leetcode.com/problems/shortest-path-visiting-all-nodes/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int shortestPathLength(vector<vector<int>>& graph){
        int n = graph.size();
        int target = (1 << n) - 1;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        for(int i = 0; i < n; i++){
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                if(curr.second == target) return steps;
                for(auto next : graph[curr.first]){
                    int mask = curr.second | (1 << next);
                    if(!visited[next][mask]){
                        q.push({next, mask});
                        visited[next][mask] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    cout << Solution::shortestPathLength(graph) << endl;
    return 0;
}