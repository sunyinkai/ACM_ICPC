#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=307;
const int INF=1e9+7;
struct Edge{int from,to,cap,flow,cost;};
vector<int>G[MAXN];
vector<Edge>edges;
int n,m,s,t;

void  addEdge(int from,int to,int cap,int cost){
	edges.push_back((Edge){from,to,cap,0,cost});
	edges.push_back((Edge){to,from,0,0,-cost});
	int m=edges.size();
	G[from].push_back(m-2);
	G[to].push_back(m-1);
}

int inq[MAXN],a[MAXN],d[MAXN],p[MAXN];
bool Bellman(int s,int t,int &flow,int &cost){
	for(int i=0;i<MAXN;++i)d[i]=INF;
	memset(inq,0,sizeof(inq));
	d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;

	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=0;i<G[u].size();++i){
			Edge&e=edges[G[u][i]];
			if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
				d[e.to]=d[u]+e.cost;
				p[e.to]=G[u][i];
				a[e.to]=min(a[u],e.cap-e.flow);
				if(!inq[e.to]){q.push(e.to);inq[e.to]=1;}
			}
		}
	}

	if(d[t]==INF)return false;
	flow+=a[t];
	cost+=d[t]*a[t];
	int u=t;
	while(u!=s){
		edges[p[u]].flow+=a[t];
		edges[p[u]^1].flow-=a[t];
		u=edges[p[u]].from;
	}
	return true;
}

int Mincost(int s,int t){
	int flow=0,cost=0;
	while(Bellman(s,t,flow,cost));
	if(flow!=2)return cost=INF;
	else return cost;
}
void MCMF_int(){
	for(int i=0;i<MAXN;++i)G[i].clear();
	edges.clear();
}

int main(){ 
	int test=1;
	while(~scanf("%d%d",&n,&m)&&n+m){
		MCMF_int();
		for(int i=0;i<m;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			addEdge(a+n,b,1,c);
		}
		for(int i=0;i<n;++i){
			if(i==0||i==n-1)addEdge(i,n+i,2,0);
			else addEdge(i,i+n,1,0);
		}
		printf("Instance #%d: ",test++);
		s=0,t=2*n-1;
		int res=Mincost(s,t);
		if(res==INF)printf("Not possible\n");
		else printf("%d\n",res);
	}
	return 0;
}
