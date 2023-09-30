// Problem: Flatten a Linked List such that linked list given is sorted accordingly
// For eg: 5 -> 10 -> 19 -> 28
//         |    |     |     |
//         7    20    22    35
//         |          |     | 
//         8          50    40 
//         |                |   
//         30               45
// Output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 30 -> 35 -> 40 -> 45 -> 50

/* Solution:
 * 1. We will iterate till the end of the linked list so that we can start merging from last two lists and then back track till the first list by merging all the successive lists.
 * 2. We will merge the last two lists by comparing the values of the nodes and then we will merge the result with the third last list and so on.
 * 3. We will finally return the head of the merged list after whole list is flattened.
 */

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode* down;
    ListNode(int x): val(x), next(NULL), down(NULL) {}
    ListNode(int x, ListNode* next, ListNode* down): val(x), next(next), down(down) {}
    ListNode(int x, ListNode* down): val(x), next(NULL), down(down) {}
};

ListNode* mergeList(ListNode* l1, ListNode* l2){
    ListNode* temp = new ListNode(0);
    ListNode* res = temp;
    while(l1 != nullptr && l2 != nullptr){
        if(l1->val <= l2->val){
            temp->down = l1;
            temp = temp->down;
            l1 = l1->down;
        }
        else{
            temp->down = l2;
            temp = temp->down;
            l2 = l2->down;
        }
    }
    if(l1 != nullptr){
        temp->down = l1;
    }
    else{
        temp->down = l2;
    }
    return res->down;
}

ListNode* flatten(ListNode* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* l2 = flatten(head->next);
    head = mergeList(head, l2);
    return head;
}

int main()
{
    ListNode* l1 = new ListNode(7, new ListNode(8, new ListNode(30)));
        ListNode* l2 = new ListNode(20);
        ListNode* l3 = new ListNode(22, new ListNode(50));
        ListNode* l4 = new ListNode(35, new ListNode(40, new ListNode(45)));
        ListNode* head = new ListNode(5, l1, new ListNode(10, l2, new ListNode(19, l3, new ListNode(28, l4, nullptr))));
        ListNode* result = flatten(head);
        while(result != nullptr) {
            cout << result->val << " ";
            result = result->down;
        }
    return 0;
}

// Time Complexity: O(n^2) where n is the number of nodes in the linked list
// Space Complexity: O(1)