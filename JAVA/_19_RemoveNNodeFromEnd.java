// Problem: Given a linked list, remove the n-th node from the end of list and return its head.
// For eg: Input: 1->2->3->4->5 and n = 4   ==>    Output: 1->3->4->5

// Solution: Use two pointers, first pointer move n steps first, then move both pointers together until first pointer reach the end. After that, the node at second pointer will be the node before the node we want to remove.

class ListNode{
    int val;
    ListNode next;
    ListNode(int x, ListNode next){
        this.val = x;
        this.next = next;
    }
}

public class _19_RemoveNNodeFromEnd {
    static ListNode removeNthFromEnd(ListNode head, int n){
        ListNode dummy = new ListNode(0, head);
        ListNode start = dummy;
        ListNode first = dummy;
        for(int i = 1; i <= n; i++){
            first = first.next;
        }

        while(first.next != null){
            first = first.next;
            start = start.next;
        }

        start.next = start.next.next;
        return head;
    }
    public static void main(String[] args){
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, null)))));
        int n = 4;
        ListNode result = removeNthFromEnd(head, n);
        while(result != null){
            System.out.println(result.val);
            result = result.next;
        }
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)