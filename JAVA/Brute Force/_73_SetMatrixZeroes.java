// Problem: https://leetcode.com/problems/set-matrix-zeroes/
// Note: This is brute force solution. There is a optimal solution also in "JAVA/Arrays/" folder

/* Solution: 
 * 1. Iterate through the matrix and find the 0s
 * 2. As soon as you find a 0, call the markrows and markcols function
 * 3. In the markrows and markcols function, mark the rows and cols with -1
 * 4. Iterate through the matrix again and change all -1s to 0s
 */

public class _73_SetMatrixZeroes{
    public static void setZeroes(int[][] matrix){
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] == 0){
                    markrow(matrix, i);
                    markcol(matrix, j);
                }
            }
        }

        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
    private static void markrow(int[][] matrix, int i){
        for(int rcol = 0; rcol < matrix[0].length; rcol++){
            if(matrix[i][rcol] != 0){
                matrix[i][rcol] = -1;
            }
        }
    }

    private static void markcol(int[][] matrix, int j){
        for(int crow = 0; crow < matrix.length; crow++){
            if(matrix[crow][j] != 0){
                matrix[crow][j] = -1;
            }
        }
    }

    public static void main(String[] args){
        int[][] matrix = {{1,1,1},{1,0,1},{1,1,1}};
        setZeroes(matrix);
        for(int[] row : matrix){
            for(int col : row){
                System.out.print(col + " ");
            }
            System.out.println();
        }
    }
}

// Time Complexity: O(mn * (m + n)) + O(mn) ~ O(^3) complexity
// Space Complexity: O(1)