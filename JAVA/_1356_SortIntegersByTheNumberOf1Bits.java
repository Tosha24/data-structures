// ✔️ Arrays, Sort, Bit manipulation

// Problem: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

import java.util.Arrays;

public class _1356_SortIntegersByTheNumberOf1Bits {
    static private int countBits(int num){
        int count = 0;

        while(num != 0){
            count += num & 1;
            num = num >> 1;
        }
        return count;
    }

    static public int[] sortByBits(int[] arr) {
        int n = arr.length;
        Integer[] newArr = new Integer[n];

        for(int i = 0; i < n; i++) newArr[i] = arr[i];

        // Main code : Sorting the function by comparing with count bits
        Arrays.sort(newArr, (a, b) -> {
            int count_a = countBits(a); // built-in function: bitCount(a)
            int count_b = countBits(b); // built-in function: bitCount(b)

            if(count_a == count_b) return a - b;

            return count_a - count_b;
        });

        for(int i = 0; i < n; i++) arr[i] = newArr[i];

        return arr;
    }
    public static void main(String[] args) {
        int[] arr = {0,1,2,3,4,5,6,7,8};
        int[] result = sortByBits(arr);
        for (int i : result) {
            System.out.print(i + " ");
        }
    }
}

// Time Complexity: O(nlogn)
// Space Complexity: O(n)