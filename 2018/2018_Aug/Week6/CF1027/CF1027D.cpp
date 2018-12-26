//首先先想到连通性的问题
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=2e5+7;
const int MAXM=1e5+7;
const int INF=1e9+7;
int a[MAXN],val[MAXN];
int N,M;
struct edge{
	int from,to,next;
}es[MAXM*2];
int head[MAXN],tot;
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

int dfs_clock=0,dfn[MAXN],low[MAXN];
int scc,top,par[MAXN],inStack[MAXN],q[MAXN];
void dfs(int u,int pre){
	dfn[u]=low[u]=++dfs_clock;
	q[top++]=u;
	inStack[u]=1;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		//这个地方不能加v==pre
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}else if(inStack[v])low[u]=min(low[u],dfn[v]);
		//inStack[v]不能漏
	}
	if(low[u]==dfn[u]){
		++scc;
		for(;;){
			int no=q[--top];
			inStack[no]=0;
			par[no]=scc;
			if(no==u)break;
		}
	}
}

int hasCal[MAXN];

struct edges{
	int u,v,next;
}e[MAXM*2];
int tot2,head2[MAXN];
void init2(){
	tot2=0;
	memset(head2,-1,sizeof(head2));
}
void addEdge2(int a,int b){
	e[tot2].v=b;
	e[tot2].u=a;
	e[tot2].next=head2[a];
	head2[a]=tot2++;
}

int res,du[MAXN];

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
		val[i]=INF;
	}
	init();
	for(int i=1;i<=N;++i){
		int x;scanf("%d",&x);
		addEdge(i,x);
	}

	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(inStack,0,sizeof(inStack));
	scc=0,top=0;
	for(int i=1;i<=N;++i){
		if(!dfn[i])dfs(i,-1);//一定要先考虑连通性
	}

	memset(hasCal,0,sizeof(hasCal));
	M=N;
	for(int i=0;i<M;++i){
		int u=es[i].from,v=es[i].to;
		if(!hasCal[v])val[par[v]]=min(val[par[v]],a[v]);
		if(!hasCal[u])val[par[u]]=min(val[par[u]],a[u]);
		hasCal[u]=hasCal[v]=1;
	}

	init2();
	for(int i=0;i<M;++i){
		int u=es[i].from,v=es[i].to;
		if(par[v]!=par[u]){
			addEdge2(par[u],par[v]);
			du[par[u]]++;
		}
	}
	int res=0;
	for(int i=1;i<=scc;++i){
		if(du[i]==0)res+=val[i];
	}
	printf("%d\n",res);

	return 0;
}
