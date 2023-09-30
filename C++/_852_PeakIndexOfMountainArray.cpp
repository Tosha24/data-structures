// Problem: Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
// For eg: Input: arr = [0,1,0]   ==>   Output: 1

// Approach: Binary Search
/* Solution: 
 * Here we compare the mid value with the mid+1 value.
 * If mid > mid+1, means the peak is on left side of the array
 * If mid < mid+1, means the peak is on its right side
 * At last when start and end crosses each other, we return start as peak will be start after they cross.
 */

#include <iostream>
#include <vector>
using namespace std;

class _852_PeakIndexOfMountainArray {
public:
    static int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] > arr[mid+1])
                end = mid - 1;
            else if(arr[mid] < arr[mid+1])
                start = mid + 1;
        }
        return start;
    }
};

int main(){
    vector<int> arr = {0, 10, 5, 2};
    cout << _852_PeakIndexOfMountainArray::peakIndexInMountainArray(arr) << endl;
    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(n)