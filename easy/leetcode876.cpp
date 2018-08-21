class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        ListNode* mid = head;
        int countF = 0, countM = 0, move, i;
        while(fast != NULL){
            countF++;
            fast = fast->next;
            move = countF / 2 - countM;
            if(fast == NULL){
                if(move == 0)
                    mid = mid->next;
            }
            for(i = 0; i<move; i++){
                mid = mid->next;
                countM++;
            }
        }
        return mid;
    }
};
