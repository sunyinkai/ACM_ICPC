#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=5007;
const int INF=1e9+7;
int s,t;
struct Edge{
	int from,to,cap,flow;
};
vector<Edge>edges;
vector<int>G[MAXN];
void addEdge(int from,int to,int cap){
	edges.push_back(Edge{from,to,cap,0});
	edges.push_back(Edge{to,from,0,0});
	int m=edges.size();
	G[from].push_back(m-2);
	G[to].push_back(m-1);
}

int visit[MAXN],d[MAXN];
int BFS(){
	memset(visit,0,sizeof(visit));
	d[s]=0;
	queue<int>q;
	q.push(s);
	//visit[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		visit[u]=1;
		int len=G[u].size();
		for(int i=0;i<len;++i){
			Edge &e=edges[G[u][i]];
			if(!visit[e.to]&&e.cap>e.flow){
				d[e.to]=d[u]+1;
		//		visit[e.to]=1;
				q.push(e.to);
			}
		}
	}
	return visit[t];
}

int cur[MAXN];
LL DFS(int x,int a){
	if(x==t||a==0)return a;
	int len=G[x].size();
	LL f,flow=0;
	for(int& i=cur[x];i<len;++i){
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

LL MaxFlow(int s,int t){
	LL flow=0;
	while(BFS()){
		memset(cur,0,sizeof(cur));
		flow+=DFS(s,INF);
		//printf("flow=%d\n",flow);
	}
	return flow;
}

int done[MAXN],cnt;
void dfs(int u){
	int len=G[u].size();
	for(int i=0;i<len;++i){
		Edge &e=edges[G[u][i]];
		if(!done[e.to]&&e.cap>0&&visit[e.to]){
			done[e.to]=1;
			dfs(e.to);
			cnt++;
		}
	}
}
int main(){
	int N,M;scanf("%d%d",&N,&M);
	s=0,t=N+1;
	LL sum=0;
	for(int i=1;i<=N;++i){
		int val;scanf("%d",&val);
		if(val>0)addEdge(s,i,val);
		else if(val<0)addEdge(i,t,-val);
		if(val>0)sum+=val;
	}
	for(int i=0;i<M;++i)
		int a,b;scanf("%d%d",&a,&b);
		addEdge(a,b,INF);
	}

	LL val=sum-MaxFlow(s,t);
	memset(done,0,sizeof(done));
	cnt=0;
	done[s]=1;
	dfs(s);
	printf("%d %lld\n",cnt,val);
	return 0;
}