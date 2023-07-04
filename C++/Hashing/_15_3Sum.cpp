// Problem: https://leetcode.com/problems/3sum/

/* Solution (Better Solution using Set and hashing)
 * 1. We use a list to store each triplets
 * 2. We use a set to store the middle elements (nums[j])
 * 3. We use a hashset to store the third element (-1 * sum)
 * 4. If the hashset contains the third element, we add the triplet to the list, otherwise we add the jth element to the hashset.
 * 5. Finally, we add the set to the list, so that we don't have duplicate triplets
 */

#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    set<vector<int>> triplets;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        set<long long> hashset;
        for(int j = i + 1; j < n; j++){
            long long sum = nums[i];
            sum += nums[j];
            long long third = (-1) * sum;
            if(hashset.find(third) != hashset.end()){
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back((int) third);
                sort(temp.begin(), temp.end());
                triplets.insert(temp);
            }
            hashset.insert((long long)nums[j]);
        }
    }
    
    vector<vector<int>> result(triplets.begin(), triplets.end());
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; 
    vector<vector<int>> result = threeSum(nums);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(N^2 + log(m)) --> n = size of array, m = no. of elements in the set (because we search for the third element in the set)
// Space Complexity: O(2*triplets) + O(n) ---> O(n) for hashset that stores the middle elements and O(2*triplets) for set that stores the triplets, and also for the list that stores the triplets  