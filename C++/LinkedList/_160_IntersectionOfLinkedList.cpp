// Problem: 
// For eg: 

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

#include <iostream>
#include "ListNode.h"
using namespace std;

class _160_IntersectionOfLinkedList {
public:
    static ListNode* getIntersectionNodeA1(ListNode* headA, ListNode* headB){
        int lenA = 0;
        ListNode* l1 = headA;
        while(l1 != nullptr){
            l1 = l1->next;
            lenA++;
        }

        int lenB = 0;
        ListNode* l2 = headB;
        while(l2 != nullptr){
            l2 = l2->next;
            lenB++;
        }

        int count;
        if(lenA > lenB){
            count = lenA - lenB;
        }
        else{
            count = lenB - lenA;
            ListNode* temp = headA;
            headA = headB;
            headB = temp;
        }

        while(count != 0){
            headA = headA->next;
            count--;
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    static ListNode* getIntersectionNodeA2(ListNode* headA, ListNode* headB){
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        int count = 2;
        while(l1 != nullptr && l2 != nullptr){
            if(l1 == l2){
                return l1;
            }
            l1 = l1->next;
            l2 = l2->next;

            if(count == 0 && l1 == nullptr && l2 == nullptr)
                break;
            if(l1 == nullptr && count != 0){
                l1 = headB;
                count = count - 1;
            }
            if(l2 == nullptr && count != 0){
                l2 = headA;
                count = count - 1;
            }
        }
        return nullptr;
    }
};

int main(){
    ListNode* common = new ListNode(8, new ListNode(4, new ListNode(5, nullptr)));
    ListNode* headA = new ListNode(2, new ListNode(4, new ListNode(5, common)));
    ListNode* headB = new ListNode(3, new ListNode(4, new ListNode(5, common)));
    ListNode* result = _160_IntersectionOfLinkedList::getIntersectionNodeA1(headA, headB);
    if(result)
        cout << result->val << endl;
    else
        cout << result << endl;

    result = _160_IntersectionOfLinkedList::getIntersectionNodeA2(headA, headB);
    if(result)
        cout << result->val << endl;
    else
        cout << result << endl;
    return 0;
}

// Time Complexity for approach first: O(m+n)
// Space Complexity for approach first: O(1)
// Time Complexity for approach second: O(m+n)
// Space Complexity for approach second: O(1)