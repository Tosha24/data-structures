// Problem: https://leetcode.com/problems/missing-number/

/* Solution:
 * We use the Gauss' Formula to solve this problem:
 * 1. Find sum of all the numbers from 1 to n using Gauss' Formula: sumN = n * (n+1)/2
 * 2. Subtract all the numbers in the array repeatedly from sumN
 * 3. The result obtained after subtracting all the numbers from the total sum will be the missing number.
 */

#include <bits/stdc++.h>
using namespace std;

class _268_MissingNumber{
public:
    static int missingNumber(int nums[], int n){
        int sumN = n * (n+1)/2;

        for(int i = 0; i < n; i++){
            sumN = sumN - nums[i];
        }
        return sumN;
    }
};

int main(){
    int nums[] = {0, 1};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << _268_MissingNumber::missingNumber(nums, n) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)