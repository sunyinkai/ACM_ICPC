#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int INF=1e9+7;
const int MAXN=407;
struct edge{ int from,to,cap,flow; };
vector<int>G[MAXN];
vector<edge>es;
void addEdge(int a,int b,int c){
	es.push_back(edge{a,b,c,0});
	es.push_back(edge{b,a,0,0});
	int m=es.size();
	G[a].push_back(m-2);//以a为顶点的第i条边的编号
	G[b].push_back(m-1);
}
bool visit[MAXN];
int d[MAXN];
int cur[MAXN];
int s,t;
bool bfs(){//构造层次图
	memset(visit,0,sizeof(visit));
	queue<int>q;
	q.push(s);
	d[s]=0;
	visit[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<G[x].size();++i){
			edge &e=es[G[x][i]];
			if(!visit[e.to]&&e.cap>e.flow){//没有被访问过且流量还有剩余
				visit[e.to]=1;
				d[e.to]=d[x]+1;
				q.push(e.to);
			}
		}
	}
	return visit[t];//终点是否被参观过
}

int dfs(int x,int a){//从s->x的最小剩余流量
	if(x==t||a==0)return a;
	int flow=0,f;
	for(int &i=cur[x];i<G[x].size();++i){
		edge& e=es[G[x][i]];
		if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
			e.flow+=f;
			es[G[x][i]^1].flow-=f;
			flow+=f;
			a-=f;//当前弧优化
			if(a==0)break;
		}
	}
	return flow;
}
int Maxflow(int s,int t){
	int flow=0;
	while(bfs()){//每次完成后最短增广路长度单调递
		memset(cur,0,sizeof(cur));
		flow+=dfs(s,INF);
	}
	return flow;
}

int main(){
	int N,F,D;
	while(~scanf("%d%d%d",&N,&F,&D)){
		es.clear();
		for(int i=0;i<=2*N+F+D+1;++i)G[i].clear();
		for(int i=1;i<=N;++i){
			int f,d;scanf("%d%d",&f,&d);
			for(int j=0;j<f;++j){
				int x;scanf("%d",&x);
				addEdge(2*N+x,i,1);
			}
			for(int j=0;j<d;++j){
				int x;scanf("%d",&x);
				addEdge(N+i,2*N+F+x,1);
			}
		}

		for(int i=1;i<=N;++i)addEdge(i,N+i,1);
		for(int i=1;i<=F;++i)addEdge(0,2*N+i,1);

		for(int i=1;i<=D;++i)addEdge(2*N+F+i,2*N+F+D+1,1);
		s=0,t=2*N+F+D+1;
		printf("%d\n",Maxflow(0,2*N+F+D+1));
	}
	return 0;
}
