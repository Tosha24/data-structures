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

public class _MColoring{
    private static boolean graphColoring(boolean[][] graph, int M, int N){
        int[] color = new int[N];
        return coloringTheGraph(0, graph, M, N, color);
    }
    private static boolean coloringTheGraph(int node, boolean[][] graph, int M, int N, int[] color){
        if(node == N){
            return true;
        }

        for(int clr = 1; clr <= M; clr++){
            if(isPossible(node, clr, graph, color)){
                color[node] = clr;
                if(coloringTheGraph(node + 1, graph, M, N, color)){
                    return true;
                }
                else{
                    color[node] = 0;
                }
            }
        }
        return false;
    }
    private static boolean isPossible(int node, int clr, boolean[][] graph, int[] color){
        int index = 0;
        for(boolean i : graph[node]){
            if(i == true){
                if(color[index] == clr){
                    return false;
                }
            }
            index = index + 1;
        }
        return true;
    }
    public static void main(String[] args){
        int N = 4;
        int M = 3;
        boolean[][] graph = {{false, true, true, true}, {true, false, true, false}, {true, true, false, true}, {true, false, true, false}};
        System.out.println(graphColoring(graph, M, N));
    }    
}

// Time Complexity: O(N^M)
// Space Complexity: O(N) + O(N)