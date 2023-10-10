// ✔️ Strings

// Problem: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static bool winnerOfGame(string colors){
        int n = colors.length();

        int count = 0;

        for(int i = 1; i < n - 1; i++){
            if(colors[i] == colors[i-1] && colors[i] == colors[i+1]){
                if(colors[i] == 'A') count++;
                else count--;
            }
        }

        return count > 0;
    }
};

int main(){
    string colors = "ABBBBBBBAAA";
    Solution::winnerOfGame(colors) ? cout << "Alice Wins" << endl : cout << "Bob Wins" << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)