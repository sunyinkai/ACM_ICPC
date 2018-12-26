//好题,有坑点
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+7;
const int MAXM=1e5+7;
int N,M;
struct edge{
	int to,next,cost;
}es[MAXM*2];
int head[MAXN],tot;
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b,int c){
	es[tot].to=b;
	es[tot].cost=c;
	es[tot].next=head[a];
	head[a]=tot++;
}

struct edges{
	int u,v,c;
	bool operator <(const edges&other){
		return c<other.c;
	}
}e[MAXM];

int par[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}

void MST(){
	init();
	sort(e,e+M);
	for(int i=1;i<=N;++i)par[i]=i;
	for(int i=0;i<M;++i){
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			par[u]=v;
			addEdge(e[i].u,e[i].v,e[i].c);
			addEdge(e[i].v,e[i].u,e[i].c);
		}
	}
}

int dep[MAXN],f[MAXN][21],Max[MAXN][21];
//Max[i][j]: i与他的2^j级祖先间的路径上的最大值
void dfs(int u,int pre,int depth){
	dep[u]=depth;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		Max[v][0]=es[i].cost;
		f[v][0]=u;
		dfs(v,u,depth+1);
	}
}
void LCA_init(){
	memset(f,-1,sizeof(f));
	memset(Max,0,sizeof(Max));
	memset(dep,0,sizeof(dep));
	dfs(1,-1,0);
	for(int k=1;k<=20;++k){
		for(int i=1;i<=N;++i){
			int u=f[i][k-1];
			if(u!=-1){
				f[i][k]=f[u][k-1];
				Max[i][k]=max(Max[i][k-1],Max[u][k-1]);
			}
		}
	}
}
int query(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	int d=dep[a]-dep[b];
	int res=0;
	for(int i=0;(1<<i)<=d;++i){
		if(d&(1<<i)){
			res=max(res,Max[a][i]);
			a=f[a][i];
		}
	}
	if(a!=b){
		for(int i=(int)log2(N);i>=0;--i)//注意这个括号
			if(f[a][i]!=-1&&f[a][i]!=f[b][i]){
				res=max(Max[a][i],res);
				res=max(Max[b][i],res);
				a=f[a][i],b=f[b][i];
			}

		res=max(res,Max[a][0]);
		res=max(res,Max[b][0]);//!!
		a=f[a][0];
		b=f[b][0];
	}
	return res;
}
void solve(){
	int Q;scanf("%d",&Q);
	while(Q--){
		int a,b;scanf("%d%d",&a,&b);
		printf("%d\n",query(a,b));
	}
}
int main(){
	int tag=0;
	while(~scanf("%d%d",&N,&M)){
		if(tag)printf("\n");
		tag=1;
		for(int i=0;i<M;++i)
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
		MST();
		LCA_init();
		solve();
	}
	return 0;
}
