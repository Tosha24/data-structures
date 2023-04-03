// Problem: Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// For eg: Input: head = [3,2,0,-4], pos = 1   ==>  Output: 1

/* Solution: 
 * 1. Use two pointers, slow and fast. Move slow pointer by one and fast pointer by two. If the list has a cycle, the two pointers will meet at some node.
 * 2. If the list does not have a cycle, the fast pointer will either reach the end of the list or null.
 * 3. If the list has a cycle, assign the temp pointer to the head of the list. Move both pointers (temp and slow) one node at a time. The node at which the two pointers meet is the start of the cycle.
 * 4. If the list does not have a cycle, return null.
*/

 final class ListNode{
    int val;
    ListNode next;
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class _142_LinkedListCycleII {
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

    static ListNode detectCycle(ListNode head) {
        if(head == null || head.next == null){
            return null;
        }

        ListNode slow = head, fast = head;
        while((fast != null && fast.next != null) && (slow.next != null)){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                break;
            }
        }
        if(slow == fast){
            ListNode temp = head;
            while(temp != slow){
                temp = temp.next;
                slow = slow.next;
            }
            return temp;
        }
        return null;
    }
    public static void main(String[] args){
        ListNode head = null;
        head=insertNode(head,1);
        head=insertNode(head,2);
        head=insertNode(head,3);
        head=insertNode(head,4);
        createCycle(head, 1, 3);//creating cycle in the list
        ListNode result = detectCycle(head);
        if(result != null){
            System.out.println(result.val);
        }
        else{
            System.out.println("No cycle");
        }
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)