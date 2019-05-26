#include<cstdio>
typedef unsigned long long ull;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(NULL) {}
};

ListNode* XOR(ListNode*a,ListNode*b){
    return (ListNode*)(ull(a)^ull(b));
}


bool isPalindrome(ListNode* head) {
    if(head==NULL||head->next==NULL)return true;

    ListNode *begin=head,*end=NULL;
    //encode,transfer single linked list to double
    ListNode*prev=NULL;
    for(;head;){
        if(head->next==NULL)end=head;
        ListNode*nextNode=head->next;
        head->next=XOR(prev,head->next);
        prev=head;
        head=nextNode;
    }
    //decode
    ListNode*front=NULL,*back=NULL;
    for(;;){
        if(begin>=end)break;
        if(begin->val!=end->val)return false;
        front=begin;back=end;
        begin=XOR(begin,front);
        end=XOR(end,back);
    }
    return true;
}

void show(ListNode*t){
    for(;t;t=t->next){
        printf("t->val:%d,t=%p\n",t->val,t);
    }
}

int main(){
    ListNode*begin=new ListNode();
    ListNode*t=begin;
    for(int i=1;i<=2;++i){
        begin->val=i;
        if(i!=2){begin->next=new ListNode();}
        else begin->next=NULL;
        begin=begin->next;
    }
    show(t);
    printf("%d\n",isPalindrome(t));
    return 0;
}
