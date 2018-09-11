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
     ListNode* merge(ListNode* &a, ListNode* &b){
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while(a || b){
            if(a && b){
                if(a->val <= b->val){
                    ListNode* tmp = new ListNode(0);
                    tmp->val = a->val;
                    tmp->next = NULL;
                    if(!head){
                        head = tmp;
                        tail = tmp;
                    }
                    else{
                        tail->next = tmp;
                        tail = tail->next;
                    }
                    a = a->next;
                }
                else if(b->val < a->val){
                    ListNode* tmp = new ListNode(0);
                    tmp->val = b->val;
                    tmp->next = NULL;
                    if(!head){
                        head = tmp;
                        tail = tmp;
                    }
                    else{
                        tail->next = tmp;
                        tail = tail->next;
                    }
                    b = b->next;
                }
            }
            else if(!a && b){
                ListNode* tmp = new ListNode(0);
                tmp->val = b->val;
                tmp->next = NULL;
                if(!head){
                    head = tmp;
                    tail = tmp;
                }
                else{
                    tail->next = tmp;
                    tail = tail->next;
                }
                b = b->next;
            }
            else if(a && !b){
                ListNode* tmp = new ListNode(0);
                tmp->val = a->val;
                tmp->next = NULL;
                if(!head){
                    head = tmp;
                    tail = tmp;
                }
                else{
                    tail->next = tmp;
                    tail = tail->next;
                }
                a = a->next;
            }
        }
        ListNode* tmp = head;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        int size = lists.size();
        while(size > 1){
            int index = 0;
            for(int i = 0; i<size; i++){
                if(i == size-1)
                    lists[index] = lists[i];
                else{
                    lists[index] = merge(lists[i], lists[i+1]);
                    i++;
                    index++;
                }
            }
            if(size % 2 == 0)
                size /= 2;
            else
                size = size/2 + 1;
        }
        return lists[0];
    }
};
