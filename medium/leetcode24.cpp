public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* front = NULL;
        ListNode* tail = NULL;
        while(head != NULL){
            if(head -> next != NULL){
                ListNode* tmp1 = new ListNode(0);
                ListNode* tmp2 = new ListNode(0);
                if(front == NULL){
                    tmp1->val = head->val;
                    tmp2->val = head->next->val;
                    tmp2->next = tmp1;
                    front = tmp2;
                    tail = tmp1;
                    /*tmp1->val = head->val;
                    tmp1->next = head->next->next;
                    head = head->next;
                    head->next = tmp1;
                    front = head;*/
                }
                else{
                    tmp1->val = head->val;
                    tmp2->val = head->next->val;
                    tmp2->next = tmp1;
                    tail->next = tmp2;
                    tail = tail->next->next;
                }
                head = head->next->next;
            }
            else{
                ListNode* tmp1 = new ListNode(0);
                if(front == NULL){
                    tmp1->val = head->val;
                    tmp1->next = NULL;
                    front = tmp1;
                    tail = tmp1;
                }
                else{
                    tmp1->val = head->val;
                    tmp1->next = NULL;
                    tail->next = tmp1;
                    tail = tail->next;
                }
                head = head->next;
            }
        }
        return front;
    }
};
