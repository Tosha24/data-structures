// Problem: Search for a target element in an infinite array. (As infinite array cannot be created, we assume that the array is infinite and hence we do not know the length of the array)

// Approach: Binary Search
/* Solution:
 * Like normal binary search, we do not find the mid element, and then continue by dividing by 2. Instead we first initialize the start and end index at 0th and 1st index, and we double it after every iteration.
 * We point start at the end+1 position and double the value of only end after every iteration, until the target < current element.
 * As soon as the target is less than the current element, we perform binary search between updated start and end pointer.
 */

public class _BinarySearchInInfiniteArray {
    static int findRange(int[] nums, int target){
        int size = 2;
        int start = 0;
        int end = 1;
        while(target > nums[end]){
            size = 2*size;
            start = end + 1;
            end = end + size;
        }
        return binarySearch(nums, target, start, end);
    }
    static int binarySearch(int[] nums, int target, int start, int end){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target > nums[mid]){
                start = mid + 1;
            }
            else if(target < nums[mid]){
                end = mid - 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] nums = {2, 3, 5, 6, 7, 8, 10, 11, 13, 15, 18, 21, 23, 24, 28, 30};
        int target = 10;
        int range = findRange(nums, target);
        System.out.println(range);
    }
}

// Time Complexity: O(logn)
// Space Complexity: O(n)