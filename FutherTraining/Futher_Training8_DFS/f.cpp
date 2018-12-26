#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=2e5+7;
int a[MAXN];
int N,M;
vector<int>G[MAXN];
int low[MAXN],dfn[MAXN],dfs_clock;
int inStack[MAXN],q[MAXN],top;
int par[MAXN],scc;
void dfs(int);
void find_scc(){
	scc=top=dfs_clock=0;
	memset(par,0,sizeof(par));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(inStack,0,sizeof(inStack));
	for(int i=0;i<2*N;++i)if(!dfn[i])dfs(i);
}
void dfs(int u){
	dfn[u]=low[u]=++dfs_clock;
	inStack[u]=1;
	q[top++]=u;
	int len=G[u].size();
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(!dfn[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		}else if(inStack[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		++scc;
		for(;;){
			int no=q[--top];
			inStack[no]=0;
			par[no]=scc;//这个地方可以存缩点后的权值
			if(no==u)break;
		}
	}
}
int sum;
void init(){
	for(int i=0;i<=2*N;++i)G[i].clear();
	sum=0;
	for(int i=0;i<N;++i)scanf("%d",&a[i]),sum+=a[i];
	for(int i=0;i<M;++i){
		int u,v;scanf("%d%d",&u,&v);
		u--;v--;
		if((N*a[u]>=sum&&N*a[v]>=sum)||(N*a[u]<sum&&N*a[v]<sum)){//同一类
			G[u].push_back(v+N);//A真->B假
			G[v].push_back(u+N);//B真->A假
			G[u+N].push_back(v);//A假->B真
			G[v+N].push_back(u);//B假->A真
		}else{//不同类
			G[u+N].push_back(v);//A假->B真
			G[v+N].push_back(u);//B假->A真
		}
	}
}
void solve(){
	bool hasAns=true;
	for(int i=0;i<N;++i){
		if(par[i]==par[i+N])hasAns=false;
	}
	if(!hasAns){
		printf("No solution.\n");
		return;
	}
	for(int i=0;i<N;++i){
		if(N*a[i]>=sum){
			if(par[i]>par[N+i]){
				printf("C\n");
			}else{
				printf("A\n");
			}
		}else{
			if(par[i]>par[N+i]){
				printf("C\n");
			}else{
				printf("B\n");
			}
		}
	}
}
int main(){
	while(~scanf("%d%d",&N,&M)&&N+M){
		init();
		find_scc();
		solve();
	}
	return 0;
}
