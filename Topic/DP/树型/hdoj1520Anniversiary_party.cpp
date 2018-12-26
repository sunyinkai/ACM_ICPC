#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=6007;
int cost[MAXN];
int res;
vector<int>G[MAXN];
int dp[MAXN][2];
int dfs(int u,int pre,int sta){//当前状态
	if(dp[u][sta])return dp[u][sta];
	int len=G[u].size();
	if(sta==1)dp[u][1]=cost[u];
	else dp[u][0]=0;
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(v==pre)continue;
		if(sta==1){
			dp[u][1]+=dfs(v,u,0);
		}else{
			dp[u][0]+=max(dfs(v,u,0),dfs(v,u,1));
		}
	}
	return dp[u][sta];
}
int main(){
	int N;
	while(~scanf("%d",&N)){
		for(int i=1;i<=N;++i)scanf("%d",&cost[i]);
		for(int i=1;i<=N;++i)G[i].clear();
		int a,b;
		res=0;
		while(~scanf("%d%d",&a,&b)&&a+b){
			G[b].push_back(a);
			G[a].push_back(b);
		}
		memset(dp,0,sizeof(dp));
		int res=dfs(1,-1,0);
		memset(dp,0,sizeof(dp));
		res=max(res,dfs(1,-1,1));
		printf("%d\n",res);

	}
	return 0;
}
