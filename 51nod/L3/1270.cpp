#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e4+7;
long long dp[MAXN][2];//当前处理到i,0代表取极小，1代表取最大.
int a[MAXN];
//每个数只取极大或者极小的情况

int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);

	for(int i=2;i<=N;++i){
		dp[i][0]=max(dp[i-1][1]+abs(1-a[i-1]),dp[i-1][0]+abs(1-1));
		dp[i][1]=max(dp[i-1][1]+abs(a[i]-a[i-1]),dp[i-1][0]+abs(a[i]-1));
	}
	printf("%lld\n",max(dp[N][0],dp[N][1]));
	return 0;
}
