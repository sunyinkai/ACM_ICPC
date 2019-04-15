#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e4+7;
const int L=20;
struct edge{
	int to,next,cost;
}es[MAXN*2];
int tot,head[MAXN];
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
int N;

int dis[MAXN];
int par[MAXN][L+1],dfs_clock;
int in[MAXN],out[MAXN];
void dfs(int u,int pre){
	par[u][0]=pre;
	for(int i=1;i<=L;++i)
		par[u][i]=par[par[u][i-1]][i-1];

	in[u]=++dfs_clock;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		dis[v]=dis[u]+es[i].cost;
		dfs(v,u);
	}
	out[u]=dfs_clock;
}

bool is_ancestor(int u,int v){
	return in[u]<=in[v]&&out[u]>=out[v];
}
int query(int u,int v){
	if(is_ancestor(u,v))return u;
	if(is_ancestor(v,u))return v;
	for(int i=L;i>=0;--i)if(!is_ancestor(par[u][i],v))u=par[u][i];
	return par[u][0];
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int Q;
		scanf("%d%d",&N,&Q);
		init();
		for(int i=1;i<N;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		memset(dis,0,sizeof(dis));
		dfs_clock=0;
        //notice the par[root]=root,otherwise there will be problem
		dfs(1,1); 
		while(Q--){
			int a,b;scanf("%d%d",&a,&b);
			printf("%d\n",dis[a]+dis[b]-2*dis[query(a,b)]);
		}
	}
	return 0;
}
