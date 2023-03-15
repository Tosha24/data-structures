// Problem: We are given value of N (2d maze matrix size) and m (maze board). We have to find the path of rat to reach [n-1][n-1] cell from [0][0]. The rat can only traverse the path when the value is 1. The value 0 in the matrix denotes that the path is blocked.
// For eg: Input: N=4, m[][] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}}    ==>   Output: ["DDRDRR", "DRDDRR"]

// Approach: Recursion and Backtracking
/* Solution:
 * We maintain mainly the visited 2d matrix, which gets updated to 1 when the current node is visited, and gets updated back to 0, when not visited.
 * We maintain visited matrix so that our iterator does not go back to the same cell from which we already came further.
 * Our program return successfully when we reach the exit cell [n-1][n-1]
 * Otherwise we check for all the direction possible for our rat path to move further.
 * For every direction, we update the visited matrix value to 1 (denoting visited)
 * And call the function again for further paths.
 * If at some point, no further paths are possible, we update the visited matrix back to 0 (denoting not visited)
 * We only start finding the Path of the rat if the start cell [0][0] has value 1.
 */

#include <bits/stdc++.h>
using namespace std;

class _RatInAMaze {
public:
    static vector<string> ratMaze(int n, vector<vector<int>>& m){
        vector<string> ans;
        string move = "";
        vector<vector<int>> visited(n, vector<int> (n, 0));
        if(m[0][0] == 1) findPath(0, 0, n, m, visited, move, ans);
        return ans;
    }

    static void findPath(int i, int j, int n, vector<vector<int>>& m, vector<vector<int>>& visited, string move, vector<string>& ans){
        if(i == n-1 && j == n-1){
            ans.push_back(move);
            return;
        }

        // downward
        if(i+1 < n && visited[i+1][j] != 1 && m[i+1][j] == 1){
            visited[i][j] = 1;
            findPath(i+1, j, n, m, visited, move + "D", ans);
            visited[i][j] = 0;
        }

        // left
        if(j-1 >= 0 && visited[i][j-1] != 1 && m[i][j-1] == 1){
            visited[i][j] = 1;
            findPath(i, j-1, n, m, visited, move + "L", ans);
            visited[i][j] = 0;
        }

        // right
        if(j+1 < n && visited[i][j+1] != 1 && m[i][j+1] == 1){
            visited[i][j] = 1;
            findPath(i, j+1, n, m, visited, move + "R", ans);
            visited[i][j] = 0;
        }

        // upward
        if(i-1 >= 0 && visited[i-1][j] != 1 && m[i-1][j] == 1){
            visited[i][j] = 1;
            findPath(i-1, j, n, m, visited, move + "U", ans);
            visited[i][j] = 0;
        }
    }
};

int main(){
    int N = 4;
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = _RatInAMaze::ratMaze(N, m);
    for(string i : ans){
        cout << i << endl;
    }
    return 0;
}
