#include<cstdio>
#include<cstring>
const int  MAXN=2e3+7;
struct edge{
	int to,next,cost;
}es[MAXN];
int tot,head[MAXN],ans[MAXN];
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
int size[MAXN];
void  dfs2(int u,int pre){
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		size[v]=es[i].cost&1;
		dfs2(v,u);
	}
}
int dfs(int u,int pre){
	if(ans[u]!=-1)return ans[u];
	int val=size[u];
	int num=0;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		num^=dfs(v,u);
	}
	ans[u]=val+num;
	return ans[u];
}
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		init();
		int N;scanf("%d",&N);
		for(int i=1;i<N;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		dfs2(0,-1);
		memset(ans,-1,sizeof(ans));
		int val=dfs(0,-1);
		printf("Case %d: ",test);
		if(val!=0)printf("Emily\n");
		else printf("Jolly\n");
	}
	return 0;
}
