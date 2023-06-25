// Problem: https://leetcode.com/problems/merge-intervals/

/* Solution:
* 1. Sort the intervals by start time
* 2. Iterate through the intervals
* 3. If the current interval's start time is less than the previous interval's end time, then merge the intervals
* 4. Else, add the interval to the result
*/

import java.util.*;

public class _56_MergeIntervals {
    private static List<List<Integer>> merge(int[][] intervals){
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[0] - b[0];
            }
        });
        for(int i = 0; i < intervals.length; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(!result.isEmpty() && end <= result.get(result.size() - 1).get(1)){
                continue;
            }
            for(int j = i + 1; j < intervals.length; j++){
                if(intervals[j][0] <= end){
                    end = Math.max(end, intervals[j][1]);
                }
                else{
                    break;
                }
            }
            result.add(Arrays.asList(start, end));
        }
        return result;
    }
    public static void main(String[] args) {
        int[][] intervals = {{1,3},{8, 10},{2,6},{15,18}};
        List<List<Integer>> result = merge(intervals);
        System.out.println(result);
    }
}

// Time Complexity: O(nlogn) + O(2n)
// Space Complexity: O(n)