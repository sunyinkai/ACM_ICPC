#include<cstdio>
const long long mod=998244353;
const int MAXN=2007;
long long dp[MAXN][MAXN];
int main(){
	int N,M,K;scanf("%d%d%d",&N,&M,&K);

	dp[1][0]=M;

	for(int i=2;i<=N;++i){
		for(int j=0;j<=K;++j){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*(M-1)%mod;
			dp[i][j]%=mod;
		}
	}
	printf("%lld\n",dp[N][K]);
	return 0;
}
