#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1e9+7;
const int MAXN=57;
const int MAXT=257;
int T,N,M1,M2;
int t[MAXN];
int a[MAXN],b[MAXN];
int left[MAXN][MAXT];//在i点t时刻,有一个车
int right[MAXN][MAXT];
int dp[MAXN][MAXT];
int visit[MAXN][MAXT];
int dfs(int u,int time){
	//printf("u:%d t:%d\n",u,time);
	if(visit[u][time])return dp[u][time];
	visit[u][time]=1;
	if(u==N&&time==T)return 0;
	if(time+1<=T)dp[u][time]=min(dp[u][time],dfs(u,time+1)+1);//等一分钟

	if(left[u][time] && u!=N && time+t[u]<=T){
		dp[u][time]=min(dp[u][time],dfs(u+1,time+t[u]));
	}//向右
	
	if(right[u][time] && u!=1 && time+t[u-1]<=T){
		dp[u][time]=min(dp[u][time],dfs(u-1,time+t[u-1]));
	}
	return dp[u][time];
}

int main(){
	int test=1;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d",&N)&&N){
		scanf("%d",&T);
		for(int i=1;i<N;++i)scanf("%d",&t[i]);
		scanf("%d",&M1);
		for(int i=1;i<=M1;++i)scanf("%d",&a[i]);
		scanf("%d",&M2);
		for(int i=1;i<=M2;++i)scanf("%d",&b[i]);

		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		memset(visit,0,sizeof(visit));

		for(int i=1;i<=M1;++i){
			int sum=a[i];
			if(sum<=T)left[1][sum]=1;
			for(int j=1;j<N;++j){
				sum+=t[j];
				if(sum<=T)left[j+1][sum]=1;
			}
		}

		for(int i=1;i<=M2;++i){
			int sum=b[i];
			if(sum<=T)right[N][sum]=1;
			for(int j=N-1;j>=1;--j){
				sum+=t[j];
				if(sum<=T)right[j][sum]=1;
			}
		}

		for(int i=0;i<MAXN;++i)
			for(int j=0;j<MAXT;++j)
				dp[i][j]=INF;

		int val=dfs(1,0);
		printf("Case Number %d: ",test++);
		if(val==INF)printf("impossible\n");
		else printf("%d\n",val);
	}
	return 0;
}
