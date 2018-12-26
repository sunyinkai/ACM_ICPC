//01分数规划
//最优比例环 二分+spfa判负环
#include<cstdio>
#include<cstring>
#include<cmath>
const int MAXV=1007;
const int MAXE=1e5+7; 
const double INF=1e9+7;
struct edge{
	int u,v;
	double c;	
}es[MAXE],e[MAXE];
int N,M;
int visit[MAXV];
double d[MAXV];

int head[MAXV],tot;
struct Edge{
	int to,next;
	double cost;
}edges[MAXE*2];
void init(){
	memset(head,-1,sizeof(head));
	tot=0;
}
void addEdge(int a,int b,double c){
	edges[tot].to=b;
	edges[tot].cost=c;
	edges[tot].next=head[a];
	head[a]=tot++;
}
int q[MAXV],top,inq[MAXV],cnt[MAXV];
bool hasLoop(){
	top=0;
	memset(inq,0,sizeof(inq));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=N;++i){
		d[i]=0;
		inq[1]=1;
		q[top++]=i;
	}
	while(top!=0){
		int u=q[--top];
		inq[u]=0;
		for(int i=head[u];~i;i=edges[i].next){
			if(d[edges[i].to]>d[u]+edges[i].cost){
				d[edges[i].to]=d[u]+edges[i].cost;
				if(!inq[edges[i].to]){
					q[top++]=edges[i].to;
					inq[edges[i].to]=1;
					if(++cnt[edges[i].to]>N)return true;
				}
			}
		}
	}
	return false;
}
bool isok(double mid){
	init();
	for(int i=0;i<M;++i)
		addEdge(es[i].u,es[i].v,es[i].c-mid);
	if(hasLoop())return true;
	else return false;
}
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		scanf("%d%d",&N,&M);
		for(int i=0;i<M;++i){
			scanf("%d%d%lf",&es[i].u,&es[i].v,&es[i].c);	
		}
		printf("Case #%d: ",test);
		double lo=0.0,hi=1e9;
		if(!isok(hi)){
			printf("No cycle found.\n");
			continue;
		}
		for(int i=0;i<100;++i){
			double mid=(hi+lo)/2.0;
			if(isok(mid))hi=mid;
			else lo=mid;	
		}
		printf("%.2f\n",hi);
	}
	return 0;	
}

