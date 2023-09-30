// Problem: Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// For eg: Input: head = [1,2,2,1]      ==>    Output: true

/* Solution:
 * 1. Find the middle node of the linked list.
 * 2. Reverse the second half of the linked list.
 * 3. Compare the first half and the second half of the linked list.
 * 4. Return true if both the halves are equal else return false.
 */

#include <iostream>
#include "ListNode.h"
using namespace std;

// Function to find the middle node of the linked list
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to reverse the linked list
ListNode* reverseList(ListNode* head, ListNode* mid) {
    ListNode* prev = nullptr, *curr = mid->next, *succ = nullptr;
    while(curr != nullptr){
        succ = curr->next;
        curr->next = prev;
        prev = curr;
        curr = succ;
    }
    mid->next = prev;
    return head;
}

// Function to check if the linked list is palindrome or not
bool isPalindrome(ListNode* head) {
    if(head->next == nullptr){
        return true;
    }

    ListNode* mid = middleNode(head);
    head = reverseList(head, mid);
    ListNode* ptr = mid->next;

    while(ptr != nullptr){
        if(ptr->val != head->val){
            return false;
        }
        ptr = ptr->next;
        head = head->next;
    }
    return true;
}

int main()
{
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1, nullptr))));
    isPalindrome(head) ? cout << "true" : cout << "false";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)