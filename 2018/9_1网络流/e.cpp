#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=507;
const int INF=1e9+7;
struct Edge{ int from,to,cap,flow;};
vector<int>G[MAXN];
vector<Edge>edges;
void addEdge(int from,int to,int cap){ 
	edges.push_back((Edge){from,to,cap,0 });
	edges.push_back((Edge){to,from,0,0});
	int m=edges.size();
	G[from].push_back(m-2);
	G[to].push_back(m-1);
}

int s,t;
int visit[MAXN],d[MAXN];
int BFS(){ 
	memset(visit,0,sizeof(visit));
	d[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){ 
		int u=q.front();q.pop();
		visit[u]=1;
		for(int i=0;i<G[u].size();++i){ 
			Edge &e=edges[G[u][i]];
			if(e.cap>e.flow&&!visit[e.to]){ 
				d[e.to]=d[u]+1;
				q.push(e.to);
			}
		}
	}
	return visit[t];
}

int cur[MAXN];
int DFS(int x,int a){ 
	if(x==t||a==0)return a;
	int flow=0,f;
	for(int &i=cur[x];i<G[x].size();++i){ 
		Edge &e=edges[G[x][i]];
		if(d[e.to]==d[x]+1&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){ 
			flow+=f;
			e.flow+=f;
			edges[G[x][i]^1].flow-=f;
			a-=f;
			if(a==0)break;
		}
	}
	return flow;
}

int MaxFlow(int s,int t){ 
	int flow=0;
	int x;
	while(x=BFS()){ 
		memset(cur,0,sizeof(cur));
		flow+=DFS(s,INF);
	}
	return flow;
}

int N,M;
void init(){ 
	for(int i=0;i<N;++i){ 
		G[i].clear();
	}
	edges.clear();
}

struct node{ 
	int from,to,cost;
}no[MAXN*MAXN];

void solve(){ 
	int res=INF;
	for(int u=0;u<N;++u){ 
		for(int v=u+1;v<N;++v){ 
			init();
			for(int i=0;i<M;++i){ 
				addEdge(no[i].from,no[i].to,no[i].cost);
				addEdge(no[i].to,no[i].from,no[i].cost);
			}
			s=u,t=v;
			res=min(res,MaxFlow(s,t));
		}
	}
	printf("%d\n",res);
}
int main(){ 
	while(~scanf("%d%d",&N,&M)){
		for(int i=0;i<M;++i){ 
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			no[i].from=x;no[i].to=y;no[i].cost=z;
		}
		solve();
	}
	return 0;
}
