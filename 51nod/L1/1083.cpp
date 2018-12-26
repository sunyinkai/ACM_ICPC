#include<cstdio>
#define max(a,b) (a>b?a:b)
const int MAXN=507;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
		}
	}
	printf("%d\n",dp[N][N]);
	return 0;
}
