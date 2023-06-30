// Problem: https://leetcode.com/problems/unique-paths/

/* Solution (Optimal Solution): 
 * 1. The total steps to reach the bottom right corner is m + n - 2
 * 2. We can say that the total steps is the combination of m - 1 (down) and n - 1 (right)
 * 3. So, the result will be calculated using NCr where N = m + n - 2 and r = m - 1 or n - 1 whichever is smaller (to reduce the time complexity slightly)  
 */

#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n){
    int r = m - 1;
    if(m > n){
        r = n - 1;
    }
    int N = m + n - 2;
    double res = 1;

    for(int i = 1; i <= r; i++){
        res = res * (N - r + i) / i;
    }
    return (int)res;
}

int main() {
    int m = 3, n = 7;
    cout << uniquePaths(m, n) << endl;
}

// Time Complexity: O(min(m, n))
// Space Complexity: O(1)