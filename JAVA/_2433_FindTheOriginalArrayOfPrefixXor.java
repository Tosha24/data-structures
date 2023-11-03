// ✔️ Array, XOR (Bitwise)

// Problem: https://www.leetcode.com/problems/find-the-original-array-of-prefix-xor/

public class _2433_FindTheOriginalArrayOfPrefixXor {
    public static int[] findArray(int[] pref){
        int n = pref.length;

        for(int i = n - 1; i > 0; i--){
            pref[i] = pref[i] ^ pref[i - 1];
        }
        return pref;
    }
    public static void main(String[] args) {
        int[] pref = {5, 2, 0, 3, 1};
        int[] res = findArray(pref);
        for(int i = 0; i < res.length; i++){
            System.out.print(res[i] + " ");
        }
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)