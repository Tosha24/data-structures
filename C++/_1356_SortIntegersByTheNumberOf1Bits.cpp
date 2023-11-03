// ✔️ Arrays, Bit manipulation, Sorting

// Problem: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int countBits(int num){
        int count = 0;

        while(num != 0){
            count += num & 1;
            num = num >> 1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

        // Main code : Sorting the function by comparing with count bits
        sort(arr.begin(), arr.end(), [](int a, int b){
            int count_a = Solution().countBits(a);  // built in function can also be used: __builtin_popcount(a);
            int count_b = Solution().countBits(b);  // built in function can also be used: __builtin_popcount(b);
        
            if(count_a == count_b) return a < b;

            return count_a < count_b;
        });

        return arr;
    }
};

int main(){
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> res = Solution().sortByBits(arr);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(1)