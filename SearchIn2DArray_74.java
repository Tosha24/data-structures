import java.util.Arrays;

public class SearchIn2DArray_74 {
    public static void main(String[] args) {
        int[][] matrix = {
            {10, 20, 30, 40},
            {15, 25, 35, 45},
            {28, 29, 37, 49},
            {33, 34, 38, 50}
        };
        System.out.println(Arrays.toString(search(matrix, 49)));
    }
    static int[] search(int[][] matrix, int target){
        int r = 0;
        int c = matrix[0].length - 1;
        while(r < matrix.length && c >= 0){
            if(matrix[r][c] == target){
                return new int[]{r, c};
            }
            else if(matrix[r][c] > target){
                c = c - 1;
            }
            else{
                r = r + 1;
            }
        }
        return new int[]{-1, -1};
    }
}
