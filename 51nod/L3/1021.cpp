#include<bits/stdc++.h>
using namespace std;
const int MAXN=107;
const long long INF=1e9+7;

int a[MAXN];
int dp[MAXN][MAXN];
int sum[MAXN];
//dp[i][j]:把i~j的合并的最小代价
//dp[i][j]=min(dp[i][k]+dp[k+1][j]+sum[r]-sum[l-1]);
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			dp[i][j]=INF;

	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
		dp[i][i]=a[i];
		sum[i]=sum[i-1]+a[i];
	}

	for(int l=N;l>=1;--l){
		for(int r=l+1;r<=N;++r){
			for(int k=l;k<=r-1;++k){
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+sum[r]-sum[l-1]);
			}
		}
	}
	printf("%d\n",dp[1][N]-sum[N]);
	return 0;
}
