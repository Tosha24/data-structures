// ✔️ Arrays, Stack

// Problem: https://leetcode.com/problems/build-an-array-with-stack-operations/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n){
        vector<string> result;
        int stream = 1;
        int i = 0;

        while(i < target.size() && stream <= n){
            result.push_back("Push");

            if(target[i] == stream) i += 1;
            else result.push_back("Pop");

            stream += 1;
        }
        return result;
    }
};

int main(){
    vector<int> target = {1, 3};
    int n = 3;
    vector<string> result = Solution().buildArray(target, n);
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)