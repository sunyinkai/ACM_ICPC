#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
const int INF=1e9+7;
vector<int>G[MAXN];
int cost[MAXN],res=-INF;
void dfs(int u,int MIN,int MAX,int pre){
	//printf("u=%d,MIN=%d,MAX=%d\n",u,MIN,MAX);
	res=max(res,MAX-MIN);
	int len=G[u].size();
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(v==pre)continue;
	//	printf("%d->%d\n",u,v);
		dfs(v,min(MIN,cost[v]),max(MAX,cost[v]),u);
	}
}
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",&cost[i]);
	for(int i=2;i<=N;++i){
		int x;scanf("%d",&x);
		G[x].push_back(i);
		G[i].push_back(x);
	}
	dfs(1,INF,-INF,-1);
	printf("%d\n",res);
	return 0;
}
