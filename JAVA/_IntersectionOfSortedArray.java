// Problem: Find the intersection of the two arrays: Intersection means the common elements in both the arrays.

/* Solution:
 * We use three pointers i, j, k.
 * We traverse through the arrays and check if nums1[i] > nums2[j], if yes, we increment j by 1.
 * Similarly, if nums1[i] < nums2[j], we increment i by 1.
 * Otherwise, we check if inter.size() == 0 || inter.get(k) != nums1[i], if yes, we add nums1[i] to inter and increment k by 1.
 * Finally, we return inter.
 */

import java.util.ArrayList;
import java.util.Arrays;

public class _IntersectionOfSortedArray {
    private static ArrayList<Integer> intersection(ArrayList<Integer> nums1, ArrayList<Integer> nums2){
        ArrayList<Integer> inter = new ArrayList<>();
        int i = 0, j = 0, k = -1;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1.get(i) > nums2.get(j)){
                j = j + 1;
            }
            else if(nums1.get(i) < nums2.get(j)){
                i = i + 1;
            }
            else{
                if(inter.size() == 0 || inter.get(k) != nums1.get(i)){
                    inter.add(nums1.get(i));
                    k = k + 1;
                }
                i = i + 1;
                j = j + 1;
            }
        }
        return inter;
    }
    public static void main(String[] args) {
        ArrayList<Integer> nums1 = new ArrayList<>(Arrays.asList(1, 2, 2, 3, 3, 4, 5, 6));
        ArrayList<Integer> nums2 = new ArrayList<>(Arrays.asList(2, 3, 3, 5, 6, 6, 7));
        ArrayList<Integer> inter = intersection(nums1, nums2);
        System.out.println(inter);
    }
}

// Time Complexity: O(n + m)
// Space Complexity: O(n + m) where n and m are the sizes of the two arrays.