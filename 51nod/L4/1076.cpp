#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=25007;
const int MAXM=5e4+7;

int low[MAXN],dfn[MAXN],timer=0;
struct edge{
	int to,next;
	bool isok;
}es[MAXM*2];

int tot,head[MAXN];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	es[tot].isok=false;
	head[a]=tot++;
}

void dfs(int u,int pre){
	low[u]=dfn[u]=++timer;;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if((i^pre)==1)continue;
		if(!dfn[v]){
			dfs(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				es[i].isok=es[i^1].isok=true;	
			}
		}else low[u]=min(low[u],dfn[v]);
	}
}

vector<int>G[MAXN];
int par[MAXN];
int find(int x){return par[x]==x?par[x]:par[x]=find(par[x]);}
void unit(int x,int y){
	x=find(par[x]);
	y=find(par[y]);
	if(x!=y)par[x]=y;
}

int main(){
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	timer=0;
	int N,M;scanf("%d%d",&N,&M);
	init();
	for(int i=1;i<=M;++i){
		int x,y;scanf("%d%d",&x,&y);
		addEdge(x,y);
		addEdge(y,x);
	}
	for(int i=1;i<=N;++i)
		if(!dfn[i])dfs(i,-1);
	for(int i=1;i<=N;++i)par[i]=i;
	for(int u=1;u<=N;++u){
		for(int i=head[u];~i;i=es[i].next){
			if(es[i].isok)continue;
			int v=es[i].to;
			G[u].push_back(v);
			G[v].push_back(u);
			unit(u,v);
		}
	}

	int Q;scanf("%d",&Q);
	while(Q--){
		int x,y;scanf("%d%d",&x,&y);
		int u=find(x),v=find(y);
		if(u==v)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
