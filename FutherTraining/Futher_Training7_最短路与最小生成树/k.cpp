//没考虑到没有那种路的情况
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1007;
const int MAXE=4007;
const int INF=1e9+7;
typedef pair<int,int> P;
int N,S,E,M,K;
int x[MAXN],y[MAXN],z[MAXN];
int xx[MAXN],yy[MAXN],zz[MAXN];
struct edg{
	int from,to,next,cost;
}es[MAXE*4];
int tot,head[MAXE];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b,int c){
	es[tot].from=a;
	es[tot].to=b;
	es[tot].cost=c;
	es[tot].next=head[a];
	head[a]=tot++;
}
int d[MAXN],done[MAXN],par[MAXN];
void dijkstra(int s){
	for(int i=1;i<=N;++i)d[i]=INF,done[i]=0;
	priority_queue<P,vector<P>,greater<P> >q;
	memset(par,-1,sizeof(par));

	d[s]=0;
	q.push(P(0,s));
	while(!q.empty()){
		P p=q.top();q.pop();
		int u=p.second;
		if(done[u])continue;
		done[u]=1;
		d[u]=p.first;
		for(int i=head[u];~i;i=es[i].next){
			int  v=es[i].to;
			if(d[v]>d[u]+es[i].cost){
				d[v]=d[u]+es[i].cost;
				par[v]=i;
				q.push(P(d[v],v));
			}
		}
	}
}
int res,theCom;
vector<int>resQ;
void solve(){
	res=INF;
	resQ.clear();
	theCom=-1;

	for(int i=0;i<K;++i){//枚举边
		init();
		addEdge(xx[i],yy[i],zz[i]);
		addEdge(yy[i],xx[i],zz[i]);
		for(int j=0;j<M;++j){
			addEdge(x[j],y[j],z[j]);
			addEdge(y[j],x[j],z[j]);
		}
		dijkstra(S);
		if(d[E]<res){
			res=d[E];
			resQ.clear();
			resQ.push_back(E);
			int visit=0;
			int u=E;
			while(par[u]!=-1){
				resQ.push_back(es[par[u]].from);
				if(par[u]==0||par[u]==1){
					visit=es[par[u]].from;
				}
				u=es[par[u]].from;
			}

			if(visit)theCom=visit;
			else theCom=-1;
		}
	}
	int len=resQ.size();
	reverse(resQ.begin(),resQ.end());
	for(int i=0;i<len;++i){
		printf(i==0?"%d":" %d",resQ[i]);
	}
	printf("\n");//first;
	if(~theCom)printf("%d\n",theCom);//second
	else printf("Ticket Not Used\n");
	printf("%d\n",res);//third;
}
int main(){
	int tag=0;
	while(~scanf("%d%d%d",&N,&S,&E)){
		if(tag)printf("\n");
		tag=1;
		scanf("%d",&M);
		for(int i=0;i<M;++i){
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
		}
		scanf("%d",&K);
		for(int i=0;i<K;++i){
			scanf("%d%d%d",&xx[i],&yy[i],&zz[i]);
		}//input
		solve();
	}
	return 0;
}
