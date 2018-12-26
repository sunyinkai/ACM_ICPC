#include<cstdio>
#define min(a,b) (a<b?a:b)
const int MAXN=307;
const int INF=1e9+7;
int dp[MAXN][MAXN];
int main(){
	int M,N;
	while(~scanf("%d%d",&M,&N)){
		printf("%d\n",M*N-1);
	/*	for(int i=1;i<=M;++i)
			for(int j=1;j<=N;++j)
				dp[i][j]=INF;
		for(int i=1;i<=M;++i)dp[i][1]=i-1;
		for(int i=1;i<=N;++i)dp[1][i]=i-1;

		for(int i=2;i<=M;++i){
			for(int j=1;j<=N;++j){
				for(int k=1;k<j;++k){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
				}

				for(int k=1;k<i;++k){
					dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
				}
	//			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);

			}
		}
		printf("%d\n",dp[M][N]);
*/
	}
	return 0;
}
