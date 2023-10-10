// Problem: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// For eg: Input: l1 = [2, 4, 3], l2 = [5, 6, 4]     ==>    Output: [7, 0, 8]

/* Solution:
 * We take two pointers l1 and l2 and iterate over both the linked lists simultaneously.
 * We add the values of both the nodes and store the sum variable. Sum variable represents the total sum (including the carry).
 * We only need the last digit of the sum variable and store that last digit in the new node.
 * We also need to store the carry for the next iteration. So, we divide the sum variable by 10 and store the quotient in the carry variable.
 * We then move the pointers to the next nodes.
 */

class ListNode {
    int val;
    ListNode next;

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class _2_AddTwoNumbers {
    static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = null, temp = null;
        int sum, carry = 0;
        while ((l1 != null || l2 != null) || (carry != 0)) {
            sum = 0;
            if (l1 != null) {
                sum = l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum = sum + l2.val;
                l2 = l2.next;
            }
            sum = sum + carry;
            carry = sum / 10;

            ListNode curr = new ListNode(sum % 10, null);
            if (head == null) {
                head = curr;
                temp = head;
            } else {
                temp.next = curr;
                temp = temp.next;
            }
        }
        return head;
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(3, null)));
        ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(4, null)));
        ListNode result = addTwoNumbers(l1, l2);
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}

// Time Complexity: O(max(m, n)) where m and n are the number of nodes in l1 and l2 respectively.
// Space Complexity: O(max(m, n))