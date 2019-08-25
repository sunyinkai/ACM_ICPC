#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int MAXN=2e5+7;
struct node{
    long long val;
    int id;
    bool operator<(const node& other)const{
        return val>other.val||(val==other.val&&other.id>id);
    }
}no[MAXN];
priority_queue<node,vector<node>,less<node> >q,zero;
int ans[MAXN];

int main(){
    int N;scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%lld",&no[i].val);
        no[i].id=i;
        if(no[i].val==0)zero.push(no[i]);
        else q.push(no[i]);
    }

    int num=1;
    long long sub=0;
    for(;!zero.empty();){
        node t=zero.top();zero.pop();
        sub+=num;
        ans[t.id]=num++;
        while(!q.empty()){
            node tmp=q.top();q.pop();
            if(tmp.val<=sub)tmp.val=0;
            if(tmp.val==0)zero.push(tmp);
            else {
                q.push(tmp);
                break;
            }
        }
    }
    for(int i=0;i<N;++i)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
