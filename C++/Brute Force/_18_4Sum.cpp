// Problem: https://leetcode.com/problems/4sum/

/* Solution (Brute Force):
 * 1. We use 4 pointer approach to solve the problem. The most naive approach.
 * 2. We iterate over the array using those 4 pointers.
 * 3. We check if the sum of those 4 pointers is equal to the target sum.
 * 4. If yes, then we add those 4 numbers to the set after sorting internally (this will avoid duplicates).
 * 5. Finally, we convert set into list. 
 */

#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
    set<vector<int>> quad;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                for(int l = k + 1; l < n; l++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        quad.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> result(quad.begin(), quad.end());
    return result;
}

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> result = fourSum(nums, target);
    for(int i = 0; i < result.size(); i++){
        cout << "[";
        for(int j = 0; j < result[0].size(); j++){
            cout << result[i][j] << ", ";
        }
        cout << "]";
        cout << endl;
    }
}

// Time Complexity: O(N^4)
// Space Complexity: O(2 * no of quadruplets) ----> here we use extra set to store the quadruplets in order to avoid duplicates