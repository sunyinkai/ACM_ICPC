#include<cstdio>
const int MAXN=1e5+7;
const int MAXK=107;
double p[MAXN],dp[MAXN][MAXK];
int main(){
	int N,K;scanf("%d%d",&N,&K);
	double sum=0;
	for(int i=0;i<N;++i)scanf("%lf",&p[i]),sum+=p[i];
	dp[0][0]=1.0;
	for(int i=0;i<N;++i){
		for(int j=0;j<=K;++j){
			if(j==0) dp[i+1][0]=dp[i][0]*(1-p[i]);
			else dp[i+1][j]=dp[i][j]*(1-p[i])+dp[i][j-1]*p[i];
		}
	}
	printf("%.4f\n%.4f\n",sum,dp[N][K]);
	return 0;
}
