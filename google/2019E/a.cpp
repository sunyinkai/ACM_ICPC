//tag: union_set,graph
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
struct edge{
    int u,v,cost;
    bool operator<(const edge&other)const{
        return cost<other.cost;
    }
}no[MAXN];
int par[MAXN];
int find(int x){
    return par[x]==x?par[x]:par[x]=find(par[x]);
}
void unit(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y)par[x]=y;
}

int main(){
    int T;scanf("%d",&T);
    for(int test=1;test<=T;++test){
        int N,M;scanf("%d%d",&N,&M);
        for(int i=0;i<M;++i){
            scanf("%d%d",&no[i].u,&no[i].v);
            no[i].cost=1;
        }
        sort(no,no+M);
        for(int i=1;i<=N;++i)par[i]=i;
        int ans=0;
        for(int i=0;i<M;++i){
            int x=no[i].u,y=no[i].v;
            x=find(x);y=find(y);
            if(x!=y){
                par[x]=y;
                ans++;
            }
        }
        printf("Case #%d: %d\n",test,ans+(N-1-ans)*2);
    }
    return 0;
}
