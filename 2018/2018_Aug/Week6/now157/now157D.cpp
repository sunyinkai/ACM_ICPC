#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
const int MAXE=1e5+7;
struct edge{
	int to,next,cost;
}es[MAXE];
int tot,head[MAXE];
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
int in[MAXE],res;
void dfs(int u,int pre,int dis){
	res=max(res,dis);
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		dfs(v,u,dis+es[i].cost);
	}
}
int  main(){
	int N;scanf("%d",&N);
	init();
	for(int i=1;i<N;++i){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		addEdge(b,a,c);
		in[a]++;
	}
	int root;
	for(root=1;in[root]!=0;++root);
	res=0;
	dfs(root,-1,0);
	printf("%d\n",res);
	return 0;
}
