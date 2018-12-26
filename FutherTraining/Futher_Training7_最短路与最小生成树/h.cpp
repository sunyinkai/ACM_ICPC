//floyd
//仔细读题
#include<cstdio>
#include<cstring>
const int MAXN=107;
const int INF=1e9+7;
int dp[MAXN][MAXN];
int main(){
	int a,b;
	int test=1;
	while(scanf("%d%d",&a,&b)&&a+b){
		for(int i=1;i<=101;++i){
			for(int j=1;j<=101;++j){
				dp[i][j]=INF;
			}
		}
		int cnt=0,res=0;
		dp[a][b]=1;
		while(scanf("%d%d",&a,&b)&&a+b)
			dp[a][b]=1;

		for(int k=1;k<=101;++k){
			for(int i=1;i<=101;++i){
				for(int j=1;j<=101;++j){
					if(dp[i][j]>dp[i][k]+dp[k][j]){
						dp[i][j]=dp[i][k]+dp[k][j];
					}
				}
			}
		}
		for(int i=1;i<=101;++i){
			for(int j=1;j<=101;++j){
				if(i!=j&&dp[i][j]!=INF){
					//printf("%d-%d %d\n",i,j,dp[i][j]);
					++cnt,res+=dp[i][j];
				}
			}
		}
		//printf("%d %d\n",res,cnt);
		printf("Case %d: average length between pages = %.3f clicks\n",test,res*1.0/cnt);
		++test;
	}
	return 0;
}
