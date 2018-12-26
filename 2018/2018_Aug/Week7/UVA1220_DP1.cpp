#include<cstdio>
#include<cstring>
#include<map>
#include<iostream>
#include<vector>
using namespace std;
const int MAXN=207;
map<string,int>mp;
vector<int>G[MAXN];
int dp[MAXN][2];//dp[i][0/1]:i是否加入独立集的子树独立集的最大值
int f[MAXN][2];//f[i][0]:不选i，是否唯一，f[i][1]:选i,是否唯一
bool isok=true;
void dfs(int u){
	dp[u][1]=1,dp[u][0]=0;
	int len=G[u].size();
	for(int i=0;i<len;++i){
		int v=G[u][i];
		dfs(v);
		dp[u][1]+=dp[v][0];//选u

		if(f[v][0])f[u][1]=1;
		if(dp[v][0]>dp[v][1]){
			dp[u][0]+=dp[v][0];
			if(f[v][0])f[u][0]=1;
		}
		else if(dp[v][0]==dp[v][1]){
			dp[u][0]+=dp[v][0];
			f[u][0]=true;
		}
		else{
			dp[u][0]+=dp[v][1];
			if(f[v][1])f[u][0]=1;
		}
	}
}
int main(){
	int N;
	while(~scanf("%d",&N)&&N){
		mp.clear();
		for(int i=1;i<=N;++i)G[i].clear();
		string root;cin>>root;
		int tot=0;
		mp[root]=++tot;
		for(int i=1;i<N;++i){
			string x,y;cin>>x>>y;
			if(!mp[x])mp[x]=++tot;
			if(!mp[y])mp[y]=++tot;
			G[mp[y]].push_back(mp[x]);
		}
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		dfs(1);
		if(dp[1][0]==dp[1][1])printf("%d No\n",dp[1][0]);
		else if(dp[1][0]>dp[1][1])printf("%d %s\n",dp[1][0],f[1][0]?"No":"Yes");
		else printf("%d %s\n",dp[1][1],f[1][1]?"No":"Yes");
	}
	return 0;
}
