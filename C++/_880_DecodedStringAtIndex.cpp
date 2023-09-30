// Problem: https://leetcode.com/problems/decoded-string-at-index/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution_Stack {
public:
    static string decodeAtIndex(string s, int k){
        int n = s.length();
        long long int size = 0;
        for(char c : s){
            if(isdigit(c)) size *= (c - '0');
            else size++;
        }

        for(int i = n - 1; i >= 0; i--){
            k %= size;
            if(k == 0 && isalpha(s[i])) return (string) "" + s[i];

            if(isdigit(s[i])) size /= (s[i] - '0');
            else size--;
        }
        return "";
    }
};

int main(){
    string s = "leet2code3";
    int k = 10;
    cout << Solution_Stack::decodeAtIndex(s, k) << endl;
    return 0;
}