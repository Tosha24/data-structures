// Problem: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    static int sumOfElements(vector<int>& weights){
        int n = weights.size();

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += weights[i];
        }
        return sum;
    }
    static int getDays(vector<int>& weights, int capacity){
        int n = weights.size();

        int noOfDays = 1, load = 0;
        for(int i = 0; i < n; i++){
            if(load + weights[i] > capacity){
                noOfDays += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return noOfDays;
    }
public:
    static int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = sumOfElements(weights);

        while(start <= end){
            int mid = start + (end - start)/2;      // Here mid is the capacity of the ship

            if(getDays(weights, mid) <= days) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << Solution::shipWithinDays(weights, days) << endl;
    return 0;
}

// Time Complexity: O(n*log(sumOfElements - maxElement))
// Space Complexity: O(1)