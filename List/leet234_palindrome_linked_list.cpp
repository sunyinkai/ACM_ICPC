//判断一个单链表是不是回文链表
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
    ListNode* reverse(ListNode*head){
        ListNode*prev=NULL,*next=NULL;
        while(head){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode*faster=head,*slower=head;
        ListNode*nowstart=head;
        while(faster){
            slower=slower->next;
            faster=faster->next;
            if(faster==NULL)break;
            faster=faster->next;
        }
        ListNode*newstart=reverse(slower);
        for(ListNode*tmp=newstart;tmp;tmp=tmp->next){
            printf("%d\n",tmp->val);
        }
        for(;nowstart&&newstart;){
            if(nowstart->val!=newstart->val)return false;
            nowstart=nowstart->next;
            newstart=newstart->next;
        }
        return true;
    }
};
