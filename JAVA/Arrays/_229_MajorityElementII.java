// Problem: https://leetcode.com/problems/majority-element-ii/

/* Solution:
 * 1. Use Boyer-Moore Majority Vote algorithm to find the two most frequent elements
    * 1.1 If the count of the two elements are 0, set the first element as the first element
    * 1.2 If the count of the two elements are 0, set the second element as the second element
    * 1.3 If the current element is equal to the first element, increase the count of the first element
    * 1.4 If the current element is equal to the second element, increase the count of the second element
    * 1.5 Else If the current element is not equal to the first element and the second element, decrease the count of the first element and the second element
 * 2. Count the frequency of the two elements
 * 3. If the frequency is greater than n/3, add it to the result
 * 4. Return the result
 */

package Arrays;

import java.util.*;

public class _229_MajorityElementII {
    private static List<Integer> majorityElement(int[] nums){
        List<Integer> result = new ArrayList<>();
        int cnt1 = 0, cnt2 = 0;
        int ele1 = 0, ele2 = 0;
        for(int i = 0; i < nums.length; i++){
            if(cnt1 == 0 && nums[i] != ele2){
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && nums[i] != ele1){
                ele2 = nums[i];
                cnt2 = 1;
            }
            else if(nums[i] == ele1){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0; cnt2 = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }
        
        int mini = (int)(nums.length/3) + 1;
        if(cnt1 >= mini) result.add(ele1);
        if(cnt2 >= mini && ele1 != ele2) result.add(ele2);
        return result;  
    }
    public static void main(String[] args) {
        int[] nums = {1, 1, 1, 3, 3, 2, 2, 2, 3};
        System.out.println(majorityElement(nums));
    }
}

// Time Complexity: O(2n)
// Space Complexity: O(1)