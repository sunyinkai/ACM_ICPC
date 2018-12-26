#include<cstdio>
#include<cstring>
#include<map>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;
const int MAXV=1007,MAXE=1e5+7;
struct edge{
	int to,next;
}es[MAXE],es2[MAXE];
int tot,head[MAXV];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

int tot2,head2[MAXV];
void init2(){
	tot2=0;
	clr(head2,-1);
}
void addEdge2(int a,int b){
	es2[tot2].to=b;
	es2[tot2].next=head2[a];
	head2[a]=tot2++;
}

int belong[MAXV],scc;
int low[MAXV],dfn[MAXV],dfs_clock;
int stack[MAXV],top;
int weight[MAXV];
void dfs(int u,int pre){
	low[u]=dfn[u]=++dfs_clock;
	stack[top++]=u;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}else if(!belong[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		scc++;
		for(;;){
			int no=stack[--top];
			belong[no]=scc;
			weight[scc]++;
			if(no==u)break;
		}
	}
}
int in[MAXV],dp[MAXV];
int V,E;
void solve(){
	init2();
	map<long long,int>mp;
	mp.clear();
	clr(dp,0);
	clr(in,0);
	for(int u=1;u<=V;++u){
		for(int i=head[u];~i;i=es[i].next){
			int v=es[i].to;
			if(belong[u]!=belong[v]){
				if(!mp[(long long )belong[u]*MAXV+belong[v]]){
					addEdge2(belong[u],belong[v]);
					in[belong[v]]++;
					mp[(long long )belong[u]*MAXV+belong[v]]=1;
				}
			}
		}
	}
	top=0;
	int res=0;
	printf("scc=%d\n",scc);
	for(int i=1;i<=scc;++i){
		if(in[i]==0){
			stack[top++]=i;
			dp[i]=weight[i];
			res=max(res,dp[i]);
		}
	}
	while(top!=0){
		int no=stack[--top];
		for(int i=head2[no];~i;i=es2[i].next){
			int v=es2[i].to;
			dp[v]=max(dp[v],dp[no]+weight[v]);
			res=max(res,dp[v]);
			in[v]--;
			if(in[v]==0)stack[top++]=v;
		}
	}
	printf("%d\n",res);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&V,&E);
		init();
		scc=dfs_clock=top=0;
		clr(low,0);
		clr(dfn,0);
		clr(belong,0);
		clr(weight,0);
		for(int i=0;i<E;++i){
			int a,b;scanf("%d%d",&a,&b);
			addEdge(a,b);
		}
		for(int i=1;i<=V;++i){
			if(!dfn[i])dfs(i,-1);
		}
		solve();
	}
	return 0;
}
