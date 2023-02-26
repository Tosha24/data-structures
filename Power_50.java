public class Power_50 {
    public static void main(String[] args) {
        double ans = power(2, -2147483648);
        System.out.println(String.format("%.5f", ans));
    }

    static double power(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            x = 1 / x;
            n = -1 * n;
        }
        if (n % 2 == 1) {
            return x * power(x, n - 1);
        }
        return power(x * x, n / 2);
    }
}