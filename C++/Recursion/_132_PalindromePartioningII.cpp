// Problem: Partition the String such that each partition is a palindrome string and return the min cuts required to partition.
// For eg: Input: s = "aabb"   ==>   Output: 1

// Worst case Approach: Recursion and Backtracking
 
#include <iostream>
#include <vector>
using namespace std;

class _132_PalindromePartioningII {
public:
	static bool isPalindrome(string str, int i, int j) {
		while (i < j) {
			if (str[i] != str[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	static int partitionString(string str, int i, int j) {
		if (i >= j || isPalindrome(str, i, j))
			return 0;

		int ans = INT32_MAX, count;

		for (int k = i; k < j; k++) {
			count = partitionString(str, i, k) + partitionString(str, k + 1, j) + 1;
			ans = min(ans, count);
		}
		return ans;
	}
};

int main(){
	string str = "aabb";
	int ans = _132_PalindromePartioningII::partitionString(str, 0, str.length() - 1);
	cout << ans << endl;
	return 0;
}