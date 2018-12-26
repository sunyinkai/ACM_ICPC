#include<cstdio>
#include<cstring>
#include<stack>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
const int MAXE=2e5+7;
const int MAXV=2e4+7;
int V,E;
struct edge{
	int next,v;
}es[MAXE];
int head[MAXV],tot;
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int u,int v){
	es[tot].v=v;
	es[tot].next=head[u];
	head[u]=tot++;
}
int low[MAXV],dfn[MAXV],time;
int belong[MAXV],scc;
bool instack[MAXV];
stack<int>s;
void dfs(int u,int pre){
	low[u]=dfn[u]=++time;
	instack[u]=true;
	s.push(u);
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].v;
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}else if(instack[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		scc++;
		for(;;){
			int now=s.top();s.pop();
			belong[now]=scc;
			instack[now]=false;
			if(now==u)break;
		}
	}
}
int in[MAXV],out[MAXV];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&V,&E);	
		init();
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		memset(instack,0,sizeof(instack));
		memset(belong,0,sizeof(belong));
		time=scc=0;
		for(int i=0;i<E;++i){
			int a,b;scanf("%d%d",&a,&b);
			addEdge(a,b);
		}
		for(int i=1;i<=V;++i){
			if(!dfn[i]){
				dfs(i,-1);
			}
		}
	//	printf("scc=%d\n",scc);
		if(scc==1){
			printf("0\n");
			continue;
		}
		for(int u=1;u<=V;++u){//缩点后的操作,对代表元进行操作
			for(int i=head[u];~i;i=es[i].next){
				int v=es[i].v;
				if(belong[u]!=belong[v]){
					out[belong[u]]++;
					in[belong[v]]++;
				}
			}
		}
		int IN=0,OUT=0;
		for(int i=1;i<=scc;++i){
		//	printf("in[%d]=%d,out[%d]=%d\n",i,in[i],i,out[i]);
			if(in[i]==0)++IN;
			if(out[i]==0)++OUT;
		}
		printf("%d\n",max(IN,OUT));
	}
	return 0;
}
