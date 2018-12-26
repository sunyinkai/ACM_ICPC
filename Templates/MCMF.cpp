//MCMF在满足最大流条件下求最小费用
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=2007;
const int INF=1e9+7;
int N,M,s,t;
struct edge{
	int from,to,cap,flow,cost;
};
vector<edge>es;
vector<int>G[MAXN];
void MCMF_init(int N){
	for(int i=0;i<=N;++i)G[i].clear();
	es.clear();
}

void addEdge(int a,int b,int cap,int cost){//<from,to,cap,cost>
	es.push_back((edge){a,b,cap,0,cost});
	es.push_back((edge){b,a,0,0,-cost});
	int m=es.size();
	G[a].push_back(m-2);
	G[b].push_back(m-1);
}
int inq[MAXN],d[MAXN],p[MAXN],a[MAXN];
bool bellman(int s,int t,int &flow,int &cost){
	for(int i=0;i<=307;++i)d[i]=INF;
	memset(inq,0,sizeof(inq));
	d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
	queue<int>Q;
	Q.push(s);
	//printf("s=%d,t=%d,d[s]=%d,d[t]=%d\n",s,t,d[s],d[t]);
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
	//printf("d[t]=%d\n",d[t]);
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
	while(bellman(s,t,flow,cost)){ 
	};
	//printf("flow=%d,cost=%d\n",flow,cost);
	return flow==2?cost:INF;
}
int main(){ 
	while(~scanf("%d",&N)&&N){ 
		MCMF_init(N+1);
		int M;scanf("%d",&M);
		for(int i=0;i<M;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,1,c);
			addEdge(b,a,1,c);
		}
		addEdge(0,1,2,0);
		addEdge(N,N+1,INF,0);
		s=0;t=N+1;
		int res=Mincost(s,t);
		if(res==INF)printf("Back to jail\n");
		else printf("%d\n",res);
	}
	return 0;
}
