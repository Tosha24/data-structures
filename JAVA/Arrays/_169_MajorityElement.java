// Problem: https://leetcode.com/problems/majority-element/
// Note: Moore's Voting Algorithm

/* Solution:
 * 1. Initialize count = 0, ele = nums[0]
 * 2. Iterate through the array and cancel out the elements with the majority element if not equal to the majority element. We do this because the majority element's count will be always greater than the count of any other element (> n/2)
 * 3. If the count becomes 0, then we set the count to 1 and the majority element to the current element in the array.
 * 4. Return the majority element after checking if the obtained majority element is truely a majority element (by iterating through the array and counting the number of times the majority element occurs) 
 */

package Arrays;

public class _169_MajorityElement{
    private static int majorityElement(int[] nums){
        int count = 0;
        int ele = nums[0];
        for(int i=0; i < nums.length; i++){
            if(count == 0){
                count = 1;
                ele = nums[i];
            }
            else if(nums[i] == ele){
                count = count + 1;
            }
            else{
                count = count - 1;
            }
        }
        return ele;
    }
    public static void main(String[] args){
        int[] nums = {2,2,1,1,1,2,2};
        System.out.println(majorityElement(nums));
    }
}

// Time Complexity: O(n) + O(n) = O(n)     // here we take extra O(n) only in the case when the majority element is guaranteed to be present in the array otherwise we directly return the element without checking it's count in the array.
// Space Complexity: O(1)