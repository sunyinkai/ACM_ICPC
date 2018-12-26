#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=107;
int a[MAXN],sum[MAXN];
int dp[MAXN][MAXN];
int visit[MAXN][MAXN];
//dp[i][j]:当前状态为l,r,双方都采取最优策略，先手最多能获得多少分
int dfs(int l,int r){
	if(visit[l][r])return dp[l][r];
	visit[l][r]=1;
	int m=0;//全部都取
	for(int k=l+1;k<=r;++k)
		m=min(m,dfs(k,r));
	for(int k=r-1;k>=l;--k)
		m=min(m,dfs(l,k));//让对方取最少
	return dp[l][r]=sum[r]-sum[l-1]-m;
}
int main(){
	int N;
	while(~scanf("%d",&N)&&N){
		for(int i=1;i<=N;++i){
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		memset(visit,0,sizeof(visit));
		printf("%d\n",2*dfs(1,N)-sum[N]);
	}
	return 0;
}
