// Problem: Find the intersection of the two arrays: Intersection means the common elements in both the arrays.

/* Solution:
 * We use three pointers i, j, k.
 * We traverse through the arrays and check if nums1[i] > nums2[j], if yes, we increment j by 1.
 * Similarly, if nums1[i] < nums2[j], we increment i by 1.
 * Otherwise, we check if inter.size() == 0 || inter.get(k) != nums1[i], if yes, we add nums1[i] to inter and increment k by 1.
 * Finally, we return inter.
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> intersection(vector<int> nums1, vector<int> nums2){
        vector<int> inter;
        int i = 0, j = 0, k = -1;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1.at(i) > nums2.at(j)){
                j = j + 1;
            }
            else if(nums1.at(i) < nums2.at(j)){
                i = i + 1;
            }
            else{
                if(inter.size() == 0 || inter.at(k) != nums1.at(i)){
                    inter.push_back(nums1.at(i));
                    k = k + 1;
                }
                i = i + 1;
                j = j + 1;
            }
        }
        return inter;
    }

int main() {
    vector<int> nums1 = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> nums2 = {2, 3, 3, 5, 6, 6, 7};
    vector<int> inter = intersection(nums1, nums2);
    for(int i : inter){
        cout << i << " ";
    }
    return 0;
}

// Time Complexity: O(n + m)
// Space Complexity: O(n + m) where n and m are the sizes of the two arrays.