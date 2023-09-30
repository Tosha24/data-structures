// Problem: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

/* Intuition: 
*  1. Sort the array of structures according to the end time of the meetings
*  2. Take the first meeting and set the limit to the end time of the first meeting
*  3. Traverse through the array and check if the start time of the current meeting is greater than the limit
*  4. If yes, then increment the max_meetings and set the limit to the end time of the current meeting
*  5. Return the max_meetings
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct meeting {
    int start;
    int end;
    int pos;
};

class _NMeetingsInOneRoom {
public:
    bool static comparator(struct meeting m1, meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.pos < m2.pos) return true;
        return false;
    }

    static int maxMeetings(int start[], int end[], int n){
        struct meeting meet[n];
        int max_meetings = 0;
        for(int i = 0; i < n; i++) meet[i].start = start[i], meet[i].end = end[i], meet[i].pos = i + 1;

        sort(meet, meet + n, comparator);

        int limit = meet[0].end;
        max_meetings += 1;

        for(int i = 1; i < n; i++){
            if(meet[i].start > limit){
                limit = meet[i].end;
                max_meetings += 1;
            }
        }

        return max_meetings;
    }
};

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = 6;

    cout << _NMeetingsInOneRoom::maxMeetings(start, end, n) << endl;
    return 0;
}

// Time Complexity: O(N) + O(NLogN) + O(N)  --> O(N) for traversing through the array and inserting the values, O(NLogN) for sorting the array, O(N) for traversing through the array and finding the max meetings
// Space Complexity: O(N)   --> For storing the array of structures