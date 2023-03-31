// Problem: Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// For eg: Input: head = [1,2,2,1]      ==>    Output: true

/* Solution:
 * 1. Find the middle node of the linked list.
 * 2. Reverse the second half of the linked list.
 * 3. Compare the first half and the second half of the linked list.
 * 4. Return true if both the halves are equal else return false.
 */

class ListNode{
    int val;
    ListNode next;
    ListNode(int val, ListNode next){
        this.val = val;
        this.next = next;
    }
}

public class _234_PalindromeLinkedList {
    static ListNode middleNode(ListNode head){
        ListNode slow = head, fast = head;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    static ListNode reverseList(ListNode head, ListNode mid){
        ListNode prev = null, curr = mid.next;
        ListNode succ = null;
        while(curr != null){
            succ = curr.next;
            curr.next = prev;
            prev = curr;
            curr = succ;
        }
        mid.next = prev;
        return head;
    }
    static boolean isPalindrome(ListNode head){
        if(head == null || head.next == null){
            return true;
        }
        ListNode mid = middleNode(head);
        head = reverseList(head, mid);
        ListNode ptr = mid.next;
        while(ptr != null) {
            if(ptr.val != head.val){
                return false;
            }
            ptr = ptr.next;
            head = head.next;
        }
        return true;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1, null))));
        System.out.println(isPalindrome(head));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)