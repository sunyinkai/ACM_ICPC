//寻找一条边，边两端人口/非这条边上的最小生成树的值最大。 
//先处理出任意两点的瓶颈路f[u][v] 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN=1007;
const double INF=1e9+7;
int x[MAXN],y[MAXN],p[MAXN];
struct edge{
	int u,v;double c;
	bool operator <(const edge&other)const{
		return c<other.c;
	}
}es[MAXN*MAXN];
int par[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
double dis(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)*1.0+(y1-y2)*(y1-y2)*1.0);
}

struct Edge{
	int to,next;double cost;
}edges[MAXN*2];
int head[MAXN],tot;
inline void init(){
	memset(head,-1,sizeof(head));
	tot=0;
}
inline void  addEdge(int a,int b,double c){
	edges[tot].to=b;
	edges[tot].cost=c;
	edges[tot].next=head[a];
	head[a]=tot++;
}
double f[MAXN][MAXN];
void dfs(int root,int u,int pre){
	for(int i=head[u];~i;i=edges[i].next){
		int v=edges[i].to;
		if(v==pre)continue;
		f[root][v]=max(f[root][u],edges[i].cost);
		dfs(root,v,u);
	}
}
int main(){
	freopen("in.txt","r",stdin);
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		for(int i=1;i<=N;++i)scanf("%d%d%d",&x[i],&y[i],&p[i]);
		int edgeCnt=0;
		for(int i=1;i<=N;++i){
			for(int j=i+1;j<=N;++j){
				es[edgeCnt].u=i;es[edgeCnt].v=j;
				es[edgeCnt++].c=dis(x[i],y[i],x[j],y[j]);
				printf("%d-%d %.6f\n",es[edgeCnt-1].u,es[edgeCnt-1].v,es[edgeCnt-1].c);
			}
		}
		sort(es,es+edgeCnt);
		double res=0.0;
		for(int i=1;i<=N;++i)par[i]=i;
		init();
		for(int i=0;i<edgeCnt;++i){
			int u=es[i].u,v=es[i].v;
			int x=find(u),y=find(v);
			if(x!=y){
				par[x]=y;
				addEdge(es[i].u,es[i].v,es[i].c);
				addEdge(es[i].v,es[i].u,es[i].c);
				printf("%d-%d %.6f\n",es[i].u,es[i].v,es[i].c);
				res+=es[i].c;
			}
		}
		
		memset(f,0,sizeof(f));
		for(int i=1;i<=N;++i){//init
			dfs(i,i,-1);	
		}
		double ans=0.0;
		for(int i=0;i<edgeCnt;++i){
				int u=es[i].u,v=es[i].v;
				printf("res=%.6f f[u][v]=%.6f\n",res,f[u][v]);
				ans=max(ans,(p[u]+p[v])*1.0/(res-f[u][v]));
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
