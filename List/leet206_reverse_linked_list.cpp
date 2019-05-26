//翻转单链表
#include<cstdio>
#include<cstring>
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* pre=NULL;
    ListNode* next=NULL;
    while(head!=NULL){
        next=head->next;
        head->next=pre;//待插入的头结点
        pre=head;
        head=next;
    }
    return pre;
}

void show(ListNode*t){
    for(;t!=NULL;t=t->next){
        printf("t:%p\n",t);
        printf("%d ",t->val);
    }
    printf("\n");
    printf("-------------\n");
}

int main(){
    ListNode*head=new ListNode();
    ListNode*start=head;
    for(int i=1;i<=5;++i){
        head->val=i;
        if(i!=5)head->next=new ListNode();
        else head->next=NULL;
        head=head->next;
    }
    show(start);
    ListNode* a=reverseList(start);
    show(a);
    return 0;
}
