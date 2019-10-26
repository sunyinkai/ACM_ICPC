#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1007;
int par[MAXN][11];
int dis[MAXN];
int N,M;
struct edge{
    int to,next,cost;
}es[MAXN*2];
int head[MAXN];
int in[MAXN],out[MAXN];
int tot=0,dfs_clock;
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void addEdge(int a,int b,int c){
    es[tot].to=b;
    es[tot].cost=c;
    es[tot].next=head[a];
    head[a]=tot++;
}

void dfs(int u,int pre,int len){
    in[u]=dfs_clock++;
    dis[u]=len;
    par[u][0]=pre;
    for(int i=1;i<11;++i)par[u][i]=par[par[u][i-1]][i-1];
    for(int i=head[u];~i;i=es[i].next){
        int v=es[i].to;
        if(v==pre)continue;
        dfs(v,u,len+es[i].cost);
    }
    out[u]=dfs_clock;
}

bool is_ancesstor(int u,int v){
    return (u==0)||(in[u]<=in[v]&&out[u]>=out[v]);
}

int LCA(int x,int y){
    if(is_ancesstor(x,y))return x;
    if(is_ancesstor(y,x))return y;
    for(int i=10;i>=0;--i)
        if(!is_ancesstor(par[x][i],y))x=par[x][i];
    return par[x][0];
}

int main(){
 //   freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&N,&M)){
        init();
        memset(dis,0,sizeof(dis));
        dfs_clock=1;
        for(int i=1;i<N;++i){
            int u,v,c;scanf("%d%d%d",&u,&v,&c);
            addEdge(u,v,c);
            addEdge(v,u,c);
        }
        dfs(1,0,0);
        while(M--){
            int x,y;scanf("%d%d",&x,&y);
            printf("%d\n",dis[x]+dis[y]-2*dis[LCA(x,y)]);
        }
    }

    return 0;
}
