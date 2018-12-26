#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=25*25;
const int INF=1e9+7;
int SpaceMark;
struct Edge{ int from,to,cap,flow;};
vector<int>G[MAXN];
vector<Edge>edges;
int s,t;
void addEdge(int from,int to, int cap){ 
	edges.push_back((Edge){ from,to,cap,0});
	edges.push_back((Edge){ to,from,0,0});
	int m=edges.size();
	G[from].push_back(m-2);
	G[to].push_back(m-1);
}

int  visit[MAXN];
int d[MAXN];

int BFS(){ 
	memset(visit,0,sizeof(visit));
	queue<int>q;
	d[s]=0;
	visit[s]=1;
	q.push(s);
	while(!q.empty()){ 
		int u=q.front();q.pop();
		visit[u]=1;
		for(int i=0;i<G[u].size();++i){ 
			Edge &e=edges[G[u][i]];
			if(!visit[e.to]&&e.cap>e.flow){ 
				q.push(e.to);
				d[e.to]=d[u]+1;
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
		if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){ 
			e.flow+=f;
			edges[G[x][i]^1].flow-=f;
			flow+=f;
			a-=f;
			if(a==0)break;//已经分配完了
		}
	}
	return flow;
}

int MaxFlow(int s,int t){ 
	int flow=0;
	while(BFS()){ 
		memset(cur,0,sizeof(cur));
		flow+=DFS(s,INF);
	}
	return flow;
}

int cnt[MAXN][MAXN];
int win[MAXN],lose[MAXN];
int N;

void init(){ 
	s=t=0;
	for(int i=0;i<MAXN;++i)G[i].clear();
	edges.clear();
}

bool check(){ 
	int val=MaxFlow(s,t);
	//printf("val=%d\n",val);
	int flag=true;
	for(int i=0;i<G[0].size();++i){ 
		Edge &e =edges[G[0][i]];
	//	printf("e.cap=%d,e.flow=%d\n",e.cap,e.flow);
		if(e.cap!=0){ 
			if(e.flow!=e.cap){ 
				flag=false;
			}
		}
	}
	//printf("\n");
	return flag;
}

void solve(){ 
	for(int k=1;k<=N;++k){ //if k win
		init();
		int total=win[k];
		for(int i=1;i<=N;++i)total+=cnt[i][k];
		int tot=1;
		int base=(N*N+N)/2;
		for(int i=1;i<=N;++i){ 
			for(int j=i;j<=N;++j){ 
				addEdge(0,tot,cnt[i][j]);
				addEdge(tot,base+i,INF);
				addEdge(tot,base+j,INF);
				++tot;
			}
		}
		bool hasAns=true;
	//	printf("k=%d,win[k]=%d,total=%d\n",k,win[k],total);
		for(int i=1;i<=N;++i){ 
			addEdge(base+i,base+N+1,total-win[i]);
			if(total-win[i]<0)hasAns=false;
		}
		if(!hasAns)continue;
		s=0,t=base+N+1;
		if(check()){ 
			if(SpaceMark)printf(" %d",k);
			else printf("%d",k);
			SpaceMark=1;
		}
	}
	printf("\n");
}

int main(){ 
	int T;scanf("%d",&T);
	while(T--){ 
		SpaceMark=0;
		scanf("%d",&N);
		for(int i=1;i<=N;++i)scanf("%d%d",&win[i],&lose[i]);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&cnt[i][j]);
		solve();
	}
	return 0;
}
