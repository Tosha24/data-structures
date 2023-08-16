// Problem: https://leetcode.com/problems/koko-eating-bananas/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    static int findMax(vector<int>& v) {
        int maxi = INT_MIN;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    static double calculateTotalHours(vector<int> &v, int hourly) {
        double totalH = 0;
        int n = v.size();
        //find total hours:
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)(v[i]) /(double)(hourly));
        }
        return totalH;
    }
public:
    static int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while (low <= high) {
            int mid = (low + high) / 2;
            double totalH = calculateTotalHours(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main(){
    vector<int> piles = {3,6,7,11};
    int H = 8;
    cout << Solution::minEatingSpeed(piles, H) << endl;
    return 0;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(1)