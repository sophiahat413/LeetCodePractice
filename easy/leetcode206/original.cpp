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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* nHead = NULL;
        ListNode* nTail = NULL;
        while(head){
            ListNode* tmp = new ListNode(0);
            tmp->val = head->val;
            tmp->next = NULL;
            if(nHead == NULL){
                nHead = tmp;
                nTail = tmp;
            }
            else{
                tmp->next = nHead;
                nHead = tmp;
            }
            head = head->next;
        }
        return nHead;
    }
};
