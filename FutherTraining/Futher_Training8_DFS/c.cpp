//缩点
//特判
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXV=2e4+7;
const int MAXE=5e4+7;
struct edge{
	int from,to,next;
}es[MAXE];
int tot,head[MAXV];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].from=a;
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

int N,M,dfs_clock,scc,top;
int dfn[MAXV],low[MAXV],par[MAXV];
int inStack[MAXV],q[MAXV];
void dfs(int u,int pre){
	dfn[u]=low[u]=++dfs_clock;
	inStack[u]=1;
	q[top++]=u;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}else if(inStack[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		scc++;
		for(;;){
			int no=q[--top];
			par[no]=scc;
			inStack[no]=0;
			if(no==u)break;
		}
	}
}

int in[MAXV],out[MAXV];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		init();
		for(int i=0;i<M;++i){
			int a,b;scanf("%d%d",&a,&b);
			addEdge(a,b);
		}
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(inStack,0,sizeof(inStack));
		dfs_clock=scc=top=0;
		for(int i=1;i<=N;++i){
			if(!dfn[i])dfs(i,-1);
		}
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		for(int i=0;i<M;++i){
			int u=es[i].from,v=es[i].to;
			if(par[u]!=par[v]){
	//			printf("%d->%d\n",par[u],par[v]);
				out[par[u]]++;
				in[par[v]]++;
			}
		}
		int in0=0,out0=0;
		for(int i=1;i<=scc;++i){
	//		printf("in[%d]=%d,out[%d]=%d\n",i,in[i],i,out[i]);
			if(out[i]==0)out0++;
			if(in[i]==0)in0++;
		}
		if(scc!=1)printf("%d\n",max(in0,out0));
		else printf("0\n");
	}
	return 0;
}
