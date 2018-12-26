#include<cstdio>
#include<cstring>
const int MAXM=10707;
long long dp[2][MAXM],dp2[2][MAXM];
const long long mod=1e9+7;
int main(){
	int N;scanf("%d",&N);
	for(int j=1;j<=9;++j)dp[0][j]=1;
	for(int j=0;j<=9;++j)dp2[0][j]=1;

	for(int i=1;i<N;++i){//1000*9000*9
		for(int j=0;j<=9*i;++j){
			for(int k=0;k<=9;++k){
				dp[1][j+k]=(dp[1][j+k]+dp[0][j])%mod;
				dp2[1][j+k]=(dp2[1][j+k]+dp2[0][j])%mod;
			}
		}
		for(int j=0;j<=9*i+9;++j)
			dp[0][j]=dp[1][j],dp2[0][j]=dp2[1][j];;
		memset(dp[1],0,sizeof(dp[1]));
		memset(dp2[1],0,sizeof(dp2[1]));
	}

	long long ans=0;
	for(int i=1;i<=9*N;++i){
		ans+=dp[0][i]*dp2[0][i];
		ans%=mod;
	}
	printf("%lld\n",ans);
}
