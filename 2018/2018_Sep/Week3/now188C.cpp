#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=5e4+7;
const int MAXE=1e5+7;
struct edge{
	long long to,next,cost;
}es[MAXE];
int head[MAXN],tot;
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(long long a,long long b,long long c){
	es[tot].cost=c;es[tot].to=b;es[tot].next=head[a];
	head[a]=tot++;
}
long long dfs(int u,int pre,long long dis){
	long long res=dis;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		res=max(res,dfs(v,u,dis+es[i].cost));
	}
	return res;
}

int main(){
	int N,x;scanf("%d%d",&N,&x);
	init();
	long long res=0;
	for(int i=1;i<N;++i){
		long long x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
		addEdge(x,y,z);
		addEdge(y,x,z);
		res+=2*z;
	}
	printf("%lld\n",res-dfs(x,-1,0));
	return 0;
}
