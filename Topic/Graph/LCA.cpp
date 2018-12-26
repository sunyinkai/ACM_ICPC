// 树上不带修改的任意两点间的路径询问
//soj1677
#include<bits/stdc++.h>
using namespace std;
const int MAXE=2e4+7;
const int MAXV=1e4+7;
struct edge{
	int to,next,cost;
}es[MAXE*2];
int tot,head[MAXV];
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
int par[MAXV][20],depth[MAXV],cost[MAXV];
int N,M;
void dfs(int u,int pre,int f,int dep){
	par[u][0]=pre;
	cost[u]=f;
	depth[u]=dep;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		dfs(v,u,f+es[i].cost,dep+1);
	}
}
void preLCA(){
	for(int j=1;(1<<j)<=N;++j){
		for(int i=1;i<=N;++i){
			int a=par[i][j-1];
			par[i][j]=par[a][j-1];
		}
	}
}
int LCA(int a,int b){
	if(depth[a]<depth[b])swap(a,b);
	int d=depth[a]-depth[b];
	for(int i=0;(1<<i)<=d;++i)
		if(d&(1<<i))a=par[a][i];
	if(a!=b){
		for(int i=(int)log2(N);i>=0;--i)
			if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
		a=par[a][0];
	}
	return a;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&N,&M);
		for(int i=1;i<N;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		dfs(1,-1,0,0);
		preLCA();
		for(int i=0;i<M;++i){
			int a,b;scanf("%d%d",&a,&b);
			//printf("LCA=%d\n",LCA(a,b));
			printf("%d\n",cost[a]+cost[b]-2*cost[LCA(a,b)]);
		}
		printf("\n");
	}
	return 0;
}
