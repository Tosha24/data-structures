#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution{ 
public:
    static int updateMatrix(vector<vector<int>>& mat){
        return 0;
    }
};

int main(){
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    cout << Solution::updateMatrix(mat) << endl;
    return 0;
}