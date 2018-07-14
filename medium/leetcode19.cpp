/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode* tmp = head;
        int count = 0;
        while(tmp != NULL){
            count++;
            tmp = tmp->next;
        }
        
        ListNode* front = NULL;
        ListNode* tail = NULL;
        int index = count - n;
        for(int i = 0; i< count; i++){
            if(i != index){
                ListNode* tmp = new ListNode(0);
                tmp->val = head->val;
                tmp->next = NULL;
                if(front == NULL){
                    front = tmp;
                    tail = tmp;
                }
                else{
                    tail->next = tmp;
                    tail = tail->next;
                }
            }
            head = head->next;
        }
        return front;
    }
};
