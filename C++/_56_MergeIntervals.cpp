// ✔️ Arrays

// Problem: https://leetcode.com/problems/merge-intervals/

/* Solution: 
*  1. Sort the intervals based on the first element of each interval
*  2. Push the first interval into the result vector
*  3. If the last element of the result vector is smaller than the first element of the current interval, push the current interval into the result vector
*  4. Else, update the last element of the result vector with the max value of the last element of the result vector and the last element of the current interval
*  5. Return the result vector
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals){
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());

    for(int i = 0; i < intervals.size(); i++){
        if(result.empty() || result.back()[1] < intervals[i][0]){
            result.push_back(intervals[i]);
        }
        else{   
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
    }
    return result;
}

int main(){
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = merge(intervals);
    for (int i = 0; i < result.size(); i++){
        cout << "[" << result[i][0] << ", " << result[i][1] << "], ";
    }
    return 0;
}

// Time Complexity: O(nlogn) + O(n)         ----> nlogn for sorting and n for traversing
// Space Complexity: O(n)           ---> n for storing answers