#include<cstdio>
#include<vector>
using namespace std;

const int MAXN=5e5+7;
vector<int>G[MAXN];
int ans[MAXN];
int q[MAXN],top=0;
int  dfs(int u,int prev){
    q[top++]=u;
    int ans=1;
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i];
        if(v==prev)continue;
        ans+=dfs(v,u);
    }
    return ans;
}

int main(){
    int N,M;scanf("%d%d",&N,&M);
    while(M--){
        int x;scanf("%d",&x);
        if(x==0)continue;
        int from;scanf("%d",&from);
        for(int i=1;i<x;++i){
            int to;scanf("%d",&to);
            G[from].push_back(to);
            G[to].push_back(from);
        }
    }
    for(int i=1;i<=N;++i){
        if(ans[i])continue;
        top=0;
        int val=dfs(i,-1);
        for(int j=0;j<top;++j)ans[q[j]]=val;
    }
    for(int i=1;i<=N;++i)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
