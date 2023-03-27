// Problem: Check if n is power of four.
// For eg: Input: n = 16   ==>  Output: true

// Approach: Brute force approach

#include <bits/stdc++.h>
using namespace std;

class _342_PowerOfFour {
public:
    static bool isPowerOfFour(int n) {
        while(n!=1){
            if(n % 4 != 0 || n<=0){
                return false;
            }
            n = n/4;
        }
        return true;
    }
};

int main(){
    int n = 16;
    _342_PowerOfFour::isPowerOfFour(n) ? cout << "true" : cout << "false";
    return 0;
}