#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
//让每个点的度数都>=2即可
//(1+n)/2,其实是n/2向上取整,一条边的贡献为2

const int MAXN=1007;
int N,M;
struct edge{
	int to,next;
	int iscut;
}es[MAXN*MAXN];
int tot,head[MAXN];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].iscut=0;
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

int low[MAXN],dfn[MAXN],dfs_clock;
void dfs(int u,int pre){
	low[u]=dfn[u]=++dfs_clock;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if((i^pre)==1)continue;
		if(!dfn[v]){
			dfs(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				es[i].iscut=es[i^1].iscut=1;
			}
		}else low[u]=min(low[u],low[v]);
	}
}
void find_ebcc(int N){
	memset(dfn,0,sizeof(dfn));
	dfs_clock=0;
	for(int i=1;i<=N;++i){
		if(!dfn[i])dfs(i,-1);
	}
}

int par[MAXN];
int find(int i){
	return par[i]==i?par[i]:par[i]=find(par[i]);
}
void unit(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y)par[x]=y;
}

int q[MAXN],belong[MAXN],du[MAXN];
void solve(){
	for(int i=1;i<=N;++i)par[i]=i;
	for(int u=1;u<=N;++u){
		for(int i=head[u];~i;i=es[i].next){
			int v=es[i].to;
			if(es[i].iscut)continue;
			unit(u,v);
		}
	}
	int top=0;
	memset(belong,0,sizeof(belong));
	memset(du,0,sizeof(du));
	for(int i=1;i<=N;++i){
		par[i]=find(i);
		if(par[i]==i)q[top++]=i;
	}
	//将离散的ebcc编号,变为连续的

	sort(q,q+top);
	for(int i=0;i<top;++i)
		belong[q[i]]=i+1;
	
	for(int u=1;u<=N;++u){
		for(int i=head[u];~i;i=es[i].next){
			int v=es[i].to;
			if(es[i].iscut&&u<v){
				int x=belong[find(u)],y=belong[find(v)];
				du[x]++;du[y]++;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=top;++i){
		if(du[i]==0)cnt+=2;
		else if(du[i]==1)cnt++;
	}
	if(top==1)printf("%d\n",0);//只有1个连通块
	else printf("%d\n",(cnt+1)/2);
}
int main(){
	while(~scanf("%d%d",&N,&M)){
		init();
		for(int i=0;i<M;++i){
			int a,b;scanf("%d%d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}
		find_ebcc(N);
		solve();
	}
	return 0;
}
