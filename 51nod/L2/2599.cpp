//tag: LCA
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN=1007;
const int MAXM=20;
int in[MAXN],out[MAXN];
int time=0;
vector<int>G[MAXN];
int par[MAXN][MAXM];

void dfs(int u,int pre){
    par[u][0]=pre;
    for(int i=1;i<MAXM;++i){
        par[u][i]=par[par[u][i-1]][i-1];
    }

    in[u]=++time;
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i];
        if(v==pre)continue;
        dfs(v,u);
    }
    out[u]=time;
}

bool is_ancesstor(int u,int v){
    return (in[u]<=in[v]&&out[u]>=out[v]);
}
int LCA(int u,int v){
    if(is_ancesstor(u,v))return u;
    if(is_ancesstor(v,u))return v;
    for(int k=MAXM-1;k>=0;--k)
        if(!is_ancesstor(par[u][k],v))u=par[u][k];
    return par[u][0];
}

int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<N;++i){
        int x,y;scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,1);//important
    int M;scanf("%d",&M);
    while(M--){
        int x,y;scanf("%d%d",&x,&y);
        printf("%d\n",LCA(x,y));
    }
    return 0;
}
