// Problem: https://leetcode.com/problems/3sum/

/* Solution:
 * 1. We will iterate through the array and find all the possible combinations of 3 numbers
 * 2. If the sum of the 3 numbers is 0, we will add it to the result
 * 3. We will use a set to avoid duplicates
 * 4. We will sort the list before adding it to the set
 * 5. We will add all the elements of the set to the result and return it.
 */

#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    int n = nums.size();

    set<vector<int>> triplet;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                if(sum == 0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sort(temp.begin(), temp.end());
                    triplet.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> result(triplet.begin(), triplet.end());
    return result;
}

int main() {
    vector<int> nums = {0, 0, 0};
    vector<vector<int>> result = threeSum(nums);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
    }
}

// Time Complexity: O(n^3)
// Space Complexity: O(2*no. of triplets)