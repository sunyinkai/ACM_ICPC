#include<cstdio>
#include<cstring>
const int MAXN=1007,MAXL=2007;
long long dp[MAXL][MAXN];
const long long mod=1e9+9;
int main(){
	int N,L;scanf("%d%d",&N,&L);
	dp[0][0]=1;
	for(int i=1;i<=L;++i){
		for(int j=1;j<=N;++j){
			dp[i][j]+=dp[i-1][j]*(j-1)%mod;//前面已经出现过的种类
			dp[i][j]+=dp[i-1][j-1]*(N-j+1)%mod;//选前面没出现过的种类
			dp[i][j]%=mod;
	//		printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
		}
	}
	printf("%lld\n",dp[L][N]);
	return 0;
}
