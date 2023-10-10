// Problem: Calculate x raised to the power of n
// For eg: Input: x = 2, n = -2   ==>  Output: 0.2500

// Approach: Recursion
/* Solution:
 * For positive exponential we divide the exponential in odd or even. If it is an even, we multiple the same number twice and decrease value of exponential by 2. If it is odd exponential, we multiply the value of base with the prev ans and then store that value in ans and also decrease the value of exponential by 1.
 * Here for negative exponential we first make the n value positive. Then calculate the power as we do in positive number. At last we divide 1 with that ans.
*/

public class _50_Powerxn {
    static double power(double x, int n) {
        double ans = 1.0;
        long nn = n;
        if(nn < 0){
            nn = -1*nn;
        }
        while(nn > 0){
            if(nn % 2 == 1){
                ans = ans * x;
                nn = nn - 1;
            }
            else{
                x = x * x;
                nn = nn/2;
            }
        }
        if(n < 0){
            ans = (double) 1.0 / (double) (ans);
        }
        return ans;
    }
    public static void main(String[] args) {
        double ans = power(2, -2);
        System.out.println(String.format("%.5f", ans));
    }
}

// Time complexity: O(logn base 2)
// Space complexity: O(1)