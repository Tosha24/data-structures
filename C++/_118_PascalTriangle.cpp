// ✔️ Arrays

// Problem: https://leetcode.com/problems/pascals-triangle/

/* Solution:
 * 1. Create a list of list to store the final result
 * 2. Create a list to store the temporary result
 * 3. Create a variable to store the answer for each column
 * 4. Loop through the rows
 * 5. Loop through the column such that it must be less than the row
 * 6. Here, we use the formula to calculate the answer for each column
 * 7. The formula is ans = ans * (row - col)/col. This will give the answer of each row's col. We do not calculate for col = 0 for each row as it will always be 1.
 * 8. Add the answer to the temporary list as obtained in every col iteration.
 * 9. Add the temporary list to the final list. It will contain one whole row.
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> finalList;
    vector<int> temp;
    int ans;
    for(int row = 1; row <= numRows; row++){
        ans = 1;
        temp.push_back(ans);
        for(int col = 1; col < row; col++){
            ans = ans * (row - col)/col;
            temp.push_back(ans);
        }
        finalList.push_back(temp);
        temp.clear();
    }
    return finalList;
}

int main(){
    int numRows = 5;
    vector<vector<int>> result = generate(numRows);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }
}

// Time Complexity: O(n^2)  --> here n is the number of rows. The final time complexity will be less than n^2.
// Space Complexity: O(1)   because we are not using any extra space apart from the required space for the final result.