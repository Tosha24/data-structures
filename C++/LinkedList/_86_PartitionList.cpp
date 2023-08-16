// Problem: https://leetcode.com/problems/partition-list/

#include <iostream>
#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    static ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = nullptr; 
        ListNode* greaterHead = nullptr;
        ListNode* small = new ListNode();
        ListNode* greater = new ListNode();
        ListNode* mainHead = head;

        while(head != nullptr){
            if(head->val < x){
                if(smallHead == nullptr) smallHead = head;
                small->next = head;
                head = head->next;
                small = small->next;
            }
            else{
                if(greaterHead == nullptr) greaterHead = head;
                greater->next = head;
                head = head->next;
                greater = greater->next;
            }
        }

        if(head == nullptr){
            small->next = greaterHead;
            greater->next = nullptr;
        }
        if(smallHead != nullptr){
            mainHead = smallHead;
        }

        return mainHead;
    }
};

int main(){
    ListNode* head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2, nullptr))))));
    int x = 3;
    ListNode* result = Solution::partition(head, x);
    while(result != nullptr){
        cout << result->val << " -> ";
        result = result->next;
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)