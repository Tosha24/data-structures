// Problem: Reverse the given array
// For eg: Input: arr = [1, 2, 3, 4]   ==>  Output: [4, 3, 2, 1]

// Approach: Recursion

public class _ReverseArray {
    static void swap(int[] nums, int low, int high){
        int temp = nums[low];
        nums[low] = nums[high];
        nums[high] = temp;
    }
    static void reverse(int[] nums, int low){
        if(low >= nums.length/2){
            return;
        }
        swap(nums, low, nums.length - low - 1);
        reverse(nums, low+1);
    }
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        reverse(nums, 0);
        for(int i : nums){
            System.out.print(i + ", ");
        }
    }
}
