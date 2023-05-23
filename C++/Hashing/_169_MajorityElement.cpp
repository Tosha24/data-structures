// Problem: https://leetcode.com/problems/majority-element/
// Note: This is a better solution after the brute force one. For the most optimal solution, refer "../Arrays/_169_MajorityElement.java"

/* Solution:
 * Initialize the hashmap and store the count of each element in the array.
 * Iterate through the hashmap and return the element with the count greater than n/2
*/

#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

int majorityElement(vector<int> nums){
    map<int,int> counter;
    for(int i=0; i < nums.size(); i++){
        counter[nums[i]]++;
    }
    for(auto major : counter){
        if(major.second > nums.size()/2){
            return major.first;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
}


// Time Complexity: O(n)  --> Taken for iterating through the array and simultaneously storing the count of each element
// Space Complexity: O(n)  --> Taken for storing the elements in the hashmap