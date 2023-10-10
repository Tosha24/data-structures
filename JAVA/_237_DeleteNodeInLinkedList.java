// Problem: https://leetcode.com/problems/delete-node-in-a-linked-list/
// For eg: Input: head = [4,5,1,9], node = 5    ==>   Output: [4,1,9]

/* Solution:
 * We do not delete the node from the memory but instead we copy the value of the next node to the given node(to be deleted).
 * We then point the given node to the next of the next node.
 * So that the linked list is continous.
 */

class ListNode{
    int val;
    ListNode next;
    ListNode(int val, ListNode next) { 
        this.val = val;
        this.next = next;
    }
}

public class _237_DeleteNodeInLinkedList {
    static void deleteNode(ListNode node){
        node.val = node.next.val;
        node.next = node.next.next;
    }
    public static void main(String[] args) {
        ListNode node = new ListNode(3, new ListNode(4, new ListNode(5, null)));
        ListNode head = new ListNode(1, new ListNode(2, node));
        deleteNode(node);
        while(head != null){
            System.out.print(head.val + ", ");
            head = head.next;
        }
    }
}

// Time Complexity: O(1)
// Space Complexity: O(1)
