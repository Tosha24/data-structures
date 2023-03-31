// Problem: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is. You may not alter the values in the list's nodes, only nodes themselves may be changed.
// For eg: Input: 1->2->3->4->5, k = 2     ==>   Output: 2->1->4->3->5

#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode* reverseKGroup(ListNode* head, int k){
    if(head == nullptr || k == 1){
        return head;
    }

    ListNode* dummy = new ListNode(0, head);
    ListNode* prev = dummy, *curr = dummy, *succ = dummy;
    int count = 0;
    
    while(curr->next != nullptr){
        curr = curr->next;
        count++;
    }

    while(count >= k){
        curr = prev->next;
        succ = curr->next;
        for(int i = 1; i < k; i++){
            curr->next = succ->next;
            succ->next = prev->next;
            prev->next = succ;
            succ = curr->next;
        }
        prev = curr;
        count = count - k;
    }
    return dummy->next;
}

int main(){
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, NULL)))));
    int k = 2;
    ListNode* result = reverseKGroup(head, k);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)