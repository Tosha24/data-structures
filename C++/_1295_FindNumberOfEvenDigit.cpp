// Problem: Given an array nums of integers, return how many of them contain an even number of digits.
// For eg: Input: nums = [12,345,2,6,7896]   ==>  Output: 2

// Approach: Brute force

#include <bits/stdc++.h>
using namespace std;

class _1295_FindNumberOfEvenDigit {
public:
    static int findNumber(vector<int>& nums){
        int count = 0;
        for(int item : nums){
            if(even(item)){
                count += 1;
            }
        }
        return count;
    }
    static bool even(int num){
        int numberOfDigits = digits(num);
        return (numberOfDigits%2==0);
    }
    static int digits(int num){
        return ((int)(log10(num)) + 1);
    }
};
int main(){
    vector<int> nums = {12, 345, 2, 6, 7896};
    cout << _1295_FindNumberOfEvenDigit::findNumber(nums);
    return 0;
}
