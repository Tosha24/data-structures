// Problem: Check if n is power of four.
// For eg: Input: n = 16   ==>  Output: true

// Approach: Brute force approach

public class _342_PowerOfFour {
    private static boolean isPowerOfFour(int n) {
        while(n!=1){
            if(n % 4 != 0 || n<=0){
                return false;
            }
            n = n/4;
        }
        return true;
    }
    public static void main(String[] args) {
        System.out.println(isPowerOfFour(16));
        System.out.println(isPowerOfFour(3));
    }
}