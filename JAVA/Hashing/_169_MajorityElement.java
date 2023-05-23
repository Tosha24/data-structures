// Problem: https://leetcode.com/problems/majority-element/
// Note: This is a better solution after the brute force one. For the most optimal solution, refer "../Arrays/_169_MajorityElement.java"

/* Solution:
 * Initialize the hashmap and store the count of each element in the array.
 * Iterate through the hashmap and return the element with the count greater than n/2
*/

import java.util.HashMap;

public class _169_MajorityElement{
    private static int majorityElement(int[] nums){
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i=0; i < nums.length; i++){
            if(map.get(nums[i]) == null){
                map.put(nums[i], 1);
            }
            else{
                map.put(nums[i], map.get(nums[i]) + 1);
            }
        }
        for(int major : map.keySet()){
            if(map.get(major) > nums.length/2){
                return major;
            }
        }
        return 0;
    }
    public static void main(String[] args){
        int[] nums = {2,2,1,1,1,2,2};
        System.out.println(majorityElement(nums));
    }
}

// Time Complexity: O(n)  --> Taken for iterating through the array and simultaneously storing the count of each element
// Space Complexity: O(n)  --> Taken for storing the elements in the hashmap