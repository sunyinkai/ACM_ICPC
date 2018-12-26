#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+7;
int tot,head[MAXN];
int N,M,root;
struct edge{
	int to,next;
}es[MAXN*2];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}
int par[MAXN][21],depth[MAXN];
void dfs(int u,int pre,int dep){
	par[u][0]=pre;
	depth[u]=dep;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		dfs(v,u,dep+1); 
	}
}
void LCA_init(){
	for(int k=1;k<=20;++k){
		for(int i=1;i<=N;++i){
			int u=par[i][k-1];
			if(u!=-1){
				par[i][k]=par[u][k-1];
			}
		}
	}
}
int query(int a,int b){
	if(depth[a]<depth[b])swap(a,b);
	int len=depth[a]-depth[b];
	for(int i=0;(1<<i)<=len;++i)
		if(len&(1<<i))a=par[a][i];
	if(a!=b){
		for(int i=20;i>=0;--i){
			if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
		}
		a=par[a][0];
	}
	return a;
}

int main(){
	scanf("%d%d%d",&N,&M,&root);
	init();
	for(int i=1;i<M;++i){
		int a,b;scanf("%d%d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	memset(par,-1,sizeof(par));
	dfs(root,-1,0);
	LCA_init();
	while(M--){
		int a,b;scanf("%d%d",&a,&b);
		printf("%d\n",query(a,b));
	}
	return 0;
}
