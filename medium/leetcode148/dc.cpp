/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//4->2->1->3
//2->4->1->3

class Solution {
public:
    ListNode* sortList(ListNode* head) {
       if(head == NULL)
           return NULL;
        ListNode* tail = head;
        while(tail->next)
            tail = tail->next;
        return mergeSortedList(head, tail);
    }
    ListNode* mergeList(ListNode* a, ListNode* b){
        ListNode head(0);
        ListNode *headPtr = &head;
        while(a && b){
            if(a->val < b->val){
                headPtr->next = a;
                a = a->next;
            }
            else{
                headPtr->next = b;
                b = b->next;
            }
            headPtr = headPtr->next;
        }
        headPtr->next = !a ? b : a;
        return head.next;
    }
    ListNode* getmid(ListNode* front, ListNode* tail){
        if(front == tail)
            return front;
        ListNode* slow = front;
        ListNode* fast = front;
        while(slow && fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSortedList(ListNode* front, ListNode* tail){
        if(front == tail)
            return front;
        ListNode* mid = getmid(front, tail);
        ListNode* postList = mergeSortedList(mid->next, tail);
        mid->next = NULL;
        ListNode* preList = mergeSortedList(front, mid);
        return mergeList(preList, postList);   
    }
};
