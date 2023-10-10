// Problem: https://leetcode.com/problems/rotate-image/

/* Solution: (Optimal Solution)
 * 1. Transpose the original matrix
 * 2. Reverse each row of the transposed matrix
 */

public class _48_RotateImage {
    private static void rotate(int[][] matrix){
        int n = matrix.length;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix, matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                swap(matrix, matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
    private static void swap(int[][] matrix, int x, int y){
        int temp = x;
        x = y;
        y = temp;
    }
    public static void main(String[] args) {
        int[][] matrix = { { 1, 2, 3 }, 
                           { 4, 5, 6 }, 
                           { 7, 8, 9 } };
        rotate(matrix);
        System.out.println(matrix);
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)