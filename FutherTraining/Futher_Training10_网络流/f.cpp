#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int INF=1e9+7;
const int MAXN=207;
struct edge{ int from,to,cap,flow; };
vector<int>G[MAXN];
vector<edge>es;
void addEdge(int a,int b,int c){
	es.push_back(edge{a,b,c,0});
	es.push_back(edge{b,a,0,0});
	int m=es.size();
	G[a].push_back(m-2);//以a为顶点的第i条边的编号
	G[b].push_back(m-1);
}
bool visit[MAXN];
int d[MAXN];
int cur[MAXN];
int s,t;
bool bfs(){
	memset(visit,0,sizeof(visit));
	queue<int>q;
	q.push(s);
	d[s]=0;
	visit[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<G[x].size();++i){
			edge &e=es[G[x][i]];
			if(!visit[e.to]&&e.cap>e.flow){
				visit[e.to]=1;
				d[e.to]=d[x]+1;
				q.push(e.to);
			}
		}
	}
	return visit[t];
}
int dfs(int x,int a){//从s->x的最小剩余流量
	if(x==t||a==0)return a;
	int flow=0,f;
	for(int &i=cur[x];i<G[x].size();++i){
		edge& e=es[G[x][i]];
		if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
			e.flow+=f;
			es[G[x][i]^1].flow-=f;
			flow+=f;
			a-=f;//?
			if(a==0)break;
		}
	}
	return flow;
}
int Maxflow(int s,int t){
	int flow=0;
	while(bfs()){//每次完成后最短增广路长度单调递 
		memset(cur,0,sizeof(cur));
		flow+=dfs(s,INF);
	}
	return flow;
}
int sumRow[25],sumCol[25];
int N,M;
int main(){
 	int T;scanf("%d",&T);
	int tag=0;
	for(int test=1;test<=T;++test){
		if(tag)printf("\n");
		tag=1;
		scanf("%d%d",&N,&M);
		es.clear();
		for(int i=0;i<=N+M+1;++i)G[i].clear();

		for(int i=1;i<=N;++i)scanf("%d",&sumRow[i]);
		for(int i=1;i<=M;++i)scanf("%d",&sumCol[i]);
		//build
		for(int i=1;i<=N;++i)
			for(int j=N+1;j<=N+M;++j)
				addEdge(i,j,19);
		//s->row
		s=0;
		for(int i=1;i<=N;++i){
			addEdge(0,i,sumRow[i]-sumRow[i-1]-M);
		}
		//col->t
		t=N+M+1;
		for(int i=N+1;i<=N+M;++i){
			addEdge(i,N+M+1,sumCol[i-N]-sumCol[i-1-N]-N);
		}
		int res=Maxflow(s,t);
	//	printf("%d\n",res);
		printf("Matrix %d\n",test);
		for(int i=1;i<=N;++i){
			for(int j=0;j<G[i].size()-1;++j){
				printf(j==0?"%d":" %d",es[G[i][j]].flow+1);
			}
			printf("\n");
		}
	}
	return 0;
}
