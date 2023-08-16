#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    static int findTime(vector<int>& piles, int n, int k){
        int reqTime = 0;

        for(int i = 0; i < n; i++){
            reqTime += ceil(piles[i]/k);
        }
        return reqTime;
    }
public:
    static int minEatingSpeed(vector<int>& piles, int h){
        int n = piles.size();
        int maxi = *max_element(piles.begin(), piles.end());

        for(int k = 1; k < maxi; k++){
            int requiredTime = findTime(piles, n, k);
            if(requiredTime <= h)
                return k;
        }

        return 0;
    }
};

int main(){
    vector<int> piles = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
    int H = 823855818;
    cout << Solution::minEatingSpeed(piles, H) << endl;
    return 0;
}