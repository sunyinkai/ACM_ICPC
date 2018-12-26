#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
//节点上有限制的最大流
//unsolved
using namespace std;
typedef long long LL;
const LL  INF=1e9+7;
const LL  MAXN=1e5+7;
struct edge{
	LL  from,to,cap,flow;
};
vector<LL >G[MAXN];
vector<edge>es;
void addEdge(LL  a,LL  b,LL  c){
	es.push_back(edge{a,b,c,0});
	es.push_back(edge{b,a,0,0});
	LL  m=es.size();
	G[a].push_back(m-2);//以a为顶点的第i条边的编号
	G[b].push_back(m-1);
}
bool visit[MAXN];
LL  d[MAXN];
LL  cur[MAXN];
LL  s,t;
bool bfs(){
	memset(visit,0,sizeof(visit));
	queue<LL >q;
	q.push(s);
	d[s]=0;
	visit[s]=1;
	while(!q.empty()){
		LL  x=q.front();q.pop();
		for(LL  i=0;i<G[x].size();++i){
			edge &e=es[G[x][i]];
			if(!visit[e.to]&&e.cap>e.flow){
				visit[e.to]=1;
				d[e.to]=d[x]+1;
				q.push(e.to);
			}
		}
	}
	return visit[t];
}
LL  dfs(LL  x,LL  a){//从s->x的最小剩余流量
	if(x==t||a==0)return a;
	LL  flow=0,f;
	for(LL  &i=cur[x];i<G[x].size();++i){
		edge& e=es[G[x][i]];
		if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
			e.flow+=f;
			es[G[x][i]^1].flow-=f;
			flow+=f;
			a-=f;//?
			if(a==0)break;
		}
	}
	return flow;
}
LL  Maxflow(LL  s,LL  t){
	LL  flow=0;
	while(bfs()){//每次完成后最短增广路长度单调递
		memset(cur,0,sizeof(cur));
		flow+=dfs(s,INF);
	}
	return flow;
}
LL  cost[MAXN];
int  main(){
	LL  N,M;
	while(~scanf("%lld%lld",&N,&M)){ 
		LL  S,T;scanf("%lld%lld",&S,&T);
		es.clear();
		for(LL  i=0;i<MAXN;++i)G[i].clear();

		for(LL  i=1;i<=N;++i){
			scanf("%lld",&cost[i]);
			addEdge(i,i+N,cost[i]);
		}
		for(LL  i=0;i<M;++i){
			LL  a,b;scanf("%lld%lld",&a,&b);
			addEdge(a+N,b,INF);
			addEdge(b+N,a,INF);
		}
		s=S,t=T+N;
		printf("%lld\n",Maxflow(s,t));
	}
	return 0;
}
