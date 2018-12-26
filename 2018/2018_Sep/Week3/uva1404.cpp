#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN=1007;
struct node{
	int u,v;
	double c;
	bool operator <(const node&other )const{
		return c<other.c;
	}
}es[MAXN*MAXN];
int x[MAXN],y[MAXN],p[MAXN];
int par[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
struct edge{
	int to,next;
	double cost;
}e[MAXN*2];
int top,head[MAXN];
void init(){
	top=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b,double c){
	e[top].to=b;
	e[top].cost=c;
	e[top].next=head[a];
	head[a]=top++;
}

double f[MAXN][MAXN];
void dfs(int root,int u,int pre,double dis ){
	f[root][u]=max(f[root][u],dis);
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].to;
		if(v==pre)continue;
		dfs(root,v,u,max(e[i].cost,f[root][u]));
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		for(int i=0;i<N;++i)scanf("%d%d%d",&x[i],&y[i],&p[i]);
		int tot=0;
		for(int i=0;i<N;++i){
			for(int j=i+1;j<N;++j){
				es[tot].u=i;es[tot].v=j;
				es[tot].c=sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	//			printf("%d-%d %.6f\n",es[tot].u,es[tot].v,es[tot].c);
				++tot;
			}
		}
		sort(es,es+tot);
		for(int i=0;i<N;++i)par[i]=i;
		double ans=0;
		init();
		for(int i=0;i<tot;++i){
			int x=find(es[i].u),y=find(es[i].v);
			if(x!=y){
				par[x]=y;
				ans+=es[i].c;
				addEdge(es[i].u,es[i].v,es[i].c);
				addEdge(es[i].v,es[i].u,es[i].c);
	//			printf("%d-%d %.6f\n",es[i].u,es[i].v,es[i].c);
			}
		}
		memset(f,0,sizeof(f));
		for(int i=0;i<N;++i)dfs(i,i,-1,0);
		double res=0.0;
		for(int i=0;i<tot;++i){
			int u=es[i].u,v=es[i].v;
			//printf("ans=%.6f,f[u][v]=%.6f\n",ans,f[u][v]);
			res=max(res,(p[u]+p[v])*1.0/(ans-f[u][v]));
		}
		printf("%.2f\n",res);
	}
	return 0;
}
