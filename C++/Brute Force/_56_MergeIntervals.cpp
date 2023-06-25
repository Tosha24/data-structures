// Problem: https://leetcode.com/problems/merge-intervals/

/* Solution:
* 1. Sort the intervals by start time
* 2. Iterate through the intervals
* 3. If the current interval's start time is less than the previous interval's end time, then merge the intervals
* 4. Else, add the interval to the result
*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());

    for(int i = 0; i < intervals.size(); i++){
        int start = intervals[i][0];
        int end = intervals[i][1];

        if(!result.empty() && end <= result.back()[1]){     // if that interval is already merged, then skip
            continue;
        }

        for(int j = i + 1; j < intervals.size(); j++){ 
            if(intervals[j][0] <= end){                 // if the current interval's start time is less than the previous interval's end time, then merge the intervals
                end = max(end, intervals[j][1]);
            }
            else{           // if the current interval's start time is greater than the previous interval's end time, then break because we do not want to check further
                break;
            }
        }
        result.push_back({start, end});
    }
    return result;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = merge(intervals);
    for(int i = 0; i < result.size(); i++){
        cout << "[" << result[i][0] << ", " << result[i][1] << "], ";
    }
    return 0;
}

// Time Complexity: O(nlogn) + O(2n)
// Space Complexity: O(n)