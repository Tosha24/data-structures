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

package Arrays;
import java.util.*;

public class _118_PascalTriangle{
    public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> finalList = new ArrayList<List<Integer>>();
        List<Integer> temp = new ArrayList<>();
        int ans;
        for(int row = 1; row <= numRows; row++){
            ans = 1;
            temp.add(ans);
            for(int col = 1; col < row; col++){
                ans = ans * (row - col)/col;
                temp.add(ans);
            }
            finalList.add(new ArrayList<Integer>(temp));
            temp.clear();
        }
        return finalList;
    }
    public static void main(String[] args){
        int numRows = 5;
        List<List<Integer>> result = generate(numRows);
        System.out.println(result);
    }
}

// Time Complexity: O(n^2)  --> here n is the number of rows. The final time complexity will be less than n^2.
// Space Complexity: O(1)   because we are not using any extra space apart from the required space for the final result.