#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN=307;
const LL INF=1e15+7;
LL N,M,s,t;
struct edge{
	LL from,to,cap,flow,cost;
};
vector<edge>es;
vector<LL>G[MAXN];
void MCMF_init(LL N){
	for(LL i=0;i<=N;++i)G[i].clear();
	es.clear();
}

void addEdge(LL a,LL b,LL cap,LL cost){
	es.push_back((edge){a,b,cap,0,cost});
	es.push_back((edge){b,a,0,0,-cost});
	LL m=es.size();
	G[a].push_back(m-2);
	G[b].push_back(m-1);
}

LL inq[MAXN],d[MAXN],p[MAXN],a[MAXN];
bool bellman(LL s,LL t,LL&flow,LL&cost){
	for(LL i=0;i<MAXN;++i)d[i]=INF;
	memset(inq,0,sizeof(inq));
	d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
	queue<LL>Q;
	Q.push(s);
	while(!Q.empty()){
		LL u=Q.front();Q.pop();
		inq[u]=0;
		for(LL i=0;i<G[u].size();++i){
			edge &e=es[G[u][i]];
			if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
				d[e.to]=d[u]+e.cost;
				p[e.to]=G[u][i];
				a[e.to]=min(a[u],e.cap-e.flow);
				if(!inq[e.to])Q.push(e.to),inq[e.to]=1;
			}
		}
	}
	if(d[t]>0)return false;
	flow+=a[t];
	cost+=d[t]*a[t];
	for(LL u=t;u!=s;u=es[p[u]].from){
		es[p[u]].flow+=a[t];
		es[p[u]^1].flow-=a[t];
	}
	return true;
}

LL Mincost(LL s,LL t){
	LL flow=0,cost=0;
	while(bellman(s,t,flow,cost));
	return cost;
}

LL aa[MAXN],bb[MAXN],cc[MAXN],dd[MAXN],ee[MAXN];
int  main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	LL T;scanf("%lld",&T);
	for(LL test=1;test<=T;++test){
		LL c;scanf("%lld%lld",&N,&c);
		for(LL i=1;i<=N;++i){
			scanf("%lld%lld%lld%lld%lld",&aa[i],&bb[i],&cc[i],&dd[i],&ee[i]);
		}
		MCMF_init(2*N+1);
		s=0,t=2*N+1;
		for(LL i=1;i<=N;++i){
			addEdge(s,i,bb[i],aa[i]);
			addEdge(N+i,t,dd[i],-cc[i]);
		}
		for(LL i=1;i<=N;++i){
			LL x=ee[i];
			for(LL j=i+N;j<=2*N&&j<=N+i+x;++j){
				addEdge(i,j,INF,(j-i-N)*c);
			}
		}
		printf("Case %lld: %lld\n",test,-Mincost(s,t));
	}
}
