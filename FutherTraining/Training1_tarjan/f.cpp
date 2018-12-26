#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXV=2e5+7,MAXE=1e6+7;
int N,M;
struct edge{
	int from,to,next;
	bool isCut;
}*es;
int *low=NULL,*dfn=NULL,dfs_clock;
int tot,*head=NULL;
void init(){
	tot=0;
	memset(head,-1,(N+7)*sizeof(int));
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
}*es2;

int tot2,*head2=NULL;
void init2(){
	tot2=0;
	memset(head2,-1,(N+7)*sizeof(int));
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
		if((i^par)==1)continue;
		if(!dfn[v]){
			dfs(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				es[i].isCut=es[i^1].isCut=1;
			}
		}else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int *par=NULL;
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
void inline unit(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b)par[a]=b;
}
int begin2,maxLen=0;
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
	while(~scanf("%d%d",&N,&M)&&N+M){
		head=new int[N+7];
		es= new edge[2*(M+7)];
		init();
		dfn=new int[N+7];
		low=new int[N+7];
		getchar();
		memset(dfn,0,(N+7)*sizeof(int));
		memset(low,0,(N+7)*sizeof(int));
		dfs_clock=0;
		for(int i=0;i<M;++i){
			int a,b;scanf("%d%d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		dfs(1,-1);
		delete [] dfn;
		delete [] low;
		delete [] head;
		par =new int[N+7];
		for(int i=1;i<=N;++i)par[i]=i;
		int edgeCnt=0;
		for(int i=0;i<tot;i+=2){
			if(es[i].isCut){
				edgeCnt++;
				continue;
			}
			int u=es[i].from,v=es[i].to;
			unit(u,v);
		}
		head2=new int[N+7];
		es2=new edge2[2*(edgeCnt+7)];
		init2();
		int begin=0;
		for(int i=0;i<tot;i+=2){
			if(es[i].isCut){
				int u=es[i].from,v=es[i].to;
				//printf("%d-%d\n",par[u],par[v]);
				addEdge2(par[u],par[v]);
				addEdge2(par[v],par[u]);
				begin=par[u];
			}
		}
		delete [] par;
		delete [] es;
		maxLen=0;
		dfs2(begin,-1,0);
		dfs3(begin2,-1,0);
		printf("%d\n",edgeCnt-maxLen);
		delete []head2;
		delete []es2;
	}
	return 0;
}
