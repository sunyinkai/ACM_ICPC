#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=35;
const int MAXM=507;
int a[MAXN];
int dp[MAXN][MAXN][MAXM];//从前i个选j个花费k元的方案数
int main(){ 
	int T;scanf("%d",&T);
	while(T--){ 
		int N,M;scanf("%d%d",&N,&M);
		for(int i=1;i<=N;++i)scanf("%d",&a[i]);
		sort(a+1,a+1+N);
		int ans=0,sum=M;
		if(a[1]>M){ 
			printf("Sorry, you can't buy anything.\n");
			continue;
		}

		for(int i=1;i<=N;++i)
			if(a[i]<=sum)sum-=a[i],++ans;
		
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=N;++i)
			for(int j=0;j<=M;++j)
			dp[i][j][0]=1;
		
		for(int i=1;i<=N;++i){ 
			for(int j=N;j>=1;--j){ 
				for(int k=M;k>=a[i];--k){ 
					dp[i][j][k]+=dp[i-1][j-1][k-a[i]];
				}
			}
		}
		int res=0;
		printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n",dp[N][M][ans],ans);
	}
	return 0;
}
