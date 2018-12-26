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

void addEdge(int a,int b,int cap,int cost){
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
	return cost;
}

char ch[MAXN][MAXN];
int x[MAXN],y[MAXN];
void solve(){ 
	int top1=0,top2=0;
	for(int i=0;i<N;++i){ 
		for(int j=0;j<M;++j){ 
			if(ch[i][j]=='H')x[top1++]=i*M+j;
			if(ch[i][j]=='m')y[top2++]=i*M+j;
		}
	}

	MCMF_init(307);
	s=2*top1,t=2*top1+1;
	for(int i=0;i<top1;++i){ 
		for(int j=0;j<top2;++j){ 
			int x1=x[i]/M,y1=x[i]%M;
			int x2=y[j]/M,y2=y[j]%M;
	//		printf("x1:%d,y1:%d,x2:%d,y2:%d\n\n",x1,y1,x2,y2);
			int dis=abs(x1-x2)+abs(y1-y2);
			//from,to,cap,cost
			addEdge(i,j+top1,INF,dis);//i->top+j;
	//		printf("%d->%d,cap:%d,cost:%d\n",i,j+top1,1,dis);
		}
	}
	for(int i=0;i<top1;++i){ 
		addEdge(s,i,1,0);
	}
	for(int j=0;j<top2;++j){ 
		addEdge(j+top1,t,1,0);
	}
	int res=Mincost(s,t);
	printf("%d\n",res);
}
int main(){ 
	while(~scanf("%d%d",&N,&M)&&N+M){ 
		for(int i=0;i<N;++i)scanf("%s",ch[i]);
		solve();
	}
	return 0;
}
