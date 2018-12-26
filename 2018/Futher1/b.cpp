#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=507;
int dp[MAXN][MAXN];
int weight[MAXN],cost[MAXN];
int main(){ 
	int T;scanf("%d",&T);
	while(T--){ 
		int N,M;scanf("%d%d",&N,&M);
		for(int i=1;i<=N;++i){ 
			scanf("%d",&weight[i]);
			cost[i]=1;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;++i){ 
			for(int j=1;j<=M;++j){ 
				if(j>=weight[i])
					dp[i][j]=max(dp[i][j],dp[i-1][j-weight[i]]+cost[i]);
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
			}
		}
		int res=dp[N][M];
		printf("%d\n",res);
	}
	return 0;
}
