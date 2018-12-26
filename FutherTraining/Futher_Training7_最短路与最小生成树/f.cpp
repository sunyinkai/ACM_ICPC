//floyd求联通块
//tarjan也可以求连通块
//初始化从0开始
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
using namespace std;
const int MAXN=107;
int dp[MAXN][MAXN];
int visit[MAXN];
vector<int>G[MAXN];
map<string,int>mp;
map<int,string>fp;

int main(){
	int N,M;
	int test=1;
	int tag=0;
	while(~scanf("%d%d",&N,&M)&&N+M){
		if(tag)printf("\n");
		tag=1;
		mp.clear();
		fp.clear();

		int tot=1;
		memset(dp,0,sizeof(dp));

		for(int i=0;i<M;++i){
			string a,b;cin>>a>>b;
			int x,y;
			if(!mp[a]){
				mp[a]=tot++;
				fp[tot-1]=a;
			}
			if(!mp[b]){
				mp[b]=tot++;
				fp[tot-1]=b;
			}
			x=mp[a];y=mp[b];
			dp[x][y]=1;
		}
		//floyd
		for(int k=1;k<=N;++k)
			for(int i=1;i<=N;++i)
				for(int j=1;j<=N;++j)
					if(dp[i][k]&&dp[k][j])dp[i][j]=1;

		memset(visit,0,sizeof(visit));
		for(int i=0;i<=N;++i)G[i].clear();
		int cnt=0;

		for(int i=1;i<=N;++i){
			if(visit[i])continue;
			visit[i]=1;
			G[cnt].push_back(i);
			for(int j=1;j<=N;++j){
				if(i==j)continue;
				if(dp[i][j]&&dp[j][i]){
					if(!visit[j]){
						G[cnt].push_back(j);
						visit[j]=1;
					}
				}
			}
			++cnt;
		}
		printf("Calling circles for data set %d:\n",test++);
		for(int i=0;i<cnt;++i){
			int len=G[i].size();
			cout<<fp[G[i][0]];
			for(int j=1;j<len;++j){
				printf(", %s",fp[G[i][j]].c_str());
			}
			printf("\n");
		}
	}
		
	return 0;
}
