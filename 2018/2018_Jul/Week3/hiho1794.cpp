#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1<<15;
int dp[MAXN],a[MAXN],N;
int visit[MAXN];
//dp[u]:使用u这些木棍最多能拼成棍子的数目
int dfs(int u){
	if(u==0)return 0;
	if(visit[u])return dp[u];
	visit[u]=1;
	int q[16],top=0;
	for(int i=0;i<N;++i)
		if(u&(1<<i))q[top++]=i;
	for(int i=0;i<top;++i){
		for(int j=i+1;j<top;++j){
			for(int k=j+1;k<top;++k){
				int t=u;
	//			printf("%d-%d-%d\n",a[q[i]],a[q[j]],a[q[k]]);
				if(a[q[i]]+a[q[j]]<=a[q[k]])continue;
				t-=(1<<q[i]);
				t-=(1<<q[j]);
				t-=(1<<q[k]);
				dp[u]=max(dp[u],dfs(t)+1);
			}
		}
	}
	return dp[u];
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+N);
	memset(dp,0,sizeof(dp));
	printf("%d\n",dfs((1<<N)-1));
	return 0;
}
