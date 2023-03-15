// Problem: Given the number n (Integer.MIN_VALUE <= n <= Integer.MAX_VALUE). Check if the number n is a power of two.
// For eg: n = 6   ==>  Output: false

// Approach: Brute force approach 

public class _231_PowerOfTwo {
    private static boolean isPowerOfTwo(int n){
        if(n!=0 && ((n & (n - 1)) == 0)){
            return true;
        }
        return false;
    }
    public static void main(String[] args) {
        int n = 6;
        System.out.println(isPowerOfTwo(n));
    }
}
