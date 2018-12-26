#include<cstdio>
const int MAXN=1007;
const int MAXM=10007;
long long dp[MAXN][MAXM],dp2[MAXN][MAXM];
const long long mod=1e9+7;
int main(){
	int N;scanf("%d",&N);
	for(int j=1;j<=9;++j)dp[1][j]=1;
	for(int j=0;j<=9;++j)dp2[1][j]=1;

	for(int i=1;i<N;++i){//1000*9000*9
		for(int j=0;j<=9*i;++j){
			for(int k=0;k<=9;++k){
				dp[i+1][j+k]+=dp[i][j];
				dp[i+1][j+k]%=mod;

				dp2[i+1][j+k]+=dp2[i][j];
				dp2[i+1][j+k]%=mod;
			}
		}
	}

	long long ans=0;
	for(int i=1;i<=9*N;++i){
		ans+=dp[N][i]*dp2[N][i];
		ans%=mod;
	}
	printf("%lld\n",ans);
}
