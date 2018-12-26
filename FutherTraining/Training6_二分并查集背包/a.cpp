#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1007;
int cost[MAXN],val[MAXN];
int dp[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N,V;scanf("%d%d",&N,&V);
		for(int i=1;i<=N;++i)scanf("%d",&val[i]);
		for(int i=1;i<=N;++i)scanf("%d",&cost[i]);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;++i){
			for(int j=V;j>=0;--j){//从0开始
				if(j>=cost[i]){
					dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
				}
				dp[j]=max(dp[j],dp[j]);
			}
		}
		printf("%d\n",dp[V]);
	}
	return 0;
}
