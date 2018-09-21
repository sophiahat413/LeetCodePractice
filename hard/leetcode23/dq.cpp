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
    ListNode* merge2List(ListNode* l1, ListNode* l2){
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val <= l2 ->val){
            l1->next = merge2List(l1->next, l2);
            return l1;
        }
        if(l1->val > l2->val){
            l2->next = merge2List(l1, l2->next);
            return l2;
        }
    }
    ListNode* doMerge(vector<ListNode*>& lists, int left, int right){
        if(left == right)
            return lists[left];
        if(left + 1 == right)
            return merge2List(lists[left], lists[right]);
        ListNode* l1 = doMerge(lists, left, (left+right) / 2);
        ListNode* l2 = doMerge(lists, (left+right) / 2 + 1, right);
        return merge2List(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        if((int)lists.size() == 1)
            return lists[0];
        return doMerge(lists, 0, (int)lists.size()-1);
    }
};
