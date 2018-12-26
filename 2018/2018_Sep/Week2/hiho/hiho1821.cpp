#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
const long long  INF=1e17+7;
int a[MAXN];
long long sum[MAXN];
long long  dp[MAXN];
int visit[MAXN];
//dp[i]:当前序列状态为i...n,双方均采取最优策略,先手的分数
int N;
long long dfs(int u){
	if(u==N)return a[u];
	if(visit[u])return dp[u];
	visit[u]=1;

	long long  m=INF;
	for(int i=1;i<=3;++i){
		if(u+i<=N){
			m=min(m,dfs(u+i));
		}
	}
	return dp[u]=sum[N]-sum[u-1]-m;
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+N+1,greater<int>());
	for(int i=1;i<=N;++i){
		sum[i]=sum[i-1]+a[i];
	}
	printf("%lld\n",dfs(1));
	return 0;
}

