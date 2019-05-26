//判断单链表是否有环
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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode*slower=head,*faster=head;
        while(true){
            slower=slower->next;
            faster=faster->next;
            if(faster==NULL)return false;
            faster=faster->next;
            if(faster==NULL)return false;
            if(slower==faster)break;
        }
        return true;
    }
};
