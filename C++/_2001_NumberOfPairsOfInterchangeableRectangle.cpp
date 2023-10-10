// ✔️ Arrays, HashMap

// Problem: https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static long long interchangeableRectangles(vector<vector<int>>& rectangles){
        int n = rectangles.size();
        unordered_map<double, int> map;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            double ratio = (double)rectangles[i][0] / (double)rectangles[i][1];
            if(map.find(ratio) != map.end()){
                ans += map[ratio];
            }
            map[ratio]++;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> rectangles = {{4,8},{3,6},{10,20},{15,30}};
    cout << Solution::interchangeableRectangles(rectangles) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)