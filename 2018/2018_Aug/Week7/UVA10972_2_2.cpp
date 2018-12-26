#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define min(a,b) (a<b?a:b)
//找到桥，然后边双连通缩点
// (a+1)/2+b a为叶子节点数,b为孤立点数

const int MAXN=1007;
struct edge{
	int to,next;
	int isedge;
}es[MAXN*MAXN];
int tot,head[MAXN];

void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].isedge=0;
	es[tot].next=head[a];
	head[a]=tot++;
}

int low[MAXN],dfn[MAXN],time;
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	time=0;
}
void tarjan(int u,int prev){
	low[u]=dfn[u]=++time;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if((i^prev)==1)continue;
		if(!dfn[v]){
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				es[i].isedge=es[i^1].isedge=1;
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}

int par[MAXN],du[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
inline void unit(int x,int y){
	int tx=find(x);
	int ty=find(y);
	if(tx!=ty){
		par[tx]=ty;
	}
}

vector<int>G[MAXN];
int isok[MAXN];
int main(){
	int N,M;
	while(~scanf("%d%d",&N,&M)){
		init();
		for(int i=0;i<M;++i){
			int a,b;scanf("%d%d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}
		for(int i=1;i<=N;++i){
			if(!dfn[i])tarjan(i,-1);
		}
		for(int i=1;i<=N;++i)par[i]=i,G[i].clear();
		for(int u=1;u<=N;++u){
			for(int i=head[u];~i;i=es[i].next){
				int v=es[i].to;
				if(es[i].isedge)continue;
				unit(u,v);
			}
		}//不包含桥
		memset(isok,0,sizeof(isok));
		for(int i=1;i<=N;++i)
			isok[find(i)]=1;
		for(int i=1;i<=N;++i)du[i]=0;
		for(int u=1;u<=N;++u){
			for(int i=head[u];~i;i=es[i].next){
				int v=es[i].to;
				if(es[i].isedge&&u>v){
					int x=find(u),y=find(v);
					G[x].push_back(y);
					G[y].push_back(x);
					du[x]++;du[y]++;
				}
			}
		}
		int ans=0;
		int tag=false;
		for(int i=1;i<=N;++i){
			if(isok[i]&&(G[i].size()==0)){
				ans+=2;
				tag=true;
			}
			if(du[i]==1)ans++;
		}
		if(tag&&ans==2)printf("0\n");
		else printf("%d\n",(ans+1)/2);
	}
	return 0;
}
