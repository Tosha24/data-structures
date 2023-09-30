// Problem: https://leetcode.com/problems/middle-of-the-linked-list/
// Description: Given a non-empty, singly linked list with head node head, return a middle node of linked list. If there are two middle nodes, return the second middle node.
// For eg: Input: [1,2,3,4,5]   ==>   Output: [3, 4, 5]

/* Solution:
    1. Use two pointers, slow and fast. Move slow pointer by 1 and fast pointer by 2 (Similar to binary search in infinite array)
    2. When fast reaches the end, slow will be at the middle.
    3. Return slow.
 */

#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode* middleNode(ListNode* head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    ListNode* mid = middleNode(head);
    while(mid != nullptr){
        cout << mid->val << " ";
        mid = mid->next;
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)