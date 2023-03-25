// Problem: Given a linked list head, reverse the linked list and return the reversed list.
// For eg: Input: head = [1, 2, 3, 4, 5]     ==>    Output: [5, 4, 3, 2, 1]

/* Solution:
 * Here we simply iterate from the first element in linked list and reverse the link of each element.
 * We iterate till our head reaches the nullptr.
 */

class ListNode{
    int val;
    ListNode next;
    ListNode(){
        this.val = 0;
        this.next = null;
    }
    ListNode(int val, ListNode next){
        this.val = val;
        this.next = next;
    }
}
public class _206_ReverseLinkedList {
    public static ListNode reverseList(ListNode head){
        if(head == null || head.next == null){
            return head;
        }
        ListNode succ = head.next;
        ListNode prev = head;
        head.next = null;
        head = succ;
        while(head != null){
            succ = head.next;
            head.next = prev;
            prev = head;
            head = succ;
        }
        head = prev;
        return head;
    }
    public static void main(String[] args){
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, null)))));
        ListNode list = reverseList(head);
        while(list != null){
            System.out.println(list.val);
            list = list.next;
        }
    }   
}

// Time Complexity: O(n)
// Space Complexity: O(1)