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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* faster=head, *slower=head;
        while(faster&&faster->next){
            slower=slower->next;
            faster=faster->next;
            if(faster!=NULL)faster=faster->next;
        }
        return slower;
    }
};
