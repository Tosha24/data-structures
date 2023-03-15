// Problem: To print only one subsequence whose sum is equal to the given sum.
// For eg: Input: arr = [1, 2, 1], target = 2   ==>  Output: [1, 1]

// Approach: Recursion
/* Solution:
Here we keep track of stack(that push the current index's element) and also the sum variable(that calculates the sum of elements present in the stack).
 Here we either take the element or not take the element. By adding the element into the stack and adding all the elements in the stack, we consider that element. And by removing the element from the stack and then adding all the remaining elements in the stack, we do not consider that element. We reach end of the array length(for all possible iterations) and then we print the entire subsequence whose sum is equal to the required sum and return true if the sequence is obtained, so that no further function calls can be made to find the other subsequences.
 */

#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;

class _PrintOneSubsequenceWithSum {
public:
    static bool printSubsequence(int index, vector<int>& nums, vector<int>& ds, int sum, int target){
        if(index >= nums.size()){
            if(sum == target){
                for(int i = 0; i < ds.size(); i++){
                    cout << ds[i] << " ";
                }
                return true;
            }
            else{
                return false;
            }
        }
        
        ds.push_back(nums[index]);
        sum = sum + nums[index];
        if(printSubsequence(index + 1, nums, ds, sum, target) == true)
            return true;
        
        ds.pop_back();
        sum = sum - nums[index];
        if(printSubsequence(index + 1, nums, ds, sum, target) == true)
            return true;
        return false;
    }
};

int main(){
    vector<int> nums = {1, 2, 1};
    int target = 2;
    vector<int> ds;
    _PrintOneSubsequenceWithSum::printSubsequence(0, nums, ds, 0, target);
    return 0;
}

// Time Complexity: O(2^N)
// Space Complexity: O(N)