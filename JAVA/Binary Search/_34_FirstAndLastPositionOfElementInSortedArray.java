// Problem: Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value. If target is not found in the array, return [-1, -1].
// For eg: Input: nums = [5,7,7,8,8,10], target = 8  ==> Output: [3,4]

// Approach: Binary Search
/* Solution:
 * To search the range in which the particular target lies, we first calculate the start index of that element using binary search. To calculate the start index, we have to decrement the end pointer after storing the current index as soon as we get one element same as target. To calculate the end index, we have to increment the start pointer after storing the current index, as soon as we get one element same as target. And keep searching for other same elements. As soon as our start and end pointer crosses each other, we simply return the value of index that we stored when we obtained the target every time.
 * After finding the start and end (range), we return both indices both in form of list.
 */

public class _34_FirstAndLastPositionOfElementInSortedArray {
    static int[] searchRange(int[] nums, int target){
        int[] ans = {-1, -1};
        int start = findIndex(nums, target, true);
        int end = findIndex(nums, target, false);
        ans[0] = start;
        ans[1] = end;
        return ans;
    }
    static int findIndex(int[] nums, int target, boolean findStartIndex){
        int ans = 0;
        int start = 0;
        int end = nums.length - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target > nums[mid]){
                start = mid + 1;
            }
            else if(target < nums[mid]){
                end = mid - 1;
            }
            else{
                ans = mid;
                if(findStartIndex){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] nums = {5, 7, 7, 7, 7, 8, 8, 10};
        int target = 7;
        int[] ans = searchRange(nums, target);
        for(int item: ans){
            System.out.println(item);
        }
    }
}

// Time Complexity: O(logn)
// Space Complexity: O(n)