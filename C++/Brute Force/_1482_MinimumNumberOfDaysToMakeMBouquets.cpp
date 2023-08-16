// Problem: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    static bool possible(vector<int>& bloomDay, int m, int k, int day){
        int n = bloomDay.size();

        int count = 0, noOfBouquets = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= day) count += 1;
            else{
                noOfBouquets += count/k;
                count = 0;
            }
        }

        noOfBouquets += count/k;

        return noOfBouquets >= m;
    }
public:
    static int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        for(int day = mini; day <= maxi; day++){
            if(possible(bloomDay, m, k, day)) return day;
        }

        return -1;
    }
};

int main(){
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3, k = 1;
    cout << Solution::minDays(bloomDay, m, k) << endl;
    return 0;
}

// Time Complexity: O((maxi - mini) * N)
// Space Complexity: O(1)