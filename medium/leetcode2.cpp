class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int digit = 0, flow = 0;
        vector<int> ans;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(l1 != NULL || l2 != NULL){
            digit = 0;
            ListNode* tmp = new ListNode(0); 
            if(l1 != NULL && l2 != NULL){
                digit = l1->val + l2->val + flow;
                flow = 0;
                if(digit >= 10){
                    flow = 1;
                    digit = digit % 10;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 != NULL && l2 == NULL){
                digit = l1->val + flow;
                flow = 0;
                if(digit >= 10){
                    flow = 1;
                    digit = digit % 10;
                }
                l1 = l1->next;
            }
            else if(l1 == NULL && l2 != NULL){
                digit = l2->val + flow;
                flow = 0;
                if(digit >= 10){
                    flow = 1;
                    digit = digit % 10;
                }
                l2 = l2->next;
            }
            tmp->val = digit;
            tmp->next = NULL;
            if(head == NULL){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->next = tmp;
                tail = tail->next;
            }
        }
        if(flow != 0){
            ListNode* tmp = new ListNode(0);
            tmp->val = flow;
            tmp->next = NULL;
            if(head == NULL){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->next = tmp;
                tail = tail->next;
            }
        }
        return head;
    }
};
