#include<cstdio>
#include<cstring>
const int MAXN=1007;
const int mod=1e9+7;
int a[MAXN],b[MAXN];
int dp[MAXN][MAXN];
int main(){
	int N,M;
	while(~scanf("%d%d",&N,&M)){
		for(int i=0;i<N;++i)scanf("%d",&a[i]);
		for(int i=0;i<M;++i)scanf("%d",&b[i]);
		for(int i=0;i<=N;++i)
			for(int j=0;j<=M;++j)
				dp[i][j]=0;
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				dp[i+1][j+1]=(dp[i][j+1]+dp[i+1][j])%mod;
				if(a[i]==b[j])dp[i+1][j+1]=(dp[i+1][j+1]+1)%mod;
				if(a[i]!=b[j])dp[i+1][j+1]=(dp[i+1][j+1]-dp[i][j]+mod)%mod;
			}
		}
		printf("%d\n",dp[N][M]);
	}
	return 0;
}
