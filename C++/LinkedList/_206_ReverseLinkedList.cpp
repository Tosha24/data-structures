// Problem: Given a linked list head, reverse the linked list and return the reversed list.
// For eg: Input: head = [1, 2, 3, 4, 5]     ==>    Output: [5, 4, 3, 2, 1]

/* Solution:
 * Here we simply iterate from the first element in linked list and reverse the link of each element.
 * We iterate till our head reaches the nullptr.
 */

#include "ListNode.h"
#include <bits/stdc++.h>
using namespace std;

ListNode* reverseList(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* succ = head->next;
    ListNode* prev = head;
    head->next = nullptr;
    head = succ;
    while(head != nullptr){
        succ = head->next;
        head->next = prev;
        prev = head;
        head = succ;
    }
    head = prev;
    return head;
}

int main(){
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    ListNode* list = reverseList(head);
    while(list != nullptr){
        cout << list->val << " ";
        list = list->next;
    }
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)