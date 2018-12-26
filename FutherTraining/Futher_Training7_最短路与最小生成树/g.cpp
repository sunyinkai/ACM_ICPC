//瓶颈路查询,可以O(n^2)预处理
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXE=1007;
const int MAXV=107;
const int INF=1e9+7;
int f[MAXV][MAXV];
int N,M,Q,tot,head[MAXV];
struct edge{
	int u,v,c,next;
	bool operator <(const edge&other)const{
		return c<other.c;
	}
}ES[MAXE*2],e[MAXE*2];
int par[MAXV];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b,int c){
	e[tot].v=b;
	e[tot].c=c;
	e[tot].next=head[a];
	head[a]=tot++;
}
void dfs(int root,int u,int pre){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v==pre)continue;
		f[root][v]=max(f[root][u],e[i].c);
		dfs(root,v,u);
	}
}
void solve(){
	memset(f,-1,sizeof(f));
	for(int u=1;u<=N;++u){
		dfs(u,u,-1);
	}
}
int main(){
	int test=1;
	int tag=0;
	while(~scanf("%d%d%d",&N,&M,&Q)&&N+M+Q){
		if(tag)printf("\n");
		tag=1;
		printf("Case #%d\n",test++);
		for(int i=0;i<M;++i){
			scanf("%d%d%d",&ES[i].u,&ES[i].v,&ES[i].c);
		}
		sort(ES,ES+M);
		init();
		for(int i=1;i<=N;++i)par[i]=i;
		for(int i=0;i<M;++i){
			int u=ES[i].u,v=ES[i].v;
			u=find(u);v=find(v);
			if(u!=v){
				addEdge(ES[i].u,ES[i].v,ES[i].c);
				addEdge(ES[i].v,ES[i].u,ES[i].c);
				par[u]=v;
			}
		}//MST
		solve();
		while(Q--){
			int a,b;scanf("%d%d",&a,&b);
			if(f[a][b]==-1)printf("no path\n");
			else printf("%d\n",f[a][b]);
		}
	}
	return 0;
}
