#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAXN=107;
int a[MAXN];
int dp[MAXN][MAXN*MAXN];
//分组,让两组之差最小
//背包
int main(){
	int N;scanf("%d",&N);
	int sum=0;
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}

	for(int i=1;i<=N;++i){
		for(int j=sum/2;j>=0;--j){
			if(j>=a[i])
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
			else 
				dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d\n",abs(sum-2*dp[N][sum/2]));
	return 0;
}
