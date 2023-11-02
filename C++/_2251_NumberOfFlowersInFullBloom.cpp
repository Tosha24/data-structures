// Arrays, Sorting, Upper and Lower Bound

// Problem: https://leetcode.com/problems/number-of-flowers-in-full-bloom/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution{
public:
    static vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people){
        int noOfFlowers = flowers.size();
        int noOfPeople = people.size();

        vector<int> result(noOfPeople);
        vector<int> start_time(noOfFlowers);
        vector<int> end_time(noOfFlowers);

        for(int f = 0; f < noOfFlowers; f++){
            start_time[f] = flowers[f][0];
            end_time[f] = flowers[f][1];
        }

        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());

        for(int p = 0; p < noOfPeople; p++){
            int time = people[p];
            int bloomed_flower_already = upper_bound(start_time.begin(), start_time.end(), time) - start_time.begin();
            int died_already = lower_bound(end_time.begin(), end_time.end(), time) - end_time.begin();
            result[p] = bloomed_flower_already - died_already;
        }

        return result;
    } 
};

int main(){
    vector<vector<int>> flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    vector<int> people = {2, 3, 7, 11};
    vector<int> res = Solution::fullBloomFlowers(flowers, people);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << ", ";
    }
    return 0;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(n)