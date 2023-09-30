// Problem: You are given an m x n integer matrix matrix with the following two properties: Each row is sorted in non-decreasing order. The first integer of each row is greater than the last integer of the previous row. Given an integer target, return true if target is in matrix or false otherwise.
// For eg: Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3  ==>  Output: true

// Approach: Binary Search
/* Solution:
 * We will start with two pointers. First pointer for iterating over row and another over column. The row pointer will start from the first row till last whereas the column pointer start with the last column to the first. Here we don't have mid to check, instead we check the value at row and column index. 
 * If it is equal to target, then return that both indexes.
 * If it is greater than target, means the target lies to the left of the current value, hence we decrement the column pointer.
 * If it is smaller than target, means the target lies to the bottom of the current value, hence we increment the row pointer.
 */

#include <iostream>
#include <vector>
using namespace std;

class _74_SearchIn2DArray {
public:
    static bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0;
        int c = matrix[0].size() - 1;
        while(r < matrix.size() && c >= 0){
            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c] > target){
                c = c - 1;
            }
            else{
                r = r + 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {
            {10, 20, 30, 40},
            {15, 25, 35, 45},
            {28, 29, 37, 49},
            {33, 34, 38, 50}
        };
    int target = 36;
    _74_SearchIn2DArray::searchMatrix(matrix, target) ? cout << "true" : cout << "false";
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)