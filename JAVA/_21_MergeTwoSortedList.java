// Problem: Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
// For eg: Input: 1->2->4, 1->3->4    ==>   Output: 1->1->2->3->4->4

/* Solution:
 * 1. Create a new node with value 0 and next pointing to null. This will be used to store the last node of the merged list.
 * 2. Compare the values of the first nodes of both the lists. If the value of the first node of the first list is greater than the value of the first node of the second list, then swap the two lists.
 * 3. Now, the first node of the first list will be the smallest node. So, store the first node of the first list in a variable called head. This will be the head of the merged list.
 * 4. Now, traverse the first list until the value of the current node is less than or equal to the value of the first node of the second list.
 * 5. When the value of the current node is greater than the value of the first node of the second list, then store the current node in a variable called temp.
 * 6. Now, swap the two lists. So, the first list will be the second list and the second list will be the first list.
 */

class ListNode{
    int val;
    ListNode next;
    ListNode(int val, ListNode next){
        this.val = val;
        this.next = next;
    }
}

public class _21_MergeTwoSortedList {
    static ListNode mergeTwoLists(ListNode l1, ListNode l2){
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        if(l1.val > l2.val){
            ListNode temp = l1;
            l1 = l2;
            l2 = temp;
        }

        ListNode head = l1;
        ListNode temp = new ListNode(0, null);
        while(l1 != null && l2 != null){
            while(l1 != null && l1.val <= l2.val){
                temp = l1;
                l1 = l1.next;
            }
            temp.next = l2;

            ListNode temp2 = l1;
            l1 = l2;
            l2 = temp2;
        }
        return head;
    }
    public static void main(String[] args){
        ListNode l1 = new ListNode(5, new ListNode(7, new ListNode(9, null)));
        ListNode l2 = new ListNode(3, new ListNode(4, new ListNode(8, new ListNode(10, null))));
        ListNode result = mergeTwoLists(l1, l2);
        while(result != null){
            System.out.println(result.val);
            result = result.next;
        }
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)