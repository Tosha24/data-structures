// Problem: https://leetcode.com/problems/delete-node-in-a-linked-list/
// For eg: Input: head = [4,5,1,9], node = 5    ==>   Output: [4,1,9]

/* Solution:
 * We do not delete the node from the memory but instead we copy the value of the next node to the given node(to be deleted).
 * We then point the given node to the next of the next node.
 * So that the linked list is continous.
 */

#include <iostream>
#include "ListNode.h"
using namespace std;

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int main()
{
    ListNode* node = new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7, nullptr)))));
    ListNode* head = new ListNode(1, new ListNode(2, node));
    deleteNode(node);
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)