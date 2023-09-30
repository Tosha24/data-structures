// Problem: Given a linked list, remove the n-th node from the end of list and return its head.
// For eg: Input: 1->2->3->4->5 and n = 4   ==>    Output: 1->3->4->5

// Solution: Use two pointers, first pointer move n steps first, then move both pointers together until first pointer reach the end. After that, the node at second pointer will be the node before the node we want to remove.

#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* dummy = new ListNode(0, head);
    ListNode* first = dummy;
    ListNode* second = dummy;
    for(int i = 1; i < n + 1; i++){
        first = first->next;
    }

    while(first->next != nullptr){
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return head;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    int n = 4;
    ListNode* result = removeNthFromEnd(head, n);
    while(result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)