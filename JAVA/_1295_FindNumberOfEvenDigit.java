// Problem: Given an array nums of integers, return how many of them contain an even number of digits.
// For eg: Input: nums = [12,345,2,6,7896]   ==>  Output: 2

// Approach: Brute force

public class _1295_FindNumberOfEvenDigit {
    static int findNumber(int[] nums){
        int count = 0;
        for(int item : nums){
            if(even(item)){
                count += 1;
            }
        }
        return count;
    }
    static boolean even(int num){
        int numberOfDigits = digits(num);
        return (numberOfDigits%2==0);
    }
    static int digits(int num){
        return ((int)(Math.log10(num)) + 1);
    }
    public static void main(String[] args) {
        int[] nums = {12,345,22,6,7896};
        System.out.println(findNumber(nums));
    }
}
