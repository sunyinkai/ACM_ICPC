#include<bits/stdc++.h>
using namespace std;

const int MAXN=507;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=i;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=i;++j){
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j-1])+a[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=N;++i)
		ans=max(ans,dp[N][i]);
	printf("%d\n",ans);
	return 0;
}
