// Problem: https://leetcode.com/problems/reorganize-string/

#include <bits/stdc++.h>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    static string rearrangeString(string s){
        string result = "";
        // creating a frequency array to store frequencies of all the alphabets
        vector<int> freq(26, 0);
        
        // iterate over the string and increment the frequency in the frequency array
        for(char c : s){
            freq[c - 'a']++;
        }

        // after creating frequency array, create a priority queue (depending on the highest frequency)
        priority_queue<pair<int, char>> pq;
        
        // iterate over the frequency array and push the characters with their respective frequencies (if greater than 0) into the priority queue
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                pq.push({freq[i], i + 'a'});
            }
        }

        // creating the resultant string using only priority queue while keeping track of prev and curr character
        pair<int, char> prev = { -1, '#'};
        while(!pq.empty()){
            pair<int, char> curr = pq.top();
            pq.pop();

            if(prev.first > 0){
                pq.push(prev);
            }

            result += curr.second;

            curr.first--;
            prev = curr;

            if(pq.empty() && prev.first > 0){
                return "";
            }
        }

        return result;
    }
};

int main() {
    string s = "aabbaacc";
    cout << Solution::rearrangeString(s) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n*2)