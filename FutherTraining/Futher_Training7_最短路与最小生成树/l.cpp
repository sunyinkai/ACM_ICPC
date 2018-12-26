//先处理出最短路
//DAG上dp
#include<bits/stdc++.h>
using namespace std;
const int MAXV=1e3+7;
const int INF=1e9+7;
typedef pair<int,int> P;
vector<P>G[MAXV];
vector<int>Q[MAXV];
int d[MAXV],done[MAXV];
int V,E;
void dijkstra(){
	for(int i=1;i<=V;++i)d[i]=INF;
	d[2]=0;
	memset(done,0,sizeof(done));
	priority_queue<P,vector<P>,greater<P> >q;
	while(!q.empty())q.pop();
	q.push(P(0,2));
	while(!q.empty()){
		P p=q.top();q.pop();
		int u=p.second;
		if(done[u])continue;
		done[u]=1;
		d[u]=p.first;
		int len=G[u].size();
		for(int i=0;i<len;++i){
			int v=G[u][i].second;
			if(d[v]>d[u]+G[u][i].first){
				d[v]=d[u]+G[u][i].first;
				q.push(P(d[v],v));
			}
		}
	}
}
//
int dp[MAXV];
int dfs(int u){//从u到家的路径条数
	if(u==2)return 1;
	if(dp[u])return dp[u];
	int len=Q[u].size();
	for(int i=0;i<len;++i){
		int v=Q[u][i];
		dp[u]+=dfs(v);
	}
	return dp[u];
}
int main(){
	while(~scanf("%d",&V)&&V){
		scanf("%d",&E);
		for(int i=1;i<=V;++i)G[i].clear(),Q[i].clear();
		for(int i=0;i<E;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			G[a].push_back(P(c,b));
			G[b].push_back(P(c,a));
		}
		dijkstra();
		for(int u=1;u<=V;++u){
			int len=G[u].size();
			for(int j=0;j<len;++j){
				int v=G[u][j].second;
				if(d[u]>d[v]){
	//				printf("%d->%d,d[u]=%d,d[v]=%d\n",u,v,d[u],d[v]);
					Q[u].push_back(v);
				}
			}
		}
		memset(dp,0,sizeof(dp));
		printf("%d\n",dfs(1));
	}
	return 0;
}
