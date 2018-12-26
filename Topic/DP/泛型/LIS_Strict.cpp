#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1007;
const int INF=1e9+7;
int dp[MAXN];
int main(){
	int N;scanf("%d",&N);
	fill(dp,dp+N,INF);
	for(int i=0;i<N;++i){
		int x;scanf("%d",&x);
		*lower_bound(dp,dp+N,x)=x;
	}
	printf("%d\n",lower_bound(dp,dp+N,INF)-dp);
	return 0;
}
