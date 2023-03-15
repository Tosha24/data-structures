// Problem: Color the graph with nodes N and with edges E with M colors such that no two adjacent nodes get the same color. Return if the given graph can be colored or not. (return true or false)
// For eg: Input: N=3, M=4, E=5, E[]=[(0,1), (1,2), (2,3), (0,3), (0,2)]    ==>   Output: true

// Approach: Recursion and Backtracking
/* Solution:
 * We are given the value of total nodes, M number of colors and also the connected edges.
 * We are also given the graph of n*n 2d array, like adjacency matrix.
 * The boolean[] graph variable is an adjancency matrix.
 * We start coloring the graph by first creating the color array, that will store the colors given to the particular node(represented by the index of the array).
 * We first start with the first node in the graph.
 * We try all the colors from 1 to M, and try to see if that color is possible for that node or not.
 * We check the possibility of that color, by simply checking the colors assigned to all its adjacent nodes of that node, and if the color is already assigned to the adjacent nodes, we return false means "Not Possible".
 * Otherwise, we assign that color to the current node, and try to color the next node in sequence.
 * If all the nodes are colored, we return true, and we backtrack and confirm all the function calls about the end of the solution by checking the true returned.
 * If the node is checked for all the colors, still is not being colored, then we return false.
 * Also, then we remove the colors given to all the previous nodes, by backtracking.
 */

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101])
{
    if (node == N)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, N, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, N, graph))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N) {
    int color[N] = {0};
    if (solve(0, color, m, N, graph))
        return true;
    return false;
}

int main() {
    int N = 4;
    int m = 3;

    bool graph[101][101];
    memset(graph, false, sizeof graph);

    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][0] = 1;
    graph[0][3] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;

    graphColoring(graph, m, N) ? cout << "true" : cout << "false";
    return 0;
}

// Time Complexity: O(N^M)
// Space Complexity: O(N) + O(N)