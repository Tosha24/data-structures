// Problem: Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// For eg: Input: s = "aab"    ==>   Output: [["a","a","b"],["aa","b"]]

// Approach: Recursion and backtracking
/* Solution:
 * We start with iterating the string from 0th index.
 * Either we take only 0th index, or we take all indices after 0, one by one (like 0-1, 0-2, 0-3, ... 0-n)
 * We can only take those substrings that are palindrome, So we check everytime we consider some indices.
 * When we find the substring that is palindrome within indices (index to i), we add that substrings to the final ans.
 * We continue this process, and move the iterator to the next non-considering index.
 * We continue to do this until we reach the end of the string.
 * When the iterator reaches end of the string, we add that particular partioned string to the final_ans and backtrack.
 * While backtracking, we remove the last inserted string and continue for the range of indices.
 */

#include <iostream>
#include <vector>
using namespace std;

class _131_PalindromePartioning {
public:
    static vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; // stores the final ans
        vector<string> subPalindromes;    // stores each ans at every possible iteration
        partitionString(0, s, subPalindromes, ans);
        return ans;
    }

    static void partitionString(int index, string s, vector<string>& subPalindrome, vector<vector<string>>& ans){
        if(index == s.length()){
            ans.push_back(subPalindrome);
            return;
        }

        for(int i = index; i < s.length(); ++i){    
            if(isPalindrome(s, index, i)){
                subPalindrome.push_back(s.substr(index, i - index + 1));
                partitionString(i + 1, s, subPalindrome, ans);
                subPalindrome.pop_back();
            }
        }
    }

    static bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s = "aab";
    vector<vector<string>> ans = _131_PalindromePartioning::partition(s);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
        cout << "\"" << ans[i][j] << "\"" << ", ";
        }
        cout << "]";
    }
    cout << " ]";
    return 0;
}