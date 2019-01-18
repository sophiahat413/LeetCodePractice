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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int len = 1;
        ListNode *newHead, *newTail;
        newHead = newTail = head;
        while(newTail->next){
            newTail = newTail->next;
            len++;
        }
        newTail->next = head; //circle the list
        //after k rotate the len - k node would be at the tail
        if(k %= len){
            for(int i = 0; i < (len-k); i++)
                newTail = newTail->next;
        }
        newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};
