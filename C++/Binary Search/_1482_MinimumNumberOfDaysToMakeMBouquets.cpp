// Problem: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    static int possible(vector<int>& bloomDay, int m, int k, int day){
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

        long long multi = m * 1ll * k * 1ll;
        if(multi > n) return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        int start = mini, end = maxi;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(possible(bloomDay, m, k, mid)){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

        return start;
    }
};

int main(){
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3, k = 1;
    cout << Solution::minDays(bloomDay, m, k) << endl;
    return 0;
}

// Time Complexity: O(nlog(maxi-mini))
// Space Complexity: O(1)