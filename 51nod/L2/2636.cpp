//tag: greedy,logic
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1e4+7;
struct node{
    int p,c;
    bool operator<(const node&other)const{
        return p>other.p;
    }
}no;

priority_queue<node,vector<node>,less<node> >q;
priority_queue<int,vector<int>,less<int> >has;

int main(){
    int N,L,P;scanf("%d%d%d",&L,&P,&N);
    for(int i=0;i<N;++i){
        scanf("%d%d",&no.p,&no.c);
        q.push(no);
    }
    int now=P;
    bool hasAns=true;
    int cnt=0;
    for(int i=1;i<=L;++i){
        while(!q.empty()){
            node u=q.top();
            if(u.p>i)break;
            has.push(u.c);
            q.pop();
        }

        if(now==0){
            if(!has.empty()){
                now+=has.top();
                has.pop();
                ++cnt;
            }else{
                hasAns=false;
                break;
            }
        }

        now--;
    }
    if(hasAns)printf("%d\n",cnt);
    else printf("-1\n");
    return 0;
}
