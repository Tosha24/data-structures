// Problem: Find the Union of the two sorted arrays: Union means all the unique elements in both the arrays.

/* Solution:
 * We use three pointers i, j, k.
 * We traverse through the arrays and check if nums1[i] > nums2[j], if yes, we increment j by 1.
 * Similarly, if nums1[i] < nums2[j], we increment i by 1.
 * Otherwise, we check if union.size() == 0 || union.get(k) != nums1[i], if yes, we add nums1[i] to union and increment k by 1.
 * Finally, we return union.
 */

import java.util.*;

public class _UnionOfSortedArray {
    private static ArrayList<Integer> union(ArrayList<Integer> nums1, ArrayList<Integer> nums2){
        ArrayList<Integer> union = new ArrayList<>();
        int i = 0, j = 0, k = -1;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1.get(i) > nums2.get(j)){
                if(union.size() == 0 || union.get(k) != nums2.get(j)){
                    union.add(nums2.get(j));
                    k = k + 1;
                }
                j = j + 1;
            }
            else if(nums1.get(i) < nums2.get(j)){
                if(union.size() == 0 || union.get(k) != nums1.get(i)){
                    union.add(nums1.get(i));
                    k = k + 1;
                }
                i = i + 1;
            }
            else{
                if(union.size() == 0 || union.get(k) != nums1.get(i)){
                    union.add(nums1.get(i));
                    k = k + 1;
                }
                i = i + 1;
                j = j + 1;
            }
        }

        while(i < nums1.size()){
            if(union.size() == 0 || union.get(k) != nums1.get(i)){
                union.add(nums1.get(i));
                k = k + 1;
            }
            i = i + 1;
        }

        while(j < nums2.size()){
            if(union.size() == 0 || union.get(k) != nums2.get(j)){
                union.add(nums2.get(j));
                k = k + 1;
            }
            j = j + 1;
        }
        return union;
    }
    public static void main(String[] args) {
        ArrayList<Integer> nums1 = new ArrayList<>(Arrays.asList(3, 3, 5, 7, 9, 11, 13, 15, 15, 15));
        ArrayList<Integer> nums2 = new ArrayList<>(Arrays.asList(2, 4, 6, 8, 10, 11, 12, 13, 15, 15, 15, 16));
        ArrayList<Integer> union = union(nums1, nums2);
        System.out.println(union);
    }
}

// Time Complexity: O(n + m)
// Space Complexity: O(n + m) where n and m are the sizes of the two arrays.