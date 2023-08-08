#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    static int uniquePaths(int m, int n)
    {
        int r = m - 1;
        if (m > n)
        {
            r = n - 1;
        }
        int N = m + n - 2;
        double res = 1;

        for (int i = 1; i <= r; i++)
        {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};

int main()
{
    int m = 3, n = 3;
    cout << Solution::uniquePaths(m, n) << endl;
    return 0;
}