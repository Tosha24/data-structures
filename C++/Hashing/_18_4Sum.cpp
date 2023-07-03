// Problem: https://leetcode.com/problems/4sum/

/* Solution (Better Solution using Set and hashing)
 * 1. We use a list to store each quadruplets
 * 2. We use a set to store the middle elements (nums[j] + nums[k])
 * 3. We use a hashset to store the fourth element (target - sum)
 * 4. If the hashset contains the fourth element, we add the quadruplet to the list, otherwise we add the kth element to the hashset.
 * 5. Finally, we add the set to the list, so that we don't have duplicate quadruplets
 */

#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
    set<vector<int>> res;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            set<long long> hashset;
            for(int k = j + 1; k < n; k++){
                long sum = nums[i] + nums[j];
                sum += nums[k];

                long fourth = target - sum;
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> quad;
                    quad.push_back(nums[i]);
                    quad.push_back(nums[j]);  
                    quad.push_back(nums[k]);
                    quad.push_back((int)fourth);
                    sort(quad.begin(), quad.end());

                    res.insert(quad);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(res.begin(), res.end());
    return ans;
}

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> result = fourSum(nums, target);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

// Time Complexity: O(N^3 + log(m)) --> n = size of array, m = no. of elements in the set (because we search for the fourth element in the set)
// Space Complexity: O(2*quadruplets) + O(n) ---> O(n) for hashset that stores the middle elements and O(2*quadruplets) for set that stores the quadruplets, and also for the list that stores the quadruplets  