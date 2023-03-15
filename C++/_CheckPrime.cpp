// Problem: Check if the number given is prime or not.
// For eg: 3 is prime whereas 8 is not prime

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class _CheckPrime {
public:
    static bool isPrime(int n) {
        if (n == 1 || n == 0) {
            return false;
        } else if (n == 2) {
            return true;
        } else {
            int power = pow(2, n - 1);
            int p = (int) power%n;
            if (p == 1) {
                return true;
            } else {
                return false;
            }
        }
    }
};

int main(){
    int n = 53;
    _CheckPrime::isPrime(n) ? cout << "true" : cout << "false";
    return 0;
}
