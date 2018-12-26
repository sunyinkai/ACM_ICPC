#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+7;
struct edge{
	int to,next;
}es[MAXN*2];
//数组开不下?
int tot,head[MAXN];
vector<int>G[MAXN];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

int N,T;
int dp[MAXN];
vector<int>son[MAXN];
int dfs(int u,int pre){
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		int ans=dfs(v,u);
		G[u].push_back(ans);
	}
	if(G[u].empty())return dp[u]=1;
	sort(G[u].begin(),G[u].end());
	int res=0;
	int k=G[u].size();
	for(int i=0;i<k;){
		res+=G[u][i];
		++i;
		if(i*100>=T*k)break;
	}
	return dp[u]=res;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d%d",&N,&T)&&N+T){
		init();
		for(int i=1;i<=N;++i){
			int x;scanf("%d",&x);
			addEdge(i,x);
			addEdge(x,i);
		}
		for(int i=0;i<=N;++i){
			dp[i]=0;
			G[i].clear();
		}
		printf("%d\n",dfs(0,-1));
	}
	return 0;
}
