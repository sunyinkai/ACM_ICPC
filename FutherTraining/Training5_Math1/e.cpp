#include<cstdio>
#include<cstring>
const int MAXN=1e4+7;
const int INF=1e9+7;
long long dp[MAXN];
int main(){
	//完全背包,恰好装满方案数
	int n;
	while(~scanf("%d",&n)){
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=21;++i){
			for(int j=1;j<=n;++j){
				if(j>=i*i*i)dp[j]+=dp[j-i*i*i];
			}
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
