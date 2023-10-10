// better as well as optimal solution both in this

// Problem: https://leetcode.com/problems/set-matrix-zeroes/

/* Solution (for better approach):
 * 1. Use two arrays to store the row and column index of the matrix where 0 is present.
 * 2. Iterate through the matrix and if 0 is found, store the row and column index in the respective arrays.
 * 3. Iterate through the matrix again and if the row or column index is present in the respective arrays, make the element 0.
 */

/* Solution (for optimal approach):
 * 1. Use the first row and first column of the matrix to store the row and column index of the matrix where 0 is present.
 * 2. Iterate through the matrix and if 0 is found, store the row and column index in the first row and first column respectively.
 * 3. Iterate through the matrix again and if the row or column index is present in the first row or first column respectively, make the element 0.
 * 4. Check if the first row or first column has 0, if yes, make the entire row or column 0.
 * 5. Check if the first row has 0, if yes, make the entire row 0.
 * 6. Check if the first column has 0, if yes, make the entire column 0.
 */

public class _73_SetMatrixZeroes {
    private static void better_setZeroes(int[][] matrix){
        int[] colArr = new int[matrix[0].length];
        int[] rowArr = new int[matrix.length];
        
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] == 0){
                    rowArr[i] = 1;
                    colArr[j] = 1;
                }
            }
        }

        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(rowArr[i] == 1 || colArr[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    private static void setZeroes(int[][] matrix){
        int col0 = 1;
        int m = matrix.length;
        int n = matrix[0].length;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;

                    if(j!=0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
    public static void main(String[] args) {
        int[][] matrix = {{1,1,1},{1,0,0},{1,1,1}};
        setZeroes(matrix);
        for(int[] row : matrix){
            for(int col : row){
                System.out.print(col + " ");
            }
            System.out.println();
        }
    }
}

// For Better Approach:
// Time Complexity : O(m*n)
// Space Complexity : O(m+n)

// For Optimal Approach:
// Time Complexity : O(m*n)
// Space Complexity : O(1)
