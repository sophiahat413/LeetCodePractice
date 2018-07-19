class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        ListNode* front = NULL;
        ListNode* tail = NULL;
        int i;
        while(head != NULL){
            ListNode* tmpf = NULL;
            ListNode* tmpt = NULL;
            ListNode* tmp2 = head;
            for(i = 0; i<k; i++){
                ListNode* tmp = new ListNode(0);
                tmp->val = head->val;
                tmp->next = tmpf;
                if(i==0)
                    tmpt = tmp;
                tmpf = tmp;
                head = head->next;
                if(head == NULL)
                    break;
            }
            if(i < k-1){
                if(front == NULL)
                    return tmp2;
                else
                    tail->next = tmp2;
            }
            else{
                if(front == NULL){
                    front = tmpf;
                    tail = tmpt;
                }
                else{
                    tail->next = tmpf;
                    tail = tmpt;
                }
            }
        }
        return front;
    }
};
