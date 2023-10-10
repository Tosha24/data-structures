// Problem: Given a linked list, return the node where the intersection of two singly linked lists begins. If the two linked lists have no intersection at all, return null.
// For eg: Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3   ==>   Output: Reference of the node with value = 8

/* Solution:
 * Approach 1:
 * 1. Find the length of both the linked list
 * 2. Move the pointer of the longer list by the difference of the length of both the list
 * 3. Now move both the pointer by one step at a time and check if they are equal
 * 4. If they are equal then return the node
 * 
 * Approach 2:
 * 1. Take two pointers and point them to the head of both the linked list
 * 2. Now move both the pointers by one step at a time
 * 3. If any of the pointer reaches the end of the list then point it to the head of the other list
 * 4. If both the pointers are equal then return the node
 * 5. We maintain the variable count so that for no intersecting point we don't get into an infinite loop. We only swap the count pointer twice in overall iteration
 */

class ListNode{
    int val;
    ListNode next;
    ListNode(int val, ListNode next){
        this.val = val;
        this.next = next;
    }
}

public class _160_IntersectionOfLinkedList {
    private static ListNode getIntersectionNodeA1(ListNode headA, ListNode headB){
        int lenA = 0;
        ListNode l1 = headA;
        ListNode l2 = headB;
        while(l1 != null){
            l1 = l1.next;
            lenA++;
        }

        int lenB = 0;
        while(l2 != null){
            l2 = l2.next;
            lenB++;
        }

        int count;
        if(lenA > lenB){
            count = lenA - lenB;
        }
        else{
            count = lenB - lenA;
            ListNode temp = headA;
            headA = headB;
            headB = temp;
        }

        while(count != 0){
            headA = headA.next;
            count--;
        }

        while(headA != headB){
            headA = headA.next;
            headB = headB.next;
        }
        return headA;
    }
    static ListNode getIntersectionNodeA2(ListNode headA, ListNode headB){
        ListNode l1 = headA;
        ListNode l2 = headB;
        int count = 2;
        while(l1 != null && l2 != null){
            if(l1 == l2){
                return l1;
            }
            l1 = l1.next;
            l2 = l2.next;

            if(count == 0 && l1 == null && l2 == null)
                break;
            if(l1 == null && count != 0){
                l1 = headB;
                count = count - 1;
            }
            if(l2 == null && count != 0){
                l2 = headA;
                count = count - 1;
            }
        }
        return null;
    }
    public static void main(String[] args){
        ListNode common = new ListNode(8, new ListNode(4, new ListNode(5, null)));
        ListNode headA = new ListNode(4, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5, null)))));
        ListNode headB = new ListNode(5, new ListNode(6, new ListNode(1, common)));
        
        // First Approach
        ListNode result = getIntersectionNodeA1(headA, headB);
        if(result != null)
            System.out.println("Intersection node using first optimal approach: " + result.val);
        else
            System.out.println("No Intersection found: " + result);

        // Second Approach
        result = getIntersectionNodeA2(headA, headB);
        if(result != null)
            System.out.println("Intersection node using second optimal approach: " + result.val);
        else 
            System.out.println("No intersection found: " + result);
    }
}

// Time Complexity for approach first: O(m+n)
// Space Complexity for approach first: O(1)
// Time Complexity for approach second: O(m+n)
// Space Complexity for approach second: O(1)