// Problem: Partition the String such that each partition is a palindrome string and return the min cuts required to partition.
// For eg: Input: s = "aabb"   ==>   Output: 1

// Worst case Approach: Recursion and Backtracking
 
public class _132_PalindromePartioningII {
	static boolean isPalindrome(String string, int i, int j) {
		while (i < j) {
			if (string.charAt(i) != string.charAt(j))
				return false;
			i++;
			j--;
		}
		return true;
	}
	static int partitionString(String string, int i, int j) {
		if (i >= j || isPalindrome(string, i, j))
			return 0;

		int ans = Integer.MAX_VALUE, count;

		for (int k = i; k < j; k++) {
			count = partitionString(string, i, k) + partitionString(string, k + 1, j) + 1;
			ans = Math.min(ans, count);
		}
		return ans;
	}
	public static void main(String args[]) {
		String str = "aabb";
		System.out.println(partitionString(str, 0, str.length() - 1));
	}
}