// Problem: Check if the number given is prime or not.
// For eg: 3 is prime whereas 8 is not prime

public class _CheckPrime {
    private static boolean isPrime(int n) {
        if (n == 1 || n == 0) {
            return false;
        } else if (n == 2) {
            return true;
        } else {
            int p = (int) ((Math.pow(2, n - 1)) % n);
            if (p == 1) {
                return true;
            } else {
                return false;
            }
        }
    }
    public static void main(String[] args) {
        int n = 341;
        System.out.println(isPrime(n));
    }
}
