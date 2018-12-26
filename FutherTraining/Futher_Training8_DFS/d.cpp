//缩点
//DAG上最长路
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXV=2e4+7;
const int MAXE=5e4+7;
struct edge{
	int from,to,next;
}es[2][MAXE];
int tot[2],head[2][MAXV];
void init(int kind){
	tot[kind]=0;
	memset(head[kind],-1,sizeof(head[kind]));
}

void addEdge(int kind,int a,int b){
	es[kind][tot[kind]].from=a;
	es[kind][tot[kind]].to=b;
	es[kind][tot[kind]].next=head[kind][a];
	head[kind][a]=tot[kind]++;
}

int N,M,dfs_clock,scc,top;
int dfn[MAXV],low[MAXV],par[MAXV];
int inStack[MAXV],q[MAXV];
void dfs(int kind,int u,int pre){
	dfn[u]=low[u]=++dfs_clock;
	inStack[u]=1;
	q[top++]=u;
	for(int i=head[kind][u];~i;i=es[kind][i].next){
		int v=es[kind][i].to;
		//if(v==pre)continue;
		if(!dfn[v]){
			dfs(kind,v,u);
			low[u]=min(low[u],low[v]);
		}else if(inStack[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		scc++;
		for(;;){
			int no=q[--top];
			inStack[no]=0;
			par[no]=scc;
			if(no==u)break;
		}
	}
}

int val[MAXV],visit[MAXV],dp[MAXV];
int ddfs(int u,int pre){
	if(dp[u])return dp[u];
	for(int i=head[1][u];~i;i=es[1][i].next){
		int v=es[1][i].to;
		if(v==pre)continue;
		dp[u]=max(dp[u],ddfs(v,u));
	}
	dp[u]+=val[u];
	return dp[u];
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		init(0);
		for(int i=0;i<M;++i){
			int a,b;scanf("%d%d",&a,&b);
			addEdge(0,a,b);
		}

		if(N==0){
			printf("0\n");
			continue;
		}else if(M==0){
			printf("1\n");
			continue;
		}

		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(inStack,0,sizeof(inStack));
		dfs_clock=scc=top=0;
		for(int i=1;i<=N;++i){
			if(!dfn[i])dfs(0,i,-1);
		}

		memset(val,0,sizeof(val));
		memset(visit,0,sizeof(visit));
		memset(dp,0,sizeof(dp));
		init(1);
		for(int i=0;i<M;++i){
			int u=es[0][i].from,v=es[0][i].to;
			if(!visit[u])val[par[u]]++;
			if(!visit[v])val[par[v]]++;
			visit[u]=visit[v]=1;
			if(par[u]!=par[v])addEdge(1,par[u],par[v]);
		}

		int res=1;
		for(int i=1;i<=scc;++i)if(!dp[i])ddfs(i,-1);
		for(int i=1;i<=scc;++i)res=max(res,dp[i]);
		printf("%d\n",res);
	}
	return 0;
}
