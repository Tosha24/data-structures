// Problem: Given the head of a linked list, rotate the list to the right by k places
// Input: 1->2->3->4->5->NULL, k = 2        ==>   Output: 4->5->1->2->3->NULL

/* Solution:
 * 1. Find the length of the list
 * 2. Connect the last node in list to the head.
 * 3. Iterate only first (len - k) nodes and break the connection after making head point to the next node which will be the head of the linked list after rotation.
 * 4. Assign null to the last node of the rotated linked list.
 * 5. Return the head of the rotated linked list.
 */

class ListNode{
    int val;
    ListNode next;
    ListNode(int val, ListNode next){
        this.val = val;
        this.next = next;
    }
}

public class _61_RotateList{
    public static ListNode rotateRight(ListNode head, int k){
        if(head == null){
            return head;
        }
        int len = 1;
        ListNode temp = head;
        while(temp.next != null){
            len = len + 1;
            temp = temp.next;
        }
        temp.next = head;
        k = k % len;
        int iter = len - k;
        while(iter != 0){
            temp = temp.next;
            iter = iter - 1;
        }
        head = temp.next;
        temp.next = null;
        return head;
    }
    public static void main(String[] args){
        ListNode head = new ListNode(0, new ListNode(1, new ListNode(2, null)));
        int k = 4;

        ListNode result = rotateRight(head, k);
        while(result != null){
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)