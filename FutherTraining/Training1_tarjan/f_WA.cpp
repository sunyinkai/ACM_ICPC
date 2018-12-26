#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const int MAXV=2e5+7,MAXE=1e6+7;
struct edge{
	int from,to,next;
	bool isCut;
}es[MAXE*2];
int low[MAXV],dfn[MAXV],dfs_clock;
int tot,head[MAXV];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].from=a;
	es[tot].isCut=0;
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

struct edge2{
	int to,next;
}es2[MAXE*2];

int tot2,head2[MAXV];
void init2(){
	tot2=0;
	memset(head2,-1,sizeof(head2));
}
void addEdge2(int a,int b){
	es2[tot2].to=b;
	es2[tot2].next=head2[a];
	head2[a]=tot2++;
}

void dfs(int u,int par){
	dfn[u]=low[u]=++dfs_clock;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
	//	printf("i=%d,i^1=%d,par=%d,u=%d,v=%d\n",i,i^1,par,u,v);
		if((i^1)==par)continue;
	//	printf("tag\n");
		if(!dfn[v]){
			dfs(v,i);
			printf("tag:low[%d]=%d\n",v,low[v]);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				es[i].isCut=es[i^1].isCut=1;
			}
		}else{
			low[u]=min(low[u],dfn[v]);
		}
	}
	printf("low[%d]=%d,dfn[%d]=%d\n",u,low[u],u,dfn[u]);
}
int par[MAXV];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
void inline unit(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b)par[a]=b;
}
int begin2,maxLen;
void dfs2(int u,int pre,int len){
	if(len>maxLen){
		maxLen=len;
		begin2=u;
	}

	for(int i=head2[u];~i;i=es2[i].next){
		int v=es2[i].to;
		if(v==pre)continue;
		dfs2(v,u,len+1);
	}
}
void dfs3(int u,int pre,int len){
	if(len>maxLen){
		maxLen=len;
	}
	for(int i=head2[u];~i;i=es2[i].next){
		int v=es2[i].to;
		if(v==pre)continue;
		dfs3(v,u,len+1);
	}
}
int main(){
	int N,M;
	while(~scanf("%d%d",&N,&M)&&N+M){
		init();
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		dfs_clock=0;
		for(int i=0;i<M;++i){
			int a,b;scanf("%d%d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}
		for(int i=1;i<=N;++i){
			if(!dfn[i])dfs(i,-1);
		}
		for(int i=1;i<=N;++i)par[i]=i;
		int edgeCnt=0;
		for(int i=0;i<tot;i+=2){
			if(es[i].isCut){
				edgeCnt++;
				continue;
			}
			int u=es[i].from,v=es[i].to;
			unit(u,v);//u,v在一个双连通分量里
		}

		init2();
		int begin=0;
		for(int i=0;i<tot;i+=2){
			if(es[i].isCut){
				int u=es[i].from,v=es[i].to;
				addEdge2(par[u],par[v]);
				addEdge2(par[v],par[u]);
				begin=par[u];
			}
		}
		maxLen=0;
		dfs2(begin,-1,0);
		dfs3(begin2,-1,0);
		printf("%d\n",edgeCnt);
	}
	return 0;
}

