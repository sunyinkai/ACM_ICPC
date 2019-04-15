//HDU 2544
//mutiple case notice the init
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=507;
const int INF=1e9+7;
struct edge{
	int to,cost;
	bool operator<(const edge&other)const{
		return cost>other.cost;
	}
};
vector<edge>G[MAXN];
int N,M; 
int d[MAXN],visit[MAXN];

void dijkstra(int s){
	for(int i=1;i<=N;++i)d[i]=INF;
	memset(visit,0,sizeof(visit));
	d[s]=0;
	priority_queue<edge>q;
	q.push(edge{s,0});
	while(!q.empty()){
		const edge e=q.top();q.pop();
		int u=e.to;
		if(visit[u])continue;
		visit[u]=1;
		int len=G[u].size();
		for(int i=0;i<len;++i){
			int v=G[u][i].to;
			if(d[v]>d[u]+G[u][i].cost){
				d[v]=d[u]+G[u][i].cost;
				q.push(edge{v,d[v]});
			}
		}
	}
}

int main(){
	while(scanf("%d%d",&N,&M)&&N+M){
		for(int i=0;i<=N;++i)G[i].clear();
		for(int i=0;i<M;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			G[a].push_back(edge{b,c});
			G[b].push_back(edge{a,c});
		}
		int S=1,E=N;
		dijkstra(S);
		printf("%d\n",d[E]==INF?-1:d[E]);
	}
	return 0;
}
