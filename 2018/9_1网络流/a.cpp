#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1007;
const int INF=1e9+7;

struct Edge{int from,to,cap,flow; };
vector<int>G[MAXN];
vector<Edge>edges;
void addEdge(int a,int b,int c){ 
	edges.push_back(Edge{a,b,c,0});
	edges.push_back(Edge{b,a,0,0});
	int m=edges.size();
	G[a].push_back(m-2);
	G[b].push_back(m-1);
}

int d[MAXN],visit[MAXN];
int s,t;
int BFS(){ 
	queue<int>q;
	memset(visit,0,sizeof(visit));
	d[s]=0;
	q.push(s);
	while(!q.empty()){ 
		int u=q.front();q.pop();
		visit[u]=1;
		for(int i=0;i<G[u].size();++i){ 
			Edge e=edges[G[u][i]];
			if(!visit[e.to]&&e.cap>e.flow){ 
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
			e.flow+=f;
			flow+=f;
			edges[G[x][i]^1].flow-=f;
			a-=f;
			if(a==0)break;
		}
	}
	return flow;
}

int MaxFlow(int s,int t){ 
	int flow=0;
	while(BFS()){ 
		memset(cur,0,sizeof(cur));
		flow+=DFS(s,INF);
		if(flow>=3)return flow;
	}
	return flow;
}

int N,M;
vector<int>GG[MAXN];
void init(){ 
	for(int i=0;i<2*N+3;++i)G[i].clear();
	edges.clear();
}
void solve(){ 
	bool hasAns=true;
	for(int u=0;u<N;++u){ 
		for(int v=u+1;v<N;++v){ 
			init();

			for(int i=0;i<N;++i){ 
				int len=GG[i].size();
				for(int j=0;j<len;++j){ 
					int v=GG[i][j];
					addEdge(i+N,v,1);
					printf("%d %d 1\n",i+N,v);
				}
			}
			for(int i=0;i<N;++i){ 
				addEdge(i,i+N,1);
				printf("%d %d 1\n",i,i+N);
			}
			s=2*N;
			t=2*N+1;
			addEdge(s,u,INF);
			addEdge(v+N,t,INF);
			int res=MaxFlow(s,t);
			printf("u=%d,v=%d,res=%d\n",u,v,res);
			if(res<3)hasAns=false;
			if(!hasAns)break;
		}
		if(!hasAns)break;
	}
	if(hasAns)printf("YES\n");
	else printf("NO\n");
}

int main(){ 
	while(~scanf("%d%d",&N,&M)){ 
		for(int i=0;i<M;++i){ 
			int a,b;scanf("%d%d",&a,&b);
			GG[a].push_back(b);
		}
		solve();
	}
	return 0;
}
