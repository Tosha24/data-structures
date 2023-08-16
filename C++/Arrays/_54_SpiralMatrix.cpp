// Problem: https://leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    static vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, left = 0, bottom = m - 1, right = n - 1;
        vector<int> ans;

        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top += 1;

            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right -= 1;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom -= 1;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left += 1;
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = Solution::spiralOrder(matrix);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(m * n)