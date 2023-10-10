// ✔️ String

// Problem: https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static string reverseWords(string s){
        string ans = "";
        string word = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                reverse(word.begin(), word.end());
                ans += word + " ";
                word = "";
            }else{
                word += s[i];
            }
        }
        reverse(word.begin(), word.end());
        ans += word;
        return ans;
    }
};

int main(){
    string s = "Let's take LeetCode contest";
    cout << Solution::reverseWords(s) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)