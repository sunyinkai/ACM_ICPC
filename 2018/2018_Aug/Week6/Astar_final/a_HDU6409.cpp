#include<cstdio>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int MAXN=1e5+7;
int a[MAXN];
int tot,head[MAXN];
struct  edge{
	int to,next; 
}es[MAXN*2];
void init(int N){
	tot=0;
	for(int i=0;i<=N;++i)head[i]=-1;
}
void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

long long MIN,MAX;
int visitA[MAXN],visitB[MAXN];
void dfs(int u,int pre){
	int tMax=0,tMin=0;
	int ii=0,jj=0;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		if(a[v]>0&&a[v]>tMax){
			ii=v;
			tMax=a[v];
		}
		if(a[v]<0&&a[v]<tMin){
			jj=v;
			tMin=a[v];
		}
		dfs(v,u);
	}
	visitA[ii]=visitB[jj]=1;
	//printf("u=%d,tMax=%d,tMin=%d\n",u,tMax,tMin);
	MAX+=tMax;
	MIN+=tMin;
}

int addMax,addMin;
void dfs2(int u,int pre){
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		if(!visitA[v]){
			addMax=max(addMax,a[v]);
		}
		if(!visitB[v]){
			addMin=min(addMin,a[v]);
		}
		dfs2(v,u);
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		init(N);
		for(int i=0;i<=N;++i)visitA[i]=visitB[i]=0;
		for(int i=2;i<=N;++i){
			int x;
			scanf("%d",&x);
			addEdge(i,x);
			addEdge(x,i);
		}
		addEdge(0,1);
		for(int i=1;i<=N;++i)scanf("%d",&a[i]);
		MAX=MIN=0;
		dfs(0,-1);
		addMax=addMin=0;
		dfs2(0,-1);
		printf("%lld %lld\n",MAX+addMax,MIN+addMin);
	}
	return 0;
}
