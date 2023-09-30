// Linked List

// Problem: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// For eg: Input: l1 = [2, 4, 3], l2 = [5, 6, 4]     ==>    Output: [7, 0, 8]

/* Solution:
 * We take two pointers l1 and l2 and iterate over both the linked lists simultaneously.
 * We add the values of both the nodes and store the sum variable. Sum variable represents the total sum (including the carry).
 * We only need the last digit of the sum variable and store that last digit in the new node.
 * We also need to store the carry for the next iteration. So, we divide the sum variable by 10 and store the quotient in the carry variable.
 * We then move the pointers to the next nodes.
 */

#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr, *temp = nullptr;
    int sum, carry = 0;
    while((l1 != nullptr || l2 != nullptr) || (carry != 0)) {
        sum = 0;
        if(l1 != nullptr) {
            sum = l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr) {
            sum = sum + l2->val;
            l2 = l2->next;
        }
        sum = sum + carry;
        carry = sum / 10;

        ListNode* curr = new ListNode(sum % 10, nullptr);

        if(head == nullptr){
            head = curr;
            temp = head;
        }
        else{
            temp->next = curr;
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3, nullptr)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4, nullptr)));
    ListNode* result = addTwoNumbers(l1, l2);
    while(result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}

// Time Complexity: O(max(m, n)) where m and n are the number of nodes in l1 and l2 respectively.
// Space Complexity: O(max(m, n))