#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
typedef long long LL;
const LL MAXN=2e5+7;
const LL INF=1e9+7;
LL a[MAXN];
struct edge{
	LL next,to,cost;
}es[MAXN*2];
LL tot,head[MAXN];

void addEdge(LL a,LL b,LL c){
	es[tot].to=b;
	es[tot].cost=c;
	es[tot].next=head[a];
	head[a]=tot++;
}
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}

LL size[MAXN];
LL res,id,sum,N;
void dfs(LL u,LL pre){
	size[u]=a[u];
	LL x=0;
	for(LL i=head[u];~i;i=es[i].next){
		LL v=es[i].to;
		if(v==pre)continue;
		dfs(v,u);
		size[u]+=size[v];
		x=max(size[v],x);
	}
	x=max(x,sum-size[u]);
	if(x<res){
		res=x;
		id=u;
	}
}

double ans=0.0;
void dfs2(LL u,LL pre,LL dis){
	ans+=a[u]*pow(dis,1.5);
	for(LL i=head[u];~i;i=es[i].next){
		LL v=es[i].to;
		if(v==pre)continue;
		dfs2(v,u,dis+es[i].cost);
	}
}

int main(){
	scanf("%lld",&N);
	for(LL i=1;i<=N;++i)scanf("%lld",&a[i]);
	init();
	sum=0;
	for(LL i=1;i<N;++i){
		LL a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
		sum+=c;
		addEdge(a,b,c);
		addEdge(b,a,c);
	}
	res=INF,id=0;
	dfs(1,-1);
	//prLLf("res=%d,id=%d\n",res,id);
	dfs2(id,-1,0);
	printf("%lld %.8f\n",id,ans);
	return 0;
}
