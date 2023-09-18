// Problem: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    static int calculateSoldiers(vector<int>& row){
        int low = 0;
        int high = row.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(row[mid] == 0) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
public:
    static vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for(int i = 0; i < rows; i++){
            int numberOfSoldiers = calculateSoldiers(mat[i]);
            min_heap.push({numberOfSoldiers, i});
        }

        vector<int> ans;
        for(int j = 0; j < k; j++){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> mat = {{1,1,0,0,0},
                               {1,1,1,1,0},
                               {1,0,0,0,0},
                               {1,1,0,0,0},
                               {1,1,1,1,1}};
    int k = 3;
    vector<int> result = Solution::kWeakestRows(mat, k);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}