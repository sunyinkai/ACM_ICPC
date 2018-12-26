#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=102;
const int INF=1e9+7;
struct  Edge{
	int from,to,cap,flow,cost;
};
int n,m,s,t;
vector<Edge>es;
vector<int>G[MAXN];
int inq[MAXN];
int d[MAXN];
int p[MAXN];
int a[MAXN];
void init(){
	for(int i=1;i<=n;++i)G[i].clear();
	es.clear();
}
void addEdge(int from,int to,int cap,int cost){
	es.push_back(Edge{from,to,cap,0,cost});
	es.push_back(Edge{to,from,0,0,-cost});
	int a=es.size();
	G[from].push_back(a-2);
	G[to].push_back(a-1);
}
bool Bellman(int s,int t,int &flow,int &cost){
	for(int i=1;i<=n;++i)d[i]=INF;
	memset(inq,0,sizeof(inq));
	d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
	queue<int>Q;
	Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		inq[u]=0;
		for(int i=0;i<G[u].size();++i){
			Edge&e=es[G[u][i]];
			if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
				d[e.to]=d[u]+e.cost;
				p[e.to]=G[u][i];
				a[e.to]=min(a[u],e.cap-e.flow);
				if(!inq[e.to]){
					Q.push(e.to);
					inq[e.to]=1;
				}
			}
		}
	}
	if(d[t]==INF)return false;
	printf("d[t]=%d,a[t]=%d\n",d[t],a[t]);
	flo+=a[t];
	cost+=d[t]*a[t];
	int u=t;
	while(u!=s){
		es[p[u]].flow+=a[t];
		es[p[u]^1].flow-=a[t];
		u=es[p[u]].from;
	}
	return true;
}
int minCost(int s,int t){
	int flow=0,cost=0;
	while(Bellman(s,t,flow,cost));
	printf("flow=%d,cost=%d\n",flow,cost);
	return cost;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		s=1,t=2;
		init();
		for(int i=1;i<=m;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,1,c);
			addEdge(b,a,1,c);
		}
		printf("%d\n",minCost(s,t));
	}
	return 0;
 }
