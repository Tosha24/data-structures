// Problem: https://leetcode.com/problems/max-consecutive-ones/

/* Solution: 
 * We use two variables count (stores count of each ones) and max (stores maximum occurrence of ones).
 * We traverse through the array and if we encounter 0, we reset count to 0.
 * Otherwise, we increment count by 1 and check if max < count, if yes, we update max.
 * Finally, we return max.
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> nums){
    int count = 0, max = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            count = 0;
        }
        else{
            count = count + 1;
            if(max < count){
                max = count;
            }
        }
    }
    return max;
}

int main(){
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)