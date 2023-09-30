// Problem: https://leetcode.com/problems/remove-duplicate-letters/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution_Stack {
// Time Complexity: O(n)
// Space Complexity: O(n)
public:
    static string removeDuplicateLetters(string s){
        int n = s.length();
        vector<int> count(26, 0);
        vector<bool> visited(26, false);

        for(char c : s) count[c - 'a']++;

        stack<char> st;
        for(char c : s){
            count[c - 'a']--;
            if(visited[c - 'a']) continue;

            while(!st.empty() && st.top() > c && count[st.top() - 'a'] > 0){
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            visited[c - 'a'] = true;
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

class Solution_Greedy {
// Time Complexity: O(n)
// Space Complexity: O(n) --> space of count and visited
public:
    static string removeDuplicateLetters(string s){
        int n = s.length();

        vector<int> count(26, 0);
        vector<int> visited(26, false);

        for(char c : s) count[c - 'a']++;

        string ans = "";
        for(char c : s){
            count[c - 'a']--;
            if(visited[c - 'a']) continue;

            while(!ans.empty() && ans.back() > c && count[ans.back() - 'a'] > 0){
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans += c;
            visited[c - 'a'] = true;
        }

        return ans;
    }
};

class Solution_MonotonicStack {
public:
    static string removeDuplicateLetters(string s){
        return "";
    }
};

int main() {
    string s = "bcabc";
    cout << Solution_Stack::removeDuplicateLetters(s) << endl;
    cout << Solution_Greedy::removeDuplicateLetters(s) << endl;
    cout << Solution_MonotonicStack::removeDuplicateLetters(s) << endl;
    return 0;
}