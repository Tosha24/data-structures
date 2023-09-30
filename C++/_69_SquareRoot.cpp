// Problem: Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
// For eg: Input: x = 8  ==>  Output: 2   (although sqrt(8) is 2.82842... we round it to the nearest integer)

// Approach: Binary Search
/* Solution:
 * Here we apply binary search on the range of the answer. Like if we have x = 8 then we know that the square root of 8 is smaller than half the number x. So we search for the value of answer between 0 to x/2. And for each mid, we square it and check if it is equal to the number x. If it is we return mid, else if the square is smaller than the number x, we move start pointer ahead one step, else decrease the end pointer. And at last when start and end pointer crosses each other, we return end so that our answer is the ceil value and not the floor value. 
 */

#include <iostream>
using namespace std;

class _69_SquareRoot{
public:
    long long int binarySearch(int n){
        int s = 0;
        int e = n;
        long long int ans = -1;
        while(s <= e){
            long long int mid = s + (e - s)/2;
            long long int square = mid * mid;
            if(square == n)
                return mid;
            else if(square < n){
                s = mid + 1;
            }
            else{
                e = mid - 1;
                ans = e;
            }
        }
        return ans;
    }

    int mySqrt(int x) {
        return binarySearch(x);  
    }
};

int main()
{
    int x = 4;
    _69_SquareRoot s;
    cout << s.mySqrt(x) << endl;
    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(1)