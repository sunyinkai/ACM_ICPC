//MCMF在满足最大流条件下求最小费用
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=2007;
const int INF=1e9+7;
int N,M;
struct edge{
	int from,to,cap,flow,cost;
};
vector<edge>es;
vector<int>G[MAXN];
void MCMF_int(int N){
	for(int i=0;i<=N;++i)G[i].clear();
	es.clear();
}
void addEdge(int a,int b,int cap,int cost){
	es.push_back((edge){a,b,cap,0,cost});
	es.push_back((edge){b,a,0,0,-cost});
	int m=es.size();
	G[a].push_back(m-2);
	G[b].push_back(m-1);
}
int inq[MAXN],d[MAXN],p[MAXN],a[MAXN];
bool bellman(int s,int t,int &flow,int &cost){
	for(int i=0;i<=N;++i)d[i]=INF;
	memset(inq,0,sizeof(inq));
	d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
	queue<int>Q;
	Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		inq[u]=0;
		for(int i=0;i<G[u].size();++i){
			edge &e=es[G[u][i]];
			if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
				d[e.to]=d[u]+e.cost;
				p[e.to]=G[u][i];//前一条弧
				a[e.to]=min(a[u],e.cap-e.flow);//可改进量
				if(!inq[e.to])Q.push(e.to),inq[e.to]=1;
			}
		}
	}
	if(d[t]==INF)return false;
	flow+=a[t];
	cost+=d[t]*a[t];
	//固定流量k,当flow+a>=k时,只增广k-flow的流量然后终止即可
	int u=t;
	while(u!=s){
		es[p[u]].flow+=a[t];
		es[p[u]^1].flow-=a[t];
		u=es[p[u]].from;
	}
	return true;
}
int Mincost(int s,int t){
	int flow=0,cost=0;
	while(bellman(s,t,flow,cost));
	//printf("flow=%d,cost=%d\n",flow,cost);
	return cost;
}
int main(){
	while(~scanf("%d%d",&N,&M)){
		MCMF_int(2*N);
		for(int i=0;i<M;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b+N,1,c);
		}
		for(int i=1;i<=N;++i)addEdge(i+N,i,1,0);
	}
	return 0;
}
