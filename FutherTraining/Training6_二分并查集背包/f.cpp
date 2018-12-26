#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=107;
int dp[MAXN][MAXN];//忍耐值,只数->经验
int cost[MAXN],val[MAXN];
int main(){
	int n,m,k,s;
	while(~scanf("%d%d%d%d",&n,&m,&k,&s)){
		for(int i=1;i<=k;++i){
			scanf("%d%d",&val[i],&cost[i]);
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=k;++i){
			for(int j=1;j<=m;++j){//忍耐
				for(int r=1;r<=s;++r){//只数
					if(j>=cost[i])
						dp[j][r]=max(dp[j][r],dp[j-cost[i]][r-1]+val[i]);
				}
			}
		}
		if(dp[m][s]<n){
			printf("-1\n");
		}else{
			int res=0;
			for(int i=0;i<=m;++i){
				for(int j=0;j<=s;++j){
					if(dp[i][j]>=n){
						res=max(res,m-i);
					}
				}
			}
			printf("%d\n",res);
		}
	}
	return 0;
}
