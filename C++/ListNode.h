struct ListNode{
    int val;
    ListNode* next;
    ListNode(){
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int x, ListNode* next){
        this->val = x;
        this->next = next;
    }
};