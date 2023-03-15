// Problem: Given the number n (Integer.MIN_VALUE <= n <= Integer.MAX_VALUE). Check if the number n is a power of two.
// For eg: n = 6   ==>  Output: false

// Approach: Brute force approach 

#include <bits/stdc++.h>
using namespace std;

class _231_PowerOfTwo {
public:
    static bool isPowerOfTwo(int n){
        if(n!=0 && ((n & (n - 1)) == 0)){
            return true;
        }
        return false;
    }
};

int main(){
    int n = 6;
    _231_PowerOfTwo::isPowerOfTwo(n) ? cout << "true" : cout << "false";
    return 0;
}
