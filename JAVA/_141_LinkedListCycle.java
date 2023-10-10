// Problem: Given head, the head of a linked list, determine if the linked list has a cycle in it.
// For eg: Input: head = [3,2,0,-4], pos = 1   ==>  Output: true

// Approach: Brute Force
/* Solution:
* 1. We use a HashSet to store the nodes that have been visited.
* 2. Traverse the list and check if the current node is already present in the HashSet.
* 3. If it is present, then the list has a cycle, hence return true. Otherwise, add the current node to the HashSet and move to the next node. 
* 4. If the end of the list is reached, then the list does not have a cycle, hence return false.
*/

import java.util.HashSet;

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
        HashSet<ListNode> set = new HashSet<>();
        while(head != null){
            if(set.contains(head)){
                return true;
            }
            set.add(head);
            head = head.next;
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
// Space Complexity: O(n)