// Problem: https://leetcode.com/problems/rotate-image/

/* Solution: (Brute Force)
 * 1. Create a new matrix
 * 2. Copy the elements from the original matrix to the new matrix with the rotated index
 * 3. Copy the elements from the new matrix to the original matrix
 */

public class _48_RotateImage {
    private static void rotate(int[][] matrix){
        int n = matrix.length;
        int[][] temp = new int[n][n];
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
    public static void main(String[] args) {
        int[][] matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
        rotate(matrix);
        for(int[] row : matrix){
            for(int col : row){
                System.out.print(col + " ");
            }
            System.out.println();
        }
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)