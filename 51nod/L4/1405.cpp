//tag: contribution,prefix_sum,dfs_order
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN=1e5+7;
vector<int>G[MAXN];
int in[MAXN],out[MAXN];
int dfs_clock=0;

//获取dfs序
//需要注意:时间戳,不等于真正的点
int mp[MAXN];
void dfs1(int u,int pre){
	int len=G[u].size();
	in[u]=++dfs_clock;
	mp[dfs_clock]=u;//time_stamp <---> point

	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(v==pre)continue;
		dfs1(v,u);
	}
	out[u]=dfs_clock;
}

int N;
long long sum[MAXN],ans[MAXN];
void dfs2(int u,int pre){
	int len=G[u].size();
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(v==pre)continue;
		//计算每一条边的贡献
		int cnt_0=out[v]-in[v]+1;
		int cnt_1=N-cnt_0;
		// in[v]...out[v] +=cnt_1
		sum[in[v]]+=cnt_1;sum[out[v]+1]-=cnt_1;
		// 1...in[v]-1    +=cnt_0
		sum[1]+=cnt_0;sum[in[v]]-=cnt_0;
		// out[v]+1...N	  +=cnt_0
		sum[out[v]+1]+=cnt_0;sum[N+1]-=cnt_0;

		dfs2(v,u);
	}
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<N;++i){
		int x,y;scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs1(1,-1);
	dfs2(1,-1);
	for(int i=1;i<=N;++i){
		sum[i]+=sum[i-1];
		ans[mp[i]]=sum[i];
	}
	for(int i=1;i<=N;++i)
		printf("%lld\n",ans[i]);
	return 0;
}
