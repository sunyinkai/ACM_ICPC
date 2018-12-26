#include<cstdio>
#include<cstring>
const int MAXN=1007;
const long long mod=1e9+7;
long long dp[MAXN][MAXN];
int main(){
	int N,M;scanf("%d%d",&N,&M);
	long long prev=0;
	for(int i=1;i<=M;++i){
		prev++;
		dp[1][i]=1;
	}
	for(int i=2;i<=N;++i){
		long long t=prev;
		prev=0;
		for(int j=1;j<=M;++j){
			dp[i][j]=(dp[i][j]+t-dp[i-1][j]+mod)%mod;
			prev+=dp[i][j];
		}

	}

	long long res=0;
	for(int i=1;i<=M;++i){
		res=(res+dp[N][i])%mod;
	}
	printf("%lld\n",res);
	return 0;
}
