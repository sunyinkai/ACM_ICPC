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
			a-=f;
	//当前弧优化对于节点x如果前面的一些弧已经能够把a这么多流量送往t
	//那么就不用访问后面的一些弧了.
			if(a==0)break;
		}
	}
	return flow;
}
int Maxflow(int s,int t){
	printf("s=%d,t=%d\n",s,t);
	int flow=0;
	int test=1;
	while(bfs()){//每次完成后最短增广路长度单调递
		memset(cur,0,sizeof(cur));
		flow+=dfs(s,INF);
		++test;
	}
	printf("\n");
	return flow;
}
int main(){
	es.clear();
	for(int i=0;i<MAXN;++i)G[i].clear();
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		addEdge(a,b,c);
	}
	s=1,t=N;
	printf("%d\n",Maxflow(s,t));
	return 0;
}
