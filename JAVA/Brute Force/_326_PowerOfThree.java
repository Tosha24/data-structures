// Problem: Check if the number n is power of three.
// For eg: Input: n = 6   ==>  Output: false

// Approach: Brute Force

public class _326_PowerOfThree {
    public static void main(String[] args) {
        System.out.println(isPowerOfThree(9));
    }

    private static boolean isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        int ceiling = (int) Math.ceil(Math.log10(n) / Math.log10(3));
        int flooring = (int) Math.floor(Math.log10(n) / Math.log10(3));
        if (ceiling - flooring == 0) {
            return true;
        }
        return false;
    }
}
