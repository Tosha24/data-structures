// Problem: https://leetcode.com/problems/longest-consecutive-sequence/

/* Solution (Optimal Solution):
 * 1. Create a hashset and add all the elements in the array to the hashset
 * 2. Iterate through the array and check if the hashset contains the element - 1
 * 3. If the hashset does not contain the element - 1, then we know that the element is the start of a sequence
 * 4. We then check how long the sequence is by incrementing the element by 1 and checking if the hashset contains the element + 1
 * 5. We keep incrementing the element by 1 until the hashset does not contain the element + 1  and we know that the sequence has ended
 * 6. We then update the longest variable to the length of the sequence if the length of the sequence is greater than the longest variable
 * 7. We return the longest variable
 */

#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    static int longestConsecutive(vector<int>& nums){
        unordered_set<int> hashset;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            hashset.insert(nums[i]);
        }

        int longest = 0;
        for(int i = 0; i < n; i++){
            if(hashset.find(nums[i] - 1) == hashset.end()){
                int count = 1;
                int x = nums[i];

                while(hashset.find(x + 1) != hashset.end()){
                    count = count + 1;
                    x += 1;
                }

                longest = max(longest, count);
            }
        }
        return longest;
    }
};

int main() {
    vector<int> nums = { 100, 4, 200, 1, 3, 2};
    cout << Solution::longestConsecutive(nums) << endl;
}

// Time Complexity: O(n)
// Space Complexity: O(n)