// Problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice.
// For eg: arr = [2, 7, 11, 15], target = 9   ==>  Output: [0, 1]

// Approach: Brute force

public class _1_TwoSum {
    static int[] twoSum(int[] nums, int target){
        for(int i=0; i<nums.length; i++){
            for(int j=i+1; j<nums.length; j++){
                if(nums[i] + nums[j] == target){
                    return new int[]{i, j};
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        int[] array = {2,7,11,15};
        int target = 9;
        int[] result = twoSum(array, target);
        System.out.print("[");
        for(int i : result){
            System.out.print(i + ",");
        }
        System.out.print("]");
    }
}
