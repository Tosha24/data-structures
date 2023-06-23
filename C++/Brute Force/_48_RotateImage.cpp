// Problem: https://leetcode.com/problems/rotate-image/

/* Solution: (Brute Force)
 * 1. Create a new matrix
 * 2. Copy the elements from the original matrix to the new matrix with the rotated index
 * 3. Copy the elements from the new matrix to the original matrix
 */

#include <bits/stdc++.h>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<vector<int>> temp(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[j][n-1-i] = matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = temp[i][j];
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    rotate(matrix);
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)