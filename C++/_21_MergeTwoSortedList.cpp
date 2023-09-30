// Problem: Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
// For eg: Input: 1->2->4, 1->3->4    ==>   Output: 1->1->2->3->4->4

/* Solution:
 * 1. Create a new node with value 0 and next pointing to null. This will be used to store the last node of the merged list.
 * 2. Compare the values of the first nodes of both the lists. If the value of the first node of the first list is greater than the value of the first node of the second list, then swap the two lists.
 * 3. Now, the first node of the first list will be the smallest node. So, store the first node of the first list in a variable called head. This will be the head of the merged list.
 * 4. Now, traverse the first list until the value of the current node is less than or equal to the value of the first node of the second list.
 * 5. When the value of the current node is greater than the value of the first node of the second list, then store the current node in a variable called temp.
 * 6. Now, swap the two lists. So, the first list will be the second list and the second list will be the first list.
 */

#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    
    if(list1->val > list2->val){
        ListNode* temp = list1;
        list1 = list2;
        list2 = temp;
    }

    ListNode* result = list1;
    ListNode* temp = nullptr;
    while(list1 != nullptr && list2 != nullptr){
        if(list1 != nullptr && list1->val <= list2->val){
            temp = list1;
            list1 = list1->next;
        }
        temp->next = list2;
        
        ListNode* temp1 = list1;
        list1 = list2;
        list2 = temp1;
    }
    return result;
}

int main()
{
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4, nullptr)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));
    ListNode* result = mergeTwoLists(list1, list2);
    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)