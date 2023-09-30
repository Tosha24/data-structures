// Problem: Check if the number n is power of three.
// For eg: Input: n = 6   ==>  Output: false

// Approach: Brute Force

#include <bits/stdc++.h>
using namespace std;

class _326_PowerOfThree {
public:
    static bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        int ceiling = (int) ceil(log10(n) / log10(3));
        int flooring = (int) floor(log10(n) / log10(3));
        if (ceiling - flooring == 0) {
            return true;
        }
        return false;
    }
};

int main(){
    int n = 9;
    _326_PowerOfThree::isPowerOfThree(n) ? cout << "true" : cout << "false";
    return 0;
}
