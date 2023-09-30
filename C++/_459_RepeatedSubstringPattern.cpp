#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int i = n/2; i >= 1; i--){
            if(n%i == 0){
                string substring = s.substr(0, i);
                string newString = "";
                for(int j = 1; j <= n/i; j++){
                    newString.append(substring);
                }

                if(newString.compare(s) == 0){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    string s = "abac";
    cout << Solution::repeatedSubstringPattern(s) << endl;
    return 0;
}