#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+7;
struct edge{
	int to,next;
}es[MAXN*2];
int tot,head[MAXN];
int siz[MAXN],ans=0;
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}
int dfs(int u,int pre,int d){
	siz[u]=1;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		siz[u]+=dfs(v,u,d+1);
	}
	if(pre!=-1)ans=max(ans,d+siz[u]-1);
	return siz[u];
}

int main(){
	int N;scanf("%d",&N);
	init();
	for(int i=1;i<N;++i){
		int a,b;scanf("%d%d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}
	dfs(1,-1,0);
	printf("%d\n",ans);
	return 0;
}
