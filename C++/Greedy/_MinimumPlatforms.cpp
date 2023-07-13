// Problem: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

/* Intuition:
* 1. Sort the start and end arrays
* 2. Take two pointers i and j and set them to 0
* 3. Traverse through the arrays and check if the start time of the current train is less than or equal to the end time of the current train
* 4. If yes, then increment the platform_needed and i
* 5. Else, decrement the platform_needed and j
* 6. Return the max_platform
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class _MinimumPlatforms {
public:
    static int findPlatform(int start[], int end[], int n){
        sort(start, start + n);
        sort(end, end+n);

        int platform_needed = 0;
        int max_platform = 0;
        int i = 0, j = 0;

        while(i < n && j < n){
            if(start[i] <= end[j]){
                platform_needed += 1;
                i++;
            }
            else{
                platform_needed -= 1;
                j++;
            }
            max_platform = max(max_platform, platform_needed);
        }
        return max_platform;
    }
};

int main(){
    int n = 6;
    int start[] = {900, 940, 950, 1100, 1500, 1800};
    int end[] = {910, 1200, 1120, 1130, 1900, 2000};

    cout << _MinimumPlatforms::findPlatform(start, end, n) << endl;
}

// Time Complexity: O(NLogN) + O(N) --> O(NLogN) for sorting the arrays, O(N) for traversing through the arrays and finding the max_platform
// Space Complexity: O(1)