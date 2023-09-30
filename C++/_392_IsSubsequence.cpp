// ✔️ Strings

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();

        if(slen > tlen){
            return false;
        }
        int j = 0;
        for(int i = 0; i < tlen; i++){
            if(j < slen && s[j] == t[i]){
                j++;
            }
        }

        if(j < slen){
            return false;
        }
        return true;
    }
};

int main(){
    string s = "abc";
    string t = "ahbgdc";
    cout << Solution::isSubsequence(s, t) << endl;
    return 0;
}