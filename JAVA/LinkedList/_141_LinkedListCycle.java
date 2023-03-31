// Problem: Given head, the head of a linked list, determine if the linked list has a cycle in it.
// For eg: Input: head = [3,2,0,-4], pos = 1   ==>  Output: true

/* Solution:
 * 1. Use two pointers, slow and fast. Move slow pointer by one and fast pointer by two. If the list has a cycle, the two pointers will meet at some node.
 * 2. If the list does not have a cycle, the fast pointer will either reach the end of the list or null.
 */

final class ListNode{
    int val;
    ListNode next;
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class _141_LinkedListCycle {
    static ListNode insertNode(ListNode head, int val){
        ListNode newNode = new ListNode(val, null);
        if(head == null){
            head = newNode;
            return head;
        }

        ListNode temp = head;
        while(temp.next != null){
            temp = temp.next;
        } 
        temp.next = newNode;
        return head;
    }
    static void createCycle(ListNode head, int start, int end){
        int counta = 0, countb = 0;
        ListNode l1 = head, l2 = head;
        while(counta != start || countb != end){
            if(counta != start){
                l1 = l1.next;
                ++counta;
            }
            if(countb != end){
                l2 = l2.next;
                ++countb;
            }
        } 
        l2.next = l1;
    }

    static boolean hasCycle(ListNode head) {
        if(head == null)
            return false;
        ListNode slow = head, fast = head;
        while((fast != null && fast.next != null) && (slow.next != null)){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast)
                return true;
        }
        return false;
    }
    public static void main(String[] args){
        ListNode head = null;
        head=insertNode(head,1);
        head=insertNode(head,2);
        head=insertNode(head,3);
        head=insertNode(head,4);
        createCycle(head, 1, 3);//creating cycle in the list
        System.out.println(hasCycle(head));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)