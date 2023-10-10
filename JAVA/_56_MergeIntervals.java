// Problem: https://leetcode.com/problems/merge-intervals/

/* Solution: 
*  1. Sort the intervals based on the first element of each interval
*  2. Push the first interval into the result vector
*  3. If the last element of the result vector is smaller than the first element of the current interval, push the current interval into the result vector
*  4. Else, update the last element of the result vector with the max value of the last element of the result vector and the last element of the current interval
*  5. Return the result vector
*/

import java.util.*;

public class _56_MergeIntervals {
    private static List<List<Integer>> merge(int[][] intervals){
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[0] - b[0];
            }
        });

        for(int i = 0; i < intervals.length; i++){
            if(result.isEmpty() || intervals[i][0] > result.get(result.size() - 1).get(1)){
                result.add(Arrays.asList(intervals[i][0], intervals[i][1]));
            }
            else{
                result.get(result.size() - 1).set(1, Math.max(result.get(result.size() - 1).get(1), intervals[i][1]));
            }
        }
        return result;
    }
    public static void main(String[] args) {
        int[][] intervals = {{1,3},{8, 10},{2,6},{15,18}};
        List<List<Integer>> result = merge(intervals);
        System.out.println(result);
    }
}

// Time Complexity: O(nlogn) + O(n)         ----> nlogn for sorting and n for traversing
// Space Complexity: O(n)           ---> n for storing answers