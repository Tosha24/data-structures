#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution_SpaceOptimization
{
public:
    static long long int houseRobber(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> temp1, temp2;
        for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        
        long long int ans1 = solve(temp1);
        long long int ans2 = solve(temp2);
        return max(ans1, ans2);
    }
    static long long int solve(vector<int> &nums)
    {
        int n = nums.size();
        long long int prev = nums[0];
        long long int prev_2 = 0;

        for (int i = 1; i < n; i++)
        {
            long long int pick = nums[i];
            if (i > 1)
            {
                pick += prev_2;
            }
            long long int skip = 0 + prev;

            long long int curr = max(pick, skip);

            prev_2 = prev;
            prev = curr;
        }

        return prev;
    }
};

int main()
{
    vector<int> valueInHouse = {2, 3, 2};
    cout << Solution_SpaceOptimization::houseRobber(valueInHouse) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)