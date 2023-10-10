// Problem: https://leetcode.com/problems/middle-of-the-linked-list/
// Description: Given a non-empty, singly linked list with head node head, return a middle node of linked list. If there are two middle nodes, return the second middle node.
// For eg: Input: [1,2,3,4,5]   ==>   Output: [3, 4, 5]

/* Solution:
    1. Use two pointers, slow and fast. Move slow pointer by 1 and fast pointer by 2 (Similar to binary search in infinite array)
    2. When fast reaches the end, slow will be at the middle.
    3. Return slow.
 */

class ListNode{
    int val;
    ListNode next;
    ListNode(int val, ListNode next){
        this.val = val;
        this.next = next;
    }
}

public class _876_MiddleOfLinkedList{
    static ListNode middleNode(ListNode head){
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    public static void main(String[] args){
        ListNode head = new ListNode(1, null);
        ListNode middle = middleNode(head);
        while(middle != null){
            System.out.println(middle.val);
            middle = middle.next;   
        }
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)