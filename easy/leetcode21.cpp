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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL; 
        int last;
        while(l1 != NULL || l2 != NULL){
            ListNode* tmp = new ListNode(0);
            if(l1 != NULL && l2 != NULL){
                if(l1->val <= l2->val){
                    tmp->val = l1->val;
                    tmp->next = NULL;
                    if(head == NULL){
                        head = tmp;
                        tail = tmp;
                    }
                    else{
                        tail->next = tmp;
                        tail = tail->next;
                    }
                    l1 = l1->next;
                }
                else{
                    tmp->val = l2->val;
                    tmp->next = NULL;
                    if(head == NULL){
                        head = tmp;
                        tail = tmp;
                    }
                    else{
                        tail->next = tmp;
                        tail = tail->next;
                    }
                    l2 = l2->next;
                }
            }
            else{
                if(l1 != NULL){
                    tmp->val = l1->val;
                    tmp->next = NULL;
                    if(head == NULL){
                        head = tmp;
                        tail = tmp;
                    }
                    else{
                        tail->next = tmp;
                        tail = tail->next;
                    }
                    l1 = l1->next;
                }
                else{
                    tmp->val = l2->val;
                    tmp->next = NULL;
                    if(head == NULL){
                        head = tmp;
                        tail = tmp;
                    }
                    else{
                        tail->next = tmp;
                        tail = tail->next;
                    }
                    l2 = l2->next;
                }
            }
        }
        return head;
    }
};
