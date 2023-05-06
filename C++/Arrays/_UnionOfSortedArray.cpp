// Problem: Find the Union of the two sorted arrays: Union means all the unique elements in both the arrays.

/* Solution:
 * We use three pointers i, j, k.
 * We traverse through the arrays and check if nums1[i] > nums2[j], if yes, we increment j by 1.
 * Similarly, if nums1[i] < nums2[j], we increment i by 1.
 * Otherwise, we check if union.size() == 0 || union.get(k) != nums1[i], if yes, we add nums1[i] to union and increment k by 1.
 * Finally, we return union.
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> Union(vector<int> nums1, vector<int> nums2){
    vector<int> uni;
    int i = 0, j = 0, k = -1;
    while(i < nums1.size() && j < nums2.size()){
        if(nums1.at(i) > nums2.at(j)){
            if(uni.size() == 0 || uni.at(k) != nums2.at(j)){
                uni.push_back(nums2.at(j));
                k = k + 1;
            }
            j = j + 1;
        }
        else if(nums1.at(i) < nums2.at(j)){
            if(uni.size() == 0 || uni.at(k) != nums1.at(i)){
                uni.push_back(nums1.at(i));
                k = k + 1;
            }
            i = i + 1;
        }
        else{
            if(uni.size() == 0 || uni.at(k) != nums1.at(i)){
                uni.push_back(nums1.at(i));
                k = k + 1;
            }
            i = i + 1;
            j = j + 1;
        }
    }

    while(i < nums1.size()){
        if(uni.size() == 0 || uni.at(k) != nums1.at(i)){
            uni.push_back(nums1.at(i));
            k = k + 1;
        }
        i = i + 1;
    }

    while(j < nums2.size()){
        if(uni.size() == 0 || uni.at(k) != nums2.at(j)){
            uni.push_back(nums2.at(j));
            k = k + 1;
        }
        j = j + 1;
    }
    return uni;
}

int main() {
    vector<int> nums1 = {3, 3, 5, 7, 9, 11, 13, 15, 15, 15};
    vector<int> nums2 = {2, 4, 6, 8, 10, 11, 12, 13, 15, 15, 15, 16};
    vector<int> uni = Union(nums1, nums2);
    for(int i : uni){
        cout << i << " ";
    }
    return 0;
}

// Time Complexity: O(n + m)
// Space Complexity: O(n + m) where n and m are the sizes of the two arrays.