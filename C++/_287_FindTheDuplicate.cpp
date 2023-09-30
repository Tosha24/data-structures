// ✔️ Arrays

// Problem: Find the duplicate number in the array, only one repeated number here so return that number
// For eg: Input: nums = [1, 3, 4, 2, 2]   ==>  Output: 2

// Approach: Brute Force 

#include <bits/stdc++.h>
using namespace std;

class _287_FindTheDuplicate {
public:
    static int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << _287_FindTheDuplicate::findDuplicate(nums) << endl;
    return 0;
}
