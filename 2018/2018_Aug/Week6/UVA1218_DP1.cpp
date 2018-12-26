#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; const int MAXN=1e4+7; const int INF=1e9+7;
struct edge{
	int to,next;
}es[MAXN*2];
int tot,head[MAXN];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

int dp[MAXN][3];
//dp[u][0]:u为服务器，
//dp[u][1]:u不是服务器，u的父亲有服务器
//dp[u][2]:u不是服务器，u的父亲没有服务器

int N;
int dfs(int u,int status,int pre){
	if(dp[u][status]!=-1)return dp[u][status];
	dp[u][0]=1;
	dp[u][1]=0;
	dp[u][2]=N;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		dp[u][0]+=min(dfs(v,1,u),dfs(v,0,u));//
		dp[u][1]+=dfs(v,2,u);
	}

	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		dp[u][2]=min(dp[u][2],dp[u][1]+dp[v][0]-dp[v][2]);
	}
	return dp[u][status];
}

int main(){
	while(~scanf("%d",&N)&&N!=-1){
		init();
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<N;++i){
			int a,b;scanf("%d%d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}
		int tmp;scanf("%d",&tmp);
		printf("%d\n",min(dfs(1,0,-1),dfs(1,2,-1)));
		if(tmp==-1)break;
	}
	return 0;
}
