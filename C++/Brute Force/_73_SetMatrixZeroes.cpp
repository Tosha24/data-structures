// Problem: https://leetcode.com/problems/set-matrix-zeroes/
// Note: This is brute force solution. There is a optimal solution also in "JAVA/Arrays/" folder

/* Solution: 
 * 1. Iterate through the matrix and find the 0s
 * 2. As soon as you find a 0, call the markrows and markcols function
 * 3. In the markrows and markcols function, mark the rows and cols with -1
 * 4. Iterate through the matrix again and change all -1s to 0s
 */

#include <iostream>
#include <vector>
using namespace std;

void markrow(vector<vector<int>> &matrix, int i){
    for(int rcol = 0; rcol < matrix[0].size(); rcol++){
        if(matrix[i][rcol] != 0){
            matrix[i][rcol] = -1;
        }
    }
}

void markcol(vector<vector<int>> &matrix, int j){
    for(int crow = 0; crow < matrix.size(); crow++){
        if(matrix[crow][j] != 0){
            matrix[crow][j] = -1;
        }
    }
}

void setZeroes(vector<vector<int>> &matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == 0){
                markrow(matrix, i);
                markcol(matrix, j);
            }
        }
    }

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
}

int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }        
        cout << endl;
    }
}

// Time Complexity: O(mn * (m + n)) + O(mn) ~ O(^3) complexity
// Space Complexity: O(1)