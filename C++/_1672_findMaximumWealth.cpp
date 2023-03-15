// Problem: You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has. A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
// For eg: Input: accounts = [[1,2,3],[3,2,1]]   ==>  Output: 6

#include <bits/stdc++.h>
using namespace std;

class _1672_findMaximumWealth {
public:
    static int maximumWealth(vector<vector<int>>& accounts){
        int max = 0;
        for(int i = 0; i< accounts.size(); i++){
            int rowSum = 0;
            for(int j = 0; j<accounts[i].size(); j++){
                rowSum = rowSum + accounts[i][j];
            }
            if(rowSum > max){
                max = rowSum;
            }
        }
        return max;
    }
};

int main(){
    vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 3}};
    cout << _1672_findMaximumWealth::maximumWealth(accounts) << endl;
    return 0;
}