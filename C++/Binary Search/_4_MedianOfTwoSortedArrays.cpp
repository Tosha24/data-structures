// Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/

/* Solution: notes */

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution_Better {
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        int n = n1 + n2;

        int ind2 = n/2;
        int ind1 = ind2 - 1;
        int ind2ele = -1, ind1ele = -1;

        int i = 0, j = 0;

        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(count == ind1) ind1ele = nums1[i];
                if(count == ind2) ind2ele = nums1[i];
                count++;
                i++;
            }
            else{
                if(count == ind1) ind1ele = nums2[j];
                if(count == ind2) ind2ele = nums2[j];
                count++;
                j++;
            }
        }

        while (i < n1) {
            if (count == ind1) ind1ele = nums1[i];
            if (count == ind2) ind2ele = nums1[i];
            count++;
            i++;
        }
        while (j < n2) {
            if (count == ind1) ind1ele = nums2[j];
            if (count == ind2) ind2ele = nums2[j];
            count++;
            j++;
        }

        if(n%2 == 1) return (double)ind2ele;
        
        return (double)(((double)ind1ele + (double) ind2ele)/2.0);
    }
};

class Solution { 
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n1 = nums1.size(), n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        int low = 0, high = n1;
        int left = (n1 + n2 + 1)/2;

        while(low <= high){
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];

            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1){
                if(n%2 == 1) return max(l1, l2);
                else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1; 
        }
        return 0;
    }
};

int main(){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2, 4};  
    cout << Solution_Better::findMedianSortedArrays(nums1, nums2) << endl;
    cout << Solution::findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}

// Time Complexity: O(n1 + n2)
// Space Complexity: O(1)